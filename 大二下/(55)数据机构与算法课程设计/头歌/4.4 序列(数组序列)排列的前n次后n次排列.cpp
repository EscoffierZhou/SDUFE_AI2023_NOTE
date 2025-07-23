#include<iostream>
#include<algorithm>
using namespace std;


void Next_Permutation(int *arr, int n, int m)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    while(m!=0){
        for(int i=0;i<n;i++){
            cout<<arr[i];
            if(i<n-1){
                cout<<" ";
            }
        }
        cout<<endl;
        next_permutation(arr,arr+n);
        m--;
    }
    /********** End **********/
}

void Prev_Permutation(int *arr, int n, int m)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    while(m!=0){
        for(int i=0;i<n;i++){
            cout<<arr[i];
            if(i<n-1){
                cout<<" ";
            }
        }
        cout<<endl;
        prev_permutation(arr,arr+n);
        m--;
    }
    /********** End **********/
}
/*
Next_Permutation:
1 2 3
1 3 2
2 1 3
2 3 1
Prev_Permutation:
3 2 1
3 1 2
2 3 1
2 1 3
 */