use std::io::{self, BufRead};
use std::collections::HashMap;

type T = Vec<(usize, i64)>;

fn sol() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let first_line = lines.next().unwrap().unwrap();
    let parts: Vec<usize> = first_line.split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    let n = parts[0];
    let q = parts[1];
    
    let mut col = vec![0; n + 1];
    let col_line = lines.next().unwrap().unwrap();
    let col_vals: Vec<i32> = col_line.split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    for i in 1..=n {
        col[i] = col_vals[i - 1];
    }
    
    let mut sp: i64 = 0;
    let mut g: Vec<T> = vec![vec![]; n + 1];
    let mut edg = Vec::new();
    
    for _ in 0..n - 1 {
        let edge_line = lines.next().unwrap().unwrap();
        let edge_parts: Vec<usize> = edge_line.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let u = edge_parts[0];
        let v = edge_parts[1];
        let c = edge_parts[2] as i64;
        
        g[u].push((v, c));
        g[v].push((u, c));
        edg.push((u, v, c));
        sp += c;
    }
    
    let b = 450;
    let mut es_p = vec![false; n + 1];
    for i in 1..=n {
        if g[i].len() > b {
            es_p[i] = true;
        }
    }
    
    let mut vec_p: Vec<T> = vec![vec![]; n + 1];
    for i in 1..=n {
        for &p in &g[i] {
            if es_p[p.0] {
                vec_p[i].push(p);
            }
        }
    }
    
    let mut mp: Vec<HashMap<i32, i64>> = vec![HashMap::new(); n + 1];
    for i in 1..=n {
        if es_p[i] {
            for &p in &g[i] {
                *mp[i].entry(col[p.0]).or_insert(0) += p.1;
            }
        }
    }
    
    let mut ig: i64 = 0;
    for &(u, v, c) in &edg {
        if col[u] == col[v] {
            ig += c;
        }
    }
    
    let mut res = sp - ig;
    
    for _ in 0..q {
        let query_line = lines.next().unwrap().unwrap();
        let query_parts: Vec<usize> = query_line.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let v = query_parts[0];
        let x = query_parts[1] as i32;
        
        if col[v] != x {
            let mut vo: i64 = 0;
            let mut ne: i64 = 0;
            
            if es_p[v] {
                let m = &mp[v];
                if let Some(&val) = m.get(&col[v]) {
                    vo = val;
                }
                if let Some(&val) = m.get(&x) {
                    ne = val;
                }
            } else {
                for &(a, b) in &g[v] {
                    if col[a] == col[v] {
                        vo += b;
                    }
                    if col[a] == x {
                        ne += b;
                    }
                }
            }
            
            ig -= vo;
            ig += ne;
            
            for &(u, c) in &vec_p[v] {
                let m = &mut mp[u];
                if let Some(val) = m.get_mut(&col[v]) {
                    *val -= c;
                    if *val == 0 {
                        m.remove(&col[v]);
                    }
                }
                *m.entry(x).or_insert(0) += c;
            }
            
            col[v] = x;
            res = sp - ig;
        }
        
        println!("{}", res);
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let t: usize = lines.next().unwrap().unwrap().parse().unwrap();
    
    for _ in 0..t {
        sol();
    }
}