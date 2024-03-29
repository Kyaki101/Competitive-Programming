#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    string s;
    cin >> s;
    string h = "";
    h += s[0]; h += s[1];
    int hour = stoi(h);
    if(hour > 11){
        if(hour == 12){
            cout << 12 << ":" << s[3] << s[4] << " PM\n";
            return;
        }
        hour -= 12;
        if(hour < 10){
            cout << '0' << hour << ":" << s[3] << s[4] << " PM\n";
            return;
        }
        cout << hour << ":" << s[3] << s[4] << " PM\n";
        return;
    }
    if(h == "00"){
        cout << "12" << ":" << s[3] << s[4] << " AM\n";
        return;
    }
    if(hour < 10){
        cout << '0' << hour << ":" << s[3] << s[4] << " AM\n";
        return;
    }
    cout << hour << ":" << s[3] << s[4] << " AM\n";
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