#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����X��Χ��O�ض���ͨ��һ��·��������O����
// ����������ÿһ��O��BFS ������������O�����
// ������������ δ����ǵ�O��Ϊ����Χ��O

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.size() <= 2 || board[0].size() <= 2)   // ȫ���ڵ㶼�Ǳ߽� ֱ�ӷ���
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

    // Y��ʾ���ʹ���O��Ԫ�� V��ʾ���ʹ���X��Ԫ��
    void DFS(vector<vector<char> > &board, int x, int y)
    {
        if(board[x][y] != 'V' && board[x][y] != 'Y')
        {
            if(board[x][y] == 'O')  // ֻ��O�ڵ�Ž�����DFS
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
            else{   // �ýڵ���X�ڵ� ֱ�ӱ�Ǿͺ�
                board[x][y] = 'V';
            }
        }
    }
};
