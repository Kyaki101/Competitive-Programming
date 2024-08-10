#include <bits/stdc++.h>


typedef long long int ll;
typedef std::vector<int> vec;
using namespace std;

void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<string> > letters(5);    
    letters[0].push_back("***");
    letters[0].push_back("*.*");
    letters[0].push_back("***");
    letters[0].push_back("*.*");
    letters[0].push_back("*.*");
    
    letters[1].push_back("***");
    letters[1].push_back("*.*");
    letters[1].push_back("***");
    letters[1].push_back("*.*");
    letters[1].push_back("***");

    letters[2].push_back("***");
    letters[2].push_back("*..");
    letters[2].push_back("*..");
    letters[2].push_back("*..");
    letters[2].push_back("***");

    letters[3].push_back("***");
    letters[3].push_back("*.*");
    letters[3].push_back("*.*");
    letters[3].push_back("*.*");
    letters[3].push_back("***");

    letters[4].push_back("***");
    letters[4].push_back("*..");
    letters[4].push_back("***");
    letters[4].push_back("*..");
    letters[4].push_back("***");
    string linea = "";
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < n; j++){
            linea += letters[s[j] - 'A'][i];
        }
        cout << linea << endl;
        linea = "";
    }

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

