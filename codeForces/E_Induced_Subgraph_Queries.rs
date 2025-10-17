use std::cmp::{min};
use std::io::{self, Read};

struct Scanner {
    buf: Vec<u8>,
    idx: usize,
}
impl Scanner {
    fn new() -> Self {
        let mut input = String::new();
        io::stdin().read_to_string(&mut input).unwrap();
        Self { buf: input.into_bytes(), idx: 0 }
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

const BLK_SHIFT: usize = 9;
const BLK_SIZE: usize = 1 << BLK_SHIFT;
const MAX_VAL: usize = 1 << 19;
const NB: usize = (MAX_VAL >> BLK_SHIFT) + 2;
const MAXN: usize = 500_005;

struct Orj {
    a: Vec<i64>,
    b: Vec<i64>,
    val: Vec<usize>,
}
impl Orj {
    fn new() -> Self {
        Self {
            a: vec![0; MAX_VAL + 2],
            b: vec![0; NB],
            val: vec![0; MAXN],
        }
    }
    fn ensure_n(&mut self, n: usize) {
        if self.val.len() <= n + 2 {
            self.val.resize(n + 5, 0);
        }
    }
    fn add(&mut self, x: usize, y: i64) {
        self.a[x] += y;
        self.b[x >> BLK_SHIFT] += y;
    }
    fn clear(&mut self, n: usize) {
        for i in 1..=n {
            let v = self.val[i];
            self.add(v, -1);
            self.val[i] = 0;
        }
    }
    fn add_edge(&mut self, x: usize, y: usize) {
        if x == y {
            return;
        }
        let vx = self.val[x];
        let vy = self.val[y];
        self.add(vx, -1);
        self.add(vy, -1);
        self.val[x] ^= y;
        self.val[y] ^= x;
        self.add(self.val[x], 1);
        self.add(self.val[y], 1);
    }
    fn kth(&self, k: usize) -> usize {
        let mut kk = k + 1;
        for i in (0..self.b.len()).rev() {
            if self.b[i] >= kk as i64 {
                let start = min((i << BLK_SHIFT) + (BLK_SIZE - 1), self.a.len() - 1);
                let base = i << BLK_SHIFT;
                for j in (base..=start).rev() {
                    if self.a[j] >= kk as i64 {
                        return j;
                    } else {
                        kk -= self.a[j] as usize;
                    }
                }
                return 0;
            } else {
                kk -= self.b[i] as usize;
            }
        }
        0
    }
}

#[derive(Clone)]
struct Query {
    l: usize,
    r: usize,
    k: usize,
    id: usize,
    pos: usize,
}

fn main() {
    let mut sc = Scanner::new();
    let t = sc.next_usize();
    let mut x = Orj::new();
    let mut y = Orj::new();
    x.add(0, 1_000_000_000);
    y.add(0, 1_000_000_000);
    let mut out = String::new();

    for _ in 0..t {
        let n = sc.next_usize();
        let m = sc.next_usize();

        x.ensure_n(n);
        y.ensure_n(n);

        let mut e1: Vec<Vec<usize>> = vec![vec![]; n + 2];
        let mut e2: Vec<Vec<usize>> = vec![vec![]; n + 2];

        for _ in 0..m {
            let mut u = sc.next_usize();
            let mut v = sc.next_usize();
            if u > v {
                std::mem::swap(&mut u, &mut v);
            }
            e1[u].push(v);
            e2[v].push(u);
        }
        for i in 1..=n {
            e1[i].sort_unstable();
            e2[i].sort_unstable();
            e2[i].reverse();
        }

        let qn = sc.next_usize();
        let bl = ((n + m) as f64 / ((qn + 1) as f64).sqrt()) as usize + 1;

        let mut bel = vec![0usize; n + 2];
        let mut lst = vec![0usize; n + 2];
        let mut c = 1usize;
        let mut cur = 0usize;
        for i in 1..=n {
            bel[i] = c;
            lst[c] = i;
            cur += e1[i].len() + 1;
            if cur > bl {
                cur = 0;
                c += 1;
            }
        }

        let mut qs: Vec<Query> = Vec::with_capacity(qn);
        for id in 1..=qn {
            let l = sc.next_usize();
            let r = sc.next_usize();
            let k = sc.next_usize();
            qs.push(Query { l, r, k, id, pos: bel[l] });
        }
        qs.sort_by(|a, b| {
            if a.pos == b.pos {
                a.r.cmp(&b.r)
            } else {
                a.pos.cmp(&b.pos)
            }
        });

        let mut ans = vec![0usize; qn + 1];
        let mut prev_pos = usize::MAX;
        let mut r_now = 0usize;

        for qu in qs.iter() {
            if qu.pos != prev_pos {
                x.clear(n);
                r_now = lst[qu.pos];
                prev_pos = qu.pos;
            }
            if qu.r < lst[qu.pos] {
                for l in qu.l..=qu.r {
                    for &j in e1[l].iter() {
                        if j <= qu.r {
                            y.add_edge(l, j);
                        } else {
                            break;
                        }
                    }
                }
                let len = qu.r - qu.l + 1;
                ans[qu.id] = y.kth(len - qu.k);
                for l in qu.l..=qu.r {
                    for &j in e1[l].iter() {
                        if j <= qu.r {
                            y.add_edge(l, j);
                        } else {
                            break;
                        }
                    }
                }
            } else {
                while r_now < qu.r {
                    r_now += 1;
                    for &j in e2[r_now].iter() {
                        if j >= lst[qu.pos] {
                            x.add_edge(j, r_now);
                        } else {
                            break;
                        }
                    }
                }
                let mut lcur = lst[qu.pos] - 1;
                while lcur >= qu.l {
                    for &j in e1[lcur].iter() {
                        if j <= qu.r {
                            x.add_edge(lcur, j);
                        } else {
                            break;
                        }
                    }
                    if lcur == qu.l { break; }
                    lcur -= 1;
                }
                let len = qu.r - qu.l + 1;
                ans[qu.id] = x.kth(len - qu.k);
                let mut lcur2 = lst[qu.pos] - 1;
                while lcur2 >= qu.l {
                    for &j in e1[lcur2].iter() {
                        if j <= qu.r {
                            x.add_edge(lcur2, j);
                        } else {
                            break;
                        }
                    }
                    if lcur2 == qu.l { break; }
                    lcur2 -= 1;
                }
            }
        }
        x.clear(n);
        for i in 1..=qn {
            out.push_str(&format!("{}\n", ans[i]));
        }
    }
    print!("{out}");
}