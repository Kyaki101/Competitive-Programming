#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793238460;
typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

const int MAX = 2e5+20;

vector<complex<long double>> fft(vector<complex<long double>> p) {        
    int n = p.size();
    if(n == 1) {
        return p;
    }
    long double e = M_E;
    complex<long double> i(0, 1);
    complex<long double> omega = exp(i * PI * 2.0L / static_cast<long double>(n));
    vector<complex<long double>> evens;
    vector<complex<long double>> odds;
    for(int j = 0; j < n; j += 2) {
        evens.push_back(p[j]);
    }
    for(int j = 1; j < n; j += 2) {
        odds.push_back(p[j]);
    }
    vector<complex<long double>> y1 = fft(evens);
    vector<complex<long double>> y2 = fft(odds);
    vector<complex<long double>> res(n);
    for(int j = 0; j < n / 2; j++) {
        res[j] = y1[j] + pow(omega, j) * y2[j]; 
        res[j + n / 2] = y1[j] - pow(omega, j) * y2[j];
    }
    return res;
          
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    complex<long double> a(2, 0);
    complex<long double> b(3, 0);
    complex<long double> c(1, 0);
    complex<long double> d(0, 0);
    std::vector<std::complex<long double>> p = {
    {5.0L, 0.0L}, {3.0L, 0.0L}, {2.0L, 0.0L}, {1.0L, 0.0L}
    };
    vector<complex<long double>> r = fft(p);
    for(auto i : r) {
        cout << i << endl;
    }

              
    


    return 0;
}

