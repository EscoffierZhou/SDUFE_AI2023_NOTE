#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    // 请在这里补充代码，完成本关任务
    /********* Begin *********/
    // 1.创建一个空的集合st，数据类型为char
    set<char>st;

    // 2.读取和处理数据：一行英文句子，长度不超过100
    string s;
    getline(cin, s);
    for(char c:s){
        if (isalpha(c)) {
            st.insert(c);
        }

    }

    // 3.遍历集合st，并按指定要求输出
    cout << "print set: "<<st.size() <<endl;
    bool is_first = true;
    for(char elem:st){
        if (!is_first) {
            cout << " ";
        }
        cout << elem;
        is_first = false;
    }
    cout<<endl;
    // 4.清空集合
    st.clear();
    /********* End *********/
    printf("%d\n", int(st.size()));

    return 0;
}
