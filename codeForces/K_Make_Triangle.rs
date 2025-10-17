use std::io::{self, BufRead};

fn q(s: &[i64], i: i32) -> i64 {
    if i < 0 {
        0
    } else {
        s[i as usize]
    }
}

fn check(p: Vec<usize>, mut a: Vec<i64>, sum: i64) -> Vec<Vec<i64>> {
    let s = p.len();
    let mut ans = vec![Vec::new(); s];
    
    for i in 0..s {
        a.sort();
        let n = a.len();
        let mut used = vec![false; n];
        let mut pref = vec![0i64; n];
        
        if n > 0 {
            pref[0] = a[0];
            for j in 1..n {
                pref[j] = pref[j-1] + a[j];
            }
        }
        
        let mut curr = 0i64;
        let mut cnt = 0;
        
        for j in (0..n).rev() {
            if cnt < p[i] {
                let query_idx = p[i] as i32 - 1 - 1 - cnt as i32;
                if (curr + a[j] + q(&pref, query_idx)) * 2 < sum {
                    curr += a[j];
                    cnt += 1;
                    ans[i].push(a[j]);
                    used[j] = true;
                    if cnt == p[i] {
                        break;
                    }
                }
            }
        }
        

        let mut b = Vec::new();
        for j in 0..n {
            if !used[j] {
                b.push(a[j]);
            }
        }
        a = b;
    }
    
    ans
}

fn ok(a: &[Vec<i64>], n: usize) -> bool {
    let mut sum = 0i64;
    for group in a {
        for &x in group {
            sum += x;
        }
    }
    
    let mut m = 0;
    for group in a {
        m += group.len();
    }
    if m < n {
        return false;
    }
    
    for group in a {
        let mut curr = 0i64;
        for &x in group {
            curr += x;
        }
        if curr * 2 >= sum {
            return false;
        }
    }
    
    true
}

fn nxt<T: Ord>(arr: &mut [T]) -> bool {
    let mut k = None;
    for i in 0..arr.len() - 1 {
        if arr[i] < arr[i + 1] {
            k = Some(i);
        }
    }
    
    let k = match k {
        Some(k) => k,
        None => return false,
    };
    
    let mut l = k + 1;
    for i in k + 1..arr.len() {
        if arr[k] < arr[i] {
            l = i;
        }
    }
    
    arr.swap(k, l);
    
    arr[k + 1..].reverse();
    
    true
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    
    for _ in 0..t {
        let input = lines.next().unwrap().unwrap();
        let nums: Vec<usize> = input.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let (n, n1, n2, n3) = (nums[0], nums[1], nums[2], nums[3]);
        
        let input = lines.next().unwrap().unwrap();
        let v: Vec<i64> = input.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        
        let sum: i64 = v.iter().sum();
        
        let mut p = vec![n1, n2, n3];
        p.sort();
        
        let mut ans = Vec::new();
        loop {
            ans = check(p.clone(), v.clone(), sum);
            if ok(&ans, n) {
                break;
            }
            if !nxt(&mut p) {
                break;
            }
        }
        
        if ok(&ans, n) {
            println!("YES");
            let mut real = vec![Vec::new(); 3];
            let mut used = vec![false; 3];
            
            for i in 0..3 {
                if ans[i].len() == n1 && !used[i] {
                    used[i] = true;
                    real[0] = ans[i].clone();
                    break;
                }
            }
            for i in 0..3 {
                if ans[i].len() == n2 && !used[i] {
                    used[i] = true;
                    real[1] = ans[i].clone();
                    break;
                }
            }
            for i in 0..3 {
                if ans[i].len() == n3 && !used[i] {
                    used[i] = true;
                    real[2] = ans[i].clone();
                    break;
                }
            }
            
            for i in 0..3 {
                for &x in &real[i] {
                    print!("{} ", x);
                }
                println!();
            }
        } else {
            println!("NO");
        }
    }
}