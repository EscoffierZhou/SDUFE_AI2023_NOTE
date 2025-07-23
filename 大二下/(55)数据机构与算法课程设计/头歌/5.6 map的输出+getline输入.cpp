#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// 1.定义方式:map<int,int>mp;
// 2.插入方法:插入有序对
//  pair<type1,type2>pair_name;
//  pair_name.first = content;
//  pair_name.second = content;
//  mp.insert(pair_name);
// 3.删除方法:通过键进行删除/通过迭代器删除
//  mp.erase(key) // key是定义的时候决定的
// ========================================
//  map<char, int>::iterator it=mp.begin();
//  mp.erase(it);
// 4.查询单个关键键
//  map<char, int>iterator it = mp.find('a');
//  if(it==mp.end()){}\\cannot found
//  else cout<<it->first<<" "<<it->second; // first为键，second为值
// 5.遍历多个关键键
// for(map<char, int>::iterator it=mp.begin();it!=mp.end();it++)
//    cout<<it->first<<" "<<it->second;
// 6.清空
// mp.clear()
int main(int argc, const char * argv[]) {
    map<char,int>mp;
    string s;
    getline(cin,s);
    for(char c: s){
        if(isalpha(c)) {
            mp[c]++;
        }
    }
    cout<<"print map: "<<mp.size()<<endl;
    // 本身已经是按照 ASCII 值从小到大排序存储的
    for(map<char, int>::iterator it=mp.begin();it!=mp.end();it++)
        cout<<it->first<<" "<<it->second<<endl;

    mp.clear();
    printf("%d\n", int(mp.size()));
    return 0;
}
