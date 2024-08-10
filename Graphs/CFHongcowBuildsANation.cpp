/*
*https://codeforces.com/group/5GNF7zti59/contest/535722/problem/F
*/



#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

bitset<1000> special;
int total = 0;

class UnionFind {
private: vector<long long int> p, rank, size;
public:
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        size.assign(n, 1);
        
        for(long long int i = 0; i < n; i++){
            p[i] = i;
        }
    }
    long long int find(long long int i){
        return (p[i] == i)? i : (p[i] = find(p[i]));
    }
    bool inSameSet(long long int i, long long int j){
        return find(i) == find(j);
    }
    
    void unionSet(long long int i, long long j){
        if(!inSameSet(i, j)){
            long long int x = find(i), y = find(j);
            if(rank[x] > rank[y] ) {
                p[y] = x;
                size[x] += size[y];
                size[y] = size[x];
                

            }
            else{
                p[x] = y;
                size[y] += size[x];
                size[x] = size[y];
                if(rank[x] == rank[y]) rank[y] ++;
            }
            if(special.test(x) || special.test(y)){
                special.set(x);
                special.set(y);
                special.set(i); special.set(j);
            }
        }
    }
    ll largestSet(){
        ll largest = 0;
        ll index = 0;
        for(int i = 0; i < size.size(); i++){
            if(special.test(i)){
                if(size[i] > largest){
                    index = i;
                    largest = size[i];
                }
            }

        }
        return index;
    }


    ll getSize(ll n){
        return size[find(n)];
    }
    bool isSpecial(ll n){
        return special.test(find(n));
    }
    
};

void sol(){
    int n, m, k;
    cin >> n >> m >> k;
    ll a;
    UnionFind ufds(n);

    vector<vector<ll> > graph(n, vector<ll>());
    for(int i = 0; i < k; i++){
        cin >> a;
        a --;
        special.set(a);
    }
    int b;
    for(int i = 0; i < m; i++){
        
        cin >> a >> b;
        a --; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        ufds.unionSet(a, b);
    }
    ll largest = ufds.largestSet();
    for(int i = 0; i < n; i++){
        if(!ufds.isSpecial(i)){
            ufds.unionSet(largest, i);
        }
    }
    set<int> sets;
    for(int i = 0; i < n; i++){
        int sete = ufds.find(i);
        int tam = ufds.getSize(ufds.find(i)); 
        if(sets.find(sete) == sets.end()){
            total += (tam * (tam - 1)) / 2;
            sets.insert(sete);
        } 
    }
    cout << total - m << endl;
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

