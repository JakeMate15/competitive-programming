use std::io::{self, BufRead};
use std::cmp::max;

#[derive(Clone, Copy, Default)]
struct S {
    sum: i64,
    pre: i64,
    suf: i64,
}

fn f(l: S, r: S) -> S {
    S {
        sum: l.sum + r.sum,
        pre: max(l.pre, l.sum + r.pre),
        suf: max(r.suf, r.sum + l.suf),
    }
}

fn e() -> S {
    S::default()
}

struct Segtree {
    n: usize,
    s: Vec<S>,
}

impl Segtree {
    fn new(a: Vec<S>) -> Self {
        let n = a.len();
        let mut st = Self {
            n,
            s: vec![e(); 2 * n],
        };
        for i in 0..n {
            st.s[i + n] = a[i];
        }
        for i in (1..n).rev() {
            st.s[i] = f(st.s[i * 2], st.s[i * 2 + 1]);
        }
        st
    }

    fn upd(&mut self, mut i: usize, v: S) {
        i += self.n;
        self.s[i] = v;
        while i > 1 {
            i /= 2;
            self.s[i] = f(self.s[i * 2], self.s[i * 2 + 1]);
        }
    }

    fn qry(&self, mut l: usize, mut r: usize) -> S {
        let mut u = e();
        let mut v = e();
        l += self.n;
        r += self.n;
        while l < r {
            if l % 2 == 1 {
                u = f(u, self.s[l]);
                l += 1;
            }
            if r % 2 == 1 {
                r -= 1;
                v = f(self.s[r], v);
            }
            l /= 2;
            r /= 2;
        }
        f(u, v)
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    
    for _ in 0..t {
        let n: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
        
        let a: Vec<i32> = lines.next().unwrap().unwrap()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        
        let mut l = vec![-1i32; n];
        let mut r = vec![n as i32; n];
        let mut stk = Vec::new();
        let mut pos: Vec<Vec<usize>> = vec![vec![]; n + 1];
        
        for i in 0..n {
            pos[a[i] as usize].push(i);
            while !stk.is_empty() && a[i] <= a[*stk.last().unwrap()] {
                r[stk.pop().unwrap()] = i as i32;
            }
            if !stk.is_empty() {
                l[i] = *stk.last().unwrap() as i32;
            }
            stk.push(i);
        }
        
        let mut lo = a.clone();
        let mut hi = vec![n as i32; n];
        
        loop {
            let mut duus = true;
            let mut hen: Vec<Vec<usize>> = vec![vec![]; n + 1];
            
            for i in 0..n {
                if lo[i] < hi[i] {
                    duus = false;
                    hen[((lo[i] + hi[i] + 1) / 2) as usize].push(i);
                }
            }
            
            if duus {
                break;
            }
            
            let mut st = Segtree::new(vec![S { sum: -1, pre: 0, suf: 0 }; n]);
            
            for i in (1..=n).rev() {
                for &x in &pos[i] {
                    st.upd(x, S { sum: 1, pre: 1, suf: 1 });
                }
                for &x in &hen[i] {
                    if st.qry(x + 1, r[x] as usize).pre + st.qry((l[x] + 1) as usize, x).suf > 0 {
                        lo[x] = i as i32;
                    } else {
                        hi[x] = i as i32 - 1;
                    }
                }
            }
        }
        
        let ans = (0..n).map(|i| lo[i] - a[i]).max().unwrap();
        println!("{}", ans);
    }
}