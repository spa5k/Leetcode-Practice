// Time - O(n) | Space - O(d)

const productArraySum = (arr, depth = 1) => {
  let sum = 0;
  arr.map((element) => {
    if (Array.isArray(element)) {
      sum += productArraySum(element, depth + 1);
    } else {
      sum += lement;
    }
  });
  return sum * depth;
};
