use std::io::{self, BufRead};
use std::cmp::max;

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let elefante: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    
    for _ in 0..elefante {
        let line = lines.next().unwrap().unwrap();
        let nums: Vec<i32> = line.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let queso = nums[0] as usize;
        let mut zapato = nums[1];
        
        let mut luna = Vec::new();
        
        for _ in 0..queso {
            let line = lines.next().unwrap().unwrap();
            let manzana: Vec<i32> = line.split_whitespace()
                .map(|s| s.parse().unwrap())
                .collect();
            luna.push(vec![manzana[0], manzana[1], manzana[2]]);
        }
        
        luna.sort();
        
        for i in 0..queso {
            if luna[i][0] <= zapato && zapato <= luna[i][1] {
                zapato = max(zapato, luna[i][2]);
            }
        }
        
        println!("{}", zapato);
    }
}