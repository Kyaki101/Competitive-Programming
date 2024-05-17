/*
*https://codeforces.com/gym/105164/problem/G
*/


#![allow(unused)]

use std::*;

fn main(){
    let mut stdin = std::io::stdin();
    let mut line = String::new();
    stdin.read_line(& mut line);
    let mut t: i32 = line.trim().parse().unwrap();
    stdin.read_line(& mut line);
    let mut nums: Vec<i32> = line.split_ascii_whitespace().map(|s| s.parse().unwrap()).collect();
    nums.sort();
    if(nums[0] != 1){
        print!("Alicius\n");
        return;
    }
    let mut winner: bool = false;
    let mut curr: i32 = nums[0];
    for i in 1..(t - 1){
        if nums[(i as usize) - 1] + 1 == nums[i as usize] && nums[(i as usize)] != nums[(t as usize) - 1]{
            winner = !winner;
        }
        else if nums[(i as usize) - 1] != nums[i as usize]{
            if winner {
                print!("Alicius\n");
                return;
            }
            print!("Bobius\n");
            return;
        }
        if nums[(i as usize)] == nums[(t as usize) - 1]{
            break;
        }
    }
    if winner || (!winner && nums[(t as usize) - 1] == 1){
        print!("Alicius\n");
        return;
    }
    print!("Bobius\n");
    return;

}

