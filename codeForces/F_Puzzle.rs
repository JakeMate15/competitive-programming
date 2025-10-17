use std::io::{self, Read};
use std::cmp::max;
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

fn po(mut a: i64, mut b: i64, p: i64) -> i64 {
    let mut res = 1i64;
    a %= p;
    while b > 0 {
        if b & 1 == 1 { res = res * a % p; }
        a = a * a % p;
        b >>= 1;
    }
    res
}

fn inv(x: i64, p: i64) -> i64 {
    po(x, p - 2, p)
}

fn f(h: i64) -> i64 {
    let h2 = h / 2;
    if h2 % 2 == 0 {
        h2 * h2 / 4
    } else {
        (h2 * h2 - 1) / 4
    }
}

fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let t = a % b;
        a = b;
        b = t;
    }
    a.abs()
}

fn main() {
    let mut sc = Scanner::new();
    let t = sc.next_usize();
    let mut out = String::new();
    for _ in 0..t {
        let mut p = sc.next_i64();
        let mut s = sc.next_i64();
        let o = gcd(p, s);
        p /= o;
        s /= o;
        let mut v: Vec<(i64, i64)> = Vec::new();
        let mut s1 = 1i64;
        for p1 in (4..=100010).step_by(2) {
            if p1 as i64 % p == 0 {
                s1 = (p1 as i64 / p) * s;
                let mis = p1 as i64 / 2 - 1;
                let a = (p1 / 2) / 2;
                let b = (p1 / 2 + 1) / 2;
                let mas = (a as i64) * (b as i64);
                if s1 >= mis && s1 <= mas {
                    for i in 0..a {
                        v.push((i as i64, 0));
                    }
                    for i in 1..b {
                        v.push((0, i as i64));
                    }
                    'outer: for i in 1..a {
                        if v.len() as i64 == s1 { break; }
                        for j in 1..b {
                            if v.len() as i64 == s1 { break 'outer; }
                            v.push((i as i64, j as i64));
                        }
                    }
                    break;
                }
            }
        }
        if v.len() as i64 != s1 {
            out.push_str("-1\n");
            continue;
        }
        out.push_str(&format!("{}\n", v.len()));
        for (x, y) in v {
            out.push_str(&format!("{x} {y}\n"));
        }
    }
    print!("{out}");
}