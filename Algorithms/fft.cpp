#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
const double PI = 3.141592653589793238460;
typedef std::complex<long double> Complex;
using namespace std;

void fft(vector<Complex> & polynomial){
    ll N = polynomial.size();
    cout << N << endl;
    if(N <= 1) return;
    vector<Complex> even, odd;
    for(int i = 0; i < N; i+= 2){
        even.push_back(polynomial[i]);
    }
    for(int i = 1; i < N; i += 2){
        odd.push_back(polynomial[i]);
    }
    fft(even);
    fft(odd);

    for(int i = 0; i < N / 2; i++){
        Complex t = (Complex)polar(1.0, (-2 * PI * i) / N) * odd[i]; 
        polynomial[i] = even[i] + t;
        polynomial[i + N / 2] = even[i] - t;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<Complex> test;
    test.push_back(1.0);

    test.push_back(0.0);

    test.push_back(1.0);

    test.push_back(0.0);

    test.push_back(1.0);

    test.push_back(0.0);
    test.push_back(1.0);
    test.push_back(0.0);

    fft(test);
    for(int i = 0; i < 8; i++){
        cout << test[i] << endl;
    }


    return 0;
}

