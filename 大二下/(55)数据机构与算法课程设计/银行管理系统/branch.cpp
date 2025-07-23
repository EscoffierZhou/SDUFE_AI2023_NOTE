#include "branch.h"
#include "utils.h"
#include <vector> // 添加 vector 头文件

// 全局变量，用于存储所有路径
std::vector<std::vector<int>> allPaths;
bool visited[MaxVertexNum]; // 记录顶点是否被访问过

// 初始化图
mgraph initgraph() {
    mgraph c;
    c.vexnum = 0;
    c.arcnum = 0;
    
    // 初始化邻接矩阵
    for (int i = 0; i < MaxVertexNum; i++) {
        for (int j = 0; j < MaxVertexNum; j++) {
            c.arcs[i][j].adj = Infinity;
        }
    }
    
    return c;
}

// 定位顶点
int locatevex(mgraph c, int v) {
    for (int i = 0; i < c.vexnum; i++) {
        if (c.vexs[i].position == v) {
            return i;
        }
    }
    return -1;
}

// 构造图的邻接矩阵
void creatgraph(mgraph* c) {
    std::cout << "请输入网点数量：";
    std::cin >> c->vexnum;
    
    std::cout << "请输入边的数量：";
    std::cin >> c->arcnum;
    
    // 输入顶点信息
    for (int i = 0; i < c->vexnum; i++) {
        std::cout << "请输入第" << i + 1 << "个网点的信息（编号 名称 地址 联系方式）：" << std::endl;
        std::cin >> c->vexs[i].position >> c->vexs[i].name >> c->vexs[i].address >> c->vexs[i].phonenumber;
    }
    
    // 初始化邻接矩阵
    for (int i = 0; i < c->vexnum; i++) {
        for (int j = 0; j < c->vexnum; j++) {
            c->arcs[i][j].adj = Infinity;
        }
    }
    
    // 输入边的信息
    for (int k = 0; k < c->arcnum; k++) {
        int v1, v2, w;
        std::cout << "请输入第" << k + 1 << "条边的信息（起点编号 终点编号 权值）：" << std::endl;
        std::cin >> v1 >> v2 >> w;
        
        int i = locatevex(*c, v1);
        int j = locatevex(*c, v2);
        
        if (i != -1 && j != -1) {
            c->arcs[i][j].adj = w;
            c->arcs[j][i].adj = w; // 无向图，对称赋值
        } else {
            std::cout << "输入的顶点编号不存在，请重新输入！" << std::endl;
            k--;
        }
    }
}

// 点信息查询
void seeabout(mgraph* c) {
    int position;
    std::cout << "请输入要查询的网点编号：";
    std::cin >> position;
    
    int index = locatevex(*c, position);
    if (index != -1) {
        std::cout << "网点信息如下：" << std::endl;
        std::cout << "编号：" << c->vexs[index].position << std::endl;
        std::cout << "名称：" << c->vexs[index].name << std::endl;
        std::cout << "地址：" << c->vexs[index].address << std::endl;
        std::cout << "联系方式：" << c->vexs[index].phonenumber << std::endl;
    } else {
        std::cout << "未找到该网点！" << std::endl;
    }
}

// 两网点最短路径查询 (Dijkstra算法)
void shortestpath(mgraph c) {
    int start, end;
    std::cout << "请输入起点编号：";
    std::cin >> start;
    std::cout << "请输入终点编号：";
    std::cin >> end;
    
    int s = locatevex(c, start);
    int e = locatevex(c, end);
    
    if (s == -1 || e == -1) {
        std::cout << "输入的网点编号不存在！" << std::endl;
        return;
    }
    
    // Dijkstra算法实现
    int dist[MaxVertexNum]; // 最短路径长度
    int path[MaxVertexNum]; // 前驱顶点
    bool visited[MaxVertexNum] = {false}; // 是否已访问
    
    // 初始化
    for (int i = 0; i < c.vexnum; i++) {
        dist[i] = c.arcs[s][i].adj;
        if (dist[i] < Infinity) {
            path[i] = s;
        } else {
            path[i] = -1;
        }
    }
    
    visited[s] = true;
    dist[s] = 0;
    
    // 主循环
    for (int i = 1; i < c.vexnum; i++) {
        int min = Infinity;
        int u = s;
        
        // 找出当前未访问的顶点中距离最小的
        for (int j = 0; j < c.vexnum; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        
        visited[u] = true;
        
        // 更新距离
        for (int j = 0; j < c.vexnum; j++) {
            if (!visited[j] && c.arcs[u][j].adj < Infinity) {
                if (dist[u] + c.arcs[u][j].adj < dist[j]) {
                    dist[j] = dist[u] + c.arcs[u][j].adj;
                    path[j] = u;
                }
            }
        }
    }
    
    // 输出最短路径
    if (dist[e] == Infinity) {
        std::cout << "从网点" << start << "到网点" << end << "没有可达路径！" << std::endl;
    } else {
        std::cout << "从网点" << start << "到网点" << end << "的最短路径长度为：" << dist[e] << std::endl;
        
        // 输出路径
        int stack[MaxVertexNum];
        int top = -1;
        int temp = e;
        
        while (temp != -1) {
            stack[++top] = temp;
            temp = path[temp];
        }
        
        std::cout << "路径为：";
        while (top >= 0) {
            std::cout << c.vexs[stack[top]].position;
            top--;
            if (top >= 0) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }
}

// 更新图信息
int newgraph(mgraph* c) {
    int choice;
    std::cout << "请选择操作：" << std::endl;
    std::cout << "1. 增加边" << std::endl;
    std::cout << "2. 增加节点" << std::endl;
    std::cout << "3. 删除节点" << std::endl;
    std::cout << "4. 删除边" << std::endl;
    std::cout << "5. 返回上级菜单" << std::endl;
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            return enarc(c);
        case 2:
            return envex(c);
        case 3:
            return delvex(c);
        case 4:
            return delarc(c);
        case 5:
            return 0;
        default:
            std::cout << "输入有误，请重新选择！" << std::endl;
            return newgraph(c);
    }
}

// 增加边
int enarc(mgraph* c) {
    int v1, v2, w;
    std::cout << "请输入要增加的边（起点编号 终点编号 权值）：" << std::endl;
    std::cin >> v1 >> v2 >> w;
    
    int i = locatevex(*c, v1);
    int j = locatevex(*c, v2);
    
    if (i != -1 && j != -1) {
        c->arcs[i][j].adj = w;
        c->arcs[j][i].adj = w; // 无向图，对称赋值
        c->arcnum++;
        std::cout << "边添加成功！" << std::endl;
    } else {
        std::cout << "输入的顶点编号不存在！" << std::endl;
    }
    
    return 1;
}

// 增加节点
int envex(mgraph* c) {
    if (c->vexnum >= MaxVertexNum) {
        std::cout << "网点数量已达上限！" << std::endl;
        return 1;
    }
    
    std::cout << "请输入新网点的信息（编号 名称 地址 联系方式）：" << std::endl;
    std::cin >> c->vexs[c->vexnum].position >> c->vexs[c->vexnum].name 
             >> c->vexs[c->vexnum].address >> c->vexs[c->vexnum].phonenumber;
    
    // 初始化新顶点的边
    for (int i = 0; i < c->vexnum; i++) {
        c->arcs[c->vexnum][i].adj = Infinity;
        c->arcs[i][c->vexnum].adj = Infinity;
    }
    
    c->vexnum++;
    std::cout << "网点添加成功！" << std::endl;
    
    return 1;
}

// 删除节点
int delvex(mgraph* c) {
    int position;
    std::cout << "请输入要删除的网点编号：";
    std::cin >> position;
    
    int index = locatevex(*c, position);
    if (index == -1) {
        std::cout << "未找到该网点！" << std::endl;
        return 1;
    }
    
    // 删除与该顶点相关的边
    for (int i = 0; i < c->vexnum; i++) {
        if (c->arcs[index][i].adj < Infinity) {
            c->arcnum--;
        }
    }
    
    // 移动顶点数组
    for (int i = index; i < c->vexnum - 1; i++) {
        c->vexs[i] = c->vexs[i + 1];
    }
    
    // 调整邻接矩阵
    for (int i = 0; i < c->vexnum; i++) {
        for (int j = index; j < c->vexnum - 1; j++) {
            c->arcs[i][j] = c->arcs[i][j + 1];
        }
    }
    
    for (int i = index; i < c->vexnum - 1; i++) {
        for (int j = 0; j < c->vexnum; j++) {
            c->arcs[i][j] = c->arcs[i + 1][j];
        }
    }
    
    c->vexnum--;
    std::cout << "网点删除成功！" << std::endl;
    
    return 1;
}

// 删除边
int delarc(mgraph* c) {
    std::cout << "请输入要删除的边的两个顶点编号：" << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    
    // 修复错误：将 locat 改为 locatevex
    int i = locatevex(*c, v1);
    int j = locatevex(*c, v2);
    
    if (i < 0 || j < 0 || i >= c->vexnum || j >= c->vexnum) {
        std::cout << "顶点不存在！" << std::endl;
        return 0;
    }
    
    if (c->arcs[i][j].adj == Infinity) {
        std::cout << "该边不存在！" << std::endl;
        return 0;
    }
    
    // 删除边（设置为无穷大表示不连通）
    c->arcs[i][j].adj = Infinity;
    c->arcs[j][i].adj = Infinity;
    c->arcnum--;
    
    std::cout << "边删除成功！" << std::endl;
    return 1;
}

// 路径辅助函数 - 深度优先搜索找出所有路径
void path(mgraph c, int start, int end, std::vector<int>& currentPath) {
    // 标记当前顶点为已访问
    visited[start] = true;
    // 将当前顶点加入路径
    currentPath.push_back(c.vexs[start].position);
    
    // 如果到达终点，保存当前路径
    if (start == end) {
        allPaths.push_back(currentPath);
    } else {
        // 继续搜索所有相邻且未访问的顶点
        for (int i = 0; i < c.vexnum; i++) {
            if (!visited[i] && c.arcs[start][i].adj < Infinity) {
                path(c, i, end, currentPath);
            }
        }
    }
    
    // 回溯：移除当前顶点，标记为未访问
    currentPath.pop_back();
    visited[start] = false;
}

// 查询两网点间的所有可行路径
int allpath(mgraph c) {
    int start, end;
    std::cout << "请输入起点编号：";
    std::cin >> start;
    std::cout << "请输入终点编号：";
    std::cin >> end;
    
    int s = locatevex(c, start);
    int e = locatevex(c, end);
    
    if (s == -1 || e == -1) {
        std::cout << "输入的网点编号不存在！" << std::endl;
        return 0;
    }
    
    // 初始化全局变量
    allPaths.clear();
    for (int i = 0; i < MaxVertexNum; i++) {
        visited[i] = false;
    }
    
    // 开始搜索所有路径
    std::vector<int> currentPath;
    path(c, s, e, currentPath);
    
    // 输出所有路径
    if (allPaths.empty()) {
        std::cout << "从网点" << start << "到网点" << end << "没有可达路径！" << std::endl;
    } else {
        std::cout << "从网点" << start << "到网点" << end << "共有" << allPaths.size() << "条可行路径：" << std::endl;
        
        for (size_t i = 0; i < allPaths.size(); i++) {
            std::cout << "路径" << i + 1 << "：";
            for (size_t j = 0; j < allPaths[i].size(); j++) {
                std::cout << allPaths[i][j];
                if (j < allPaths[i].size() - 1) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl;
        }
    }
    
    return 1;
}

// 银行网点查询主函数
void mainwork() {
    clearScreen();
    displayBankLogo();
    std::cout << "【银行网点查询系统】" << std::endl << std::endl;
    
    mgraph c = initgraph();
    int yourchoice = 0;
    
    // 首先创建图
    std::cout << "请先创建银行网点图：" << std::endl;
    creatgraph(&c);
    
    while (true) {
        clearScreen();
        displayBankLogo();
        std::cout << "【银行网点查询系统】" << std::endl << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "         1.网点信息查询               " << std::endl;
        std::cout << "         2.两网点最短路径查询         " << std::endl;
        std::cout << "         3.更改图信息                 " << std::endl;
        std::cout << "         4.查询两网点间的所有可行路径 " << std::endl;
        std::cout << "         5.退出                       " << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "请输入您的选择: ";
        std::cin >> yourchoice;
        
        switch (yourchoice) {
            case 1:
                seeabout(&c);
                break;
            case 2:
                shortestpath(c);
                break;
            case 3:
                newgraph(&c);
                break;
            case 4:
                allpath(c);
                break;
            case 5:
                return;
            default:
                std::cout << "输入有误，请重新选择！" << std::endl;
        }
        
        pauseAndContinue();
    }
}