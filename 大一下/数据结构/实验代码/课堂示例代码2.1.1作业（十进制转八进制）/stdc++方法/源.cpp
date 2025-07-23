#include<iostream>
#include<stack>
typedef int s_Elemtype;
using namespace std;
int main() {
	stack<s_Elemtype>stk;
	cout << "Insert the number converted" << endl;
	int x,y=1,cnt=0; cin >> x;
	while (y!=0) {
		y = x % 8;
		stk.push(y);
		x /= 8;
		cnt++;
	}
	cout << "=========================" << endl;
	cout << "The answr is:" << endl;
	stk.pop();
	for (int i = 1; i < cnt; i++) {
		int ans= stk.top();
		cout << ans;
		stk.pop();
	}
}