#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;
int k;
string str;
vector<int> cants;

void sol(){
    cin >> n >> k;
    cin >> str;
    cants.assign(26, 0);
    for(char i : str){
        cants[i - 'a'] ++;
    }
    int odds = 0;
    for(int i = 0; i < 26; i++){
        if(cants[i] & 1)odds ++;
    }
    if(odds <= k + 1)cout << "YES\n";
    else cout << "NO\n";
    
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