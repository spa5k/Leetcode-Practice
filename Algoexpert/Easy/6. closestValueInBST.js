// Average- Time - O(Log(n)) || Space - O(Log(n))
// Worst- Time - O(n) || Space - O(n)
// Recursive
// const findClosestValueInBst = (tree, target) => {
//   let closest = 0;

//   return findClosestValueInBstHelper(tree, target, closest);
// };

// const findClosestValueInBstHelper = (tree, target, closest) => {
//   if (!tree) {
//     return closest;
//   }

//   if (Math.abs(target - closest) > Math.abs(target - tree.value)) {
//     closest = tree.value;
//   }

//   if (target < tree.value) {
//     return findClosestValueInBstHelper(tree.left, target, closest);
//   } else if (target > tree.value) {
//     return findClosestValueInBstHelper(tree.right, target, closest);
//   } else {
//     return closest;
//   }
// };

// Average- Time - O(Log(n)) || Space - O(1)
// Worst- Time - O(n) || Space - O(1)
// Iterative
const findClosestValueInBst = (tree, target) => {
  let closest = 0;

  return findClosestValueInBstHelper(tree, target, closest);
};

const findClosestValueInBstHelper = (tree, target, closest) => {
  let currentNode = tree;
  while (currentNode) {
    if (Math.abs(target - closest) > Math.abs(target - currentNode.value)) {
      closest = currentNode.value;
    }

    if (target < currentNode.value) {
      currentNode = tree.left;
    } else if (target > currentNode.value) {
      currentNode = currentNode.right;
    } else {
      break;
    }
  }
  return closest;
};
