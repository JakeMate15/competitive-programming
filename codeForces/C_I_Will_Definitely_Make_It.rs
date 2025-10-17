use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let tres: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    
    for _ in 0..tres {
        let line = lines.next().unwrap().unwrap();
        let nums: Vec<usize> = line.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let n = nums[0];
        let k = nums[1];
        
        let mut tristes: Vec<i32> = lines.next().unwrap().unwrap()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        
        let tigres = tristes[k - 1];
        tristes.sort();
        tristes.dedup();
        
        let mut tragaron = false;
        for i in 0..tristes.len() - 1 {
            if tristes[i] >= tigres && tristes[i + 1] - tristes[i] > tigres {
                tragaron = true;
                break;
            }
        }
        
        println!("{}", if tragaron { "NO" } else { "YES" });
    }
}