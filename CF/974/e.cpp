#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename Key, typename Value>
using ordered_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename Key, typename Value = null_type>
using trie = trie<Key, Value, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) (cout << (n) << endl)
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

vector<pair<int, int>> G[MAX];

typedef struct node {
    pair<int, int> n;
    bool boost;
} node;

struct Compare {
    bool operator()(const node a, const node b) const {
        return a.n.second < b.n.second;
    }
};

int dp[MAX];

void Dijkstra(int st, vector<vector<pair<int, int>>> & G, int * dp, vector<bool> & boosts){
    
    for(int i = 0; i < G.size(); i++) {
        dp[i] = (1 << 30);
    }
    priority_queue<node, vector<node>, Compare> pq;
    node * temp = new node;
    if(boosts[st]) {

        *temp = {{st, 0}, true};

    }
    else *temp = {{st, 0}, false};
    node bruh = *temp;


    dp[st] = 0; pq.push(bruh);
    while(!pq.empty()){
        node curr = pq.top();
        int now = curr.n.first;
        int weight = dp[now];
        pq.pop();
        for(auto &p : G[now]) {
            int next = p.first;
            int w = p.second;

            if(curr.boost || boosts[now]) {
                if(weight + w / 2 < dp[next]) {

                    dp[next] = weight + w / 2;
                    pq.push({{next, dp[next]}, true});

                }
            }

            else {
                if(weight + w < dp[next]) {
                    dp[next] = weight + w;
                    pq.push({{next, dp[next]}, false});
                }

            }
        }


        

    }

}

void sol(){        
    int n, m, h;
    cin >> n >> m >> h;
    vector<bool> boosts(n);
    for(int i = 0; i < h; i++) {
        int a;
        cin >> a;
        a --;
        boosts[a] = true;

    }
    int a, b, w;
    vector<vector<pair<int, int>>> G(n);
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        a--;
        b--;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    int dp[MAX];
    int dp2[MAX];
    Dijkstra(0, G, dp, boosts);
    Dijkstra(n - 1, G, dp2, boosts);
    ll res = (1 << 30);
    ll index = 0;
    if(dp2[0] == (1 << 30)) {
        cout << "-1" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(max(dp[i], dp2[i]) < res) {
            res = max(dp[i], dp2[i]);
            index = i;
        }
    }
    cout << res<< endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

              
    int t;
    cin >> t;
    while(t--){
        sol();
    }


    return 0;
}

