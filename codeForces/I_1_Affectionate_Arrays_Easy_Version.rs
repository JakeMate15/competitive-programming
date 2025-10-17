use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();
    
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut a: Vec<i64> = Vec::with_capacity(n);
        let mut sum: i64 = 0;
        
        for _ in 0..n {
            let v: i64 = it.next().unwrap().parse().unwrap();
            a.push(v);
            sum += v;
        }
        
        let mut l: i64 = 0;
        let mut r: i64 = 0;
        let mut ans: i32 = n as i32;
        
        for i in 0..n {
            if r + a[i] < 0 {
                ans += 1;
                l = 0;
                r = sum;
            }
            if l + a[i] > sum {
                ans += 1;
                l = 0;
                r = sum;
            }
            l = (l + a[i]).max(0);
            r = (r + a[i]).min(sum);
        }
        
        if r < sum {
            ans += 1;
        }
        
        output.push_str(&format!("{}\n", ans));
    }
    
    print!("{}", output);
}