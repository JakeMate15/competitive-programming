use std::io::{self, Read};
use std::collections::{BTreeSet, HashMap};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();
    
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();
        
        let mut loc_a: HashMap<i64, usize> = HashMap::new();
        let mut loc_b: HashMap<i64, usize> = HashMap::new();
        let mut a: Vec<i64> = Vec::new();
        for i in 0..(n * m) {
            let val: i64 = it.next().unwrap().parse().unwrap();
            a.push(val);
            loc_a.insert(val, i);
        }
        
        let mut b: Vec<i64> = Vec::new();
        for i in 0..(n * m) {
            let val: i64 = it.next().unwrap().parse().unwrap();
            b.push(val);
            loc_b.insert(val, i);
        }
        
        let mut p = 0;
        
        for i in 0..n {
            let end_ind = (i + 1) * m - 1;
            let beg_ind = i * m;
            let mut at = 0;
            
            while at <= end_ind && p <= beg_ind {
                if let Some(&nat) = loc_b.get(&a[p]) {
                    if nat < at || nat < beg_ind || nat > end_ind {
                        break;
                    }
                    at = nat + 1;
                    p += 1;
                } else {
                    break;
                }
            }
            
            let mut tp = p;
            if p > beg_ind {
                p -= 1;
            }
            
            while at <= end_ind && tp > beg_ind {
                if tp >= a.len() || at >= b.len() || a[tp] != b[at] {
                    break;
                }
                tp += 1;
                at += 1;
            }
            
            if at == end_ind + 1 {
                p = tp;
            }
        }
        
        output.push_str(&format!("{}\n", n * m - p));
        
        let mut amz: Vec<Vec<i64>> = vec![Vec::new(); n * m + 1];
        let mut p2 = 0;
        let mut cnt = 0;
        
        for i in 0..(n * m) {
            if p2 < a.len() && p2 < p && a[p2] == b[i] {
                cnt += 1;
                p2 += 1;
                continue;
            }
            amz[cnt].push(b[i]);
        }
        
        let mut pnt: Vec<usize> = vec![0; n + 1];
        let mut can: BTreeSet<usize> = BTreeSet::new();
        
        for i in 0..=n {
            pnt[i] = i * m;
            if pnt[i] < amz.len() && !amz[pnt[i]].is_empty() {
                can.insert(i);
            }
        }
        
        while !can.is_empty() {
            let id = *can.iter().next_back().unwrap();
            can.remove(&id);
            
            let loc = pnt[id];
            if loc < amz.len() && !amz[loc].is_empty() {
                output.push_str(&format!("{} {}\n", id + 1, amz[loc].last().unwrap()));
                amz[loc].pop();
                
                if !amz[loc].is_empty() {
                    can.insert(id);
                }
            }
            
            for i in (id + 1)..=n {
                if pnt[i] > 0 {
                    pnt[i] -= 1;
                }
                if pnt[i] <= (i - 1) * m {
                    break;
                }
                if pnt[i] < amz.len() && !amz[pnt[i]].is_empty() {
                    can.insert(i);
                }
            }
        }
    }
    
    print!("{}", output);
}