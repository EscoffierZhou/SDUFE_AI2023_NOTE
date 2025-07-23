//
// Created by 柊杏介 on 2025/3/6.
//
//#include <iostream>
//#include <queue>
//using namespace std;
// 优先队列具有最高级先出first in, largest out的特性
// !!!采用堆的数据结构来实现
// priority_queue<int> mypq; // 创建一个整型的优先队列，默认数值越大优先级越高
// mypq.push(num)
// mypq.top(); // 获取队首（最高优先级）元素
// mypq.pop()
//
// 自定义优先级
// 1.参数优先级法:priority_queue<int,vector<int>, greater<int> > que1; // x小的优先级高
// 2.重载括号法:
//           /*
//              struct comp{
//                  bool operator()(int x,int y){
//                      return x>y;   //重载()的方式，x小的优先级高
//                  }
//              };
//              priority_queue<int, vector<int>, comp> que2; // 从小到大的优先队列
//           */
// 3.结构体方法:
//             /*
//              struct node {
//　　                int x, y;
//　　                friend bool operator < (node a, node b) {
//　　　　                  return a.x > b.x;    //结构体类型的方式，x小的优先级高
//　　                }
//              };
//              priority_queue<node> que3;
//              */

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        pq.push(weight);
    }
    int energy = 0;
    // 小根堆直接取top加就行了
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        energy += sum;
        pq.push(sum);
    }
    cout << energy << endl;
    return 0;
}
