#include <iostream>
#include <string>
using namespace std;

#define N 50

bool in_square_grid(int x, int y, int n){
    return x>=0&&x<n&&y>=0&&y<n;
}

int count(char m[N][N], int x, int y, int n){
    int test[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int ans = 0;
    for(int i=0;i<4;i++){
        if(!in_square_grid(x+test[i][0],y+test[i][1],n)||m[x+test[i][0]][y+test[i][1]]=='0'){
            ans++;
        }
    }
    return ans;
}

void go(char m[N][N], int head_x, int head_y, int tail_x, int tail_y, int n){
    int x = head_x;
    int y = head_y;
    int walk[N][N] {{0}};
    int test[4][2] {{0,1},{0,-1},{1,0},{-1,0}};
    while(x!=tail_x||y!=tail_y){
        cout<<m[x][y];
        walk[x][y]++;
        for(int i=0;i<4;i++){
            if(in_square_grid(x+test[i][0],y+test[i][1],n)&&(m[x+test[i][0]][y+test[i][1]]!='0'&&walk[x+test[i][0]][y+test[i][1]]==0)){
                x+=test[i][0];
                y+=test[i][1];
                break;
            }
        }
    }
    cout<<m[tail_x][tail_y];
}

int main(){
    int n;
    cin>>n;
    char m[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            m[i][j] = '0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    int head[2][2];
    int c_h = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]!='0'){
                if(count(m,i,j,n)==3){
                    head[c_h][0] = i;
                    head[c_h][1] = j;
                    c_h++;
                }
            }
        }
    }
    if(m[head[0][0]][head[0][1]]>m[head[1][0]][head[1][1]]){
        go(m,head[1][0],head[1][1],head[0][0],head[0][1],n);
    }else{
        go(m,head[0][0],head[0][1],head[1][0],head[1][1],n);
    }
    return 0;
}