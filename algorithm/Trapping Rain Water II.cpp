#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// ʹ����С���ѽ������
class Solution {
public:
    struct cell{    // ����ڵ��� �����ֱ�Ϊx��y�����Լ��õ�ĸ߶�
        int x, y, h;
        cell() {}
        cell(int _x, int _y, int _h): x(_x), y(_y), h(_h) {}
    };
    struct cmp{     // �Զ���ıȽϺ��� ����ʵ����С����(���ȼ�������Ĭ����������󻯶�)
        bool operator() (const cell &a, const cell &b){
            return a.h > b.h;
        }
    };

    int trapRainWater(vector<vector<int> >& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        if(m <= 2 || n <= 2) return 0;  // ��ĳ���򳤶�С��2 ��ȫ���㶼�ڱ߽� ֱ�ӷ���

        vector<vector<bool> > visit(m, vector<bool>(n, false)); // ����ÿ���ڵ�ķ���״̬
        priority_queue<cell, vector<cell>, cmp> heap;   // �������ȶ��� ÿ���ڵ����һ��
        for(int i =0; i < m; ++i){      // ����һ�к����һ�нڵ����
            heap.push(cell(i, 0, heightMap[i][0]));
            heap.push(cell(i, n-1, heightMap[i][n-1]));
            visit[i][0] = visit[i][n-1] = true;
        }
        for(int j = 1; j < n-1; ++j){   // ��ʣ��ı߽�ڵ����
            heap.push(cell(0, j, heightMap[0][j]));
            heap.push(cell(m-1, j, heightMap[m-1][j]));
            visit[0][j] = visit[m-1][j] = true;
        }

        int res = 0;    // ������ˮ��
        const int dx[4] = {0, 1, 0, -1};    // dx��dy����ÿ���ڵ���ƶ����ĸ���λ
        const int dy[4] = {1, 0, -1, 0};

        cell curr;      // ������ǰ�ڵ� �������и߶���С�Ľڵ�
        int xx = 0, yy = 0;
        while(!heap.empty()){   // �Ӹ߶���С�Ľڵ���Χ��ʼ��� һ���������� ��һ�������
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
