#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

vector<vector<int> > graphs[101];
vector<bitset<101> > vis(101);
int counter = 0;

bool dfs(int node,  int fin, int color){
    if(node == fin) return true;
    vis[color].set(node);
    for(int i = 0; i < graphs[color][node].size(); i++){
        if(!vis[color].test(graphs[color][node][i]) && dfs(graphs[color][node][i], fin, color)){
            return true;
        }
    }
    return false;
}

void sol(){
    int n;
    int m;
    cin >> n >> m;
    for(int i = 0; i < 101; i++){
        graphs[i].assign(n, vector<int>());
    }
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a --; b--; c--;
        graphs[c][a].push_back(b);
        graphs[c][b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--){
        counter = 0;
        cin >> a >> b;
        a --; b --;
        for(int i = 0; i < 101; i++){
            if(dfs(a, b, i)) counter ++;
            vis[i].reset();
        }
        cout << counter << endl;
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

