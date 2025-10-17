use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();

    for _ in 0..t {
        let n: i64 = it.next().unwrap().parse().unwrap();
        let k: i64 = it.next().unwrap().parse().unwrap();
        let s = it.next().unwrap();
        let cnt_ones = s.bytes().filter(|&b| b == b'1').count() as i64;
        let cnt = ((2 * cnt_ones - n).abs()) / 2;
        if k >= cnt && (k % 2 == cnt % 2) {
            output.push_str("YES\n");
        } else {
            output.push_str("NO\n");
        }
    }

    print!("{}", output);
}