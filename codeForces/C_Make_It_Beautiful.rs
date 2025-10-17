use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();
    
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut k: i64 = it.next().unwrap().parse().unwrap();
        
        let mut arr = Vec::with_capacity(n);
        for _ in 0..n {
            arr.push(it.next().unwrap().parse::<i64>().unwrap());
        }
        
        let mut ans = 0;
        for j in 0..=60 {
            for i in 0..n {
                if arr[i] & (1i64 << j) != 0 {
                    ans += 1;
                } else if k >= (1i64 << j) {
                    ans += 1;
                    k -= 1i64 << j;
                }
            }
        }
        
        output.push_str(&format!("{}\n", ans));
    }
    
    print!("{}", output);
}