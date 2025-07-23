#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
//声明:queue<int> myqueue;
//插入:myqueue.push (myint);
//大小:myqueue.size()
//队首:myqueue.front()
//出队:myqueue.pop()
struct Node {
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    // 读入起点和终点坐标
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 用 visited 数组记录是否访问过
    // parent 数组用于记录路径前驱
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));

    // BFS 队列
    queue<pair<int,int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;

    // 定义四个方向的偏移量
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool found = false;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        // 到达终点则退出
        if (x == x2 && y == y2) {
            found = true;
            break;
        }
        // 遍历四个方向
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            // 判断边界和是否可以通过
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && maze[nx][ny] == '*') {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }
    // 回溯路径，从终点到起点
    vector<pair<int,int>> path;
    int cx = x2, cy = y2;
    while (!(cx == x1 && cy == y1)) {
        path.push_back({cx, cy});
        auto pr = parent[cx][cy];
        cx = pr.first;
        cy = pr.second;
    }
    path.push_back({x1, y1});
    reverse(path.begin(), path.end());

    cout << "最短路径为：";
    for (int i = 0; i < path.size(); i++) {
        cout << "(" << path[i].first << "," << path[i].second << ")";
        if (i != path.size() - 1)
            cout << "->";
    }
    cout << "，共" << path.size() - 1 << "步" << endl;
    return 0;
}
/*
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
struct Node {
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    // 读入起点和终点坐标
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 用 visited 数组记录是否访问过
    // parent 数组用于记录路径前驱
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));

    // BFS 队列
    queue<pair<int,int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;

    // 定义四个方向的偏移量
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool found = false;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        // 到达终点则退出
        if (x == x2 && y == y2) {
            found = true;
            break;
        }
        // 遍历四个方向
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            // 判断边界和是否可以通过
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && maze[nx][ny] == '*') {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }
    if (!found) {
        cout << 0 << endl; // 如果没有找到路径，输出 0
    } else {
        // 回溯路径，从终点到起点
        vector<pair<int,int>> path;
        int cx = x2, cy = y2;
        while (!(cx == x1 && cy == y1)) {
            path.push_back({cx, cy});
            auto pr = parent[cx][cy];
            cx = pr.first;
            cy = pr.second;
        }
        path.push_back({x1, y1});
        cout << path.size() - 1 << endl; // 输出路径长度
    }
    return 0;
}

 */