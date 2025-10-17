use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();

    for _ in 0..t {
        let n: i64 = it.next().unwrap().parse().unwrap();
        let sq = (n as f64).sqrt() as i64;
        if sq * sq == n {
            output.push_str(&format!("{} 0\n", sq));
        } else {
            output.push_str("-1\n");
        }
    }

    print!("{}", output);
}