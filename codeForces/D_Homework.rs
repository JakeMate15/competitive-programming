use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut m = n;
        while m % 2 == 0 {
            m /= 2;
        }
        let k = n / m;
        let s = it.next().unwrap().as_bytes();
        let t_str = it.next().unwrap().as_bytes();
        let mut p = vec![0u8; n];
        let mut q = vec![0u8; n];
        for idx in 0..n {
            p[idx] = s[idx] - b'0';
            q[idx] = t_str[idx] - b'0';
        }
        {
            let mut row_idx = 0;
            for col in 0..m {
                let mut pivot = row_idx;
                while pivot < k && p[pivot * m + col] == 0 {
                    pivot += 1;
                }
                if pivot == k {
                    continue;
                }
                if pivot != row_idx {
                    for c in 0..m {
                        p.swap(row_idx * m + c, pivot * m + c);
                    }
                }
                for r in 0..k {
                    if r != row_idx && p[r * m + col] == 1 {
                        for c in col..m {
                            let a = r * m + c;
                            let b = row_idx * m + c;
                            p[a] ^= p[b];
                        }
                    }
                }
                row_idx += 1;
            }
        }
        {
            let mut row_idx = 0;
            for col in 0..m {
                let mut pivot = row_idx;
                while pivot < k && q[pivot * m + col] == 0 {
                    pivot += 1;
                }
                if pivot == k {
                    continue;
                }
                if pivot != row_idx {
                    for c in 0..m {
                        q.swap(row_idx * m + c, pivot * m + c);
                    }
                }
                for r in 0..k {
                    if r != row_idx && q[r * m + col] == 1 {
                        for c in col..m {
                            let a = r * m + c;
                            let b = row_idx * m + c;
                            q[a] ^= q[b];
                        }
                    }
                }
                row_idx += 1;
            }
        }
        if p == q {
            output.push_str("Yes\n");
        } else {
            output.push_str("No\n");
        }
    }

    print!("{}", output);
}