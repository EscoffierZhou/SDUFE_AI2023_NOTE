#include<iostream>
#include <stdlib.h> 
#include <queue>  
#include <vector>  
using namespace std;

#define MAX_SIZE 100
typedef void Status;

// ����ͼ�����ֱ�ʾ��ʽ���ڽӾ�����б�
typedef struct connection_graph {	// �ڽӾ���Ķ���
	int V;
	int** adjmatrix; // ָ��һ��ָ�������ָ�루Ŀ���Ƕ�̬�����ڴ棩
}*connection_graph;


// Oth
typedef struct list_node {
	int vertex;                   // ����������������ʶ��  
	struct list_node* next;       // ָ����һ���ڵ��ָ��  
} list_node;

typedef struct list {
	list_node* head;              // �����ͷ�ڵ�  
} list;

typedef struct graph {
	int V;
	list * adjlist;
}graph;

// DFS���������������������ͼ�еĽڵ�  
// ������ͼ��ָ�� g����ǰ�ڵ������ v���Լ�һ����¼�ڵ��Ƿ񱻷��ʹ������� visited  
Status dfs(graph* g, int v, int visited[]) {
    // ����ڵ� v �Ѿ������ʹ�����ֱ�ӷ��أ����ټ�������  
    if (visited[v]) return;

    printf("%d ", v); // �����ǰ���ʵĽڵ�����  
    visited[v] = 1; // ����ǰ�ڵ���Ϊ�ѷ���  

    // ��ȡ�ڵ� v ���ڽӱ��еĵ�һ���ھӽڵ�  
    list_node* nbr = g->adjlist[v].head;
    while (nbr) {
        int next_v = nbr->vertex; // ��ȡ��ǰ�ھӽڵ������  
        if (!visited[next_v]) {
            dfs(g, next_v, visited); // ����ھӽڵ�δ�����ʹ�����ݹ���� DFS ��������  
        }
        nbr = nbr->next; // �ƶ�����һ���ھӽڵ㣬������������  
    }
}

// DFS�������������ڳ�ʼ�������� DFS ��������ͼ�������������  
void dfs_main(graph* g) {
    // ��̬����һ����¼�ڵ����״̬�����飬�����СΪͼ�нڵ������  
    int* visited = (int*)malloc(sizeof(int) * g->V);
    if (visited == NULL) {
        perror("Memory allocation failed"); // ����ڴ����ʧ�ܣ������������Ϣ���˳�����  
        exit(EXIT_FAILURE);
    }

    // ��ʼ������״̬���飬�����нڵ�ķ���״̬����Ϊδ���ʣ�0 ��ʾδ���ʣ�  
    for (int v = 0; v < g->V; v++) {
        visited[v] = 0;
    }

    // ��ͼ�е�ÿ���ڵ���м�飬����ڵ�δ�����ʹ�������� DFS ������������  
    for (int v = 0; v < g->V; v++) {
        if (!visited[v]) {
            dfs(g, v, visited); // ���� DFS �������������������  
        }
    }

    free(visited); // ������ɺ��ͷŷ���״̬������ڴ�ռ�  
}

// ����һ�����нڵ�  
typedef struct queue_node {
    int vertex;
    struct queue_node* next;
} queue_node;

// ����һ������  
typedef struct queue1 {
    queue_node* front;
    queue_node* rear;
} queue;

// ���в�������  
queue1* createQueue() {
    queue1* q = (queue1*)malloc(sizeof(queue1));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue1* q, int vertex) {
    queue_node* newNode = (queue_node*)malloc(sizeof(queue_node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(queue1* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }
    queue_node* temp = q->front;
    int vertex = temp->vertex;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return vertex;
}

int isEmpty(queue1* q) {
    return q->front == NULL;
}

// BFS����  
void bfs(graph* g, int startVertex) {
    int* visited = (int*)calloc(g->V, sizeof(int));
    queue1* q = createQueue();

    visited[startVertex] = 1; // �����ʼ�ڵ�Ϊ�ѷ���  
    enqueue(q, startVertex); // ����ʼ�ڵ�������  

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q); // ����һ���ڵ�  
        printf("%d ", currentVertex); // ������ʵĽڵ�  

        list_node* nbr = g->adjlist[currentVertex].head; // ��ȡ��ǰ�ڵ���ڽӱ�  
        while (nbr) {
            int nextVertex = nbr->vertex;
            if (!visited[nextVertex]) { // ����ھӽڵ�δ�����ʹ�  
                visited[nextVertex] = 1; // ���Ϊ�ѷ���  
                enqueue(q, nextVertex); // �������  
            }
            nbr = nbr->next; // �ƶ�����һ���ھӽڵ�  
        }
    }

    free(visited); // �ͷŷ���״̬������ڴ�  
    // �˴�Ӧ��Ӵ����ͷŶ���ռ�õ��ڴ棬Ϊ�������ڴ�ʡ��  
}

// ������������BFS���й����������  
void bfs_main(graph* g, int startVertex) {
    bfs(g, startVertex);
}



// ʹ��cpp���õ�queue
// ����ͼ�����ڽ��б��ʾ��(��ά����)  
vector<vector<int>> adjList;

// BFS����  
void bfs(int startVertex) {
    vector<bool> visited(adjList.size(), false);
    std::queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";

        for (int neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // ʹ���ڽ��б����ڽṹ�壩��ʼ��ͼ  
    graph g1;
    g1.V = 5;
    g1.adjlist = (list*)malloc(g1.V * sizeof(list));

    // ��ʼ���ڽ��б�  
    for (int i = 0; i < g1.V; ++i) {
        g1.adjlist[i].head = NULL;
    }

    // ��ӱߣ�����ֻ��һ����ʾ��  
    // �����������ģ�������Ҫ���˫��ı�  
    addEdge(&g1, 0, 1);
    addEdge(&g1, 0, 2);
    addEdge(&g1, 1, 3);
    addEdge(&g1, 1, 4);
    addEdge(&g1, 1, 0);
    addEdge(&g1, 2, 0);
    addEdge(&g1, 3, 1);
    addEdge(&g1, 4, 1);

    cout << "DFS using struct-based adjacency list:" << endl;
    dfs_main(&g1); // �Ի��ڽṹ���ͼ����DFS  
    cout << endl;

    cout << "BFS using struct-based adjacency list:" << endl;
    bfs_main(&g1, 0); // �Ի��ڽṹ���ͼ����BFS���Ӷ���0��ʼ  
    cout << endl;

    // �ͷŻ��ڽṹ���ͼ���ڴ�  
    for (int i = 0; i < g1.V; ++i) {
        list_node* current = g1.adjlist[i].head;
        list_node* next;
        while (current) {
            next = current->next;
            free(current);
            current = next;
        }
    }
    free(g1.adjlist);

    // ʹ��C++ STL vector��ʼ��ͼ  
    adjList = {
        {1, 2},
        {0, 3, 4},
        {0},
        {1},
        {1}
    };

    cout << "BFS using STL vector adjacency list:" << endl;
    bfs(0); // �Ի���STL vector��ͼ����BFS���Ӷ���0��ʼ  
    cout << endl;

    return 0;
}

// ������������������ڽṹ����ڽ��б�����ӱ�  
void addEdge(graph* g, int src, int dest) {
    list_node* newNode = (list_node*)malloc(sizeof(list_node));
    newNode->vertex = dest;
    newNode->next = g->adjlist[src].head;
    g->adjlist[src].head = newNode;

    // ��Ϊ������ͼ��������Ҫ��ӷ���ı�  
    newNode = (list_node*)malloc(sizeof(list_node));
    newNode->vertex = src;
    newNode->next = g->adjlist[dest].head;
    g->adjlist[dest].head = newNode;
}