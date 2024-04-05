#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define N 50

int count(char m[N+2][N+2], int x, int y){
    int test[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int ans = 0;
    for(int i=0;i<4;i++){
        if(m[x+test[i][0]][y+test[i][1]]=='0'){
            ans++;
        }
    }
    return ans;
}

void go(char m[N+2][N+2], int head_x, int head_y, int tail_x, int tail_y){
    int x = head_x;
    int y = head_y;
    int walk[N+2][N+2]={{0}};
    int test[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while(x!=tail_x||y!=tail_y){
        printf("%c",m[x][y]);
        walk[x][y]++;
        for(int i=0;i<4;i++){
            if(m[x+test[i][0]][y+test[i][1]]!='0'&&walk[x+test[i][0]][y+test[i][1]]==0){
                x+=test[i][0];
                y+=test[i][1];
                break;
            }
        }
    }
    printf("%c",m[tail_x][tail_y]);
}

int main(){
    int n;
    scanf("%d",&n);
    char m[N+2][N+2];
    char throw_away;
    scanf("%c",&throw_away);
    for(int i=0;i<N+2;i++){
        for(int j=0;j<N+2;j++){
            m[i][j] = '0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%c",&m[i][j]);
        }
        scanf("%c",&throw_away);
    }
    int head[2][2];
    int c_h = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(m[i][j]!='0'){
                if(count(m,i,j)==3){
                    head[c_h][0] = i;
                    head[c_h][1] = j;
                    c_h++;
                }
            }
        }
    }
    if(m[head[0][0]][head[0][1]]>m[head[1][0]][head[1][1]]){
        go(m,head[1][0],head[1][1],head[0][0],head[0][1]);
    }else{
        go(m,head[0][0],head[0][1],head[1][0],head[1][1]);
    }
    return 0;
}