/*
 * @lc app=leetcode id=2236 lang=cpp
 *
 * [2236] Root Equals Sum of Children
 *
 * https://leetcode.com/problems/root-equals-sum-of-children/description/
 *
 * algorithms
 * Easy (89.89%)
 * Likes:    350
 * Dislikes: 571
 * Total Accepted:    48.8K
 * Total Submissions: 55.1K
 * Testcase Example:  '[10,4,6]'
 *
 * You are given the root of a binary tree that consists of exactly 3 nodes:
 * the root, its left child, and its right child.
 *
 * Return true if the value of the root is equal to the sum of the values of
 * its two children, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [10,4,6]
 * Output: true
 * Explanation: The values of the root, its left child, and its right child are
 * 10, 4, and 6, respectively.
 * 10 is equal to 4 + 6, so we return true.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,1]
 * Output: false
 * Explanation: The values of the root, its left child, and its right child are
 * 5, 3, and 1, respectively.
 * 5 is not equal to 3 + 1, so we return false.
 *
 *
 *
 * Constraints:
 *
 *
 * The tree consists only of the root, its left child, and its right child.
 * -100 <= Node.val <= 100
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
class Solution
{
public:
  bool checkTree(TreeNode *root)
  {
    int val_root = root->val;
    int val_left = root->left->val;
    int val_right = root->right->val;

    if (val_root == val_left + val_right)
    {
      return true;
    }
    return false;
  }
};
// @lc code=end
