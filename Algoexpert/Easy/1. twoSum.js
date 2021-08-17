// For Loop
// O(n^2) time | O(1) Space
// const twoSumFor = (array, num) => {
//   for (let i = 0; i < array.length; i++) {
//     const element = array[i];
//     for (let j = 0; j < array.length; j++) {
//       const element2 = array[j];
//       if (element + element2 === num) {
//         return [element, element2];
//       }
//     }
//   }
// };
// console.log(twoSumFor([1, 2, 3, 4, 5], 5));

// Hash table
// O(n) time | O(n) Space
// const twoSumHash = (array, target) => {
//   const lookup = {};
//   for (let index = 0; index < array.length; index++) {
//     const element = array[index];
//     const numberNeeded = target - element;
//     if (numberNeeded in lookup) {
//       return [numberNeeded, element];
//     } else {
//       lookup[element] = true;
//     }
//   }

//   return [];
// };

// console.log(twoSumHash([1, 2, 3, 4, 5], 5));

// Two Pointer
// O(nLog(n)) time | O(1) space
const twoSumTwoPointer = (array, target) => {
  const arr = array.sort((a, b) => a - b);
  let left = 0;
  let right = arr.length - 1;
  while (left < right) {
    const currentSum = arr[left] + arr[right];
    if (currentSum === target) {
      // arrayCollection.push();
      return [arr[left], arr[right]];
    } else if (currentSum < target) {
      left += 1;
    } else if (currentSum > target) {
      right -= 1;
    }
  }
  return [];
};
console.log(twoSumTwoPointer([1, 2, 3, 4, 5], 5));
