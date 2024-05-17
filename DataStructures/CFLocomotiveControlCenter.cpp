/*
*https://codeforces.com/gym/105167/problem/L
*/


#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    stack<int> a, b, c;
    a.push(0);
    int holder;
    for(int i = 0; i < n; i++){
        cin >> holder;
        a.push(holder);
    }
    c.push(0);
    b.push(1 << 30);
    vector<pair<char, char> > res;
    while(c.size() != n + 1){
        if(a.top() == c.top() + 1){
            c.push(a.top()); a.pop();
            res.push_back(make_pair('A', 'C'));
        }
        else if(b.top() == c.top() + 1){
            c.push(b.top()); b.pop();
            res.push_back(make_pair('B', 'C'));
        }
        else if(a.top() > b.top()){
            cout << "-1\n";
            return;
        }
        else{
            b.push(a.top()); a.pop();
            res.push_back(make_pair('A', 'B'));
        }
    }
    cout << res.size() << '\n';
    for(pair<char, char> i : res){
        cout << i.first << ' ' << i.second << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

