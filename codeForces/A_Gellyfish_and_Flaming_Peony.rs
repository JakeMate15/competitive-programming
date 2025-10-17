use std::io::{self, Read};

fn gcd(mut a: usize, mut b: usize) -> usize {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut a = Vec::with_capacity(n);
        let mut cnt = vec![0usize; 5001];
        let mut g = 0;
        for _ in 0..n {
            let v: usize = it.next().unwrap().parse().unwrap();
            cnt[v] += 1;
            g = gcd(g, v);
            a.push(v);
        }
        let mut dist = vec![1_000_000_000usize; 5001];
        dist[g] = 0;
        let mut mindist = 1_000_000_000usize;
        let mut i = g;
        while i <= 5000 {
            for &v in &a {
                let d = dist[gcd(i, v)] + 1;
                if d < dist[i] {
                    dist[i] = d;
                }
            }
            if cnt[i] > 0 {
                if dist[i] < mindist {
                    mindist = dist[i];
                }
            }
            i += g;
        }
        let ans = (n - cnt[g]) + (if mindist > 0 { mindist - 1 } else { 0 });
        output.push_str(&format!("{}\n", ans));
    }

    print!("{}", output);
}