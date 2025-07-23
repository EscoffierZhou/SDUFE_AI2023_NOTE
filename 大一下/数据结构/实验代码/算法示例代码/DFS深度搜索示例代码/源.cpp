/*void dfs (Parameters){
	Parameter(inside);
	if(Statement1){
		return/cnt/comment;
	}else{
//Statement1:	for(int i=Init;i<=possible expansion;i++){
					if(Undetected(i)){
						Operation to the Para;
						dfs(dep+1,Para);
					}
				}
//Statement2:	Possibility1=Para2;
				dfs(dep+1,Para2);
				Possibility=Para2;//traceback artificailly.
	}
}
*/

#include<iostream>  
#include<vector>
using namespace std;

bool book[10];//标记是否拓展
int a[100];//
int n;

//先看一个简单的把 1∼n 这 n 个整数排成一行后随机打乱顺序，输出所有可能的次序。
void Permutation1(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!book[i]) {//对于还没有搜索完的元素
            book[i] = true;
            a[u] = i;
            Permutation1(u + 1);
            book[i] = false;
        }
    }
}

int Permutation1_main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        book[i] = false;
    }
    Permutation1(0);
    return 0;
}


// DFS排序函数
void dfsSort(int base, int digits, vector<int>& permutation, vector<bool>& used) {
    // 终止条件：当排列长度达到位数时，输出当前排列
    if (permutation.size() == digits) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // 遍历所有可能的数字
    for (int i = 0; i < base; i++) {
        // 如果当前数字未被使用，将其添加到排列中，并标记为已使用
        if (!used[i]) {
            permutation.push_back(i);
            used[i] = true;

            // 递归调用DFS排序函数，生成下一个数字的排列
            dfsSort(base, digits, permutation, used);

            // 回溯：将当前数字从排列中移除，并标记为未使用
            used[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    int base, digits;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the number of digits: ";
    cin >> digits;

    vector<int> permutation;
    vector<bool> used(base, false);

    cout << "All possible permutations: " << endl;
    dfsSort(base, digits, permutation, used);

    return 0;
}