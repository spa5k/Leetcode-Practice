// Time - O(nlogn) - Space O(n)
// const squareSortedArray = (arr) => {
//   const newArr = arr.map((i) => i * i);
//   return newArr.sort((a, b) => a - b);
// };

// console.log(squareSortedArray([-7, 3, 4, 5]));

// Time - O(n) | Space - O(n) // n=length of given array
// const squareSortedArray = (arr) => {
//   let start = 0;
//   let end = arr.length - 1;
//   let insertingIndex = arr.length - 1;
//   const newArr = new Array(arr.length);
//   newArr.fill(0);

//   while (start < end) {
//     const first = Math.abs(arr[start]);
//     const last = Math.abs(arr[end]);
//     if (first > last) {
//       newArr[insertingIndex] = first * first;
//       start++;
//     } else {
//       newArr[insertingIndex] = last * last;
//       end--;
//     }
//     insertingIndex--;
//   }

//   newArr[0] = arr[start] * arr[start];

//   return newArr;
// };

// Algo original sol
// Time - O(n) | Space - O(n) // n=length of given array
const squareSortedArray = (arr) => {
  let smallerValIdx = 0;
  let largerValIdx = arr.length - 1;
  const newArr = new Array(arr.length).fill(0);
  for (let idx = arr.length - 1; idx >= 0; idx--) {
    const smallerValue = arr[smallerValIdx];
    const largerValue = arr[largerValIdx];
    if (Math.abs(smallerValue) > Math.abs(largerValue)) {
      newArr[idx] = smallerValue * smallerValue;
      smallerValIdx++;
    } else {
      newArr[idx] = largerValue * largerValue;
      largerValIdx--;
    }
  }
  return newArr;
};

console.log(squareSortedArray([-7, -5, -4, 3, 6, 8, 9]));
// [0,0,0,49]
