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

const MOD: i64 = 998_244_353;

#[derive(Clone, Copy, Debug, Default)]
struct Mint(i64);
impl Mint {
    fn new(x: i64) -> Self {
        let mut v = x % MOD;
        if v < 0 { v += MOD; }
        Mint(v)
    }
    fn val(self) -> i32 { self.0 as i32 }
    fn pow(self, mut e: i64) -> Self {
        let mut base = self;
        let mut r = Mint::new(1);
        while e > 0 {
            if (e & 1) != 0 { r *= base; }
            base *= base;
            e >>= 1;
        }
        r
    }
}
use std::ops::{Add, AddAssign, Sub, SubAssign, Mul, MulAssign, Div, DivAssign};

impl Add for Mint { type Output = Mint; fn add(self, rhs: Mint) -> Mint { Mint::new(self.0 + rhs.0) } }
impl AddAssign for Mint { fn add_assign(&mut self, rhs: Mint) { *self = *self + rhs; } }
impl Sub for Mint { type Output = Mint; fn sub(self, rhs: Mint) -> Mint { Mint::new(self.0 - rhs.0) } }
impl SubAssign for Mint { fn sub_assign(&mut self, rhs: Mint) { *self = *self - rhs; } }
impl Mul for Mint { type Output = Mint; fn mul(self, rhs: Mint) -> Mint { Mint::new((self.0 * rhs.0) % MOD) } }
impl MulAssign for Mint { fn mul_assign(&mut self, rhs: Mint) { *self = *self * rhs; } }
impl Div for Mint { type Output = Mint; fn div(self, rhs: Mint) -> Mint { self * rhs.pow(MOD - 2) } }
impl DivAssign for Mint { fn div_assign(&mut self, rhs: Mint) { *self = *self / rhs; } }

fn main() {
    let mut sc = Scanner::new();
    let t = sc.next_usize();
    let mut out = String::new();

    for _ in 0..t {
        let mut n = sc.next_i64();
        let mut m = sc.next_i64();
        let mut a = sc.next_i64();
        let mut b = sc.next_i64();

        let mut ans = Mint::new(0);
        ans += Mint::new(a + 1) * Mint::new(b + 1);

        for _ in 0..2 {
            std::mem::swap(&mut a, &mut b);
            std::mem::swap(&mut n, &mut m);
            let term = Mint::new(a + 1)
                * (Mint::new(2).pow(m - 1) - Mint::new(1))
                * Mint::new(b + 1)
                * Mint::new(b);
            ans += term;
        }

        const D: usize = 30;
        let f = |mut aa: i64| -> Vec<[Mint; 2]> {
            let mut res = vec![[Mint::new(0), Mint::new(0)]; D];
            aa += 1;
            for i in (0..D).rev() {
                res[i][0] = Mint::new(0);
                res[i][1] = Mint::new(0);
                if (aa & (1i64 << i)) != 0 {
                    if i > 0 {
                        res[i][0] = Mint::new(1i64 << (i - 1));
                    }
                    res[i][1] = Mint::new(aa - (1i64 << i));
                    aa -= 1i64 << i;
                }
            }
            res
        };

        let x = f(a);
        let y = f(b);

        let mut tmp = Mint::new(0);
        let mut s1 = Mint::new(0);
        let mut s2 = Mint::new(0);
        for i in (0..D).rev() {
            tmp += (s1 + x[i][1]) * (s2 + y[i][1]) * Mint::new(1i64 << i);
            s1 += x[i][0];
            s2 += y[i][0];
        }

        tmp *= (Mint::new(2).pow(m) - Mint::new(2)) * (Mint::new(2).pow(n) - Mint::new(2));
        ans += tmp;

        out.push_str(&format!("{}\n", ans.val()));
    }

    print!("{out}");
}
