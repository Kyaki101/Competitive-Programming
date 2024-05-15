#include <bits/stdc++.h>

using namespace std;
vector<int> memo;

vector<vector<pair<int, int>>> graph;

bool comp(int a, int b){
    return memo[a] > memo[b];
}

void dijkstra(vector<vector<pair<int, int>>> graph, int src, vector<int> & memo, vector<bool> & vis){
    vis[src] = 1;
    priority_queue<int, vector<int>, function<bool(int, int)>> pq(comp);
    pq.push(src);
    while(!pq.empty()){
        int node = pq.top();
        cout << node << endl;
        pq.pop();
        for(pair<int, int> i : graph[node]){
            if(!vis[i.first]){
                memo[i.first] = memo[node] + i.second;
                pq.push(i.first);
                vis[i.first] = true;
            }
            else memo[i.first] = min(memo[i.first], memo[node] + i.second);
        }
    }
    for(int i : memo)cout << i << " ";
    cout << endl;
    

}

int main(){
    int nodes, edges, src;
    cin >> nodes >> edges >> src;
    src --;
    memo.assign(nodes, (1<<30));
    vector<bool> vis(nodes, false);
    vector<vector<pair<int, int>>> graph(nodes);

    for(int i = 0; i < edges; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back(make_pair(b - 1, w));
    }
    memo[src] = 0;
    dijkstra(graph, src, memo, vis);

    return 0;
}
