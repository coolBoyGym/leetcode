#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 使用最小化堆进行求解
class Solution {
public:
    struct cell{    // 定义节点类 参数分别为x和y坐标以及该点的高度
        int x, y, h;
        cell() {}
        cell(int _x, int _y, int _h): x(_x), y(_y), h(_h) {}
    };
    struct cmp{     // 自定义的比较函数 用于实现最小化堆(优先级队列中默认类型是最大化堆)
        bool operator() (const cell &a, const cell &b){
            return a.h > b.h;
        }
    };

    int trapRainWater(vector<vector<int> >& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        if(m <= 2 || n <= 2) return 0;  // 若某方向长度小于2 则全部点都在边界 直接返回

        vector<vector<bool> > visit(m, vector<bool>(n, false)); // 保存每个节点的访问状态
        priority_queue<cell, vector<cell>, cmp> heap;   // 定义优先队列 每个节点进队一次
        for(int i =0; i < m; ++i){      // 将第一列和最后一列节点入队
            heap.push(cell(i, 0, heightMap[i][0]));
            heap.push(cell(i, n-1, heightMap[i][n-1]));
            visit[i][0] = visit[i][n-1] = true;
        }
        for(int j = 1; j < n-1; ++j){   // 将剩余的边界节点入队
            heap.push(cell(0, j, heightMap[0][j]));
            heap.push(cell(m-1, j, heightMap[m-1][j]));
            visit[0][j] = visit[m-1][j] = true;
        }

        int res = 0;    // 表征储水量
        const int dx[4] = {0, 1, 0, -1};    // dx和dy构成每个节点可移动的四个方位
        const int dy[4] = {1, 0, -1, 0};

        cell curr;      // 表征当前节点 即队伍中高度最小的节点
        int xx = 0, yy = 0;
        while(!heap.empty()){   // 从高度最小的节点周围开始填充 一旦比它还矮 就一定可填充
            curr = heap.top();
            heap.pop();
            for(int i = 0; i < 4; ++i){
                xx = curr.x + dx[i];
                yy = curr.y + dy[i];
                if(xx >= 0 && xx < m && yy >= 0 && yy < n && !visit[xx][yy]){
                    res += max(0, curr.h - heightMap[xx][yy]);
                    heap.push(cell(xx, yy, max(curr.h, heightMap[xx][yy])));
                    visit[xx][yy] = true;
                }
            }
        }

        return res;
    }
};
