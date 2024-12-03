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
const double PI = 3.141592653589793238460;
typedef std::complex<long double> cd;

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


const int MAX = 2e5+20;



int main(){
    ll n, m;
    cin >> n >> m;
    ll finalSize = 1;
    while(finalSize <= n + m - 1) {
        finalSize <<= 1;
    }
    vector<cd> a(finalSize, {0.0L, 0.0L}), b(finalSize, {0.0L, 0.0L});
    for(int i = 0; i < n; i++) {
        long double x;
        cin >> x;
        a[i] = {x, 0.0L};
    }
    for(int i = 0; i < m; i++) {
        long double x;
        cin >> x;
        b[i] = {x, 0.0L};
    }
    fft(a, false);
    fft(b, false);

    for(auto i : a) {
        cout << round(i.real()) << " ";
    }
    cout << endl;

    for(auto i : b) {
        cout << round(i.real()) << " ";
    }
    cout << endl;

    vector<cd> c(finalSize);
    for(int i = 0 ; i < finalSize; i++) {
        c[i] = a[i] * b[i]; 
    }
    fft(c, true);
    for(int i = 0; i < n + m - 1; i++) {
        cout << round(c[i].real()) << " ";
    }
    cout << endl;

}

