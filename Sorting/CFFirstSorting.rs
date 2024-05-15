use std::io::{self, BufRead};
use std::cmp;


fn sol(){
    let mut stdin = std::io::stdin();
    let mut line = String::new();
    stdin.read_line(& mut line);
    let a: Vec<i32> = line.split_ascii_whitespace().map(|s| s.parse().unwrap()).collect();
    print!("{} {}\n", cmp::min(a[0], a[1]), cmp::max(a[0], a[1]));
}

fn main(){
    let mut stdin = std::io::stdin();
    let mut line = String::new();
    stdin.read_line(& mut line);
    let mut t: i32 = line.trim().parse().unwrap();
    while t != 0{
        sol();
        t -= 1;
    }
}
