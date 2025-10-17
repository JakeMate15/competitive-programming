use std::io::{self, Read};

struct Scanner {
    buf: Vec<u8>,
    idx: usize,
}

impl Scanner {
    fn new() -> Self {
        let mut s = String::new();
        io::stdin().read_to_string(&mut s).unwrap();
        Self { buf: s.into_bytes(), idx: 0 }
    }
    fn skip_ws(&mut self) {
        let n = self.buf.len();
        while self.idx < n && self.buf[self.idx].is_ascii_whitespace() { self.idx += 1; }
    }
    fn next_i64(&mut self) -> i64 {
        self.skip_ws();
        let n = self.buf.len();
        let mut sign = 1i64;
        if self.idx < n && self.buf[self.idx] == b'-' { sign = -1; self.idx += 1; }
        let mut x = 0i64;
        while self.idx < n && self.buf[self.idx].is_ascii_digit() {
            x = x * 10 + (self.buf[self.idx] - b'0') as i64;
            self.idx += 1;
        }
        x * sign
    }
    fn next_usize(&mut self) -> usize { self.next_i64() as usize }
}

fn upper_bound(b: &[i128], x: i128) -> usize {
    let mut lo = 0usize;
    let mut hi = b.len();
    while lo < hi {
        let mid = (lo + hi) / 2;
        if b[mid] <= x { lo = mid + 1; } else { hi = mid; }
    }
    lo
}

fn main() {
    let mut sc = Scanner::new();
    let t = sc.next_usize();
    let mut out = String::new();
    const INF: i128 = 1_000_000_000_000_000_000;

    for _ in 0..t {
        let n = sc.next_usize();
        let mut a: Vec<i128> = Vec::with_capacity(n);
        for _ in 0..n { a.push(sc.next_i64() as i128); }

        let mut b: Vec<i128> = vec![a[n - 1]];
        for i in (0..n - 1).rev() {
            if a[i] < *b.last().unwrap() { b.push(a[i]); }
        }
        b.reverse();
        let m = b.len();

        let mut dp = vec![INF; m + 1];
        dp[0] = 0;

        for i in 0..m {
            let mut f: i128 = 2;
            for _ in 0..100 {
                let target = b[i].saturating_mul(f);
                let j = upper_bound(&b, target);
                if j > 0 {
                    let add = (b[j - 1] - 1) / b[i] + 1;
                    let cand = dp[i] + add;
                    if cand < dp[j] { dp[j] = cand; }
                }
                if j == m { break; }
                f = (b[j] - 1) / b[i] + 1;
            }
            let cand = dp[i] + 1;
            if cand < dp[i + 1] { dp[i + 1] = cand; }
        }

        out.push_str(&format!("{}\n", dp[m]));
    }

    print!("{out}");
}