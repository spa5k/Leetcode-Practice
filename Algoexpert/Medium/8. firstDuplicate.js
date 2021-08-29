// // Time - O(n) | Space - O(n)

// function firstDuplicateValue(array) {
//   const seen = new Set();

//   for (const val of array) {
//     if (seen.has(val)) return val;
//     seen.add(val);
//   }

//   // Write your code here.
//   return -1;
// }

// Time - O(n) | Space - O(1)

function firstDuplicateValue(array) {
  for (const element of array) {
    const absVal = Math.abs(element);
    if (array[absVal - 1] < 0) return absVal;
    array[absVal - 1] *= -1;
  }

  // Write your code here.
  return -1;
}

console.log(firstDuplicateValue([1, 2, 3, 4, 2, 5]));
