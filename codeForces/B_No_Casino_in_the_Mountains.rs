use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    
    for _ in 0..t {
        // Mucho texto
        let line = lines.next().unwrap().unwrap();
        let nums: Vec<usize> = line.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let n = nums[0];
        let clavito = nums[1];
        
        let arr: Vec<i32> = lines.next().unwrap().unwrap()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        
        let mut pablito = 0;
        let mut un = 0;
        
        for i in 0..n {
            if arr[i] != 0 {
                pablito += (un + 1) / (clavito + 1);
                un = 0;
            } else {
                un += 1;
            }
        }
        
        println!("{}", pablito + (un + 1) / (clavito + 1));
    }
}