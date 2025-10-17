use crate::algo_lib::collections::vec_ext::gen_vec::VecGen;
use crate::algo_lib::io::input::Input;
use crate::algo_lib::io::output::Output;
use crate::algo_lib::misc::test_type::{TaskType, TestType};
use std::collections::HashSet;
use std::collections::HashMap;
use std::collections::VecDeque;
use std::cmp::max;

const MOD: i64 = 1_000_000_007;

#[derive(Copy, Clone)]
struct ModInt {
    v: i64,
}
impl ModInt {
    fn new(a: i64) -> Self {
        let mut v = a % MOD;
        if v < 0 {
            v += MOD;
        }
        ModInt { v }
    }
    fn pow(self, mut e: i64) -> Self {
        let (mut b, mut r) = (self, ModInt::new(1));
        while e > 0 {
            if e & 1 == 1 {
                r = r * b;
            }
            b = b * b;
            e >>= 1;
        }
        r
    }
    fn inv(self) -> Self {
        self.pow(MOD - 2)
    }
}
impl std::ops::Add for ModInt {
    type Output = Self;
    fn add(self, o: Self) -> Self {
        ModInt::new(self.v + o.v)
    }
}
impl std::ops::Sub for ModInt {
    type Output = Self;
    fn sub(self, o: Self) -> Self {
        ModInt::new(self.v - o.v)
    }
}
impl std::ops::Mul for ModInt {
    type Output = Self;
    fn mul(self, o: Self) -> Self {
        ModInt::new(self.v * o.v)
    }
}
impl std::ops::Div for ModInt {
    type Output = Self;
    fn div(self, o: Self) -> Self {
        self * o.inv()
    }
}
impl std::ops::AddAssign for ModInt {
    fn add_assign(&mut self, o: Self) {
        *self = *self + o
    }
}
impl std::ops::SubAssign for ModInt {
    fn sub_assign(&mut self, o: Self) {
        *self = *self - o
    }
}
impl std::ops::MulAssign for ModInt {
    fn mul_assign(&mut self, o: Self) {
        *self = *self * o
    }
}
impl std::ops::DivAssign for ModInt {
    fn div_assign(&mut self, o: Self) {
        *self = *self / o
    }
}

fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a.abs()
}

fn exgcd(a: i64, b: i64, x: &mut i64, y: &mut i64) {
    if b == 0 {
        *x = 1;
        *y = 0;
        return;
    }
    let t = a / b;
    exgcd(b, a % b, y, x);
    *y -= t * *x;
}

/// # Type parameters
/// - `T`: Tipo
/// - `F`: `Fn(&T, &T) -> T`.
pub struct SegmentTree<T, F>
where
    F: Fn(&T, &T) -> T,
{
    n: usize,
    st: Vec<T>,
    f: F,
    neutral: T,
}

// // Sum i64
// let data = vec![1, 2, 3, 4];
// let mut st_sum = SegmentTree::new(data.clone(), 0_i64, |a, b| *a + *b);
// assert_eq!(st_sum.query(1, 3), 2 + 3);
// // Min 
// let data2 = vec![5, 3, 8, 1];
// let mut st_min = SegmentTree::new(data2.clone(), i32::MAX, |a, b| (*a).min(*b));
// assert_eq!(st_min.query(0, 4), 1);
impl<T: Clone, F: Fn(&T, &T) -> T> SegmentTree<T, F> {
    /// - `data`: n
    /// - `neutral`: `f(neutral, x) = f(x, neutral) = x`
    /// - `f`: fun asociativ
    pub fn new(data: Vec<T>, neutral: T, f: F) -> Self {
        let n = data.len();
        let mut st = vec![neutral.clone(); 2 * n];
        for i in 0..n {
            st[n + i] = data[i].clone();
        }
        for i in (1..n).rev() {
            let left = &st[2 * i];
            let right = &st[2 * i + 1];
            st[i] = f(left, right);
        }
    
        SegmentTree { n, st, f, neutral }
    }

    pub fn update(&mut self, idx: usize, v: T) {
        let mut i = idx + self.n;
        self.st[i] = v;
        while i > 1 {
            i >>= 1;
            let left = &self.st[2 * i];
            let right = &self.st[2 * i + 1];
            self.st[i] = (self.f)(left, right);
        }
    }

    /// [l, r)
    pub fn query(&self, mut l: usize, mut r: usize) -> T {
        let mut resl = self.neutral.clone();
        let mut resr = self.neutral.clone();
        let n = self.n;
        l += n;
        r += n;
        while l < r {
            if l & 1 == 1 {
                resl = (self.f)(&resl, &self.st[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                resr = (self.f)(&self.st[r], &resr);
            }
            l >>= 1;
            r >>= 1;
        }
        (self.f)(&resl, &resr)
    }
}

const B: usize = 32;
struct SegmentTreeLazy {
    n: usize,
    tree: Vec<[i32; B]>,
    lazy: Vec<i32>,
}

impl SegmentTreeLazy {
    pub fn new(a: &[i32]) -> SegmentTreeLazy {
        let n = a.len();
        let size = 4 * n;
        let mut st = SegmentTreeLazy {
            n,
            tree: vec![[0; B]; size],
            lazy: vec![0; size],
        };
        st.build(a, 1, 0, n);
        st
    }

    fn build(&mut self, a: &[i32], pos: usize, l: usize, r: usize) {
        if l + 1 == r {
            let v = a[l];
            for i in 0..B {
                self.tree[pos][i] = ((v >> i) & 1) as i32;
            }
            return;
        }
        let mid = (l + r) >> 1;
        self.build(a, pos * 2, l, mid);
        self.build(a, pos * 2 + 1, mid, r);
        for i in 0..B {
            self.tree[pos][i] = self.tree[pos * 2][i] + self.tree[pos * 2 + 1][i];
        }
    }

    fn apply(&mut self, pos: usize, l: usize, r: usize, val: i32) {
        let len = (r - l) as i32;
        for i in 0..B {
            if (val >> i) & 1 != 0 {
                self.tree[pos][i] = len - self.tree[pos][i];
            }
        }
        self.lazy[pos] ^= val;
    }

    fn push_down(&mut self, pos: usize, l: usize, r: usize) {
        let v = self.lazy[pos];
        if v != 0 {
            let mid = (l + r) >> 1;
            self.apply(pos * 2, l, mid, v);
            self.apply(pos * 2 + 1, mid, r, v);
            self.lazy[pos] = 0;
        }
    }

    fn update_node(&mut self, pos: usize, l: usize, r: usize, ql: usize, qr: usize, val: i32) {
        if ql <= l && r <= qr {
            self.apply(pos, l, r, val);
            return;
        }
        self.push_down(pos, l, r);
        let mid = (l + r) >> 1;
        if ql < mid {
            self.update_node(pos * 2, l, mid, ql, qr, val);
        }
        if qr > mid {
            self.update_node(pos * 2 + 1, mid, r, ql, qr, val);
        }
        for i in 0..B {
            self.tree[pos][i] = self.tree[pos * 2][i] + self.tree[pos * 2 + 1][i];
        }
    }

    fn query_node(&mut self, pos: usize, l: usize, r: usize, ql: usize, qr: usize) -> i64 {
        if ql <= l && r <= qr {
            let mut s = 0_i64;
            for i in 0..B {
                s += (self.tree[pos][i] as i64) << i;
            }
            return s;
        }
        self.push_down(pos, l, r);
        let mid = (l + r) >> 1;
        let mut s = 0_i64;
        if ql < mid {
            s += self.query_node(pos * 2, l, mid, ql, qr);
        }
        if qr > mid {
            s += self.query_node(pos * 2 + 1, mid, r, ql, qr);
        }
        s
    }

    pub fn update_range(&mut self, ql: usize, qr: usize, val: i32) {
        self.update_node(1, 0, self.n, ql, qr, val);
    }

    pub fn query_range(&mut self, ql: usize, qr: usize) -> i64 {
        self.query_node(1, 0, self.n, ql, qr)
    }
}

struct DSU {
    par: Vec<usize>,
    rank: Vec<usize>,
}

impl DSU {
    fn new(n: usize) -> DSU {
        let mut par = Vec::with_gen(n + 1, |i| i);
        let rank = Vec::with_gen(n + 1, |_| 1);
        DSU { par, rank }
    }
    fn find(&mut self, x: usize) -> usize {
        if self.par[x] != x {
            let p = self.par[x];
            self.par[x] = self.find(p);
        }
        self.par[x]
    }
    fn unite(&mut self, x: usize, y: usize) {
        let mut rx = self.find(x);
        let mut ry = self.find(y);
        if rx == ry {
            return;
        }
        if self.rank[rx] < self.rank[ry] {
            std::mem::swap(&mut rx, &mut ry);
        }
        self.rank[rx] += self.rank[ry];
        self.par[ry] = rx;
    }
    fn same(&mut self, x: usize, y: usize) -> bool {
        self.find(x) == self.find(y)
    }
}

use std::f64::consts::PI;
#[derive(Clone)]
struct C { re: f64, im: f64 }
impl C {
    fn new(r: f64, i: f64) -> C { C { re: r, im: i } }
    fn conj(&self) -> C { C { re: self.re, im: -self.im } }
}
impl std::ops::Add for C {
    type Output = C;
    fn add(self, o: C) -> C { C::new(self.re + o.re, self.im + o.im) }
}
impl std::ops::Sub for C {
    type Output = C;
    fn sub(self, o: C) -> C { C::new(self.re - o.re, self.im - o.im) }
}
impl std::ops::Mul for C {
    type Output = C;
    fn mul(self, o: C) -> C {
        C::new(self.re * o.re - self.im * o.im,
               self.re * o.im + self.im * o.re)
    }
}

fn fft(a: &mut [C], inv: bool) {
    let n = a.len();
    let mut j = 0;
    for i in 1..n {
        let mut bit = n >> 1;
        j ^= bit;
        while j & bit == 0 { bit >>= 1; j ^= bit; }
        if i < j { a.swap(i, j); }
    }
    let mut len = 2;
    while len <= n {
        let ang = 2.0 * PI / (len as f64) * if inv { -1.0 } else { 1.0 };
        let wlen = C::new(ang.cos(), ang.sin());
        for i in (0..n).step_by(len) {
            let mut w = C::new(1.0, 0.0);
            for j in 0..(len/2) {
                let u = a[i+j].clone();
                let v = a[i+j+len/2].clone() * w.clone();
                a[i+j] = u.clone() + v.clone();
                a[i+j+len/2] = u - v;
                w = w * wlen.clone();
            }
        }
        len <<= 1;
    }
    if inv {
        for x in a.iter_mut() {
            x.re /= n as f64;
            x.im /= n as f64;
        }
    }
}

fn conv(a: &[f64], b: &[f64]) -> Vec<f64> {
    let sz = a.len() + b.len() - 1;
    let n = sz.next_power_of_two();
    let mut fa = Vec::with_gen(n, |_| C::new(0.0, 0.0));
    let mut fb = fa.clone();
    for i in 0..a.len() { fa[i].re = a[i]; }
    for i in 0..b.len() { fb[i].re = b[i]; }
    fft(&mut fa, false);
    fft(&mut fb, false);
    for i in 0..n { fa[i] = fa[i].clone() * fb[i].clone(); }
    fft(&mut fa, true);
    let mut res = vec![0.0; sz];
    for i in 0..sz { res[i] = fa[i].re; }
    res
}

const INF_COST: i32 = 1_000_000;

struct Edge {
    to: usize,
    rev: usize,
    cap: i32,
    cost: i32,
}

struct MCMF {
    n: usize,
    graph: Vec<Vec<Edge>>,
    s: usize,
    t: usize,
    dis: Vec<i32>,
    inq: Vec<bool>,
    cur: Vec<usize>,
}

impl MCMF {
    fn new(n: usize, s: usize, t: usize) -> Self {
        MCMF {
            n,
            graph: Vec::with_gen(n, |_| Vec::new()),
            s,
            t,
            dis: vec![i32::MAX / 2; n],
            inq: vec![false; n],
            cur: vec![0; n],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize, cap: i32, cost: i32) {
        let ru = self.graph[u].len();
        let rv = self.graph[v].len();
        self.graph[u].push(Edge { to: v, rev: rv, cap, cost });
        self.graph[v].push(Edge { to: u, rev: ru, cap: 0, cost: -cost });
    }

    fn spfa(&mut self) -> bool {
        let inf = i32::MAX / 2;
        for i in 0..self.n {
            self.dis[i] = inf;
            self.inq[i] = false;
            self.cur[i] = 0;
        }
        let mut q = VecDeque::new();
        q.push_back(self.s);
        self.dis[self.s] = 0;
        self.inq[self.s] = true;
        while let Some(u) = q.pop_front() {
            self.inq[u] = false;
            for e in &self.graph[u] {
                if e.cap > 0 && self.dis[e.to] > self.dis[u] + e.cost {
                    self.dis[e.to] = self.dis[u] + e.cost;
                    if !self.inq[e.to] {
                        self.inq[e.to] = true;
                        q.push_back(e.to);
                    }
                }
            }
        }
        self.dis[self.t] < inf
    }

    fn dfs(&mut self, u: usize, flow: i32) -> i32 {
        if u == self.t {
            return flow;
        }
        self.inq[u] = true;
        let mut pushed_total = 0;
        let mut remaining = flow;
        while self.cur[u] < self.graph[u].len() {
            let i = self.cur[u];
            let (v, cap, cost, rev) = {
                let e = &self.graph[u][i];
                (e.to, e.cap, e.cost, e.rev)
            };
            if !self.inq[v] && cap > 0 && self.dis[v] == self.dis[u] + cost {
                let pushed = self.dfs(v, remaining.min(cap));
                if pushed > 0 {
                    self.graph[u][i].cap -= pushed;
                    self.graph[v][rev].cap += pushed;
                    remaining -= pushed;
                    pushed_total += pushed;
                    if remaining == 0 {
                        break;
                    }
                }
            }
            self.cur[u] += 1;
        }
        self.inq[u] = false;
        pushed_total
    }

    fn min_cost_flow(&mut self) -> (i64, i64) {
        let mut flow = 0_i64;
        let mut cost = 0_i64;
        while self.spfa() {
            if self.dis[self.t] >= 0 {
                break;
            }
            loop {
                let f = self.dfs(self.s, i32::MAX);
                if f == 0 {
                    break;
                }
                flow += f as i64;
                cost += f as i64 * self.dis[self.t] as i64;
            }
        }
        (flow, cost)
    }
}

pub static TEST_TYPE: TestType = TestType::MultiNumber;
pub static TASK_TYPE: TaskType = TaskType::Classic;

type PreCalc = ();

fn solve(input: &mut Input, out: &mut Output, _tc: usize, _data: &mut ()) {
    let n: usize = input.read();
    let m: usize = input.read();
    let k: usize = input.read();
    let mut odd = Vec::with_capacity(k + 1);
    for _ in 0..=k {
        let x: usize = input.read();
        let y: usize = input.read();
        odd.push((x - 1) * m + (y - 1));
    }
    let mut opt1 = vec![0; k];
    let mut opt2 = vec![0; k];
    let mut sc = vec![0u8; k];
    let mut bad = false;
    for i in 0..k {
        let a = odd[i];
        let c = odd[i + 1];
        let x1 = (a / m) as isize;
        let y1 = (a % m) as isize;
        let x2 = (c / m) as isize;
        let y2 = (c % m) as isize;
        let dx = (x1 - x2).abs() as usize;
        let dy = (y1 - y2).abs() as usize;
        if dx + dy != 2 {
            bad = true;
            break;
        }
        if dx == 2 {
            let xm = ((x1 + x2) / 2) as usize;
            opt1[i] = xm * m + (y1 as usize);
            sc[i] = 1;
        } else if dy == 2 {
            let ym = ((y1 + y2) / 2) as usize;
            opt1[i] = (x1 as usize) * m + ym;
            sc[i] = 1;
        } else {
            opt1[i] = (x1 as usize) * m + (y2 as usize);
            opt2[i] = (x2 as usize) * m + (y1 as usize);
            sc[i] = 2;
        }
    }
    if bad {
        out.print_line(0);
        return;
    }
    let N = n * m;
    let mut cell2seg = vec![Vec::new(); N];
    for i in 0..k {
        if sc[i] >= 1 {
            cell2seg[opt1[i]].push(i);
        }
        if sc[i] == 2 {
            cell2seg[opt2[i]].push(i);
        }
    }
    let mut used = vec![false; N];
    let mut proc = vec![false; k];
    let mut q = VecDeque::new();
    for i in 0..k {
        if sc[i] == 1 {
            q.push_back(i);
        }
    }
    let mut zero = false;
    while let Some(i) = q.pop_front() {
        if proc[i] || sc[i] != 1 {
            continue;
        }
        let u = opt1[i];
        if used[u] {
            zero = true;
            break;
        }
        used[u] = true;
        proc[i] = true;
        for &j in &cell2seg[u] {
            if proc[j] {
                continue;
            }
            if sc[j] == 2 {
                let v = if opt1[j] == u { opt2[j] } else { opt1[j] };
                opt1[j] = v;
                sc[j] = 1;
                q.push_back(j);
            }
        }
    }
    if zero {
        out.print_line(0);
        return;
    }
    let mut edges = Vec::new();
    let mut cells = Vec::new();
    let mut active = vec![false; N];
    for i in 0..k {
        if proc[i] {
            continue;
        }
        if sc[i] != 2 {
            zero = true;
            break;
        }
        let u = opt1[i];
        let v = opt2[i];
        if used[u] || used[v] {
            zero = true;
            break;
        }
        edges.push((u, v));
        if !active[u] {
            active[u] = true;
            cells.push(u);
        }
        if !active[v] {
            active[v] = true;
            cells.push(v);
        }
    }
    if zero {
        out.print_line(0);
        return;
    }
    cells.sort();
    let nc = cells.len();
    let mut mp = vec![-1isize; N];
    for (i, &c) in cells.iter().enumerate() {
        mp[c] = i as isize;
    }
    let mut adj = vec![Vec::new(); nc];
    for &(u, v) in &edges {
        let u2 = mp[u] as usize;
        let v2 = mp[v] as usize;
        adj[u2].push(v2);
        adj[v2].push(u2);
    }
    let mut vis = vec![false; nc];
    let mut ans = ModInt::new(1);
    for i in 0..nc {
        if vis[i] {
            continue;
        }
        let mut vc = 0i64;
        let mut de2 = 0i64;
        let mut dq = VecDeque::new();
        dq.push_back(i);
        vis[i] = true;
        while let Some(u) = dq.pop_front() {
            vc += 1;
            de2 += adj[u].len() as i64;
            for &w in &adj[u] {
                if !vis[w] {
                    vis[w] = true;
                    dq.push_back(w);
                }
            }
        }
        let ec = de2 / 2;
        if ec == vc - 1 {
            ans *= ModInt::new(vc);
        } else if ec == vc {
            ans *= ModInt::new(2);
        } else {
            ans = ModInt::new(0);
            break;
        }
    }
    out.print_line(ans.v);
}

pub(crate) fn run(mut input: Input, mut output: Output) -> bool {
    let mut pre_calc = ();
    match TEST_TYPE {
        TestType::Single => solve(&mut input, &mut output, 1, &mut pre_calc),
        TestType::MultiNumber => {
            let t = input.read();
            for i in 1..=t {
                solve(&mut input, &mut output, i, &mut pre_calc);
            }
        }
        TestType::MultiEof => {
            let mut i = 1;
            while input.peek().is_some() {
                solve(&mut input, &mut output, i, &mut pre_calc);
                i += 1;
            }
        }
    }
    output.flush();
    match TASK_TYPE {
        TaskType::Classic => input.is_empty(),
        TaskType::Interactive => true,
    }
}

fn main() {
    let input = crate::algo_lib::io::input::Input::stdin();
    let output = crate::algo_lib::io::output::Output::stdout();
    run(input, output);
}
pub mod algo_lib {
pub mod collections {
pub mod vec_ext {
pub mod default {
pub fn default_vec<T: Default>(len: usize) -> Vec<T> {
    let mut v = Vec::with_capacity(len);
    for _ in 0..len {
        v.push(T::default());
    }
    v
}
}
pub mod gen_vec {
use crate::algo_lib::collections::vec_ext::default::default_vec;
pub trait VecGen<T> {
    fn with_gen(n: usize, f: impl FnMut(usize) -> T) -> Vec<T>;
    fn with_gen_prefix(n: usize, f: impl FnMut(usize, &Self) -> T) -> Vec<T>;
    fn gen_append(&mut self, n: usize, f: impl FnMut(usize, &Self) -> T);
    fn with_gen_back(n: usize, f: impl FnMut(usize, &Self) -> T) -> Vec<T>
    where
        T: Default;
}
impl<T> VecGen<T> for Vec<T> {
    fn with_gen(n: usize, mut f: impl FnMut(usize) -> T) -> Vec<T> {
        Self::with_gen_prefix(n, |i, _| f(i))
    }
    fn with_gen_prefix(n: usize, f: impl FnMut(usize, &Self) -> T) -> Vec<T> {
        let mut vec = Vec::with_capacity(n);
        vec.gen_append(n, f);
        vec
    }
    fn gen_append(&mut self, n: usize, mut f: impl FnMut(usize, &Self) -> T) {
        self.reserve(n);
        let len = self.len();
        for i in 0..n {
            self.push(f(len + i, self));
        }
    }
    fn with_gen_back(n: usize, mut f: impl FnMut(usize, &Self) -> T) -> Vec<T>
    where
        T: Default,
    {
        let mut vec = default_vec(n);
        for i in (0..n).rev() {
            vec[i] = f(i, &vec);
        }
        vec
    }
}
}
}
}
pub mod io {
pub mod input {
use std::fs::File;
use std::io::{Read, Stdin};
use std::mem::MaybeUninit;
enum InputSource {
    Stdin(Stdin),
    File(File),
    Slice,
    Delegate(Box<dyn Read + Send>),
}
pub struct Input {
    input: InputSource,
    buf: Vec<u8>,
    at: usize,
    buf_read: usize,
    eol: bool,
}
macro_rules! read_impl {
    ($t:ty, $read_name:ident, $read_vec_name:ident) => {
        pub fn $read_name (& mut self) -> $t { self.read() } pub fn $read_vec_name (& mut
        self, len : usize) -> Vec <$t > { self.read_vec(len) }
    };
    ($t:ty, $read_name:ident, $read_vec_name:ident, $read_pair_vec_name:ident) => {
        read_impl!($t, $read_name, $read_vec_name); pub fn $read_pair_vec_name (& mut
        self, len : usize) -> Vec < ($t, $t) > { self.read_vec(len) }
    };
}
impl Input {
    const DEFAULT_BUF_SIZE: usize = 4096;
    pub fn slice(input: &[u8]) -> Self {
        Self {
            input: InputSource::Slice,
            buf: input.to_vec(),
            at: 0,
            buf_read: input.len(),
            eol: true,
        }
    }
    pub fn stdin() -> Self {
        Self {
            input: InputSource::Stdin(std::io::stdin()),
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            buf_read: 0,
            eol: true,
        }
    }
    pub fn file(file: File) -> Self {
        Self {
            input: InputSource::File(file),
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            buf_read: 0,
            eol: true,
        }
    }
    pub fn delegate(reader: impl Read + Send + 'static) -> Self {
        Self {
            input: InputSource::Delegate(Box::new(reader)),
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            buf_read: 0,
            eol: true,
        }
    }
    pub fn get(&mut self) -> Option<u8> {
        if self.refill_buffer() {
            let res = self.buf[self.at];
            self.at += 1;
            if res == b'\r' {
                self.eol = true;
                if self.refill_buffer() && self.buf[self.at] == b'\n' {
                    self.at += 1;
                }
                return Some(b'\n');
            }
            self.eol = res == b'\n';
            Some(res)
        } else {
            None
        }
    }
    pub fn peek(&mut self) -> Option<u8> {
        if self.refill_buffer() {
            let res = self.buf[self.at];
            Some(if res == b'\r' { b'\n' } else { res })
        } else {
            None
        }
    }
    pub fn skip_whitespace(&mut self) {
        while let Some(b) = self.peek() {
            if !b.is_ascii_whitespace() {
                return;
            }
            self.get();
        }
    }
    pub fn next_token(&mut self) -> Option<Vec<u8>> {
        self.skip_whitespace();
        let mut res = Vec::new();
        while let Some(c) = self.get() {
            if c.is_ascii_whitespace() {
                break;
            }
            res.push(c);
        }
        if res.is_empty() { None } else { Some(res) }
    }
    pub fn is_exhausted(&mut self) -> bool {
        self.peek().is_none()
    }
    pub fn is_empty(&mut self) -> bool {
        self.skip_whitespace();
        self.is_exhausted()
    }
    pub fn read<T: Readable>(&mut self) -> T {
        T::read(self)
    }
    pub fn read_vec<T: Readable>(&mut self, size: usize) -> Vec<T> {
        let mut res = Vec::with_capacity(size);
        for _ in 0..size {
            res.push(self.read());
        }
        res
    }
    pub fn read_char(&mut self) -> u8 {
        self.skip_whitespace();
        self.get().unwrap()
    }
    read_impl!(u32, read_unsigned, read_unsigned_vec);
    read_impl!(u64, read_u64, read_u64_vec);
    read_impl!(usize, read_size, read_size_vec, read_size_pair_vec);
    read_impl!(i32, read_int, read_int_vec, read_int_pair_vec);
    read_impl!(i64, read_long, read_long_vec, read_long_pair_vec);
    read_impl!(i128, read_i128, read_i128_vec);
    fn refill_buffer(&mut self) -> bool {
        if self.at == self.buf_read {
            self.at = 0;
            self.buf_read = match &mut self.input {
                InputSource::Stdin(stdin) => stdin.read(&mut self.buf).unwrap(),
                InputSource::File(file) => file.read(&mut self.buf).unwrap(),
                InputSource::Delegate(reader) => reader.read(&mut self.buf).unwrap(),
                InputSource::Slice => 0,
            };
            self.buf_read != 0
        } else {
            true
        }
    }
    pub fn is_eol(&self) -> bool {
        self.eol
    }
}
pub trait Readable {
    fn read(input: &mut Input) -> Self;
}
impl Readable for u8 {
    fn read(input: &mut Input) -> Self {
        input.read_char()
    }
}
impl<T: Readable> Readable for Vec<T> {
    fn read(input: &mut Input) -> Self {
        let size = input.read();
        input.read_vec(size)
    }
}
impl<T: Readable, const SIZE: usize> Readable for [T; SIZE] {
    fn read(input: &mut Input) -> Self {
        unsafe {
            let mut res = MaybeUninit::<[T; SIZE]>::uninit();
            for i in 0..SIZE {
                let ptr: *mut T = (*res.as_mut_ptr()).as_mut_ptr();
                ptr.add(i).write(input.read::<T>());
            }
            res.assume_init()
        }
    }
}
macro_rules! read_integer {
    ($($t:ident)+) => {
        $(impl Readable for $t { fn read(input : & mut Input) -> Self { input
        .skip_whitespace(); let mut c = input.get().unwrap(); let sgn = match c { b'-' =>
        { c = input.get().unwrap(); true } b'+' => { c = input.get().unwrap(); false } _
        => false, }; let mut res = 0; loop { assert!(c.is_ascii_digit()); res *= 10; let
        d = (c - b'0') as $t; if sgn { res -= d; } else { res += d; } match input.get() {
        None => break, Some(ch) => { if ch.is_ascii_whitespace() { break; } else { c =
        ch; } } } } res } })+
    };
}
read_integer!(i8 i16 i32 i64 i128 isize u16 u32 u64 u128 usize);
macro_rules! tuple_readable {
    ($($name:ident)+) => {
        impl <$($name : Readable),+> Readable for ($($name,)+) { fn read(input : & mut
        Input) -> Self { ($($name ::read(input),)+) } }
    };
}
tuple_readable! {
    T
}
tuple_readable! {
    T U
}
tuple_readable! {
    T U V
}
tuple_readable! {
    T U V X
}
tuple_readable! {
    T U V X Y
}
tuple_readable! {
    T U V X Y Z
}
tuple_readable! {
    T U V X Y Z A
}
tuple_readable! {
    T U V X Y Z A B
}
tuple_readable! {
    T U V X Y Z A B C
}
tuple_readable! {
    T U V X Y Z A B C D
}
tuple_readable! {
    T U V X Y Z A B C D E
}
tuple_readable! {
    T U V X Y Z A B C D E F
}
}
pub mod output {
use std::cmp::Reverse;
use std::fs::File;
use std::io::{Stdout, Write};
#[derive(Copy, Clone)]
pub enum BoolOutput {
    YesNo,
    YesNoCaps,
    PossibleImpossible,
    Custom(&'static str, &'static str),
}
impl BoolOutput {
    pub fn output(&self, output: &mut Output, val: bool) {
        (if val { self.yes() } else { self.no() }).write(output);
    }
    fn yes(&self) -> &str {
        match self {
            BoolOutput::YesNo => "Yes",
            BoolOutput::YesNoCaps => "YES",
            BoolOutput::PossibleImpossible => "Possible",
            BoolOutput::Custom(yes, _) => yes,
        }
    }
    fn no(&self) -> &str {
        match self {
            BoolOutput::YesNo => "No",
            BoolOutput::YesNoCaps => "NO",
            BoolOutput::PossibleImpossible => "Impossible",
            BoolOutput::Custom(_, no) => no,
        }
    }
}
enum OutputDest<'s> {
    Stdout(Stdout),
    File(File),
    Buf(&'s mut Vec<u8>),
    Delegate(Box<dyn Write + 's>),
}
pub struct Output<'s> {
    output: OutputDest<'s>,
    buf: Vec<u8>,
    at: usize,
    bool_output: BoolOutput,
    precision: Option<usize>,
    separator: u8,
}
impl<'s> Output<'s> {
    pub fn buf(buf: &'s mut Vec<u8>) -> Self {
        Self::new(OutputDest::Buf(buf))
    }
    pub fn delegate(delegate: impl Write + 'static) -> Self {
        Self::new(OutputDest::Delegate(Box::new(delegate)))
    }
    fn new(output: OutputDest<'s>) -> Self {
        Self {
            output,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            bool_output: BoolOutput::YesNoCaps,
            precision: None,
            separator: b' ',
        }
    }
}
impl Output<'static> {
    pub fn stdout() -> Self {
        Self::new(OutputDest::Stdout(std::io::stdout()))
    }
    pub fn file(file: File) -> Self {
        Self::new(OutputDest::File(file))
    }
}
impl Output<'_> {
    const DEFAULT_BUF_SIZE: usize = 4096;
    pub fn flush(&mut self) {
        if self.at != 0 {
            match &mut self.output {
                OutputDest::Stdout(stdout) => {
                    stdout.write_all(&self.buf[..self.at]).unwrap();
                    stdout.flush().unwrap();
                }
                OutputDest::File(file) => {
                    file.write_all(&self.buf[..self.at]).unwrap();
                    file.flush().unwrap();
                }
                OutputDest::Buf(buf) => buf.extend_from_slice(&self.buf[..self.at]),
                OutputDest::Delegate(delegate) => {
                    delegate.write_all(&self.buf[..self.at]).unwrap();
                    delegate.flush().unwrap();
                }
            }
            self.at = 0;
        }
    }
    pub fn print<T: Writable>(&mut self, s: T) {
        s.write(self);
    }
    pub fn print_line<T: Writable>(&mut self, s: T) {
        self.print(s);
        self.put(b'\n');
    }
    pub fn put(&mut self, b: u8) {
        self.buf[self.at] = b;
        self.at += 1;
        if self.at == self.buf.len() {
            self.flush();
        }
    }
    pub fn print_per_line<T: Writable>(&mut self, arg: &[T]) {
        self.print_per_line_iter(arg.iter());
    }
    pub fn print_iter<T: Writable, I: Iterator<Item = T>>(&mut self, iter: I) {
        let mut first = true;
        for e in iter {
            if first {
                first = false;
            } else {
                self.put(self.separator);
            }
            e.write(self);
        }
    }
    pub fn print_line_iter<T: Writable, I: Iterator<Item = T>>(&mut self, iter: I) {
        self.print_iter(iter);
        self.put(b'\n');
    }
    pub fn print_per_line_iter<T: Writable, I: Iterator<Item = T>>(&mut self, iter: I) {
        for e in iter {
            e.write(self);
            self.put(b'\n');
        }
    }
    pub fn set_bool_output(&mut self, bool_output: BoolOutput) {
        self.bool_output = bool_output;
    }
    pub fn set_precision(&mut self, precision: usize) {
        self.precision = Some(precision);
    }
    pub fn reset_precision(&mut self) {
        self.precision = None;
    }
    pub fn get_precision(&self) -> Option<usize> {
        self.precision
    }
    pub fn separator(&self) -> u8 {
        self.separator
    }
    pub fn set_separator(&mut self, separator: u8) {
        self.separator = separator;
    }
}
impl Write for Output<'_> {
    fn write(&mut self, buf: &[u8]) -> std::io::Result<usize> {
        let mut start = 0usize;
        let mut rem = buf.len();
        while rem > 0 {
            let len = (self.buf.len() - self.at).min(rem);
            self.buf[self.at..self.at + len].copy_from_slice(&buf[start..start + len]);
            self.at += len;
            if self.at == self.buf.len() {
                self.flush();
            }
            start += len;
            rem -= len;
        }
        Ok(buf.len())
    }
    fn flush(&mut self) -> std::io::Result<()> {
        self.flush();
        Ok(())
    }
}
pub trait Writable {
    fn write(&self, output: &mut Output);
}
impl Writable for &str {
    fn write(&self, output: &mut Output) {
        output.write_all(self.as_bytes()).unwrap();
    }
}
impl Writable for String {
    fn write(&self, output: &mut Output) {
        output.write_all(self.as_bytes()).unwrap();
    }
}
impl Writable for char {
    fn write(&self, output: &mut Output) {
        output.put(*self as u8);
    }
}
impl Writable for u8 {
    fn write(&self, output: &mut Output) {
        output.put(*self);
    }
}
impl<T: Writable> Writable for [T] {
    fn write(&self, output: &mut Output) {
        output.print_iter(self.iter());
    }
}
impl<T: Writable, const N: usize> Writable for [T; N] {
    fn write(&self, output: &mut Output) {
        output.print_iter(self.iter());
    }
}
impl<T: Writable + ?Sized> Writable for &T {
    fn write(&self, output: &mut Output) {
        T::write(self, output)
    }
}
impl<T: Writable> Writable for Vec<T> {
    fn write(&self, output: &mut Output) {
        self.as_slice().write(output);
    }
}
impl Writable for () {
    fn write(&self, _output: &mut Output) {}
}
macro_rules! write_to_string {
    ($($t:ident)+) => {
        $(impl Writable for $t { fn write(& self, output : & mut Output) { self
        .to_string().write(output); } })+
    };
}
write_to_string!(u16 u32 u64 u128 usize i8 i16 i32 i64 i128 isize);
macro_rules! tuple_writable {
    ($name0:ident $($name:ident : $id:tt)*) => {
        impl <$name0 : Writable, $($name : Writable,)*> Writable for ($name0, $($name,)*)
        { fn write(& self, out : & mut Output) { self.0.write(out); $(out.put(out
        .separator); self.$id .write(out);)* } }
    };
}
tuple_writable! {
    T
}
tuple_writable! {
    T U : 1
}
tuple_writable! {
    T U : 1 V : 2
}
tuple_writable! {
    T U : 1 V : 2 X : 3
}
tuple_writable! {
    T U : 1 V : 2 X : 3 Y : 4
}
tuple_writable! {
    T U : 1 V : 2 X : 3 Y : 4 Z : 5
}
tuple_writable! {
    T U : 1 V : 2 X : 3 Y : 4 Z : 5 A : 6
}
tuple_writable! {
    T U : 1 V : 2 X : 3 Y : 4 Z : 5 A : 6 B : 7
}
tuple_writable! {
    T U : 1 V : 2 X : 3 Y : 4 Z : 5 A : 6 B : 7 C : 8
}
impl<T: Writable> Writable for Option<T> {
    fn write(&self, output: &mut Output) {
        match self {
            None => (-1).write(output),
            Some(t) => t.write(output),
        }
    }
}
impl Writable for bool {
    fn write(&self, output: &mut Output) {
        let bool_output = output.bool_output;
        bool_output.output(output, *self)
    }
}
impl<T: Writable> Writable for Reverse<T> {
    fn write(&self, output: &mut Output) {
        self.0.write(output);
    }
}
}
}
pub mod misc {
pub mod test_type {
pub enum TestType {
    Single,
    MultiNumber,
    MultiEof,
}
pub enum TaskType {
    Classic,
    Interactive,
}
}
use std::marker::PhantomData;

macro_rules! recursive_function {
    ($name: ident, $trait: ident, ($($type: ident $arg: ident,)*)) => {
        pub trait $trait<$($type, )*Output> {
            fn call(&mut self, $($arg: $type,)*) -> Output;
        }

        pub struct $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            f: std::cell::UnsafeCell<F>,
            $($arg: PhantomData<$type>,
            )*
            phantom_output: PhantomData<Output>,
        }

        impl<F, $($type, )*Output> $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            pub fn new(f: F) -> Self {
                Self {
                    f: std::cell::UnsafeCell::new(f),
                    $($arg: Default::default(),
                    )*
                    phantom_output: Default::default(),
                }
            }
        }

        impl<F, $($type, )*Output> $trait<$($type, )*Output> for $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            fn call(&mut self, $($arg: $type,)*) -> Output {
                unsafe { (*self.f.get())(self, $($arg, )*) }
            }
        }
    }
}

recursive_function!(RecursiveFunction0, Callable0, ());
recursive_function!(RecursiveFunction, Callable, (Arg arg,));
recursive_function!(RecursiveFunction2, Callable2, (Arg1 arg1, Arg2 arg2,));
recursive_function!(RecursiveFunction3, Callable3, (Arg1 arg1, Arg2 arg2, Arg3 arg3,));
recursive_function!(RecursiveFunction4, Callable4, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4,));
recursive_function!(RecursiveFunction5, Callable5, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5,));
recursive_function!(RecursiveFunction6, Callable6, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6,));
recursive_function!(RecursiveFunction7, Callable7, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7,));
recursive_function!(RecursiveFunction8, Callable8, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7, Arg8 arg8,));
recursive_function!(RecursiveFunction9, Callable9, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7, Arg8 arg8, Arg9 arg9,));
}
}