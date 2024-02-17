int n;
#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

bool comp(pair<char, int> & a, pair<char, int> & b){
    return a.second > b.second;
}

void sol(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    vec t(1, 0);
    vec a(1, 0);
    vec g(1, 0);
    vec c(1, 0);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'T'){
            t.push_back(t[i] + 1);
            a.push_back(a[i]);
            g.push_back(g[i]);
            c.push_back(c[i]);
        }
        else if(s[i] == 'A'){
            a.push_back(a[i] + 1);
            t.push_back(t[i]);
            g.push_back(g[i]);
            c.push_back(c[i]);
        }
        else if(s[i] == 'G'){
            g.push_back(g[i] + 1);
            a.push_back(a[i]);
            t.push_back(t[i]);
            c.push_back(c[i]);
        }
        else if(s[i] == 'C'){
            c.push_back(c[i] + 1);
            a.push_back(a[i]);
            g.push_back(g[i]);
            t.push_back(t[i]);
        }
        
    }
    while(q--){
        vector<pair<char, int>> res;
        int i, b;
        cin >> i >> b;
        res.push_back(make_pair('A', a[b] - a[i - 1]));
        res.push_back(make_pair('T', t[b] - t[i - 1]));
        res.push_back(make_pair('G', g[b] - g[i - 1]));
        res.push_back(make_pair('C', c[b] - c[i - 1]));
        sort(res.begin(), res.end(), comp);
        for(pair<char, int> i: res){
            cout << i.first;
        }
        cout << endl;
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