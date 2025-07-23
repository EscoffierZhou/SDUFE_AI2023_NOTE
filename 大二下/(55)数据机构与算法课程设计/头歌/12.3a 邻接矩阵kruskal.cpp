#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#include"MGraph.h"

#define MAXE 100


typedef struct
{	int u;							//边的起始顶点
    int v;							//边的终止顶点
    int w;							//边的权值
} Edge;

void SortEdge(Edge E[],int e);		//对E数组按权值递增排序
void Kruskal(MGraph g);		// 用克鲁斯卡尔算法构造网G的最小生成树T，输出T的各条边

int main()
{
    MGraph g;
    CreateGraphF (g);  // 利用数据文件创建无向图
    Display(g);      // 输出无向图
    printf("用克鲁斯卡尔构造g的最小生成树的各条边:\n");
    Kruskal(g);  // 用克鲁斯卡尔算法构造最小生成树
    return 0;
}



void SortEdge(Edge E[],int e)		//对E数组按权值递增排序
{
    int i,j,k=0;
    Edge temp;
    for (i=1;i<e;i++)
    {	temp=E[i];
        j=i-1;						//从右向左在有序区E[0..i-1]中找E[i]的插入位置
        while (j>=0 && temp.w<E[j].w)
        {	E[j+1]=E[j];			//将权值大于E[i].w的记录后移
            j--;
        }
        E[j+1]=temp;				//在j+1处插入E[i]
    }
}

void Kruskal(MGraph g)			//输出求得的最小生树的所有边
{
    // 用克鲁斯卡尔算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边
    /********** Begin **********/
    int i,j,k;
    int vset[100];       // 并查集数组，假设最多 100 个顶点
    Edge E[MAXE];        // 边数组
    int n = g.vexnum;
    int e = 0;

    // 将所有边存入数组 E（无向图，只存一条）
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (g.arcs[i][j].adj != INT_MAX) {
                E[e].u = i;
                E[e].v = j;
                E[e].w = g.arcs[i][j].adj;
                e++;
            }
        }
    }

    SortEdge(E, e); // 排序边

    // 初始化并查集
    for (i = 0; i < n; i++)
        vset[i] = i;

    k = 0; // 记录当前选择的边数
    for (i = 0; i < e && k < n - 1; i++) {
        int vs1 = E[i].u;
        int vs2 = E[i].v;

        // 查找祖先
        while (vset[vs1] != vs1)
            vs1 = vset[vs1];
        while (vset[vs2] != vs2)
            vs2 = vset[vs2];

        if (vs1 != vs2) {
            printf("边(%s,%s),权值为%d\n", g.vexs[E[i].v], g.vexs[E[i].u], E[i].w);
            vset[vs2] = vs1;
            k++;
        }
    }
/********** End **********/

}
