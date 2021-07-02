// Swap Version
function bubbleSort(array) {
  let noSwaps;
  for (let i = array.length; i > 0; i--) {
    noSwaps = true;
    for (let j = 0; j < i - 1; j++) {
      console.log(array[j], array[j + 1]);
      if (array[j] > array[j + 1]) {
        // SWAP
        let temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        noSwaps = false;
      }
      if (noSwaps) break;
    }
  }
  return array;
}
// A bit better
// function bubbleSort(array) {
//   for (let i = array.length; i > 0; i--) {
//     for (let j = 0; j < i - 1; j++) {
//       console.log(array[j], array[j + 1]);
//       if (array[j] > array[j + 1]) {
//         // SWAP
//         let temp = array[j];
//         array[j] = array[j + 1];
//         array[j + 1] = temp;
//       }
//     }
//   }
//   return array;
// }

console.log(bubbleSort([1, 14, 22, 66, 43, 45]));

// Naive Solution
// function bubbleSort(array) {
//   for (let i = 0; i < array.length; i++) {
//     for (let j = 0; j < array.length - i; j++) {
//       console.log(array[j], array[j + 1]);
//       if (array[j] > array[j + 1]) {
//         // SWAP
//         let temp = array[j];
//         array[j] = array[j + 1];
//         array[j + 1] = temp;
//       }
//     }
//   }
//   return array;
// }

// console.log(bubbleSort([1, 14, 22, 66, 43, 123, 45]));
