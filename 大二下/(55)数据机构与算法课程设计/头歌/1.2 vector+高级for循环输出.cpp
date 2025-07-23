#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> nums = {a,b,c};
    sort(nums.begin(),nums.end());
    for (int num : nums) {
        std::cout << num << " ";
    }

    /********** End **********/

    return 0;
}
