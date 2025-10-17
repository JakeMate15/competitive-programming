use std::cmp::max;
use std::collections::HashMap;
use std::io::{self, Read};

const N: usize = 300_020;
const MOD: i64 = 998244353;

fn mul(a: i64, b: i64) -> i64 {
    (a * b) % MOD
}

static mut T: [i64; 4 * N] = [0; 4 * N];
static mut D: [i64; 4 * N] = [0; 4 * N];

fn push(v: usize) {
    unsafe {
        if D[v] != 1 {
            T[v * 2 + 1] = mul(T[v * 2 + 1], D[v]);
            D[v * 2 + 1] = mul(D[v * 2 + 1], D[v]);
            T[v * 2 + 2] = mul(T[v * 2 + 2], D[v]);
            D[v * 2 + 2] = mul(D[v * 2 + 2], D[v]);
            D[v] = 1;
        }
    }
}

fn get(v: usize, l: usize, r: usize, tl: usize, tr: usize) -> i64 {
    if tl >= r || tr <= l {
        return 0;
    }
    unsafe {
        if tl >= l && tr <= r {
            return T[v];
        } else {
            let tm = (tl + tr) / 2;
            push(v);
            return (get(v * 2 + 1, l, r, tl, tm) + get(v * 2 + 2, l, r, tm, tr)) % MOD;
        }
    }
}

fn upd(v: usize, l: usize, r: usize, tl: usize, tr: usize) {
    if tl >= r || tr <= l {
        return;
    }
    unsafe {
        if tl >= l && tr <= r {
            T[v] = mul(T[v], 2);
            D[v] = mul(D[v], 2);
        } else {
            let tm = (tl + tr) / 2;
            push(v);
            upd(v * 2 + 1, l, r, tl, tm);
            upd(v * 2 + 2, l, r, tm, tr);
            T[v] = (T[v * 2 + 1] + T[v * 2 + 2]) % MOD;
        }
    }
}

fn add_el(v: usize, l: usize, r: usize, i: usize, x: i64) {
    unsafe {
        if r - l == 1 {
            T[v] += x;
            T[v] %= MOD;
        } else {
            let m = (l + r) / 2;
            push(v);
            if i < m {
                add_el(v * 2 + 1, l, m, i, x);
            } else {
                add_el(v * 2 + 2, m, r, i, x);
            }
            T[v] = (T[v * 2 + 1] + T[v * 2 + 2]) % MOD;
        }
    }
}

fn solve_l(arr: &Vec<i32>, n: usize) -> Vec<i32> {
    let mut cur = Vec::new();
    let mut x: i32 = -1;
    for i in 0..arr.len() {
        if x == -1 || arr[i] > arr[x as usize] {
            cur.push(arr[i]);
            x = i as i32;
        }
    }

    let mut id: HashMap<i32, usize> = HashMap::new();
    for (i, &val) in cur.iter().enumerate() {
        id.insert(val, i);
    }

    let mut dp = vec![0i32; arr.len()];
    unsafe {
        for i in 0..4 * n {
            T[i] = 0;
            D[i] = 1;
        }
    }

    let m = cur.len();
    for i in 0..arr.len() {
        let pos_id = cur.binary_search(&arr[i]).unwrap_or_else(|e| e);
        upd(0, pos_id, m, 0, m);
        if let Some(&pos) = id.get(&arr[i]) {
            if pos == 0 {
                dp[i] = 1;
            } else {
                dp[i] = get(0, pos_id - 1, pos_id, 0, m) as i32;
            }
            add_el(0, 0, m, pos_id, dp[i] as i64);

            /*
            // sig valor “tope”
            let nxt = if pos_id + 1 < cur.len() { cur[pos_id + 1] } else { -1 };
            let mut ways: i64 = 1;
            for j in (i + 1)..arr.len() {
                if arr[j] <= arr[i] {
                    ways = (ways * 2) % MOD;
                }
                if arr[j] == nxt {
                    // dp[j] = (dp[j] + dp[i] * ways) % MOD
                    let add = ((dp[i] as i64) * ways) % MOD;
                    let mut vj = (dp[j] as i64 + add) % MOD;
                    if vj < 0 { vj += MOD; }
                    dp[j] = vj as i32;
                }
            }
            */
        }
    }
    dp
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let tc: usize = iter.next().unwrap().parse().unwrap();

    for _ in 0..tc {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let mut a: Vec<i32> = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(iter.next().unwrap().parse::<i32>().unwrap());
        }

        let g1 = solve_l(&a, n);
        let mut a_rev = a.clone();
        a_rev.reverse();
        let mut g2 = solve_l(&a_rev, n);
        g2.reverse();

        let mut mx = 0;
        for &val in &a {
            mx = max(mx, val);
        }

        let mut ans: i64 = 0;
        let mut pw = vec![0i64; n + 1];
        let mut rpw = vec![0i64; n + 1];
        pw[0] = 1;
        let inv_2 = (MOD + 1) / 2;
        for i in 1..=n {
            pw[i] = (pw[i - 1] * 2) % MOD;
        }
        for i in 1..=n {
            rpw[i] = (rpw[i - 1] * inv_2) % MOD;
        }

        for i in 0..n {
            if a[i] == mx {
                ans += (g1[i] as i64 * g2[i] as i64) % MOD;
                ans %= MOD;
            }
        }

        let mut result: i64 = 0;
        for i in (0..n).rev() {
            if a[i] == mx {
                let cur = (result * inv_2) % MOD;
                ans += (g1[i] as i64 * cur) % MOD;
                ans %= MOD;
                result += g2[i] as i64;
                result %= MOD;
            }
            result = (result * 2) % MOD;
        }

        /*
        // pares de máximos
        for i in 0..n {
            if a[i] == mx {
                let mut ways_between: i64 = 1;
                for j in i..n {
                    if a[j] == mx {
                        let mut cur = ((g1[i] as i64) * (g2[j] as i64)) % MOD;
                        cur = (cur * ways_between) % MOD;
                        ans = (ans + cur) % MOD;
                    }
                    if i != j {
                        ways_between = (ways_between * 2) % MOD;
                    }
                }
            }
        }
        */

        println!("{}", ans);
    }
}