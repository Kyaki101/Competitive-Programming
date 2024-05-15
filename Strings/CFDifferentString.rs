#![allow(unused)]

use std::*;

fn print_vec(list: & Vec<u8>){
    for &i in list{
        print!("{}", i as char);
    }
    print!("\n");

}

fn sol(){
    let mut stdin = std::io::stdin();
    let mut line = String::new();
    stdin.read_line(& mut line);
    line = line.trim().to_string();
    let mut holder: Vec<u8> = line.as_bytes().to_vec();
    let first: u8 = holder[0];
    for i in 1..holder.len(){
        if holder[i] != first{
            holder[0] = holder[i];
            holder[i] = first;
            print!("YES\n");
            print_vec(&holder);
            return;
        }
    }
    print!("NO\n");

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
