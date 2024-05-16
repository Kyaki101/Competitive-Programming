/*
*https://codeforces.com/gym/105164/problem/E
*/


#![allow(unused)]

use std::*;

fn main(){
    let mut stdin = std::io::stdin();
    let mut line = String::new();
    stdin.read_line(& mut line);
    let mut numbers: Vec<i32> = line.split_ascii_whitespace().map(|s| s.parse().unwrap()).collect();
    
    let mut a: i32 = numbers[0];
    let mut b: i32 = numbers[1];
    let mut k: i32 = numbers[2];
    for i in 1..k + 1{
        if i == k{
            print!("{}\n", a * i + b);
            return;
        }
        print!("{} ", a * i + b);
    }

}

