#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin>>n;
  ll a[100000];

  for(int i=0; i<n; i++)
    cin>>a[i];


  for(int i=0; i<n; i++){
    int x = __builtin_popcount(a[i]);
    int k = (int)log2(a[i]);
    ll y = 0;
    for(int j=k; j>=0; j--){
      if(x!=0){
        y += (1<<j);
        x--;
      }
    }
    a[i] = y;
  }

  sort(a, a+n);

  for(int i=0; i<n; i++){
    cout<<a[i]<<" ";
  }
  cout<<"\n";

  return 0;
}
