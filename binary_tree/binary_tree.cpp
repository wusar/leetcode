#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node->
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

public:
    vector<int> rightSideView(TreeNode *root)
    {
        // bfs search the tree
        bfs(root, 1, 0);

        return tree_view_result;
    }

private:
    void bfs(TreeNode *node, int node_id, int depth)
    {
        if (node == nullptr)
        {
            return;
        }
        if (depth_max_id.size() == depth)
        {
            depth_max_id.push_back(depth);
        }
        if (depth_max_id[depth] < node_id)
        {
            if (tree_view_result.size() == depth)
            {
                tree_view_result.push_back(node->val);
            }
            tree_view_result[depth] = node->val;
            depth_max_id[depth] = node_id;
        }
        if (node->left != nullptr)
        {
            bfs(node->left, node_id * 2, depth + 1);
        }
        if (node->right != nullptr)
        {
            bfs(node->right, node_id * 2 + 1, depth + 1);
        }
    }
    vector<int> depth_max_id;
    vector<int> tree_view_result;
};

int main()
{
}
