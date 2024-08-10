#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;


long double calcPoint(pair<long double, long double> point, long double x, long double r){
    int hipo = r * 2;
    int deltaX = abs(point.first - x); 
    long double deltaY = sqrt((hipo * hipo) - (deltaX * deltaX));
    return deltaY;
}

void sol(){
    ll n, r;
    cin >> n >> r;
    vector<long double> initial(n);
    for(int i = 0; i < n; i++){
        cin >> initial[i];
    }
    vector<pair<long double, long double> > points;
    for(int i = 0; i < n; i++){
        long double highest = 0;
        long double xcor = 0;
        long double pointer = 0;
        long double highPoint = 0;
        
        for(pair<long double, long double> point : points){
            if((initial[i] + r >= point.first - r && point.first >= initial[i]) || (initial[i] - r <= point.first + r && initial[i] >= point.first)){

                pointer = calcPoint(point, initial[i], r);
                if(point.second + pointer > highPoint){
                    highest = point.second;
                    xcor = point.first;
                    highPoint = highest + pointer;

                }
            }
            
        }

        if(highest == 0){
            points.push_back(make_pair(initial[i], r));
        }
        else{
            points.push_back(make_pair(initial[i], highPoint));
        }
/*        else if(xcor == initial[i]){
            points.push_back(make_pair(initial[i], highest + r * 2));
        }
        else{
            points.push_back(make_pair(initial[i], highPoint));
        }

*/
    }
    for(int i = 0; i < points.size(); i++){
        printf("%.18Lf ", points[i].second);
    }
    puts("");

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
              
    int t;
    t = 1;
    while(t--){
        sol();
    }


    return 0;
}

