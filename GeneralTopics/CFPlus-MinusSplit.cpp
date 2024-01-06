#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;
string s;



void sol(){
    cin >> n;
    cin >> s;
    ll sumCount = 0;
    ll minCount = 0;
    for(char i : s){
        if(i == '+')sumCount ++;
        else minCount ++;
    }
    cout << abs(sumCount - minCount) << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}