use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    
    let t: usize = it.next().unwrap().parse().unwrap();
    let mut output = String::new();
    
    for _ in 0..t {
        let n: i32 = it.next().unwrap().parse().unwrap();
        let m: i32 = it.next().unwrap().parse().unwrap();
        
        let mut ans = Vec::new();
        let mut xl = n / 2 + 1;
        let mut xr = n / 2 + 1;
        let mut yl = m / 2 + 1;
        let mut yr = m / 2 + 1;
        
        let xm = n / 2 + 1;
        let ym = m / 2 + 1;
        ans.push((xm, ym));
        
        while xl != 1 || yl != 1 {
            if xl != 1 {
                let mut l = ym;
                let mut r = ym;
                while l >= yl {
                    ans.push((xl - 1, l));
                    ans.push((xr + 1, l));
                    if l != r {
                        ans.push((xl - 1, r));
                        ans.push((xr + 1, r));
                    }
                    l -= 1;
                    r += 1;
                }
                xl -= 1;
                xr += 1;
            }
            if yl != 1 {
                let mut l = xm;
                let mut r = xm;
                while l >= xl {
                    ans.push((l, yl - 1));
                    ans.push((l, yr + 1));
                    if l != r {
                        ans.push((r, yl - 1));
                        ans.push((r, yr + 1));
                    }
                    l -= 1;
                    r += 1;
                }
                yl -= 1;
                yr += 1;
            }
        }
        
        for (x, y) in ans {
            output.push_str(&format!("{} {}\n", x, y));
        }
    }
    
    print!("{}", output);
}