#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {


    // 请在这里补充代码，完成本关任务
    /********* Begin *********/
    // 1.构建整型向量vec
    vector<int>vec;
    // 2.读取数据：序列个数n，以及n个整数并存入向量vec
    int n;cin>>n;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        vec.push_back(num);
    }
    // 3.删除向量vec中的重复元素
    // 先sort然后就很好删了,删除相邻重复元素 (vector 必须已排序)
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    // 4.使用Algorithm模板函数sort对vec排序：从小到大
    // 5.遍历向量vec并输出，元素中间空格隔开，末尾加换行符'\n'
    for(int i=0;i<vec.size();i++){
        cout<<vec[i];
        if(i<vec.size()-1){
            cout<<" ";
        }
    }
    cout<<endl;
    // 6.清空向量vec
    vec.clear();

    /********* End *********/
    printf("%d\n", int(vec.size()));

    return 0;
}
