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

    fn skip_ws(&mut self) {
        let n = self.buf.len();
        while self.idx < n && self.buf[self.idx].is_ascii_whitespace() {
            self.idx += 1;
        }
    }

    fn next_i64(&mut self) -> i64 {
        self.skip_ws();
        let n = self.buf.len();
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

    fn next_string(&mut self) -> String {
        self.skip_ws();
        let n = self.buf.len();
        let start = self.idx;
        while self.idx < n && !self.buf[self.idx].is_ascii_whitespace() {
            self.idx += 1;
        }
        String::from_utf8(self.buf[start..self.idx].to_vec()).unwrap()
    }
}

fn main() {
    let mut sc = Scanner::new();
    let t = sc.next_usize();
    let mut out = String::new();

    for _ in 0..t {
        let n = sc.next_usize();
        let s = sc.next_string();
        let bytes = s.as_bytes();
        let mut v: Vec<u8> = Vec::with_capacity(n);

        for i in 0..n {
            if let Some(&last) = v.last() {
                if last == bytes[i] {
                    v.pop();
                } else {
                    v.push(bytes[i]);
                }
            } else {
                v.push(bytes[i]);
            }
        }

        let m = v.len();
        if m % 2 == 1 {
            out.push_str("-1\n");
            continue;
        }

        if m == n && !v.is_empty() && v[0] == b')' {
            out.push_str("-1\n");
            continue;
        }

        let k = (n - m) / 2;
        if k % 2 == 1 {
            out.push_str("-1\n");
            continue;
        }

        for _ in 0..k {
            out.push('(');
        }
        for &c in &v {
            out.push(c as char);
        }
        for _ in 0..k {
            out.push(')');
        }
        out.push('\n');
    }

    print!("{out}");
}