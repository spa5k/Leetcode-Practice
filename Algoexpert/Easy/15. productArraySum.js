// Time - O(n) | Space - O(d)

const productArraySum = (arr, depth = 1) => {
  let sum = 0;
  arr.map((element) => {
    sum += Array.isArray(element)
      ? productArraySum(element, depth + 1)
      : element;
  });
  return sum * depth;
};
