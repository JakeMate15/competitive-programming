use std::collections::BTreeMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let q: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();

    for _ in 0..q {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut m = Vec::with_capacity(n);
        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            let y: i64 = it.next().unwrap().parse().unwrap();
            m.push((x, y));
        }

        if n == 1 {
            output.push_str("1\n");
            continue;
        }

        let mut xs = BTreeMap::new();
        let mut ys = BTreeMap::new();
        for &(x, y) in &m {
            *xs.entry(x).or_insert(0) += 1;
            *ys.entry(y).or_insert(0) += 1;
        }

        let mut ans: i64 = i64::MAX;
        for &(x, y) in &m {
            {
                let cnt_x = xs.get_mut(&x).unwrap();
                if *cnt_x == 1 {
                    xs.remove(&x);
                } else {
                    *cnt_x -= 1;
                }
            }
            {
                let cnt_y = ys.get_mut(&y).unwrap();
                if *cnt_y == 1 {
                    ys.remove(&y);
                } else {
                    *cnt_y -= 1;
                }
            }

            let min_x = *xs.keys().next().unwrap();
            let max_x = *xs.keys().next_back().unwrap();
            let min_y = *ys.keys().next().unwrap();
            let max_y = *ys.keys().next_back().unwrap();

            let dx = max_x - min_x + 1;
            let dy = max_y - min_y + 1;
            let mut area = dx * dy;
            if (n as i64) > area {
                area += dx.min(dy);
            }
            if area < ans {
                ans = area;
            }

            *xs.entry(x).or_insert(0) += 1;
            *ys.entry(y).or_insert(0) += 1;
        }

        output.push_str(&format!("{}\n", ans));
    }

    print!("{}", output);
}