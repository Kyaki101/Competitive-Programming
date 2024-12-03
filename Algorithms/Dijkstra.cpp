#include <bits/stdc++.h>

using namespace std;


const int MAX = 2e5 + 10;

int memo[MAX] = {(1 << 30)};


struct Compare {
    bool operator()(int a, int b) {
        return memo[a] < memo[b];
    }
};

void dijkstra(vector<vector<pair<int, int>>> & graph, int src, bitset<MAX> & vis) {
    memo[src] = 0;
    priority_queue<int, vector<int>, Compare> pq;
    pq.push(src);
    vis.set(src);
    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();
        for(int i = 0; i < graph[node].size(); i++) {

            if(memo[graph[node][i].first] > memo[node] + graph[node][i].second) {
                memo[graph[node][i].first] = memo[node] + graph[node][i].second;
                if(!vis.test(graph[node][i].first)) {
                    vis.set(graph[node][i].first);
                    pq.push(graph[node][i].first);
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    int m;
    cin >> m;
    int a, b, w;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    bitset<MAX> bits;
    for(int i = 0; i < n; i++) {
        memo[i] = (1 << 30);
    }
    dijkstra(graph, 0, bits);
    for(int i = 0; i < n; i++) {
        cout << memo[i] << " ";

    }
    cout << endl;


    return 0;
}
