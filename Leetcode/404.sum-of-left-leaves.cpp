/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (55.44%)
 * Likes:    3687
 * Dislikes: 256
 * Total Accepted:    377.1K
 * Total Submissions: 675.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the sum of all left leaves.
 *
 * A leaf is a node with no children. A left leaf is a leaf that is the left
 * child of another node.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 24
 * Explanation: There are two left leaves in the binary tree, with values 9 and
 * 15 respectively.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
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
  int ans = 0;
  int sumOfLeftLeaves(TreeNode *root)
  {
    if (!root)
      return 0;

    if (root != NULL)
    {
      if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
      {
        ans += root->left->val;
      }
      sumOfLeftLeaves(root->left);
      sumOfLeftLeaves(root->right);
    }
    return ans;
  }
};
// @lc code=end
