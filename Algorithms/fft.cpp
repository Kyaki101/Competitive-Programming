#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::vector<cd> a = {
        {8.0L, 0.0L}, {2.0L, 0.0L}, {0.0L, 0.0L}, {0.0L, 0.0L}
    };
    std::vector<cd> b = {
        {2.0L, 0.0L}, {4.0L, 0.0L}, {0.0L, 0.0L}, {0.0L, 0.0L}
    };    
    fft(a, 0);
    fft(b, 0);
    vector<cd> res(a.size());
    for(int i = 0; i < a.size(); i++) {
        res[i] = a[i] * b[i];
    }
    fft(res, 1);
    for(int i = 0; i < res.size() - 1; i++) {
        cout << round(res[i].real()) << " ";
    }
    cout << endl;


    return 0;
}

