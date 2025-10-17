use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut a = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap().parse::<i64>().unwrap());
        }
        let mut ans = 1;
        let mut x = a[0];
        for i in 0..n {
            if a[i] > x + 1 {
                ans += 1;
                x = a[i];
            }
        }
        output.push_str(&format!("{}\n", ans));
    }

    print!("{}", output);
}