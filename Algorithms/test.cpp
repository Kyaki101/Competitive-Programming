#include <bits/stdc++.h>
#include "Segment.hpp"

typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a = {-1, 3, 4, 0, 2};

    segment seg(a); 
    seg.printTree();

    seg.update(3, -8);
    seg.printTree();
    cout << seg.rangeQuery(0, 2) << endl;
    


              


    return 0;
}

