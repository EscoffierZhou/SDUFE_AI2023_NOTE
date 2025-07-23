//BF（Brute-Force）算法和KMP(Knuth,Morris,Pratt)算法
// 都是字符串匹配算法，用于在一个文本串中查找给定的模式串。
/*BF算法（字符串不一定从第一个元素开始）
	BF算法是一种简单直观的字符串匹配算法，也称为朴素匹配算法。
	它的基本思想是从文本串的起始位置开始，逐个字符地与模式串进行比较，如果发现不匹配的字符，则将模式串向后移动一位，再与文本串进行比较。
	如果匹配成功，就继续比较下一个字符，如果匹配失败，则将模式串重新回到起始位置，再与文本串下一个字符进行比较。
	BF算法的时间复杂度为O(m*n)，其中m是模式串的长度，n是文本串的长度。
*/
/*KMP算法：
	KMP算法是一种改进的字符串匹配算法，通过利用模式串中的信息，避免不必要的比较操作，提高匹配效率。
	它的核心思想是利用已经匹配过的部分字符的信息，将模式串向右移动尽量少的位数，以跳过一些不可能匹配的位置。
	KMP算法通过构建一个部分匹配表（Partial Match Table，简称PMT或next数组），记录模式串中每个位置的最长公共前缀后缀长度，从而确定模式串的移动位置。
	当发现不匹配的字符时，根据部分匹配表中的信息，将模式串向右移动一定的位数，继续进行匹配。
	KMP算法的时间复杂度为O(m+n)，其中m是模式串的长度，n是文本串的长度。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

#define MAX_LEN 100

typedef struct {
    char data[MAX_LEN];
    int length;
} SString;

// BF algorithm for string matching
int Index(SString S, SString T) {
    int i = 0;  // current index of S
    int j = 0;  // current index of T

    while (i < S.length && j < T.length) {
        if (S.data[i] == T.data[j]) {
            // characters match, move to the next ones
            i++;
            j++;
        }
        else {
            // characters don't match, go back to the next position in S
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == T.length) {
        // match found, return the position
        return i - j;
    }
    else {
        // match not found
        return -1;
    }
}

typedef struct LNode {
    char data;
    struct LNode* next;
} LNode, * LinkString;

// Create a linked string
void CreateLinkString(LinkString& S, char str[]) {
    int len = strlen(str);
    S = new LNode;
    LNode* p = S;
    for (int i = 0; i < len; i++) {
        LNode* newNode = new LNode;
        newNode->data = str[i];
        newNode->next = NULL;
        p->next = newNode;
        p = p->next;
    }
}

// BF algorithm for linked string matching
int Index(LinkString S, LinkString T) {
    LNode* p = S->next;  // current node of S

    while (p != NULL) {
        LNode* q = T->next;  // current node of T
        LNode* temp = p;    // temporary node for matching

        while (q != NULL && temp != NULL && q->data == temp->data) {
            q = q->next;
            temp = temp->next;
        }

        if (q == NULL) {
            // match found, return the position
            int position = 0;
            LNode* temp = S->next;
            while (temp != p) {
                position++;
                temp = temp->next;
            }
            return position;
        }

        p = p->next;
    }

    // match not found
    return -1;
}

int main() {
    SString S, T;
    strcpy(S.data, "Hello, world!");
    S.length = strlen(S.data);
    strcpy(T.data, "world");
    T.length = strlen(T.data);

    int position = Index(S, T);
    if (position != -1) {
        cout << "Pattern found at position: " << position << endl;
    }
    else {
        cout << "Pattern not found." << endl;
    }

    LinkString S_link, T_link;
    char strS[] = "Hello, world!";
    char strT[] = "world";
    CreateLinkString(S_link, strS);
    CreateLinkString(T_link, strT);

    position = Index(S_link, T_link);
    if (position != -1) {
        cout << "Pattern found at position: " << position << endl;
    }
    else {
        cout << "Pattern not found." << endl;
    }

    return 0;
}


//下面是KMP算法的代码实现：
//核心思路就是：
//> 1.  模式串的前后缀识别
//  >   1.   指针pattern对应两个两个指针i和j，初始位置i在j的前面
//  >   2.   对两个指针对应的元素进行比较并进行分支操作
//      >    A.如果i对应元素和j对应元素相同
//           >      A.更新部分匹配值为 j+=1，然后移动 i 和 j 指针
//      >    B.如果i对应元素和j对应元素不相同
//           >      B.调整j的位置为已知匹配表的前一位，也就是回退至上一状态+1，其实是向前走了1步
//      >    C.如果都对应不上
//           >      C.此处的匹配值为0，i向后移位
//> 2.  主字符串和模式串的匹配
/*  递归实现：
    while(遍历整个字符串)
    if（如果模式串已经全部匹配）{
        // 则返回匹配的起始位置
    }
    if(主串已经遍历完毕但仍未找到匹配){
        //则返回-1
    }
    if(如果当前字符匹配){
        //则继续匹配下一个字符
    }else{//如果当前字符不匹配
          if(匹配表的数值不为0){
                // 根据部分匹配表调整模式串的位置，继续匹配
          }else{
                // 将主串的指针向右移动一位，继续匹配
          }
    }


*/
#include <iostream>
#include <cstring>

// 构建部分匹配表
void build_partial_match_table(const char* pattern, int*& table, int pattern_length) {
    // 初始化两个指针 i 和 j
    int i = 1, j = 0;

    // 设置第一个元素为0
    table[0] = 0;

    // 从第二个字符开始遍历模式串，计算部分匹配表
    while (i < pattern_length) {
        // 如果当前字符与前一个字符匹配
        if (pattern[i] == pattern[j]) {
            // 更新部分匹配值为 j+1，然后移动 i 和 j 指针
            table[i] = j + 1;
            i++;
            j++;
        }
        else {
            // 如果当前字符不匹配
            if (j != 0) {
                // 如果 j 不为0，根据部分匹配表调整 j 的位置
                j = table[j - 1];
            }
            else {
                // 如果 j 已经为0，说明之前没有匹配的前缀，将部分匹配值设为0
                table[i] = 0;
                i++;
            }
        }
    }
}

// 在主串中查找模式串的起始位置（递归实现）
int kmp_search(const char* text, const char* pattern, int* table, int text_length, int pattern_length, int text_index, int pattern_index) {
    // 如果模式串已经全部匹配，则返回匹配的起始位置
    if (pattern_index == pattern_length) {
        return text_index - pattern_length;
    }

    // 如果主串已经遍历完毕但仍未找到匹配，则返回-1
    if (text_index == text_length) {
        return -1;
    }

    // 如果当前字符匹配，则继续匹配下一个字符
    if (text[text_index] == pattern[pattern_index]) {
        return kmp_search(text, pattern, table, text_length, pattern_length, text_index + 1, pattern_index + 1);
    }
    else {
        // 如果当前字符不匹配
        if (pattern_index != 0) {
            // 根据部分匹配表调整模式串的位置，继续匹配
            return kmp_search(text, pattern, table, text_length, pattern_length, text_index, table[pattern_index - 1]);
        }
        else {
            // 如果模式串已经回退到起始位置，将主串的指针向右移动一位，继续匹配
            return kmp_search(text, pattern, table, text_length, pattern_length, text_index + 1, 0);
        }
    }
}


int main() {
    const char* text = "ABABCABABABCABAB";
    const char* pattern = "CABAB";
    int text_length = std::strlen(text);
    int pattern_length = std::strlen(pattern);
    int* table = new int[pattern_length];

    // 构建部分匹配表
    build_partial_match_table(pattern, table, pattern_length);

    // 在主串中查找模式串的起始位置
    int match_index = kmp_search(text, pattern, table, text_length, pattern_length, 0, 0);

    // 输出匹配结果
    if (match_index != -1) {
        std::cout << "Pattern found at index: " << match_index << std::endl;
    }
    else {
        std::cout << "Pattern not found." << std::endl;
    }

    delete[] table;

    return 0;
}
