use std::io::{self, Read};
use std::collections::HashMap;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();
    
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: u64 = it.next().unwrap().parse().unwrap();
        
        let mut p = Vec::with_capacity(n);
        for _ in 0..n {
            p.push(it.next().unwrap().parse::<u64>().unwrap());
        }
        
        let mut d = Vec::with_capacity(n);
        for _ in 0..n {
            d.push(it.next().unwrap().parse::<u64>().unwrap());
        }
        
        let q: usize = it.next().unwrap().parse().unwrap();
        let mut qs = Vec::with_capacity(q);
        for _ in 0..q {
            qs.push(it.next().unwrap().parse::<u64>().unwrap());
        }
        
        let mut adj = vec![2 * n; 2 * n];
        let mut ref_map: HashMap<u64, usize> = HashMap::new();
        
        for i in 0..n {
            let val = (k + d[i] + p[i] % k) % k;
            if let Some(&target) = ref_map.get(&val) {
                adj[i + n] = target;
            }
            ref_map.insert(val, i);
        }
        
        ref_map.clear();
        
        for i in (0..n).rev() {
            let val = (k + d[i] - p[i] % k) % k;
            if let Some(&target) = ref_map.get(&val) {
                adj[i] = target;
            }
            ref_map.insert(val, i + n);
        }
        
        ref_map.clear();
        
        let mut magic: Vec<(u64, usize)> = qs
            .iter()
            .enumerate()
            .map(|(i, &val)| (val, i))
            .collect();
        magic.sort_by_key(|&(val, _)| val);
        
        let mut qr = vec![-1i32; q];
        let mut r = q as i32 - 1;
        let mut l = n as i32 - 1;
        
        while l >= 0 || r >= 0 {
            if r < 0 || (l >= 0 && p[l as usize] >= magic[r as usize].0) {
                let val = (k + d[l as usize] - p[l as usize] % k) % k;
                ref_map.insert(val, l as usize + n);
                l -= 1;
            } else {
                let val = (k - magic[r as usize].0 % k) % k;
                if let Some(&target) = ref_map.get(&val) {
                    qr[magic[r as usize].1] = target as i32;
                }
                r -= 1;
            }
        }
        
        let mut vis = vec![0u8; 2 * n];
        
        fn dfs(u: usize, adj: &[usize], vis: &mut [u8], bound: usize) -> bool {
            if u == bound {
                return false;
            }
            if vis[u] != 0 {
                return vis[u] == 1 || vis[u] == 3;
            }
            
            vis[u] = 1;
            let ans = dfs(adj[u], adj, vis, bound);
            vis[u] = if ans { 3 } else { 2 };
            ans
        }
        
        for i in 0..2 * n {
            if vis[i] == 0 {
                dfs(i, &adj, &mut vis, 2 * n);
            }
        }
        
        for &i in &qr {
            if i == -1 || vis[i as usize] == 2 {
                output.push_str("YES\n");
            } else {
                output.push_str("NO\n");
            }
        }
    }
    
    print!("{}", output);
}