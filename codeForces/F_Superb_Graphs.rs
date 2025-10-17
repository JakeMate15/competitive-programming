use std::io::{self, BufRead};

const N: usize = 300;

struct Graph {
    ej: Vec<Vec<usize>>,
    fi: Vec<Vec<usize>>,
}

impl Graph {
    fn new(size: usize) -> Self {
        Graph {
            ej: vec![Vec::with_capacity(2); size],
            fi: vec![Vec::with_capacity(2); size],
        }
    }

    fn add(&mut self, i: usize, j: usize) {
        self.ej[i ^ 1].push(j);
        self.fi[j].push(i ^ 1);
        self.ej[j ^ 1].push(i);
        self.fi[i].push(j ^ 1);
    }
}

fn dfs1(i: usize, graph: &Graph, cc: &mut Vec<i32>, qu: &mut Vec<usize>, cnt: &mut usize) {
    if cc[i] != 0 {
        return;
    }
    cc[i] = -1;
    for &j in &graph.ej[i] {
        dfs1(j, graph, cc, qu, cnt);
    }
    *cnt -= 1;
    qu[*cnt] = i;
}

fn dfs2(j: usize, c: i32, graph: &Graph, cc: &mut Vec<i32>) {
    if cc[j] != -1 {
        return;
    }
    cc[j] = c;
    for &i in &graph.fi[j] {
        dfs2(i, c, graph, cc);
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    
    for _ in 0..t {
        let line = lines.next().unwrap().unwrap();
        let parts: Vec<usize> = line.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let n = parts[0];
        let b = parts[1];
        
        let mut graph = Graph::new(n * 2);
        let mut adj = vec![vec![false; n]; n];
        
        for _ in 0..b {
            let m: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
            
            for row in &mut adj {
                row.fill(false);
            }
            
            for _ in 0..m {
                let line = lines.next().unwrap().unwrap();
                let edge: Vec<usize> = line.split_whitespace()
                    .map(|s| s.parse::<usize>().unwrap() - 1)
                    .collect();
                let i = edge[0];
                let j = edge[1];
                adj[i][j] = true;
                adj[j][i] = true;
            }
            
            for i in 0..n {
                for j in (i + 1)..n {
                    let mut same = true;
                    for k in 0..n {
                        if k != i && k != j && adj[i][k] != adj[j][k] {
                            same = false;
                            break;
                        }
                    }
                    if same {
                        if !adj[i][j] {
                            graph.add(i << 1 | 1, j << 1 | 1);
                        } else {
                            graph.add(i << 1 | 0, j << 1 | 0);
                        }
                    }
                }
            }
        }
        
        let mut cc = vec![0i32; n * 2];
        let mut qu = vec![0usize; n * 2];
        let mut cnt = n * 2;
        
        for i in 0..n * 2 {
            if cc[i] == 0 {
                dfs1(i, &graph, &mut cc, &mut qu, &mut cnt);
            }
        }
        
        let mut c = 0;
        for h in 0..n * 2 {
            let i = qu[h];
            if cc[i] == -1 {
                dfs2(i, c, &graph, &mut cc);
                c += 1;
            }
        }
        
        let mut yes = true;
        for i in 0..n {
            if cc[i << 1 | 0] == cc[i << 1 | 1] {
                yes = false;
                break;
            }
        }
        
        println!("{}", if yes { "Yes" } else { "No" });
    }
}