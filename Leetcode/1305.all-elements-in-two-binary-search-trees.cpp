/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 *
 * https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (79.70%)
 * Likes:    2450
 * Dislikes: 70
 * Total Accepted:    173K
 * Total Submissions: 217.1K
 * Testcase Example:  '[2,1,4]\n[1,0,3]'
 *
 * Given two binary search trees root1 and root2, return a list containing all
 * the integers from both trees sorted in ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: root1 = [2,1,4], root2 = [1,0,3]
 * Output: [0,1,1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: root1 = [1,null,8], root2 = [8,1]
 * Output: [1,1,8,8]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each tree is in the range [0, 5000].
 * -10^5 <= Node.val <= 10^5
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
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
  {
    stack<TreeNode *> st1, st2;
    vector<int> res;

    while (root1 || root2 || !st1.empty() || !st2.empty())
    {
      while (root1)
      {
        st1.push(root1);
        root1 = root1->left;
      }
      while (root2)
      {
        st2.push(root2);
        root2 = root2->left;
      }
      if (st2.empty() || (!st1.empty() && st1.top()->val <= st2.top()->val))
      {
        root1 = st1.top();
        st1.pop();
        res.push_back(root1->val);
        root1 = root1->right;
      }
      else
      {
        root2 = st2.top();
        st2.pop();
        res.push_back(root2->val);
        root2 = root2->right;
      }
    }
    return res;
  }
};
// @lc code=end
