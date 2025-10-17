use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    
    for _ in 0..t {
        let line = lines.next().unwrap().unwrap();
        let nums: Vec<usize> = line.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let n = nums[0];
        let m = nums[1];
        let k = nums[2];
        
        let mut adj: Vec<Vec<usize>> = vec![vec![]; n + 1];
        
        for _ in 0..m {
            let line = lines.next().unwrap().unwrap();
            let edge: Vec<usize> = line.split_whitespace()
                .map(|s| s.parse().unwrap())
                .collect();
            let u = edge[0];
            let v = edge[1];
            adj[u].push(v);
            adj[v].push(u);
        }
        
        let mut odd = 0;
        for i in 1..=n {
            let di = adj[i].len();
            for &j in &adj[i] {
                if (di + adj[j].len()) % 2 == 1 {
                    odd += 1;
                }
            }
        }
        
        if k == 1 {
            println!("{}", if odd <= 4 { "YES" } else { "NO" });
        } else if odd == 2 * m || odd == 0 {
            println!("YES");
        } else if k == 2 {
            let mut res = 0;
            for i in 1..=n {
                let di = adj[i].len();
                let r: usize = adj[i].iter()
                    .filter(|&&j| adj[j].len() % 2 == 1)
                    .count();
                res += r * (di - r);
            }
            println!("{}", if res <= 2 { "YES" } else { "NO" });
        } else {
            const INF: usize = 1_000_000_000;
            let mut mx = INF;
            
            for i in 1..=n {
                if adj[i].len() % 2 == 1 {
                    if adj[i].len() > 1 {
                        mx = 0;
                    } else {
                        let mut chain = vec![i, adj[i][0]];
                        
                        while adj[chain[chain.len() - 1]].len() == 2 {
                            let last = chain[chain.len() - 1];
                            let a = adj[last][0];
                            let b = adj[last][1];
                            let prev = chain[chain.len() - 2];
                            let nxt = if a == prev { b } else { a };
                            chain.push(nxt);
                        }
                        
                        mx = mx.min(chain.len() - 1);
                    }
                }
            }
            
            println!("{}", if k <= mx { "YES" } else { "NO" });
        }
    }
}