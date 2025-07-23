#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    set<int>st;
    set<int>::iterator it;
    int n,m,num;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>num;
        if(s=="insert"){
            it = st.find(num);
            if (it == st.end()) {
                st.insert(num);
            } else {
                cout<<num<<" in set"<<endl;
            }
        }else if(s=="erase"){
            it = st.find(num);
            if (it == st.end()) {
                cout<<num<<" not in set"<<endl;
            } else {
                st.erase(num);
            }

        }
    }
    cout<<"print set: "<<st.size()<<endl;

    std::set<int>::iterator last_it;
    last_it = prev(st.end());// 迭代器向前移一位
    for (it = st.begin(); it != st.end(); ++it) {
        cout << *it;
        if (it != last_it) {
            cout << " ";
        }
    }

    cout<<endl;
    cin>>m;
    for(int j=0;j<m;j++){
        cin>>s>>num;
        it = st.find(num);
        if(it == st.end()) {
            cout<<"find "<<num<<" not in set"<<endl;
        }else {
            cout<<"find "<<num<<" in set"<<endl;
        }
    }
    st.clear();
    printf("%d\n", int(st.size()));
}
