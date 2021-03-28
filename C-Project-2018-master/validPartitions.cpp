#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin>>t;
  while(t--){
    string s;
    int k;
    cin>>s>>k;

    vector<string> vs;
    int i=0;

    while((s.substr(i, string::npos)).size()>k){
      vs.push_back(s.substr(i, k));
      i+=k;
    }

    if(s.substr(i, string::npos).size()>=k-1){
      vs.push_back(s.substr(i, string::npos));
      if(vs.size()>=k){
        for(int i=0; i<vs.size(); i++){
          if(i==vs.size()-1)cout<<vs[i]<<'\n';
          else cout<<vs[i]<<"-";
        }
      }
      else{
        cout<<"-1\n";
      }
    }
    else {
      cout<<"-1\n";
    }
  }

  return 0;
}
