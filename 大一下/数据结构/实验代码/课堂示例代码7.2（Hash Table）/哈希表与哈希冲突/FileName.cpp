#include<iostream>
#include<string>
#define MAX_SIZE 100
#define CONCATENATE 10
#define OK 1
typedef int Status;
int hash(int key) {
	//�˴�д��ϣ��﹫ʽ���˴������๫ʽ��
	return key % 5;
}

//Ϊ�˱����ϣ��ͻ��ʹ�ù�ϣ���������Ч
typedef struct node {
	int key;
	char* name[20];
	struct node* next;
}node,*list;
//typedef Node node, * list;
list hash_table[MAX_SIZE];//��ʼ����ϣ��

Status Hash_Search(int key) {
	int hash_code = hash(key);
	node* p = hash_table[hash_code];//��һ����ָ��
	while (p != NULL) {
		if (p->key == key) {	//�����������
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
		free(p);	// ͨ���ͷ�
		return OK;
	}
	node* prev = p;
	p = p->next;
	while (p != NULL) {	// ���±�����ϣ��
		if (p->key == key) {
			prev->next = p->next;// ������ɾ��Ԫ��
			free(p);
			return OK;
		}
		prev = p;
		p = p->next;
	}
}
//���
