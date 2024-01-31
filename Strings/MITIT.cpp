/*
https://codeforces.com/gym/104936/problem/A
*/

#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    int dif = 0;
    bool even = !(s.size() - 1 & 1);
    bool flg = false;
    for(int i = 1; i < s.size() - 1; i++){
        if(even){
            if(i & 1 && !flg){
                if(s[i] == s[((i + s.size() - 1) / 2) + 1]){
                    dif = (((i + s.size() - 1) / 2) + 1) - i;
                    flg = true;
                }
            }
            else if(flg){
                if(s[i + dif] != s[i]){
                    flg = false;
                }
            }
            if(flg && i + dif == s.size() - 1){
                cout << "YES\n";
                return;
            }

        }
        if(!even){
            if(!(i & 1) && !flg){
                if(s[i] == s[((i + s.size() - 1) / 2) + 1]){
                    dif = (((i + s.size() - 1) / 2) + 1) - i;
                    flg = true;
                }
            }
            else if(flg){
                if(s[i + dif] != s[i]){
                    flg = false;
                }
            }
            if(flg && i + dif == s.size() - 1){
                cout << "YES\n";
                return;
            }

        }
        else if(flg){
            if(s[i + dif] != s[i]){
                flg = false;
            }
        }
        if(flg && i + dif == s.size() - 1){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
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