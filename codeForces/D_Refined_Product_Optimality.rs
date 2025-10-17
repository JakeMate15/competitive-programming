use std::io::{self, Read};

const MOD: i64 = 998244353;

fn power(mut a: i64, mut n: i64) -> i64 {
    let mut result = 1;
    while n > 0 {
        if n & 1 == 1 {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    result
}

fn mod_inverse(a: i64) -> i64 {
    power(a, MOD - 2)
}

fn upper_bound(arr: &[i32], target: i32) -> usize {
    let mut left = 0;
    let mut right = arr.len();
    
    while left < right {
        let mid = left + (right - left) / 2;
        if arr[mid] <= target {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    left
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();
    
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let q: usize = it.next().unwrap().parse().unwrap();
        
        let mut a: Vec<i32> = vec![0; n + 1];
        let mut b: Vec<i32> = vec![0; n + 1];
        let mut ka: Vec<i32> = vec![0; n + 1];
        let mut kb: Vec<i32> = vec![0; n + 1];
        

        for i in 1..=n {
            a[i] = it.next().unwrap().parse().unwrap();
            ka[i] = a[i];
        }
        
        for i in 1..=n {
            b[i] = it.next().unwrap().parse().unwrap();
            kb[i] = b[i];
        }
        
        ka[1..=n].sort();
        kb[1..=n].sort();
        
        let mut ans: i64 = 1;
        for i in 1..=n {
            ans = (ans * (ka[i].min(kb[i]) as i64)) % MOD;
        }
        
        output.push_str(&format!("{} ", ans));
        
        for query_idx in 0..q {
            let o: usize = it.next().unwrap().parse().unwrap();
            let x: usize = it.next().unwrap().parse().unwrap();
            
            if o == 1 {
                let p = upper_bound(&ka[1..=n], a[x]);
                
                ans = (ans * mod_inverse((ka[p].min(kb[p])) as i64)) % MOD;
                
                ka[p] += 1;
                a[x] += 1;
                
                ans = (ans * (ka[p].min(kb[p]) as i64)) % MOD;
            } else {
                let p = upper_bound(&kb[1..=n], b[x]);
                
                ans = (ans * mod_inverse((ka[p].min(kb[p])) as i64)) % MOD;
                
                kb[p] += 1;
                b[x] += 1;
                
                ans = (ans * (ka[p].min(kb[p]) as i64)) % MOD;
            }
            
            if query_idx == q - 1 {
                output.push_str(&format!("{}\n", ans));
            } else {
                output.push_str(&format!("{} ", ans));
            }
        }
    }
    
    print!("{}", output);
}