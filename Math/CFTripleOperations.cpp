/*
*https://codeforces.com/contest/1999/problem/E
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

ll powers[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441};



void sol(){
    ll r, l;
    cin >> l >> r;
    int counter;
    int start;
    for(int i = 0; i < 13; i++){
        if(l <= powers[i]){
            counter = i;
            if(l == powers[i])counter ++;
            start = i;
            counter += i * (min(powers[start], r) - l);
            if(min(powers[start], r) == r){
                if(r == powers[i]){
                    counter += i + 1;
                }
                else counter += i;
                cout << counter << endl;
                return;
            }
            break;
        }
    }
    for(int i = start; i < 12; i++){

        counter += (i + 1) * (std::min(powers[i + 1], r) - powers[i]);
        if(min(powers[i + 1], r) == r){
            if(r == powers[i + 1]) counter += i + 2;
            else counter += i + 1;
            cout << counter << endl;
            return;
        }
    }
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

