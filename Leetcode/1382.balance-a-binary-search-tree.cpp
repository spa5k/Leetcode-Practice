/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
 *
 * https://leetcode.com/problems/balance-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (80.51%)
 * Likes:    2156
 * Dislikes: 59
 * Total Accepted:    103.6K
 * Total Submissions: 128.5K
 * Testcase Example:  '[1,null,2,null,3,null,4]'
 *
 * Given the root of a binary search tree, return a balanced binary search tree
 * with the same node values. If there is more than one answer, return any of
 * them.
 *
 * A binary search tree is balanced if the depth of the two subtrees of every
 * node never differs by more than 1.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,null,3,null,4,null,null]
 * Output: [2,1,3,null,null,null,4]
 * Explanation: This is not the only correct answer, [3,1,4,null,2] is also
 * correct.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,1,3]
 * Output: [2,1,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * 1 <= Node.val <= 10^5
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// #include <vector>
// using namespace std;
// struct TreeNode
// {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution
{
  vector<TreeNode *> sorted;

public:
  TreeNode *balanceBST(TreeNode *root)
  {
    inorder(root);
    return createTree(0, sorted.size() - 1);
  }
  void inorder(TreeNode *root)
  {
    if (!root)
      return;
    inorder(root->left);
    sorted.push_back(root);
    inorder(root->right);
  }

  TreeNode *createTree(int start, int end)
  {
    if (start > end)
    {
      return nullptr;
    }
    int mid = (end - start) / 2 + start;
    TreeNode *node = sorted[mid];
    node->left = createTree(start, mid - 1);
    node->right = createTree(mid + 1, end);
    return node;
  }
};
// @lc code=end
