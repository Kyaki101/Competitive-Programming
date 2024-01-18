#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int n;

vector<vec> graph;
vector<bool> vis;
int leafCounter = 0;

int findMaxVert() {
    int greatest = -1;
    int pre = greatest;
    int index = -1;
    for (int i = 0; i < n; i++) {
        int siz = graph[i].size();
        if (siz > greatest) {
            greatest = graph[i].size();
            index = i;
        }
    }
    return index;
}

void search(int node){
    vis[node] = true;
    if(graph[node].size() - 1 == 0){
        leafCounter ++;
        return;
    }
    for(int i = 0; i < graph[node].size(); i++){
        if(!vis[graph[node][i]]){
            search(graph[node][i]);
        }
    }
}

void sol(){
    leafCounter = 0;
    int a, b;
    cin >> n;
    graph.assign(n, vec(0, 0));
    vis.assign(n, false);
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        a --; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int largest = findMaxVert();
    if(graph[largest].size() == 0){
        cout << 0 << '\n';
    }
    
    vis[largest] = true;
    for(int i = 0; i < graph[largest].size(); i++){
        search(graph[largest][i]);
    }
    cout << (leafCounter + 1)/2 << '\n';

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