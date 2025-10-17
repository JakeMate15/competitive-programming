use std::collections::{BTreeSet, HashMap};
use std::io::{self, Read};

fn solve(iter: &mut std::str::SplitWhitespace) {
    let n: usize = iter.next().unwrap().parse().unwrap();
    let q: usize = iter.next().unwrap().parse().unwrap();

    let mut a: Vec<i32> = Vec::with_capacity(n + 1);
    a.push(0);
    for _ in 1..=n {
        let v: i32 = iter.next().unwrap().parse().unwrap();
        a.push(v);
    }

    let mut op: Vec<(usize, i32)> = Vec::with_capacity(q + 1);
    op.push((0, 0));
    for _ in 1..=q {
        let pos: usize = iter.next().unwrap().parse().unwrap();
        let delta: i32 = iter.next().unwrap().parse().unwrap();
        let prev = a[pos];
        a[pos] = (a[pos] + delta).min(1_000_000_000);
        op.push((pos, prev));
    }

    let mut ans: Vec<usize> = vec![0; q + 1];

    for bit in 0..18 {
        let backup = a.clone();
        let hi: i32 = (1 << bit) - 1;

        let mut parent: Vec<usize> = (0..=n).collect();
        let mut members: Vec<Vec<usize>> = vec![Vec::new(); n + 1];
        let mut freq: Vec<HashMap<i32, i32>> = vec![HashMap::new(); n + 1];
        let mut active: BTreeSet<(usize, usize)> = BTreeSet::new();

        for i in 1..=n {
            members[i].push(i);
            if a[i] <= hi {
                freq[i].entry(a[i]).and_modify(|e| *e += 1).or_insert(1);
            }
        }

        fn remove_active(
            x: usize,
            members: &Vec<Vec<usize>>,
            active: &mut BTreeSet<(usize, usize)>,
        ) {
            let key = (members[x].len(), x);
            active.remove(&key);
        }

        fn update_active(
            x: usize,
            members: &Vec<Vec<usize>>,
            freq: &Vec<HashMap<i32, i32>>,
            active: &mut BTreeSet<(usize, usize)>,
            hi: i32,
        ) {
            let key = (members[x].len(), x);
            if freq[x].len() < (hi + 1) as usize {
                active.remove(&key);
            } else {
                active.insert(key);
            }
        }

        fn merge_sets(
            x_root: usize,
            y_root: usize,
            parent: &mut Vec<usize>,
            members: &mut Vec<Vec<usize>>,
            freq: &mut Vec<HashMap<i32, i32>>,
            active: &mut BTreeSet<(usize, usize)>,
            hi: i32,
        ) {
            let mut x = x_root;
            let mut y = y_root;
            if members[x].len() < members[y].len() {
                std::mem::swap(&mut x, &mut y);
            }
            remove_active(x, members, active);
            remove_active(y, members, active);

            let mut y_members = Vec::new();
            std::mem::swap(&mut members[y], &mut y_members);
            for idx in y_members {
                parent[idx] = x;
                members[x].push(idx);
            }

            let mut y_freq = HashMap::new();
            std::mem::swap(&mut freq[y], &mut y_freq);
            for (val, cnt) in y_freq {
                *freq[x].entry(val).or_insert(0) += cnt;
            }

            update_active(x, members, freq, active, hi);
        }

        fn change_value(
            comp: usize,
            old_val: i32,
            new_val: i32,
            freq: &mut Vec<HashMap<i32, i32>>,
            hi: i32,
        ) {
            if new_val <= hi {
                freq[comp].entry(new_val).and_modify(|e| *e += 1).or_insert(1);
            }
            if old_val <= hi {
                if let Some(e) = freq[comp].get_mut(&old_val) {
                    *e -= 1;
                    if *e == 0 {
                        freq[comp].remove(&old_val);
                    }
                }
            }
        }

        for i in 2..=n {
            if a[i] <= hi && a[i - 1] <= hi {
                let r1 = parent[i];
                let r2 = parent[i - 1];
                if r1 != r2 {
                    merge_sets(r1, r2, &mut parent, &mut members, &mut freq, &mut active, hi);
                }
            }
        }

        for i in 1..=n {
            update_active(i, &members, &freq, &mut active, hi);
        }

        for i in (1..=q).rev() {
            if let Some(&(size, _)) = active.iter().next_back() {
                ans[i] = ans[i].max(size);
            }
            let (pos, prev) = op[i];
            let old = a[pos];
            let comp = parent[pos];
            let to_merge = old > hi && prev <= hi;
            change_value(comp, old, prev, &mut freq, hi);
            a[pos] = prev;
            if to_merge {
                if pos > 1 && a[pos - 1] <= hi {
                    let c1 = parent[pos];
                    let c2 = parent[pos - 1];
                    if c1 != c2 {
                        merge_sets(c1, c2, &mut parent, &mut members, &mut freq, &mut active, hi);
                    }
                }
                if pos < n && a[pos + 1] <= hi {
                    let c1 = parent[pos];
                    let c2 = parent[pos + 1];
                    if c1 != c2 {
                        merge_sets(c1, c2, &mut parent, &mut members, &mut freq, &mut active, hi);
                    }
                }
            }
            update_active(parent[pos], &members, &freq, &mut active, hi);
        }

        a = backup;
    }

    for i in 1..=q {
        println!("{}", ans[i]);
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let t: usize = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        solve(&mut iter);
    }
}