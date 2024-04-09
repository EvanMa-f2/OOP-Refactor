#include <iostream>
using namespace std;
#include "CharSquareGrid.h"
#define N 50

bool in_square_grid(const int r, const int c, const int n){
    return r>=0&&r<n&&c>=0&&c<n;
}

void set_Grid(CharGrid& s){
    cin>>s.size;
    for(int i=0;i<s.size;i++){
        string str;
        cin>>str;
        s.cell.push_back(str);
    }
}

int cant_walk(const CharGrid s, const Position pos){
    const vector<Position> dir {{0,1},{0,-1},{1,0},{-1,0}};
    int ans {0};
    for(auto d : dir){
        if(!in_square_grid(pos.r+d.r,pos.c+d.c,s.size)||s.cell[pos.r+d.r][pos.c+d.c]=='0'){
            ans++;
        }
    }
    return ans;
}

void find_head_tail(CharGrid& s){
    vector<Position> end;
    //find end
    for(int i=0;i<s.size;i++){
        for(int j=0;j<s.size;j++){
            Position pos {i,j};
            if(s.cell[i][j]!='0'&&cant_walk(s,pos)==3){
                end.push_back(pos);
            }
        }
    }
    if(end.size()!=2){
        cout<<"The amount of size is not equal to 2\n"<<endl;
        exit(-1);
    }
    //decide head, tail
    if(s.cell[end[0].r][end[0].c]>s.cell[end[1].r][end[1].c]){
        s.head = end[1];
        s.tail = end[0];
    }else{
        s.head = end[0];
        s.tail = end[1];
    }
}

void print_snake(const CharGrid &s){
    Position cur {s.head};
    vector<vector<bool>> walk (N , vector<bool> (N,0));
    const vector<Position> dir {{0,1},{0,-1},{1,0},{-1,0}};
    while(cur.r!=s.tail.r||cur.c!=s.tail.c){
        cout<<s.cell[cur.r][cur.c];
        walk[cur.r][cur.c] = true;
        for(auto d : dir){
            if(in_square_grid(cur.r+d.r,cur.c+d.c,s.size)&&(s.cell[cur.r+d.r][cur.c+d.c]!='0'&&!walk[cur.r+d.r][cur.c+d.c])){
                cur.r += d.r;
                cur.c += d.c;
                break;
            }
        }
    }
    cout<<s.cell[s.tail.r][s.tail.c];
}