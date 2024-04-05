#include <iostream>
#include <string>
using namespace std;

#define N 50

struct Square{
    string cell[N];
    int n;
};

void init_Square(Square& s){
    cin>>s.n;
    for(int i=0;i<s.n;i++){
        cin>>s.cell[i];
    }
}

struct Position{
    int r;
    int c;
};

bool in_square_grid(const int r, const int c, const int n){
    return r>=0&&r<n&&c>=0&&c<n;
}

int count_zero(const Square s, const Position pos){
    const Position dir[4] {{0,1},{0,-1},{1,0},{-1,0}};
    int ans {0};
    for(auto d : dir){
        if(!in_square_grid(pos.r+d.r,pos.c+d.c,s.n)||s.cell[pos.r+d.r][pos.c+d.c]=='0'){
            ans++;
        }
    }
    return ans;
}

void find_head_tail(const Square s, Position &head, Position &tail){
    Position end[2];
    int count {0};
    //find end
    for(int i=0;i<s.n;i++){
        for(int j=0;j<s.n;j++){
            Position pos {i,j};
            if(s.cell[i][j]!='0'&&count_zero(s,pos)==3){
                end[count].r = pos.r;
                end[count].c = pos.c;
                count++;
            }
        }
    }
    //decide head, tail
    if(s.cell[end[0].r][end[0].c]>s.cell[end[1].r][end[1].c]){
        head.r = end[1].r;
        head.c = end[1].c;
        tail.r = end[0].r;
        tail.c = end[0].c;
    }else{
        head.r = end[0].r;
        head.c = end[0].c;
        tail.r = end[1].r;
        tail.c = end[1].c;
    }
}

void go(const Square s, const Position head, const Position tail){
    Position cur {head.r,head.c};
    bool walk[N][N] {{0}};
    const Position dir[4] {{0,1},{0,-1},{1,0},{-1,0}};
    while(cur.r!=tail.r||cur.c!=tail.c){
        cout<<s.cell[cur.r][cur.c];
        walk[cur.r][cur.c] = true;
        for(auto d : dir){
            if(in_square_grid(cur.r+d.r,cur.c+d.c,s.n)&&(s.cell[cur.r+d.r][cur.c+d.c]!='0'&&!walk[cur.r+d.r][cur.c+d.c])){
                cur.r += d.r;
                cur.c += d.c;
                break;
            }
        }
    }
    cout<<s.cell[tail.r][tail.c];
}

int main(){
    Square s;
    init_Square(s);
    Position head, tail;
    find_head_tail(s,head,tail);
    go(s,head,tail);
    return 0;
}