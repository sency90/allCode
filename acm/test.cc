/*
# Copyright (C) 2016 Lian Yang (plzrun)
# This file is MatrixMaker
#
# MatrixMaker is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# MatrixMaker is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
#
# web: sency90.tistory.com
# github: github.com/sency90 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;
map<string, vector<int> > mp;
vector<vector<char> > arr;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string filepath;
    cout << "Please input file name (Path):"<<"\n";
    cin >> filepath;
    freopen(filepath.c_str(), "r", stdin);
    string token, str;
    int lineNum=0;
    bool isIn=false;
    while(getline(cin,str)) {
        isIn=true;
        istringstream iss(str);
        while(getline(iss,token,',')) {
            int sz=token.size();
            for(int i=sz-1; i>0; i--) {
                if(token[i]=='\r'||token[i]==' '||token[i]=='\t') sz--;
                else break;
            }
            if(sz==0) continue;
            else mp[token.substr(0,sz)].push_back(lineNum);
        }
        lineNum++; //row no.
    }
    if(!isIn) {
        cout << "Input file name is not vaild.\n";
        return 0;
    }

    freopen("./output.txt", "w", stdout);
    arr.resize(lineNum, vector<char>((int)mp.size(),'0'));
    int idx=0; //column index
    cout << "No, ";
    for(auto &p: mp) {
        idx++;
        cout << p.first << ", ";
        for(auto &q: p.second) arr[q][idx]='1';
    } cout << "\n";

    for(int i=0; i<lineNum; i++) {
        cout << i+1 << ", ";
        for(int j=0; j<mp.size(); j++) {
            cout << arr[i][j] << ", ";
        } cout << "\n";
    }

    freopen("/dev/tty", "w", stdout);
    cout << "Number of rows (transactions): " << lineNum <<"\n";
    cout << "Number of columns (items): " << mp.size() <<"\n";
    return 0;
}
