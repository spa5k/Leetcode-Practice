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

// @lapp=leetcode id=938 lang=cpp
//  *
//   * [938] Range Sum of BST
//    *
//     * https://leetcode.com/problems/range-sum-of-bst/description/
//      *
//       * algorithms
//        * Easy (85.27%)
//         * Likes:    4519
//          * Dislikes: 335
//           * Total Accepted:    654.3K
//            * Total Submissions: 767.3K
//             * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
//              *
//               * Given the root node of a binary search tree and two integers low and high,
//                * return the sum of values of all nodes with a value in the inclusive range
//                 * [low, high].
//                  *
//                   *
//                    * Example 1:
//                     *
//                      *
//                       * Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
//                        * Output: 32
//                         * Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 =
//                          * 32.
//                           *
//                            *
//                             * Example 2:
//                              *
//                               *
//                                * Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
//                                 * Output: 23
//                                  * Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 =
//                                   * 23.
//                                    *
//                                     *
//                                      *
//                                       * Constraints:
//                                        *
//                                         *
//                                          * The number of nodes in the tree is in the range [1, 2 * 10^4].
//                                           * 1 <= Node.val val >= low && root->val val:0;
//                                             }
//
//                                                 if (root->val right, low, high);
//                                                     } else if (root->val >high)
//                                                         {
//                                                               val+=rangeSumBST(root->left, low, high);
//                                                                   }
//                                                                       };
//                                                                       //  else {
//                                                                             val +=rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
//                                                                                 }@
//                                                                                     root->left=root->right=nullptr;lc c
//                                                                                         return val;ode=end
//                                                                                         code=start
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
  int ans = 0;
  int sumOfLeftLeaves(TreeNode *root)
  {
    if (!root || root == nullptr)
      return 0;

    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
    {
      ans += root->left->val;
    }
    sumOfLeftLeaves(root->left);
    sumOfLeftLeaves(root->right);

    return ans;
  }
};
// @lc code=end
