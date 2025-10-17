use std::io::{self, Read};
use std::collections::{HashMap, HashSet};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();
    
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();
        
        let mut x: Vec<i64> = vec![0; n];
        let mut cnt: HashMap<(usize, usize), i64> = HashMap::new();
        let mut todo: Vec<HashSet<usize>> = vec![HashSet::new(); n];
        let mut base: i64 = 0;
        
        for i in 0..n {
            for _ in 0..m {
                let a: i32 = it.next().unwrap().parse().unwrap();
                if a == -1 {
                    x[i] += 1;
                } else {
                    let a = (a - 1) as usize;
                    *cnt.entry((i, a)).or_insert(0) += 1;
                    
                    if i > 0 {
                        todo[i - 1].insert(a);
                    }
                    if i + 1 < n {
                        todo[i + 1].insert(a);
                    }
                    
                    if i > 0 && cnt.contains_key(&(i - 1, a)) {
                        base += cnt[&(i - 1, a)];
                    }
                }
            }
            if i > 0 {
                base += x[i] * x[i - 1];
            }
        }
        
        let mut best_all: i64 = 0;
        let mut best_any: i64 = 0;
        let mut best: Vec<i64> = vec![0; k];
        
        for i in 0..n {
            for &u in &todo[i] {
                let mut add: i64 = 0;
                if i > 0 {
                    add += cnt.get(&(i - 1, u)).unwrap_or(&0);
                }
                if i + 1 < n {
                    add += cnt.get(&(i + 1, u)).unwrap_or(&0);
                }
                add *= x[i];
                
                best[u] = best[u].max(best_any) + add;
                best_all = best_all.max(best[u]);
            }
            
            if i + 1 == n {
                break;
            }
            
            best_any = best_any.max(best_all - x[i] * x[i + 1]);
        }
        
        output.push_str(&format!("{}\n", best_all + base));
    }
    
    print!("{}", output);
}