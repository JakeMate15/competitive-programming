use std::collections::BTreeMap;
use std::io::{self, Read};

fn add_rat(a: [i64; 2], b: [i64; 2]) -> [i64; 2] {
    [a[0] + b[0], a[1] + b[1]]
}

fn sub_rat(a: [i64; 2], b: [i64; 2]) -> [i64; 2] {
    [a[0] - b[0], a[1] - b[1]]
}

fn mul_rat(a: [i64; 2], x: i64) -> [i64; 2] {
    [a[0] * x, a[1] * x]
}

fn add_pt(
    a: [[i64; 2]; 2],
    b: [[i64; 2]; 2],
) -> [[i64; 2]; 2] {
    [add_rat(a[0], b[0]), add_rat(a[1], b[1])]
}

fn sub_pt(
    a: [[i64; 2]; 2],
    b: [[i64; 2]; 2],
) -> [[i64; 2]; 2] {
    [sub_rat(a[0], b[0]), sub_rat(a[1], b[1])]
}

fn mul_pt(
    a: [[i64; 2]; 2],
    x: i64,
) -> [[i64; 2]; 2] {
    [mul_rat(a[0], x), mul_rat(a[1], x)]
}

fn rotate_point(a: [[i64; 2]; 2]) -> [[i64; 2]; 2] {
    [
        [
            (a[0][1] - a[1][1]) / 2,
            a[0][0] - a[1][0],
        ],
        [
            (a[0][1] + a[1][1]) / 2,
            a[0][0] + a[1][0],
        ],
    ]
}

fn run(
    mut dir: [[i64; 2]; 2],
    ops: &Vec<(String, i64)>,
) -> Vec<[[[i64; 2]; 2]; 2]> {
    let mut cur: [[i64; 2]; 2] = [[0, 0], [0, 0]];
    let mut m: BTreeMap<[[[i64; 2]; 2]; 2], [[i64; 2]; 2]> = BTreeMap::new();

    for (s, v_ref) in ops.iter() {
        let v = *v_ref;
        if s == "rotate" {
            let times = (v / 45) as usize;
            for _ in 0..times {
                dir = rotate_point(dir);
            }
            continue;
        }
        let nx = add_pt(cur, mul_pt(dir, v));

        if s == "draw" {
            let (origen_min, direction) = if cur < nx {
                (cur, dir)
            } else {
                (nx, mul_pt(dir, -1))
            };
            let key: [[[i64; 2]; 2]; 2] = [origen_min, direction];
            let extremo_max = if cur < nx { nx } else { cur };
            m.insert(key, extremo_max);
        }
        cur = nx;
    }

    let mut result: Vec<[[[i64; 2]; 2]; 2]> = Vec::new();
    let mut keys: Vec<[[[i64; 2]; 2]; 2]> = m.keys().cloned().collect();

    for key in keys {
        if let Some(&start_extremo) = m.get(&key) {
            let u_point = key[0];
            let d = key[1];
            let mut v_point = start_extremo;
            m.remove(&key);
            loop {
                let next_key = [v_point, d];
                if let Some(&next_extremo) = m.get(&next_key) {
                    v_point = next_extremo;
                    m.remove(&next_key);
                } else {
                    result.push([u_point, v_point]);
                    break;
                }
            }
        }
    }

    result
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut ops: Vec<(String, i64)> = Vec::with_capacity(n);
    for _ in 0..n {
        let s = iter.next().unwrap().to_string();
        let v: i64 = iter.next().unwrap().parse().unwrap();
        ops.push((s, v));
    }

    let mut dir: [[i64; 2]; 2] = [[1, 0], [0, 0]];
    let v0 = run(dir, &ops);

    let mut count = 0;
    loop {
        count += 1;
        dir = rotate_point(dir);
        let u = run(dir, &ops);
        let dif = sub_pt(u[0][0], v0[0][0]);
        let mut ok = true;
        for j in 0..u.len() {
            let delta_u = sub_pt(u[j][0], v0[j][0]);
            let delta_v = sub_pt(u[j][1], v0[j][1]);
            if delta_u != dif || delta_v != dif {
                ok = false;
                break;
            }
        }
        if ok {
            println!("{}", count * 45);
            break;
        }
    }
}