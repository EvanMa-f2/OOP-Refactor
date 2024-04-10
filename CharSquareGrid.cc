#include <iostream>
using namespace std;
#include "CharSquareGrid.h"
#define N 50

CharSquareGrid::CharSquareGrid(void): walk (N,vector<bool> (N,0)){
}

bool CharSquareGrid::in(const Position &pos) const{
    auto r {pos.getRow()};
    auto c {pos.getCol()};
    return r>=0 && r<size && 
        c>=0 && c<size;
}

char CharSquareGrid::getCell(const Position &pos) const{
    auto r {pos.getRow()};
    auto c {pos.getCol()};
    if(in(pos)){
        return cell[r][c];
    }else{
        printf("position not in the grid while calling getCell\n");
        exit(-1);
    }
}

bool CharSquareGrid::walked(const Position &pos) const{
    auto r {pos.getRow()};
    auto c {pos.getCol()};
    if(in(pos)){
        return walk[r][c];
    }else{
        printf("position not in the grid while calling walked\n");
        exit(-1);
    }
}

void CharSquareGrid::walk_through(const Position &pos){
    auto r {pos.getRow()};
    auto c {pos.getCol()};
    if(in(pos)){
        walk[r][c] = true;
    }else{
        printf("position not in the grid while calling walk_through\n");
        exit(-1);
    }
}

int CharSquareGrid::neighbor_cant_walk(const Position &pos) const{
    const vector<Position> dir {{0,1},{0,-1},{1,0},{-1,0}};
    int ans {0};
    auto r {pos.getRow()};
    auto c {pos.getCol()};
    for(auto &d : dir){
        const auto dr {d.getRow()};
        const auto dc {d.getCol()};
        if(!in(Position(r+dr,c+dc))||getCell(Position(r+dr,c+dc))=='0'){
            ans++;
        }
    }
    return ans;
}

void CharSquareGrid::set_Grid(void){
    int n;
    scanf("%d",&n);
    size = n;
    for(int i=0;i<size;i++){
        string str;
        cin>>str;
        cell.push_back(str);
    }
}

void CharSquareGrid::find_head_tail(void){
    vector<Position> end;
    //find end
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(getCell(Position(i,j))!='0'&&neighbor_cant_walk(Position(i,j))==3){
                end.push_back(Position(i,j));
            }
        }
    }
    if(end.size()!=2){
        cout<<"The amount of end is not equal to 2"<<endl;
        cout<<end.size()<<endl;
        exit(-1);
    }
    //decide head, tail
    if(getCell(Position(end[0]))>getCell(Position(end[1]))){
        head.setRow(end[1].getRow());
        head.setCol(end[1].getCol());
        tail.setRow(end[0].getRow());
        tail.setCol(end[0].getCol());
    }else{
        head.setRow(end[0].getRow());
        head.setCol(end[0].getCol());
        tail.setRow(end[1].getRow());
        tail.setCol(end[1].getCol());
    }
}

void CharSquareGrid::print_snake(void){
    Position cur {head};
    const vector<Position> dir {{0,1},{0,-1},{1,0},{-1,0}};
    while(cur.getRow()!=tail.getRow()||cur.getCol()!=tail.getCol()){
        cout<<getCell(cur);
        walk_through(cur);
        for(auto &d : dir){
            const auto dr {d.getRow()};
            const auto dc {d.getCol()};
            const auto r {cur.getRow()};
            const auto c {cur.getCol()};
            if(in(Position(r+dr,c+dc))&&getCell(Position(r+dr,c+dc))!='0'&&!walked(Position(r+dr,c+dc))){
                cur.setRow(r+dr);
                cur.setCol(c+dc);
                break;
            }
        }
    }
    cout<<getCell(tail);
}