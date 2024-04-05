#include <iostream>
#include <string>
using namespace std;

#define N 50

bool in_square_grid(int r, int c, int n){
    return r>=0&&r<n&&c>=0&&c<n;
}

int count_zero(string m[N], int r, int c, int n){
    const int dir[4][2] {{0,1},{0,-1},{1,0},{-1,0}};
    int ans {0};
    for(auto d : dir){
        if(!in_square_grid(r+d[0],c+d[1],n)||m[r+d[0]][c+d[1]]=='0'){
            ans++;
        }
    }
    return ans;
}

void decide_head_tail(string m[N], int n, int &head_r, int &head_c, int &tail_r, int &tail_c){
    int end[2][2];
    int count {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]!='0'&&count_zero(m,i,j,n)==3){
                end[count][0] = i;
                end[count][1] = j;
                count++;
            }
        }
    }
    if(m[end[0][0]][end[0][1]]>m[end[1][0]][end[1][1]]){
        head_r = end[1][0];
        head_c = end[1][1];
        tail_r = end[0][0];
        tail_c = end[0][1];
    }else{
        head_r = end[0][0];
        head_c = end[0][1];
        tail_r = end[1][0];
        tail_c = end[1][1];
    }
}

void go(string m[N], int n, int head_r, int head_c, int tail_r, int tail_c){
    int r {head_r};
    int c {head_c};
    bool walk[N][N] {{0}};
    const int dir[4][2] {{0,1},{0,-1},{1,0},{-1,0}};
    while(r!=tail_r||c!=tail_c){
        cout<<m[r][c];
        walk[r][c] = true;
        for(auto d : dir){
            if(in_square_grid(r+d[0],c+d[1],n)&&(m[r+d[0]][c+d[1]]!='0'&&!walk[r+d[0]][c+d[1]])){
                r += d[0];
                c += d[1];
                break;
            }
        }
    }
    cout<<m[tail_r][tail_c];
}

int main(){
    int n;
    cin>>n;
    string m[N];
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    int head_r, head_c, tail_r, tail_c;
    decide_head_tail(m,n,head_r,head_c,tail_r,tail_c);
    go(m,n,head_r,head_c,tail_r,tail_c);
    return 0;
}