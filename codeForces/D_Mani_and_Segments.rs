use std::cmp::{max, min};
use std::collections::BTreeSet;
use std::io::{self, Read};

struct Scanner {
    buf: Vec<u8>,
    idx: usize,
}

impl Scanner {
    fn new() -> Self {
        let mut s = String::new();
        io::stdin().read_to_string(&mut s).unwrap();
        Self {
            buf: s.into_bytes(),
            idx: 0,
        }
    }

    fn next_i64(&mut self) -> i64 {
        let n = self.buf.len();
        while self.idx < n && self.buf[self.idx].is_ascii_whitespace() {
            self.idx += 1;
        }
        let mut sign = 1i64;
        if self.idx < n && self.buf[self.idx] == b'-' {
            sign = -1;
            self.idx += 1;
        }
        let mut x = 0i64;
        while self.idx < n && self.buf[self.idx].is_ascii_digit() {
            x = x * 10 + (self.buf[self.idx] - b'0') as i64;
            self.idx += 1;
        }
        x * sign
    }

    fn next_usize(&mut self) -> usize {
        self.next_i64() as usize
    }
}

struct Seg {
    n: usize,
    tr: Vec<usize>,
}

impl Seg {
    fn new(n: usize) -> Self {
        let mut p = 1usize;
        while p < n {
            p <<= 1;
        }
        Self {
            n: p,
            tr: vec![0usize; 2 * p + 5],
        }
    }

    fn upd(&mut self, mut l: usize, mut r: usize, x: usize) {
        if l > r {
            return;
        }
        l += self.n;
        r += self.n;
        self.tr[l] = self.tr[l].max(x);
        self.tr[r] = self.tr[r].max(x);
        while (l >> 1) != (r >> 1) {
            if l % 2 == 0 {
                self.tr[l + 1] = self.tr[l + 1].max(x);
            }
            if r % 2 == 1 {
                self.tr[r - 1] = self.tr[r - 1].max(x);
            }
            l >>= 1;
            r >>= 1;
        }
    }

    fn cnt(&self, mut v: usize) -> usize {
        v += self.n;
        let mut ans = self.tr[v];
        let mut u = v;
        while u > 0 {
            ans = ans.max(self.tr[u]);
            u >>= 1;
        }
        ans
    }
}

fn get(t: &[usize]) -> Vec<usize> {
    let n = t.len();
    let mut seg = Seg::new(n);
    let mut p = vec![0usize; n];
    let mut ans = vec![0usize; n];
    for i in 0..n {
        p[t[i]] = i;
    }
    let mut s: BTreeSet<usize> = BTreeSet::new();
    for i in 0..n {
        let pi = p[i];
        ans[pi] = seg.cnt(pi);
        if let Some(&x) = s.range(pi..).next() {
            seg.upd(x, n - 1, pi + 1);
        }
        s.insert(pi);
    }
    ans
}

fn main() {
    let mut sc = Scanner::new();
    let t = sc.next_usize();
    let mut out = String::new();

    for _ in 0..t {
        let n = sc.next_usize();
        let mut tvec = vec![0usize; n];
        for i in 0..n {
            tvec[i] = sc.next_usize() - 1;
        }

        let lm = get(&tvec);

        let mut trev = tvec.clone();
        trev.reverse();
        let mut rm = get(&trev);

        for v in trev.iter_mut() {
            *v = n - 1 - *v;
        }
        let mut rd = get(&trev);

        trev.reverse();
        let ld = get(&trev);

        rm.reverse();
        rd.reverse();

        for i in 0..n {
            rm[i] = n - 1 - rm[i];
        }
        for i in 0..n {
            rd[i] = n - 1 - rd[i];
        }

        let mut k = vec![0usize; n];
        for i in 0..n {
            let l = max(lm[i], ld[i]);
            let r = min(rm[i], rd[i]);
            k[l] = max(k[l], r);
        }

        for i in 0..n - 1 {
            k[i + 1] = max(k[i + 1], k[i]);
        }

        let mut ans: i64 = 0;
        for i in 0..n {
            ans += k[i] as i64 - i as i64 + 1;
        }

        out.push_str(&format!("{}\n", ans));
    }

    print!("{out}");
}
