/**/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    int n;
    cin >> s >> n;
    int val = 0;
    vec a(26, 0);
    for(char i : s){
        val += (int)(i) - 96;
        a[(char)(i) - 'a'] ++;
    }
    int i = 25;
    while(i > -1 && val > n){
        if(a[i] > 0){
            a[i]--;
            val -= i + 1;
        }
        else if (a[i] == 0){
            i--;
        }
    }
    // for(int i : a){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << val << endl;
    for(char i : s){
        if(a[i - 'a']){
            cout << i;
            a[i - 'a'] --;
        }
    }
    cout << endl;
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