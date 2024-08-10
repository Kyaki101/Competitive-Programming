/*
*https://codeforces.com/contest/1999/problem/B
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    vec cards(4);
    cin >> cards[0] >> cards[1] >> cards[2] >> cards[3];
    int counter = 0;
    int winners = 0, losers = 0;
    for(int i = 0; i < 2; i++){
        if(cards[i] > cards[i + 2]){
            winners ++;
        }
        if(cards[i + 2] > cards[i]) losers ++;

    }
    if(winners > losers) counter ++;
    counter *= 2;
    winners = 0;
    losers = 0;
    swap(cards[0], cards[1]);
    for(int i = 0; i < 2; i++){
        if(cards[i] > cards[i + 2]){
            winners ++;
        }
        if(cards[i + 2] > cards[i]) losers ++;
    }
    if(winners > losers) counter += 2;

    cout << counter << endl;
   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}

