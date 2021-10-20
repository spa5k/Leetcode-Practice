// Time - O() | Space - O()

function productSum(array, depth = 1) {
  let sum = 0;
  array.forEach((element) => {
    sum += Array.isArray(element) ? productSum(element, depth + 1) : element;
  });
  return sum * depth;
}

console.log(productSum([1, 2, [3, 4]]));
