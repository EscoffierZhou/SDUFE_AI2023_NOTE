//BF��Brute-Force���㷨��KMP(Knuth,Morris,Pratt)�㷨
// �����ַ���ƥ���㷨��������һ���ı����в��Ҹ�����ģʽ����
/*BF�㷨���ַ�����һ���ӵ�һ��Ԫ�ؿ�ʼ��
	BF�㷨��һ�ּ�ֱ�۵��ַ���ƥ���㷨��Ҳ��Ϊ����ƥ���㷨��
	���Ļ���˼���Ǵ��ı�������ʼλ�ÿ�ʼ������ַ�����ģʽ�����бȽϣ�������ֲ�ƥ����ַ�����ģʽ������ƶ�һλ�������ı������бȽϡ�
	���ƥ��ɹ����ͼ����Ƚ���һ���ַ������ƥ��ʧ�ܣ���ģʽ�����»ص���ʼλ�ã������ı�����һ���ַ����бȽϡ�
	BF�㷨��ʱ�临�Ӷ�ΪO(m*n)������m��ģʽ���ĳ��ȣ�n���ı����ĳ��ȡ�
*/
/*KMP�㷨��
	KMP�㷨��һ�ָĽ����ַ���ƥ���㷨��ͨ������ģʽ���е���Ϣ�����ⲻ��Ҫ�ıȽϲ��������ƥ��Ч�ʡ�
	���ĺ���˼���������Ѿ�ƥ����Ĳ����ַ�����Ϣ����ģʽ�������ƶ������ٵ�λ����������һЩ������ƥ���λ�á�
	KMP�㷨ͨ������һ������ƥ���Partial Match Table�����PMT��next���飩����¼ģʽ����ÿ��λ�õ������ǰ׺��׺���ȣ��Ӷ�ȷ��ģʽ�����ƶ�λ�á�
	�����ֲ�ƥ����ַ�ʱ�����ݲ���ƥ����е���Ϣ����ģʽ�������ƶ�һ����λ������������ƥ�䡣
	KMP�㷨��ʱ�临�Ӷ�ΪO(m+n)������m��ģʽ���ĳ��ȣ�n���ı����ĳ��ȡ�
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


//������KMP�㷨�Ĵ���ʵ�֣�
//����˼·���ǣ�
//> 1.  ģʽ����ǰ��׺ʶ��
//  >   1.   ָ��pattern��Ӧ��������ָ��i��j����ʼλ��i��j��ǰ��
//  >   2.   ������ָ���Ӧ��Ԫ�ؽ��бȽϲ����з�֧����
//      >    A.���i��ӦԪ�غ�j��ӦԪ����ͬ
//           >      A.���²���ƥ��ֵΪ j+=1��Ȼ���ƶ� i �� j ָ��
//      >    B.���i��ӦԪ�غ�j��ӦԪ�ز���ͬ
//           >      B.����j��λ��Ϊ��֪ƥ����ǰһλ��Ҳ���ǻ�������һ״̬+1����ʵ����ǰ����1��
//      >    C.�������Ӧ����
//           >      C.�˴���ƥ��ֵΪ0��i�����λ
//> 2.  ���ַ�����ģʽ����ƥ��
/*  �ݹ�ʵ�֣�
    while(���������ַ���)
    if�����ģʽ���Ѿ�ȫ��ƥ�䣩{
        // �򷵻�ƥ�����ʼλ��
    }
    if(�����Ѿ�������ϵ���δ�ҵ�ƥ��){
        //�򷵻�-1
    }
    if(�����ǰ�ַ�ƥ��){
        //�����ƥ����һ���ַ�
    }else{//�����ǰ�ַ���ƥ��
          if(ƥ������ֵ��Ϊ0){
                // ���ݲ���ƥ������ģʽ����λ�ã�����ƥ��
          }else{
                // ��������ָ�������ƶ�һλ������ƥ��
          }
    }


*/
#include <iostream>
#include <cstring>

// ��������ƥ���
void build_partial_match_table(const char* pattern, int*& table, int pattern_length) {
    // ��ʼ������ָ�� i �� j
    int i = 1, j = 0;

    // ���õ�һ��Ԫ��Ϊ0
    table[0] = 0;

    // �ӵڶ����ַ���ʼ����ģʽ�������㲿��ƥ���
    while (i < pattern_length) {
        // �����ǰ�ַ���ǰһ���ַ�ƥ��
        if (pattern[i] == pattern[j]) {
            // ���²���ƥ��ֵΪ j+1��Ȼ���ƶ� i �� j ָ��
            table[i] = j + 1;
            i++;
            j++;
        }
        else {
            // �����ǰ�ַ���ƥ��
            if (j != 0) {
                // ��� j ��Ϊ0�����ݲ���ƥ������ j ��λ��
                j = table[j - 1];
            }
            else {
                // ��� j �Ѿ�Ϊ0��˵��֮ǰû��ƥ���ǰ׺��������ƥ��ֵ��Ϊ0
                table[i] = 0;
                i++;
            }
        }
    }
}

// �������в���ģʽ������ʼλ�ã��ݹ�ʵ�֣�
int kmp_search(const char* text, const char* pattern, int* table, int text_length, int pattern_length, int text_index, int pattern_index) {
    // ���ģʽ���Ѿ�ȫ��ƥ�䣬�򷵻�ƥ�����ʼλ��
    if (pattern_index == pattern_length) {
        return text_index - pattern_length;
    }

    // ��������Ѿ�������ϵ���δ�ҵ�ƥ�䣬�򷵻�-1
    if (text_index == text_length) {
        return -1;
    }

    // �����ǰ�ַ�ƥ�䣬�����ƥ����һ���ַ�
    if (text[text_index] == pattern[pattern_index]) {
        return kmp_search(text, pattern, table, text_length, pattern_length, text_index + 1, pattern_index + 1);
    }
    else {
        // �����ǰ�ַ���ƥ��
        if (pattern_index != 0) {
            // ���ݲ���ƥ������ģʽ����λ�ã�����ƥ��
            return kmp_search(text, pattern, table, text_length, pattern_length, text_index, table[pattern_index - 1]);
        }
        else {
            // ���ģʽ���Ѿ����˵���ʼλ�ã���������ָ�������ƶ�һλ������ƥ��
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

    // ��������ƥ���
    build_partial_match_table(pattern, table, pattern_length);

    // �������в���ģʽ������ʼλ��
    int match_index = kmp_search(text, pattern, table, text_length, pattern_length, 0, 0);

    // ���ƥ����
    if (match_index != -1) {
        std::cout << "Pattern found at index: " << match_index << std::endl;
    }
    else {
        std::cout << "Pattern not found." << std::endl;
    }

    delete[] table;

    return 0;
}
