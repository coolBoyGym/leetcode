#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

// 根据给定的指针 复制一个有项无环图
// 第一遍BFS遍历 第二遍复制邻居节点
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
        {
            return NULL;
        }
        map<int, UndirectedGraphNode*> nodes;
        queue<UndirectedGraphNode*> q;

        q.push(node);

        while(!q.empty())
        {
            UndirectedGraphNode* tmp = q.front();
            q.pop();
            if(nodes.find(tmp->label) == nodes.end())
            {
                UndirectedGraphNode* new_node = new UndirectedGraphNode(tmp->label);
                nodes.insert(pair<int, UndirectedGraphNode*>(new_node->label, new_node));
                for(int i = 0; i < tmp->neighbors.size(); i++)
                {
                    q.push(tmp->neighbors[i]);
                }
            }
        }

        q.push(node);
        while(!q.empty())
        {
            UndirectedGraphNode* tmp = q.front();
            q.pop();
            UndirectedGraphNode* existingnode = nodes[tmp->label];
            if(existingnode->neighbors.empty() && !tmp->neighbors.empty())
            {
                for(int i = 0; i < tmp->neighbors.size(); i++)
                {
                    existingnode->neighbors.push_back(nodes[tmp->neighbors[i]->label]);
                    q.push(tmp->neighbors[i]);
                }
            }
        }

        return nodes[node->label];
    }
};
