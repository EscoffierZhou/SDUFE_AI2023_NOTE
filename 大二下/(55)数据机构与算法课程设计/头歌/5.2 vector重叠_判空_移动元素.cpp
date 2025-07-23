#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 1.引用描述
// 2.分行输入cin.peek()(但是又不需要了)
/*
 while(cin>>temp){
            row.push_back(temp);
            if (cin.peek() == '\n') {
                cin.ignore();
                break;
            }
        }
 */
// 3.向量插入
void movement(vector<vector<int>>& temp,int a,int b){
    if (a >= 0 &&
        a < temp.size() &&
        b >= 0 &&
        b < temp.size() &&
        !temp[a].empty()
            ) { // 增加边界和非空检查
        int pos = temp[a].back();
        temp[a].pop_back();
        temp[b].push_back(pos);
    }
}
int main(){
    int n,bag,bags,move;cin>>n;
    vector<vector<int>>matrix(n);//设置大小
    for(int i=0;i<n;i++){
        cin>>bags;
        matrix.push_back(vector<int>());
        for(int j=0;j<bags;j++){
            cin >> bag;
            matrix[i].push_back(bag);
        }
    }
    cin>>move;
    for(int j=0;j<move;j++){
        int a,b;
        string s;
        cin>>s>>a>>b;
        movement(matrix,a,b);
    }
    for(int i=0;i<n;i++){
        int sum = 0;
        cout<<i<<" ";
        bool result = matrix[i].empty();
        if(result == 1){
            cout<<"0 0"<<endl;
            continue;
        }
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
            sum+=matrix[i][j];
        }
        cout<<sum<<endl;
    }
    return 0;
}
// 下面是头歌代码
/*
//  main.cpp
//  step2
//
//  Created by ljpc on 2018/7/23.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {


    // 请在这里补充代码，完成本关任务
    int n,bag,bags,move;cin>>n;
    vector<vector<int>>matrix(n);//设置大小
    for(int i=0;i<n;i++){
        cin>>bags;
        matrix.push_back(vector<int>());
        for(int j=0;j<bags;j++){
            cin >> bag;
            matrix[i].push_back(bag);
        }
    }
    cin>>move;
    for(int j=0;j<move;j++){
        int a,b;
        string s;
        cin>>s>>a>>b;
        if (a >= 0 &&a < matrix.size() &&b >= 0 &&b < matrix.size() &&!matrix[a].empty()) {
            int pos = matrix[a].back();
            matrix[a].pop_back();
            matrix[b].push_back(pos);
        }
    }
    for(int i=0;i<n;i++){
        int sum = 0;
        cout<<i<<" ";
        bool result = matrix[i].empty();
        if(result == 1){
            cout<<"0 0"<<endl;
            continue;
        }
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
            sum+=matrix[i][j];
        }
        cout<<sum<<endl;
    }
    return 0;
}
*/