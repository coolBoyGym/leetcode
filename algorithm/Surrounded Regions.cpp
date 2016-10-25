#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 不被X包围的O必定能通过一条路与最外层的O相连
// 对于最外层的每一个O作BFS 并将搜索到的O做标记
// 遍历整个矩阵 未被标记的O即为被包围的O

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.size() <= 2 || board[0].size() <= 2)   // 全部节点都是边界 直接返回
            return;
        else{
            int i, j, k = board.size(), l = board[0].size();
            for(i = 0; i < k; ++i)
            {
                DFS(board, i, 0);
                DFS(board, i, l-1);
            }
            for(j = 1; j < l-1; ++j)
            {
                DFS(board, 0, j);
                DFS(board, k-1, j);
            }

            for(i = 0; i < k; ++i)
                for(j = 0; j < l; ++j)
                {
                    if(board[i][j] == 'Y')
                        board[i][j] = 'O';
                    else
                        board[i][j] = 'X';
                }
        }
    }

    // Y表示访问过的O单元格 V表示访问过的X单元格
    void DFS(vector<vector<char> > &board, int x, int y)
    {
        if(board[x][y] != 'V' && board[x][y] != 'Y')
        {
            if(board[x][y] == 'O')  // 只有O节点才进参与DFS
            {
                board[x][y] = 'Y';

                if(x > 1)
                    DFS(board, x-1, y);
                if(x < board.size() - 2)
                    DFS(board, x+1, y);
                if(y > 1)
                    DFS(board, x, y-1);
                if(y < board[0].size() - 2)
                    DFS(board, x, y+1);
            }
            else{   // 该节点是X节点 直接标记就好
                board[x][y] = 'V';
            }
        }
    }
};
