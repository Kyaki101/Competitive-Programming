#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    vector<ll> arr(3, 0);
    ll swaps = 0;
    
    for(char& i : s) arr[i-'0']++;

    for(char& i : s) (i == '0')? arr[0]-- : swaps += arr[0];

    for(char& i : s) {
        if(i == '1') arr[1]--;
        if(i == '2') swaps += arr[1];
    }

    cout << swaps << endl;
}