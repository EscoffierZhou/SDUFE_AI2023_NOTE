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
    map<string,int>mp;
    int n,m,q,grade;

    cin>>n;
    string s;//垃圾s
    string name;
    for(int i=0;i<n;i++){
        cin>>s>>name>>grade;
        if(mp.count(name)){
            cout<<name<<" has been recorded"<<endl;
        }else{
            mp[name]=grade;
        }
    }
    cin>>m;
    for(int j=0;j<m;j++){
        cin>>s>>name;
        if(!mp.count(name)){
            cout<<name<<" has not been recorded"<<endl;
        }else{
            mp.erase(name);
        }
    }
    cout<<"print map: "<<mp.size()<<endl;
    map<string,int>::iterator it = mp.begin();
    for(it;it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cin>>q;
    for(int k=0;k<q;k++){
        cin>>s>>name;
        if (mp.count(name)) {
            cout << name << " score " << mp[name] << endl;
        } else {
            cout << name << " cannot been found" << endl;
        }
    }
    mp.clear();
    printf("%d\n", int(mp.size()));
    return 0;
}
