use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();
        let mut p: f64 = it.next().unwrap().parse().unwrap();
        p /= 100.0;
        let mut h = vec![0usize; n];
        for i in 0..n {
            h[i] = it.next().unwrap().parse().unwrap();
        }
        let mut k = h.iter().cloned().min().unwrap();
        let mut s = 0usize;
        for &hi in &h {
            s += hi - k;
        }
        if m < s {
            output.push_str("0\n");
            continue;
        }
        let mut k = k as isize;
        k -= 1;
        let ms = m - s;
        let rows1 = ms + 1;
        let cols1 = s + 1;
        let mut dp1 = vec![0f64; rows1 * cols1];
        dp1[0 * cols1 + 0] = 1.0;
        for i in 0..=ms {
            for j in 0..s {
                let idx = i * cols1 + j;
                let val = dp1[idx];
                if i + 1 <= ms {
                    dp1[(i + 1) * cols1 + j] += val * p;
                }
                dp1[i * cols1 + (j + 1)] += val * (1.0 - p);
            }
        }

        let k_usize = if k < 0 { 0 } else { k as usize };
        let k_dim = k_usize + 1;
        let t_dim = m + 1;
        let mut dp = vec![0f64; k_dim * n * t_dim];
        for t0 in 0..=m {
            dp[(0 * n + 0) * t_dim + t0] = 1.0;
        }
        for i in 0..k_dim {
            for j in 0..n {
                for t0 in 1..=m {
                    if i == 0 && j == 0 {
                        continue;
                    }
                    let mut val = 0.0;
                    if i == 0 {
                        val += dp[(i * n + j) * t_dim + (t0 - 1)] * p;
                    } else {
                        val += dp[((i - 1) * n + j) * t_dim + (t0 - 1)] * p;
                    }
                    if j > 0 {
                        val += dp[(i * n + (j - 1)) * t_dim + (t0 - 1)] * (1.0 - p);
                    } else {
                        let a = if i > 0 {
                            dp[((i - 1) * n + (n - 1)) * t_dim + (t0 - 1)]
                        } else {
                            0.0
                        };
                        let b = dp[(i * n + 0) * t_dim + (t0 - 1)];
                        val += a.max(b) * (1.0 - p);
                    }
                    dp[(i * n + j) * t_dim + t0] = val;
                }
            }
        }

        let mut ans = 0.0;
        for i in 0..=ms {
            let ki = if (k - i as isize) > 0 { (k - i as isize) as usize } else { 0 };
            let t1 = ms - i;
            let v1 = dp[(ki * n + 0) * t_dim + t1];
            let v2 = dp1[i * cols1 + s];
            ans += v1 * v2;
        }
        output.push_str(&format!("{:.11}\n", ans));
    }

    print!("{}", output);
}