#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {

    int n, S;
    cin >> n >> S;
    queue<int> que;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tot = 0, minLen = 1000;
    // 定义两个整型变量：tot 用于记录当前窗口内元素的和，minLen 用于记录找到的满足条件的最短子数组的长度。
    // minLen 初始化为 1000，这是一个足够大的数，用来作为初始的最大长度，方便后续比较和更新最小值。
    // 如果最终 minLen 仍然是 1000，表示没有找到符合条件的子数组。

    for (int i = 0; i < n; i++) { // 外层循环遍历数组 arr 的每个元素，将每个元素尝试加入滑动窗口
        // 1.右侧扩张
        que.push(arr[i]); // 将当前元素 arr[i] 加入队列（滑动窗口的右端扩张）
        tot += arr[i];  // 更新当前窗口元素的和 tot
        // 2.左侧收缩
        while (tot >= S) { // 内层循环，当窗口内元素和 tot 大于等于目标值 S 时，开始收缩窗口左端，寻找更短的符合条件的子数组
            minLen = min(minLen, (int)que.size()); // 更新 minLen 为当前窗口长度和之前 minLen 的较小值。que.size() 获取当前队列的长度，即当前窗口的长度。
            tot -= que.front(); // 从总和 tot 中减去队列头部元素的值，因为要准备将队头元素移除窗口
            que.pop();      // 移除队列头部元素，窗口左端收缩
        }
    }

    cout << (minLen == 1000 ? 0 : minLen) << endl;
    return 0;
}