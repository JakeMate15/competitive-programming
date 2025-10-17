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
        let mut b = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap().parse::<i64>().unwrap());
        }
        for _ in 0..n {
            b.push(it.next().unwrap().parse::<i64>().unwrap());
        }
        let c = it.next().unwrap();
        let mut base: i64 = 0;
        for i in 0..n {
            base ^= b[i];
            a[i] ^= b[i];
        }
        for j in (0..60).rev() {
            let mut has: isize = -1;
            for i in (0..n).rev() {
                if ((a[i] >> j) & 1) != 0 {
                    if has == -1 {
                        has = i as isize;
                    } else {
                        let h = has as usize;
                        a[i] ^= a[h];
                    }
                }
            }
            if has != -1 {
                let h = has as usize;
                let c_bit = (c.as_bytes()[h] == b'1') as i64;
                let base_bit = (base >> j) & 1;
                let t = c_bit ^ base_bit;
                base ^= a[h] * t;
                a[h] = 0;
            }
        }
        output.push_str(&format!("{}\n", base));
    }

    print!("{}", output);
}