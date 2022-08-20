#include <iostream>
using namespace  std;
#include <vector>
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
    vector<int> traversal;
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
  void inorder(TreeNode *root, vector<int> &traversal)
  {
    if (!root)
      return;
    inorder(root->left, traversal);
    traversal.push_back(root->val);
    inorder(root->right, traversal);
  }
};