function threeNumberSum(array, targetSum) {
  array.sort((a, b) => a - b);
  const triples = [];
  for (let index = 0; index < array.length - 2; index++) {
    const element = array[index];
    let left = index + 1;
    let right = array.length - 1;

    while (left < right) {
      const currentSum = array[index] + array[left] + array[right];
      if (currentSum === targetSum) {
        triples.push([array[index], array[left], array[right]]);
        left += 1;
        right -= 1;
      } else if (currentSum < targetSum) {
        left += 1;
      } else {
        right -= 1;
      }
    }
  }
  return triples;
}
