#include<iostream>
#include <stdlib.h> 
#include <queue>  
#include <vector>  
using namespace std;

#define MAX_SIZE 100
typedef void Status;

// 对于图有两种表示方式：邻接矩阵和列表
typedef struct connection_graph {	// 邻接矩阵的定义
	int V;
	int** adjmatrix; // 指向一个指针数组的指针（目的是动态分配内存）
}*connection_graph;


// Oth
typedef struct list_node {
	int vertex;                   // 顶点索引或其他标识符  
	struct list_node* next;       // 指向下一个节点的指针  
} list_node;

typedef struct list {
	list_node* head;              // 链表的头节点  
} list;

typedef struct graph {
	int V;
	list * adjlist;
}graph;

// DFS函数，用于深度优先搜索图中的节点  
// 参数：图的指针 g，当前节点的索引 v，以及一个记录节点是否被访问过的数组 visited  
Status dfs(graph* g, int v, int visited[]) {
    // 如果节点 v 已经被访问过，则直接返回，不再继续搜索  
    if (visited[v]) return;

    printf("%d ", v); // 输出当前访问的节点索引  
    visited[v] = 1; // 将当前节点标记为已访问  

    // 获取节点 v 的邻接表中的第一个邻居节点  
    list_node* nbr = g->adjlist[v].head;
    while (nbr) {
        int next_v = nbr->vertex; // 获取当前邻居节点的索引  
        if (!visited[next_v]) {
            dfs(g, next_v, visited); // 如果邻居节点未被访问过，则递归调用 DFS 进行搜索  
        }
        nbr = nbr->next; // 移动到下一个邻居节点，继续进行搜索  
    }
}

// DFS的主函数，用于初始化并调用 DFS 函数进行图的深度优先搜索  
void dfs_main(graph* g) {
    // 动态分配一个记录节点访问状态的数组，数组大小为图中节点的数量  
    int* visited = (int*)malloc(sizeof(int) * g->V);
    if (visited == NULL) {
        perror("Memory allocation failed"); // 如果内存分配失败，则输出错误信息并退出程序  
        exit(EXIT_FAILURE);
    }

    // 初始化访问状态数组，将所有节点的访问状态设置为未访问（0 表示未访问）  
    for (int v = 0; v < g->V; v++) {
        visited[v] = 0;
    }

    // 对图中的每个节点进行检查，如果节点未被访问过，则调用 DFS 函数进行搜索  
    for (int v = 0; v < g->V; v++) {
        if (!visited[v]) {
            dfs(g, v, visited); // 调用 DFS 函数进行深度优先搜索  
        }
    }

    free(visited); // 搜索完成后，释放访问状态数组的内存空间  
}

// 创建一个队列节点  
typedef struct queue_node {
    int vertex;
    struct queue_node* next;
} queue_node;

// 创建一个队列  
typedef struct queue1 {
    queue_node* front;
    queue_node* rear;
} queue;

// 队列操作函数  
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

// BFS函数  
void bfs(graph* g, int startVertex) {
    int* visited = (int*)calloc(g->V, sizeof(int));
    queue1* q = createQueue();

    visited[startVertex] = 1; // 标记起始节点为已访问  
    enqueue(q, startVertex); // 将起始节点加入队列  

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q); // 出队一个节点  
        printf("%d ", currentVertex); // 输出访问的节点  

        list_node* nbr = g->adjlist[currentVertex].head; // 获取当前节点的邻接表  
        while (nbr) {
            int nextVertex = nbr->vertex;
            if (!visited[nextVertex]) { // 如果邻居节点未被访问过  
                visited[nextVertex] = 1; // 标记为已访问  
                enqueue(q, nextVertex); // 加入队列  
            }
            nbr = nbr->next; // 移动到下一个邻居节点  
        }
    }

    free(visited); // 释放访问状态数组的内存  
    // 此处应添加代码释放队列占用的内存，为简洁起见在此省略  
}

// 主函数，调用BFS进行广度优先搜索  
void bfs_main(graph* g, int startVertex) {
    bfs(g, startVertex);
}



// 使用cpp内置的queue
// 假设图是用邻接列表表示的(二维矩阵)  
vector<vector<int>> adjList;

// BFS函数  
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
    // 使用邻接列表（基于结构体）初始化图  
    graph g1;
    g1.V = 5;
    g1.adjlist = (list*)malloc(g1.V * sizeof(list));

    // 初始化邻接列表  
    for (int i = 0; i < g1.V; ++i) {
        g1.adjlist[i].head = NULL;
    }

    // 添加边，这里只是一个简单示例  
    // 假设边是无向的，所以需要添加双向的边  
    addEdge(&g1, 0, 1);
    addEdge(&g1, 0, 2);
    addEdge(&g1, 1, 3);
    addEdge(&g1, 1, 4);
    addEdge(&g1, 1, 0);
    addEdge(&g1, 2, 0);
    addEdge(&g1, 3, 1);
    addEdge(&g1, 4, 1);

    cout << "DFS using struct-based adjacency list:" << endl;
    dfs_main(&g1); // 对基于结构体的图进行DFS  
    cout << endl;

    cout << "BFS using struct-based adjacency list:" << endl;
    bfs_main(&g1, 0); // 对基于结构体的图进行BFS，从顶点0开始  
    cout << endl;

    // 释放基于结构体的图的内存  
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

    // 使用C++ STL vector初始化图  
    adjList = {
        {1, 2},
        {0, 3, 4},
        {0},
        {1},
        {1}
    };

    cout << "BFS using STL vector adjacency list:" << endl;
    bfs(0); // 对基于STL vector的图进行BFS，从顶点0开始  
    cout << endl;

    return 0;
}

// 辅助函数，用于向基于结构体的邻接列表中添加边  
void addEdge(graph* g, int src, int dest) {
    list_node* newNode = (list_node*)malloc(sizeof(list_node));
    newNode->vertex = dest;
    newNode->next = g->adjlist[src].head;
    g->adjlist[src].head = newNode;

    // 因为是无向图，所以需要添加反向的边  
    newNode = (list_node*)malloc(sizeof(list_node));
    newNode->vertex = src;
    newNode->next = g->adjlist[dest].head;
    g->adjlist[dest].head = newNode;
}