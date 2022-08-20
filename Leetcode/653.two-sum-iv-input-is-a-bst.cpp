/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (59.25%)
 * Likes:    4236
 * Dislikes: 209
 * Total Accepted:    346.1K
 * Total Submissions: 584.1K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given the root of a Binary Search Tree and a target number k, return true if
 * there exist two elements in the BST such that their sum is equal to the
 * given target.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], k = 28
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root is guaranteed to be a valid binary search tree.
 * -10^5 <= k <= 10^5
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
// class Solution
// {
// public:
//   bool findTarget(TreeNode *root, int k)
//   {
//     if (!root)
//       return false;
//     if (s.count(k - root->val))
//       return true;
//     s.insert(root->val);
//     return findTarget(root->left, k) || findTarget(root->right, k);
//   }

// private:
//   unordered_set<int> s;
// };
#include <vector>//;
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
  bool findTarget(TreeNode *root, int k)
  {
    if (!root)
      return false;
    std::vector<int> traversal;
    inorder(root, traversal);
    int left = 0;
    int right = traversal.size() - 1;

    while (left < right)
    {
      if (traversal
                  [left] +
              traversal[right] ==
          k)
      {
        return true;
      }
      else if (traversal[left] + traversal[right] > k)
      {
        /* code */
        right--;
      }
      else
      {
        left++;
      }
    }
  }
  void inorder(TreeNode *root, std::vector<int> &traversal)
  {
    if (!root)
      return;
    inorder(root->left, traversal);
    traversal.push_back(root->val);
    inorder(root->right, traversal);
  }
};
// @lc code=end
