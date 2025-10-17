use std::io::{self, Write};
use std::str::FromStr;

struct Reader {
    buf: Vec<String>,
}
impl Reader {
    fn new() -> Self { Self { buf: Vec::new() } }
    fn next<T: FromStr>(&mut self) -> T {
        loop {
            if let Some(tok) = self.buf.pop() {
                return tok.parse().ok().unwrap();
            }
            let mut s = String::new();
            io::stdin().read_line(&mut s).unwrap();
            self.buf = s.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn query(v: &Vec<usize>, rd: &mut Reader) -> i64 {
    print!("? {}", v.len());
    for &j in v { print!(" {}", j + 1); }
    println!();
    io::stdout().flush().unwrap();
    rd.next::<i64>()
}

fn main() {
    let mut rd = Reader::new();
    let t: usize = rd.next();
    for _ in 0..t {
        let n: usize = rd.next();
        let mut v: Vec<usize> = Vec::new();
        let mut r: Vec<usize> = Vec::new();
        let mut ans: Vec<i64> = vec![0; n * 2];
        for i in 0..n * 2 {
            v.push(i);
            let q = query(&v, &mut rd);
            if q != 0 {
                ans[i] = q;
                v.pop();
                r.push(i);
            }
        }
        for &i in &v {
            r.push(i);
            ans[i] = query(&r, &mut rd);
            r.pop();
        }
        print!("!");
        for x in ans { print!(" {}", x); }
        println!();
        io::stdout().flush().unwrap();
    }
}