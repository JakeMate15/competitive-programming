use std::io::{self, Read};
use std::cmp::min;

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
    fn next_i64(&mut self) -> i64 {
        let n = self.buf.len();
        while self.idx < n && self.buf[self.idx].is_ascii_whitespace() { self.idx += 1; }
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

const M: usize = 32;
const INF: i64 = 100_000_000_000_000_000;

fn need(i: usize, n: usize, a: &Vec<i64>) -> i64 {
    let mut ans = 0i64;
    if i > 0 { ans |= a[i - 1]; }
    if i + 1 < n { ans |= a[i]; }
    ans
}

fn mag(i: usize, j: usize, n: usize, a: &Vec<i64>, b: &Vec<i64>) -> i64 {
    if j == 0 { return b[i]; }
    let jj = j - 1;
    if ((b[i] >> jj) & 1) != 0 { return -1; }
    let mut ans = b[i];
    let msk: i64 = (1_i64 << jj) - 1;
    ans |= (msk + 1);
    ans &= !msk;
    ans |= need(i, n, a) & msk;
    debug_assert!(ans >= b[i]);
    ans
}

fn main() {
    let mut sc = Scanner::new();
    let t = sc.next_usize();
    let mut out = String::new();

    for _ in 0..t {
        let n = sc.next_usize();
        let mut a = vec![0i64; n.saturating_sub(1)];
        for i in 0..n.saturating_sub(1) {
            a[i] = sc.next_i64();
        }
        let mut b = vec![0i64; n];
        for i in 0..n {
            b[i] = sc.next_i64();
        }
        let mut dp = vec![vec![INF; M]; n + 1];
        for j in 0..M {
            let x = mag(0, j, n, &a, &b);
            dp[1][j] = if x == -1 { INF } else { x - b[0] };
        }
        for i in 1..n {
            for j in 0..M {
                let x = mag(i, j, n, &a, &b);
                if x == -1 { continue; }
                let mut best = INF;
                for j2 in 0..M {
                    let y = mag(i - 1, j2, n, &a, &b);
                    if y == -1 { continue; }
                    if (x & y) != a[i - 1] { continue; }
                    best = min(best, dp[i][j2] + (x - b[i]));
                }
                dp[i + 1][j] = best;
            }
        }
        let mut ans = INF;
        for j in 0..M {
            ans = min(ans, dp[n][j]);
        }
        if ans >= INF {
            out.push_str("-1\n");
        } else {
            out.push_str(&format!("{ans}\n"));
        }
    }
    print!("{out}");
}