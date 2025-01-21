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

void sol(){        
    ll n;
    cin >> n;
    vector<ll> a(n);

    vector<ll> positives;
    queue<ll> negs;
    stack<ll> rev;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] >= 0) positives.push_back(a[i]);
        else negs.push(a[i]), rev.push(a[i]);
    }
    if(positives.size() == 0 || positives.size() == 1 && positives[0] == 0) {
        cout << 0 << endl;
        return;
    }

    ll rightSum = 0;
    for(int i = 0; i < positives.size(); i++) rightSum += positives[i];
    ll reserve = rightSum;
    ll leftSum = 0;

    vector<ll> ans;
    vector<ll> rToL;

    for(int i = 0; i < positives.size(); i++) {
        leftSum += positives[i];
        ans.push_back(positives[i]);
        rightSum -= positives[i];
        while(!negs.empty() && rightSum <= leftSum) {
            ans.push_back(negs.front());
            leftSum += negs.front();
            negs.pop();

        }
        leftSum = max(0LL, leftSum);
    }
    rightSum = 0;
    leftSum = reserve;

    for(int i = positives.size() - 1; i > -1; i--) {
        rightSum += positives[i];
        rToL.push_back(positives[i]);
        leftSum -= positives[i];
        while(!rev.empty() && leftSum <= rightSum) {
            rToL.push_back(rev.top());
            rightSum += rev.top();
            rev.pop();

        }
        rightSum = max(0LL, rightSum);
    }


    ll maxi = 0;
    ll curr = 0;
    for(int i = 0; i < ans.size(); i++) {
        curr = max(0LL, curr + ans[i]);
        maxi = max(curr, maxi);

    }
    curr = 0;
    ll maxi2 = 0;
    for(int i = 0; i < rToL.size(); i++) {
        curr = max(0LL, curr + rToL[i]);
        maxi2 = max(curr, maxi2);
    }


    cout << min(maxi, maxi2) << endl;


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

