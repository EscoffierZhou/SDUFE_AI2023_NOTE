#include <iostream>
#include <cstring>
#define MAX_SIZE 100
#define CHUNK_SIZE 20
#define ERROR -1
#define OK 1

typedef struct {//����Sstring���ַ����飩�ŵ㣺���ַ�������ά��
    char ch[MAX_SIZE + 1];
    int length;
} Sstring;

typedef struct chunk {//����chunkָ��ṹ�� �ŵ㣺chunk�����ṹ�����󣬳��ַ�������
    char chunk[CHUNK_SIZE];
    struct chunk* next;
} chunk;

typedef struct {//����Lstring
    chunk* head, * tail;//����˫ָ��ָ��chunk
    int length;//���峤�ȣ������ɸ�chunk�ṹ��ĳ���
} LString;

void Init_Sstring(Sstring& str, const char* input) {//����Sstring
    int len = strlen(input);//�������볤�ȿ��ٿռ�
    if (len > MAX_SIZE)
        len = MAX_SIZE;
    strncpy(str.ch, input, len);
    str.ch[len] = '\0';//strncpy�������ѣ���ҪNULL��β
    str.length = len;//��¼Sstring�ĳ���len
}

void modifySString(Sstring& str, const char* newStr) {//�޸�Sstring��ֱ��copy���ǣ�
    int len = strlen(newStr);
    if (len > MAX_SIZE)
        len = MAX_SIZE;
    strncpy(str.ch, newStr, len);
    str.ch[len] = '\0';
    str.length = len;
}

void deleteSString(Sstring& str) {//���ó��Ⱥ���λԪ�ؼ�������
    str.length = 0;
    str.ch[0] = '\0';
}

int findSubstringSString(const Sstring& str, const char* subStr) {//Ѱ�����ַ���
    int subLen = strlen(subStr);//���Ȼ��Ƕ��峤�ȱ��ڲ���
    int strLen = str.length;

    for (int i = 0; i <= strLen - subLen; ++i) {//���ַ������Ҵ�0��len-substr�ĳ���
        int j;
        for (j = 0; j < subLen; ++j) {//����substr�ĳ�����
            if (str.ch[i + j] != subStr[j])//���������break
                break;
        }
        if (j == subLen)
            return i;
    }
    return ERROR;
}
//������Lstring�Ĵ��벿��

void Init_Lstring(LString& lstr, const char* input) {
    // ��ʼ��Lstring
    int len = strlen(input); // ��¼�����ַ����ĳ���

    // ����ͷ���
    lstr.head = new chunk;
    lstr.tail = lstr.head;
    lstr.length = len;
//�ָ��ַ���������װ������
    int remaining = len;
    const char* ptr = input;//�޸�Ϊ��������Ķ�

    while (remaining > 0) {
        int chunkLen = remaining > CHUNK_SIZE ? CHUNK_SIZE : remaining;//���ճ���Ϊchunklen���зֿ�

        strncpy(lstr.tail->chunk, ptr, chunkLen); //������Ϊ chunkLen ���ַ����� ptr ���Ƶ���ָ���Ŀ���ַ������С�
   
        lstr.tail->chunk[chunkLen] = '\0';//��strncpy���涼Ҫ�ֶ���� null ��ֹ��
        remaining -= chunkLen; //����ʣ���ַ���
        ptr += chunkLen;//����Դ�ַ���ָ���λ�á�

        if (remaining > 0) {   // �����������µĿ�
            lstr.tail->next = new chunk;
            lstr.tail = lstr.tail->next;
        }
    }
    // ����β������һ��ָ��Ϊ��
    lstr.tail->next = nullptr;
}

void modifyLString(LString& lstr, const char* newStr) {
    chunk* current = lstr.head; // ��ǰ����Ŀ�
    int len = strlen(newStr); // ���ַ����ĳ���
    lstr.length = len; // ����LString�ĳ���

    int remaining = len; // ʣ���ַ���
    const char* ptr = newStr; // Դ�ַ���ָ�룬ָ��newStr�ĳ�ʼλ��
    while (remaining > 0) {
        int chunkLen = remaining > CHUNK_SIZE ? CHUNK_SIZE : remaining; // ��ǰ��ĳ��ȣ����ΪCHUNK_SIZE
        strncpy(current->chunk, ptr, chunkLen); // ��Դ�ַ�����һ�������ݸ��Ƶ���ǰ����
        current->chunk[chunkLen] = '\0'; // �ֶ���� null ��ֹ��
        remaining -= chunkLen; // ����ʣ���ַ���
        ptr += chunkLen; // ����Դ�ַ���ָ���λ��

        if (remaining > 0) {
            if (current->next == nullptr) { // �����ǰ�����һ����Ϊ��
                current->next = new chunk; // �����µĿ�
                lstr.tail = current->next; // ���������β���
            }
            current = current->next; // �ƶ�����һ����
        }
    }
    if (current->next != nullptr) { // ���β������һ���鲻Ϊ��
        chunk* temp = current->next; // ��ʱָ��ָ��β������һ����
        current->next = nullptr; // β������һ��ָ����Ϊ��
        delete temp; // �ͷ�β������һ������ڴ�
    }
}

void deleteLString(LString& lstr) {
    chunk* current = lstr.head;
    while (current != nullptr) {
        chunk* temp = current;
        current = current->next;
        delete temp;
    }
    lstr.head = nullptr;
    lstr.tail = nullptr;
    lstr.length = 0;
}

int findSubstringLString(const LString& lstr, const char* subStr) {
    int subLen = strlen(subStr);
    chunk* current = lstr.head;
    int index = 0;

    while (current != nullptr) {
        int chunkLen = strlen(current->chunk);
        for (int i = 0; i <= chunkLen - subLen; ++i) {
            int j;
            for (j = 0; j < subLen; ++j) {
                if (current->chunk[i + j] != subStr[j])
                    break;
            }
            if (j == subLen)
                return index + i;
        }
        index += chunkLen;
        current = current->next;
    }
    return -1;
}

int main() {
    Sstring sstr;
    LString lstr;
    char input[MAX_SIZE + 1];

    std::cout << "Enter a string: ";
    std::cin.getline(input, MAX_SIZE + 1);

    Init_Sstring(sstr, input);
    Init_Lstring(lstr, input);
}
   