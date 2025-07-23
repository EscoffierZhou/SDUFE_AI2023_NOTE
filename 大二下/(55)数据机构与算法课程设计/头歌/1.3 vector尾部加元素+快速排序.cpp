#include <iostream>
#include <vector>
#include <algorithm>
// 关键代码:nums.push_back(num);
//        sort(nums.begin(),nums.end());
//        sort(nums.begin(),nums.begin()+n); // 不标准
using namespace std;

int main(int argc, const char * argv[]) {

    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());
    for (int num : nums) {
        cout << num << " ";
    }


    /********** End **********/

    return 0;
}
