#include<bits/stdc++.h>
using namespace std;

bool not_outside(int n, int m, int x, int y){
  if(x>=m || x<0)return false;
  if(y>=n || y<0)return false;
  return true;
}


int knights(int n, int m, int c, int x, int y){
  int count = 0;
  if(c==1){
    if(not_outside(n, m, x+2, y-1))count++;
    if(not_outside(n, m, x+2, y+1))count++;
    if(not_outside(n, m, x-2, y-1))count++;
    if(not_outside(n, m, x-2, y+1))count++;
    if(not_outside(n, m, x+1, y+2))count++;
    if(not_outside(n, m, x+1, y-2))count++;
    if(not_outside(n, m, x-1, y+2))count++;
    if(not_outside(n, m, x-1, y-2))count++;
    return n*m-(1+count);
  }
  if(c==0){
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++){
        count += knights(n, m, 1, i, j);
      }
  }

  return count;
}


int main(){
  int t;
  scanf("%d", &t);

  for(int i=0; i<t; i++){
    int n, m;
    scanf("%d%d", &n, &m);

    int count = knights(n, m, 0, 0, 0);
    printf("%d\n", count);
  }

  return 0;
}
