/*************************************************************
    date: April 2009
    copyright: Zhu En
    DO NOT distribute this code.
**************************************************************/
#include <string>
#include <cstring>
int FindSubStr(char* t, char* p)
/*
从字符串t查找子字符串p。
字符串以数值结尾，例如p="str",那么p[0]='s',p[1]='t',p[2]='r',p[3]=0。
采用朴素的匹配算法。
返回子字符串第一次出现的位置,例如t="string ring",p="ring"，则返回2。
若没有找到，则返回-1。
*/
{
    // 请在此添加代码，补全函数FindSubStr
    /********** Begin *********/
    int tLen = strlen(t);
    int pLen = strlen(p);
    int i,j;
    if (pLen == 0) {
        return 0;
    }

    if (tLen == 0 || tLen < pLen) {
        return -1;
    }

    for (i = 0; i <= tLen - pLen; ++i) {
        for (j = 0; j < pLen; ++j) {
            if (t[i + j] != p[j]) {
                break;
            }
        }
        if (j == pLen) {
            return i;
        }
    }
    return -1;
    /********** End **********/
}
