

/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (58.05%)
 * Likes:    4706
 * Dislikes: 88
 * Total Accepted:    493.3K
 * Total Submissions: 848.7K
 * Testcase Example:  '[1,2,3]'
 *
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 *
 * Each root-to-leaf path in the tree represents a number.
 *
 *
 * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 *
 *
 * Return the total sum of all root-to-leaf numbers. Test cases are generated
 * so that the answer will fit in a 32-bit integer.
 *
 * A leaf node is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3]
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [4,9,0,5,1]
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * 0 <= Node.val <= 9
 * The depth of the tree will not exceed 10.
 *
 *
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
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <headers.h>
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

using namespace std;

// class Solution
// {

// public:
//   int sumNumbers(TreeNode *root)
//   {
//     return helper(root, 0);
//   }
//   int helper(TreeNode *node, int curr)
//   {
//     if (!node)
//       return 0;

//     curr = curr * 10 + node->val;

//     if (node->left == nullptr && node->right == nullptr)
//     {
//       return curr;
//     }

//     int left = helper(node->left, curr);

//     int right = helper(node->right, curr);
//     return right + left;
//   }
// };
// class Solution
// {
// public:
//   int res = 0;

// public:
//   int sumNumbers(TreeNode *root)
//   {
//     helper(root, res);
//     return res;
//   }
//   void helper(TreeNode *node, int curr)
//   {
//     if (!node)
//       return;

//     curr = curr * 10 + node->val;
//     if (!node->left && !node->right)
//     {
//       // This is
//       res += curr;
//       return;
//     }

//     helper(node->left, curr);

//     helper(node->right, curr);
//   }
// };

class Solution
{
public:
  int res = 0;

public:
  int sumNumbers(TreeNode *root)
  {
    helper(root, res);
    return res;
  }
  void helper(TreeNode *node, int curr)
  {
    if (!node)
    {
      return;
    }
    curr = node->val + curr * 10;
    if (!node->left && !node->right)
    {
      res += curr;
      return;
    }
    helper(node->right, curr);
    helper(node->left, curr);
  }
};

// @lc code=end
