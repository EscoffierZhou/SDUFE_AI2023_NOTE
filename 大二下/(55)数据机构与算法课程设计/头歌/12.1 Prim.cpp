#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#include "MGraph.h"

typedef struct min
{
    /* 记录从顶点集U到V-U的代价最小的边的辅助数组定义 */
    VertexType adjvex;
    VRType lowcost;
} minside[MAX_VERTEX_NUM];

int minimum(minside SZ, MGraph G); // 求SZ.lowcost的最小正值，并返回其在SZ中的序号
void MiniSpanTree_PRIM(MGraph G, VertexType u); // 用普里姆算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边

int main()
{
    MGraph g;
    int n;
    CreateGraphF(g);  // 利用数据文件创建无向图
    Display(g);      // 输出无向图
    scanf("%d", &n);
    printf("用普里姆算法从g的第%d个顶点出发输出最小生成树的各条边:\n", n);
    printf("最小代价生成树的各条边为:\n");
    MiniSpanTree_PRIM(g, g.vexs[n]);  // Prim算法从第n个顶点构造最小生成树
    return 0;
}

int minimum(minside SZ, MGraph G)
{
    // 求SZ.lowcost的最小正值，并返回其在SZ中的序号
    int i = 0, j, k, min;
    while (!SZ[i].lowcost)
        i++;
    min = SZ[i].lowcost;                         // 第一个不为0的值
    k = i;
    for (j = i + 1; j < G.vexnum; j++)
        if (SZ[j].lowcost > 0 && min > SZ[j].lowcost) // 找到新的大于0的最小值
        {
            min = SZ[j].lowcost;
            k = j;
        }
    return k;
}

void MiniSpanTree_PRIM(MGraph G, VertexType u)
{
    minside closedge;
    int k = LocateVex(G, u);  // 获取起始顶点下标
    if (k == -1) {
        printf("起始顶点不存在！\n");
        return;
    }

    // 初始化辅助数组 closedge
    for (int j = 0; j < G.vexnum; j++) {
        if (j != k)
        {
            strcpy(closedge[j].adjvex, u); // 使用strcpy来复制字符串
            closedge[j].lowcost = G.arcs[k][j].adj;
        }
        else
        {
            closedge[j].lowcost = 0; // 自身为0，表示已加入U
        }
    }

    for (int i = 1; i < G.vexnum; i++) // 一共加入 G.vexnum - 1 条边
    {
        int minIndex = minimum(closedge, G);
        // 使用 %s 来打印字符串，而不是 %c
        printf("边(%s,%s),权值为%d", closedge[minIndex].adjvex, G.vexs[minIndex], closedge[minIndex].lowcost);
        if(i<G.vexnum)printf("\n");
        closedge[minIndex].lowcost = 0; // 标记已加入U集合

        // 更新辅助数组中其他顶点的lowcost
        for (int j = 0; j < G.vexnum; j++) {
            if (closedge[j].lowcost != 0 && G.arcs[minIndex][j].adj < closedge[j].lowcost) {
                closedge[j].lowcost = G.arcs[minIndex][j].adj;
                strcpy(closedge[j].adjvex, G.vexs[minIndex]); // 使用strcpy来复制字符串
            }
        }
    }
}
