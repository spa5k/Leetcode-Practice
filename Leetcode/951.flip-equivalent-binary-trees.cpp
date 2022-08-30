/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
 *
 * https://leetcode.com/problems/flip-equivalent-binary-trees/description/
 *
 * algorithms
 * Medium (66.77%)
 * Likes:    1804
 * Dislikes: 80
 * Total Accepted:    118.1K
 * Total Submissions: 176.8K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]'
 *
 * For a binary tree T, we can define a flip operation as follows: choose any
 * node, and swap the left and right child subtrees.
 *
 * A binary tree X is flip equivalent to a binary tree Y if and only if we can
 * make X equal to Y after some number of flip operations.
 *
 * Given the roots of two binary trees root1 and root2, return true if the two
 * trees are flip equivalent or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 =
 * [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * Output: true
 * Explanation: We flipped at nodes with values 1, 3, and 5.
 *
 *
 * Example 2:
 *
 *
 * Input: root1 = [], root2 = []
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: root1 = [], root2 = [1]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each tree is in the range [0, 100].
 * Each tree will have unique node values in the range [0, 99].
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
public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2)
  {
    // If one is null, other should be null
    if (!root1 || !root2)
    {
      return !root1 && !root2;
    }
    // Roots must be equal
    if (root1->val != root2->val)
    {
      return false;
    }

    bool no_swap = (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
    bool swap = (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    return no_swap || swap;
  }
};
// @lc code=end
