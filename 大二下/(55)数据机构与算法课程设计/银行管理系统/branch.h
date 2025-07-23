#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
#include <string>
#include <vector> // 添加 vector 头文件

#define Infinity 1000          // 无穷大
#define MaxVertexNum 6         // 最大顶点数量

// 边结构体
typedef struct arcell {        // 边的权值信息
    int adj;                   // 权值
} arcell, adjmatrix[MaxVertexNum][MaxVertexNum]; // 图的邻接矩阵类型

// 顶点结构体
typedef struct vexsinfo {
    int position;              // 编号
    std::string name;          // 网点名称
    std::string address;       // 网点地址
    std::string phonenumber;   // 网点联系方式
} vexsinfo, point;

// 图结构体
typedef struct mgraph {
    vexsinfo vexs[MaxVertexNum]; // 顶点
    adjmatrix arcs;              // 边
    int vexnum, arcnum;          // 定义顶点数量，边的数量
} mgraph;

// 点信息查询
void seeabout(mgraph* c);

// 两网点最短路径查询
void shortestpath(mgraph c);

// 定位顶点
int locatevex(mgraph c, int v);

// 构造图的邻接矩阵
void creatgraph(mgraph* c);

// 更新图信息
int newgraph(mgraph* c);

// 增加边
int enarc(mgraph* c);

// 增加节点
int envex(mgraph* c);

// 删除节点
int delvex(mgraph* c);

// 删除边
int delarc(mgraph* c);

// 更改图信息
int changegraph(mgraph* c);

// 查询两网点间的所有可行路径
int allpath(mgraph c);

// 路径辅助函数
void path(mgraph c, int start, int end, std::vector<int>& currentPath);

// 银行网点查询主函数
void mainwork();

#endif // BRANCH_H