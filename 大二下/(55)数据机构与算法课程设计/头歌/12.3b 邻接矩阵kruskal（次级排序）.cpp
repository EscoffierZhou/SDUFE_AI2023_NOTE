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



void SortEdge(Edge E[], int e, char vexs[][20]) {
    int i, j;
    Edge temp;
    for (i = 1; i < e; i++) {
        temp = E[i];
        j = i - 1;

        // 插入排序，增加次级比较逻辑
        while (j >= 0) {
            if (temp.w < E[j].w) {
                E[j + 1] = E[j];
                j--;
            } else if (temp.w == E[j].w) {
                // 边权相等，比较两个端点名称（先小点，再大点）
                const char *temp_u = vexs[temp.u];
                const char *temp_v = vexs[temp.v];
                const char *ej_u = vexs[E[j].u];
                const char *ej_v = vexs[E[j].v];

                // 确保起点小于终点（如按字典序）——排序前处理过可以跳过
                if (strcmp(temp_u, temp_v) > 0) {
                    const char *tmp = temp_u;
                    temp_u = temp_v;
                    temp_v = tmp;
                }
                if (strcmp(ej_u, ej_v) > 0) {
                    const char *tmp = ej_u;
                    ej_u = ej_v;
                    ej_v = tmp;
                }

                if (strcmp(temp_u, ej_u) < 0 ||
                    (strcmp(temp_u, ej_u) == 0 && strcmp(temp_v, ej_v) < 0)) {
                    E[j + 1] = E[j];
                    j--;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        E[j + 1] = temp;
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

    SortEdge(E, e, g.vexs);


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
