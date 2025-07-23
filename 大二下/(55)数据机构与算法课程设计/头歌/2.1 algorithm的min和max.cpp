#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
// 主要代码:对单元数据类型没有限制
using namespace std;

int main(int argc, const char * argv[]) {


    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int a,b;
    double c,d;
    char e,f;
    string g,h;
    cin>>a>>b;
    cin>>c>>d;
    cin>>e>>f;
    cin>>g>>h;
    cout<<"min("<<a<<","<<b<<")=="<<min(a,b)<<endl;
    cout<<"max("<<a<<","<<b<<")=="<<max(a,b)<<endl;
    cout<<"min("<<c<<","<<d<<")=="<<min(c,d)<<endl;
    cout<<"max("<<c<<","<<d<<")=="<<max(c,d)<<endl;
    cout<<"min("<<e<<","<<f<<")=="<<min(e,f)<<endl;
    cout<<"max("<<e<<","<<f<<")=="<<max(e,f)<<endl;
    cout<<"min("<<g<<","<<h<<")=="<<min(g,h)<<endl;
    cout<<"max("<<g<<","<<h<<")=="<<max(g,h)<<endl;
    /********** End **********/

    return 0;
}
