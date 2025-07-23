#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "kmp.h"
#include <iostream> // 为了使用 std::cout

/////////////////////////////////////////////////////

void KmpGenNext(char* p, int* next)
//生成p的next数组, next数组长度大于等于字符串p的长度加1
{
    // 请在此添加代码，补全函数KmpGenNext
    /********** Begin *********/
    int pLen = strlen(p);
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < pLen; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = next[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        next[i] = j;
    }
    /********** End     *********/
}


int KmpFindSubWithNext(char* t, char* p, int* next)
//从t中查找子串p的第一次出现的位置
//若找到，返回出现的位置，否则返回-1
{
    int i=0, j=0;
    int tLen = strlen(t);
    int pLen = strlen(p);
    while(i < pLen && j < tLen)   {
        if(p[i]==t[j])  {
            i++;
            j++;
        }
        else if (i > 0) { //  仅当 i > 0 时，才使用 next 数组回退
            i = next[i-1]; //  使用 next[i-1] 进行回退 (next 数组为 0-based)
        }
        else  { // i == 0 且 p[0] != t[j] 时， 仅需将 j++， 模式串相对于文本串右移一位
            j++;
        }
    }
    if(i==pLen) return j-i; //found
    else return -1;  //not found
}


int main() {
    char text[] = "stringabcedf1stringabcdef2stringabcdef3stringabcdef4stringabcdef5stringabcdef6stringabcdef7";
    char pattern[] = "stringabcdef7";
    int next[strlen(pattern)]; // next 数组的长度要与模式串长度匹配
    KmpGenNext(pattern, next);
    int location = KmpFindSubWithNext(text, pattern, next);

    if (location != -1) {
        printf("Location: %d\n", location);
    } else {
        printf("Not found.\n");
    }

    return 0;
}