// Time - O(n) | Space - O(n)
// Recursive
const branchRoot = (tree) => {
  const sums = [];
  branchRootSumHelper(tree, 0, sums);

  return sums;
};

const branchRootSumHelper = (node, runningSum, sums) => {
  if (!node) {
    return;
  }
  const newRunningSum = runningSum + node.value;

  if (!node.left && !node.right) {
    sums.push(newRunningSum);
    return;
  }

  branchRootSumHelper(node.left, newRunningSum, sums);
  branchRootSumHelper(node.right, newRunningSum, sums);
};
