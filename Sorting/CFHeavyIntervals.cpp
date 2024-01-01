#include <bits/stdc++.h>

typedef long long int ll;
typedef std::vector<ll> list;

ll n;
list r, l, c, sorted, diffs;
std::stack<ll> pila;
std::vector<char> parents;

void sorter(){
  ll i = 0;
  ll j = 0;
  while(i != n || j != n){
    if(i == n){
      for(j; j < n; j++){
        sorted.push_back(r[j]);
        parents.push_back(')');
      }
    }
    else if(l[i] <= r[j]){
      sorted.push_back(l[i]);
      i++;
      parents.push_back('(');
    }
    else{
      sorted.push_back(r[j]);
      j++;
      parents.push_back(')');
    }
  }
}

bool rev(ll a, ll b){
  return a > b;
}

void sol(){
  std::sort(r.begin(), r.end());
  std::sort(l.begin(), l.end());
  std::sort(c.begin(), c.end(), rev);
  sorter();
  ll res = 0;
  ll i = 0;
  while(i < sorted.size()){
    if(parents[i] == '('){
      pila.push(sorted[i]);
    }
    else{
      ll pre = sorted[i] - pila.top();
      diffs.push_back(pre); 
      pila.pop();
    }
    i++;
  }
  std::sort(diffs.begin(), diffs.end());
  for(ll i = 0; i < n; i++){
    res += c[i] * diffs[i];
  }
  std::cout << res << '\n';
}

int main(){
  ll t;
  std::cin >> t;
  while(t--){
    std::cin >> n;
    r.assign(n, 0);
    l.assign(n, 0);
    c.assign(n, 0);
    sorted.assign(0, 0);
    parents.assign(0, ' ');
    diffs.assign(0, 0);
    for(ll i = 0; i < n; i ++){
      std::cin >> l[i];
    }
    for(ll i = 0; i < n; i ++){
      std::cin >> r[i];
    }
    for(ll i = 0; i < n; i ++){
      std::cin >> c[i];
    }
    sol();
  }
}
