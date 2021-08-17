// Time - O(n) | Space - O(h) - h being height of tree
// Recursive
// const nodeDepthsSum = (root, depth = 0) => {
//   if (root === null) return 0;
//   return (
//     depth +
//     nodeDepthsSum(root.left, depth + 1) +
//     nodeDepthsSum(root.right, depth + 1)
//   );
// };

// Time - O(n)  | Space - O(h)
// Iterative
const nodeDepthsSum = (root) => {
  let sumOfDepths = 0;
  stack = [[root, 0]];
  while (stack.length > 0) {
    let nodeInfo = stack.pop();
    let node = nodeInfo[0];
    let depth = nodeInfo[1];

    if (!node) {
      continue;
    }
    sumOfDepths += depth;
    stack.push([node.left, depth + 1], [node.right, depth + 1]);
  }
  return sumOfDepths;
};
