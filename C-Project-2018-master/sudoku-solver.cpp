#include<bits/stdc++.h>
using namespace std;

int mat[9][9];
bool row[9][9];//row0[9];
bool column[9][9]; //column0[9];
bool cube[9][9]; //cube0[9];

int which_cube(int x, int y){
  if(x<=2){
    if(y<=2)return 0;
    if(y>2 && y<=5)return 1;
    if(y>5 && y<=8)return 2;
  }
  if(x>2 && x<=5){
    if(y<=2)return 3;
    if(y>2 && y<=5)return 4;
    if(y>5 && y<=8)return 5;
  }
  if(x>5 && x<=8){
    if(y<=2)return 6;
    if(y>2 && y<=5)return 7;
    if(y>5 && y<=8)return 8;
  }
}

int search_next(int x, int y, int num){
  int cu = which_cube(x, y);
  if(num!=0)
    row[x][num-1] = column[y][num-1] = cube[cu][num-1] = false;
  for(int j=num; j<9;  j++){
    if(row[x][j]==false && column[y][j]==false && cube[cu][j]==false){
      row[x][j] = column[y][j] = cube[cu][j] = true;
      return j+1;
    }
  }
  return 0;
}

bool solve(int x, int y){
  /*for(int i=x; i<9; i++){
    for(int j=y; j<9; j++){
      if(mat[i][j]==0){
        x = i;
        y = j;
        i=9;
        j=9;
      }
    }
  }*/

  while(mat[x][y]!=0){
    y++;
    if(y==9){
      x++;
      y=0;
    }
    if(x==9){
      return true;
    }
  }


  int next_num = search_next(x, y, 0);

  while(next_num!=0){
    mat[x][y] = next_num;
    bool flag = solve(x, y);
    if(flag==false){
       next_num = search_next(x, y, mat[x][y]);
    }
    if(flag==true){
      return true;
    }
  }

  if(next_num == 0){
    mat[x][y]=0;
    return false;
  }


  return true;
}

void read(int x, int y){
  if(mat[x][y]!=0){
    row[x][mat[x][y]-1] = column[y][mat[x][y]-1] = cube[which_cube(x, y)][mat[x][y]-1] = true;
  }
}

int main(){
  int t;
//  scanf("%d", &t);

  ifstream myfile;
  myfile.open("sudoku.txt");
  myfile>>t;

  for(int i=0; i<t; i++){
  /*  for(int j=0; j<9; j++){
      for(int k=0; k<9; k++){
        scanf("%d", &mat[j][k]);
      }*/

    int j=0, k=0;
    while(!myfile.eof()){
      myfile>>mat[j][k];
      k++;
      if(k==9){
        j++;
        k=0;
      }
    }

    myfile.close();

    for(int j=0; j<9; j++){
      for(int k=0; k<9; k++){
        read(j, k);
      }
    }

    bool sudoku = solve(0, 0);

    cout<<sudoku<<"\n";
    if(sudoku){
      for(int j=0; j<9; j++){
        for(int k=0; k<9; k++){
          printf("%d ", mat[j][k]);
        }
        printf("\n");
      }
    }

    printf("\n");

  }

  return 0;
}
