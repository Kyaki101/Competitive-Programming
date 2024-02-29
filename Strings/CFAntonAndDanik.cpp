#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A')a++;
        else a--;
    }
    if(a > 0){
        cout << "Anton\n"; return;
    }
    if(a < 0){
        cout << "Danik\n"; return;
    }
    cout << "Friendship\n";
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