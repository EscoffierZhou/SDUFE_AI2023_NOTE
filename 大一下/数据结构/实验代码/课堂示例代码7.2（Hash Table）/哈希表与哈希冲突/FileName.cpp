#include<iostream>
#include<string>
#define MAX_SIZE 100
#define CONCATENATE 10
#define OK 1
typedef int Status;
int hash(int key) {
	//此处写哈希表达公式（此处是求余公式）
	return key % 5;
}

//为了避免哈希冲突，使用哈希链表会有奇效
typedef struct node {
	int key;
	char* name[20];
	struct node* next;
}node,*list;
//typedef Node node, * list;
list hash_table[MAX_SIZE];//初始化哈希表

Status Hash_Search(int key) {
	int hash_code = hash(key);
	node* p = hash_table[hash_code];//给一个空指针
	while (p != NULL) {
		if (p->key == key) {	//如果搜索到了
			return p->key;
		}
		p = p->next;
	}
	return OK;
}

Status Hash_Insert(int key,int value){
	int hash_code = hash(key);
	node* new_node = (node*)malloc(sizeof(node)+CONCATENATE);
	new_node->key = key;
	new_node->next = NULL;
	node* p = hash_table[hash_code];
	if (p == NULL) {
		hash_table[hash_code] = new_node;
		return;
	}
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = new_node;
}

Status Hash_Delete(int key) {
	int hash_code = hash(key);
	node* p = hash_table[hash_code];
	if (p == NULL) {
		return OK;
	}
	if (p->key == key) {
		hash_table[hash_code] = p->next;
		free(p);	// 通过释放
		return OK;
	}
	node* prev = p;
	p = p->next;
	while (p != NULL) {	// 重新遍历哈希表
		if (p->key == key) {
			prev->next = p->next;// 跳过被删除元素
			free(p);
			return OK;
		}
		prev = p;
		p = p->next;
	}
}
//完成
