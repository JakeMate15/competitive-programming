use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let q: usize = it.next().unwrap().parse().unwrap();
        let mut c: Vec<i32> = Vec::with_capacity(n);
        for _ in 0..n {
            c.push(it.next().unwrap().parse().unwrap());
        }
        let mut mi = c.clone();
        let c0 = c.clone();
        let mut query: Vec<(usize, usize, usize)> = Vec::with_capacity(q);
        for _ in 0..q {
            let x = it.next().unwrap().parse::<usize>().unwrap() - 1;
            let y = it.next().unwrap().parse::<usize>().unwrap() - 1;
            let z = it.next().unwrap().parse::<usize>().unwrap() - 1;
            query.push((x, y, z));
        }
        query.reverse();
        for &(x, y, z) in &query {
            mi[x] = mi[x].max(mi[z]);
            mi[y] = mi[y].max(mi[z]);
            if x != z && y != z {
                mi[z] = 0;
            }
        }
        c = mi.clone();
        query.reverse();
        for &(x, y, z) in &query {
            c[z] = c[x].min(c[y]);
        }
        if c0 == c {
            for &v in &mi {
                output.push_str(&format!("{} ", v));
            }
            output.pop();
            output.push('\n');
        } else {
            output.push_str("-1\n");
        }
    }

    print!("{}", output);
}