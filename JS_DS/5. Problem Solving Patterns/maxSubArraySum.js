const maxSubArraySum = (arr, num) => {
  let maxSum = 0;
  let tempSum = 0;
  if (arr.length < num) {
    return null;
  }

  for (let index = 0; index < num; index++) {
    maxSum += arr[index];
  }

  tempSum = maxSum;

  for (let i = num; i < arr.length; i++) {
    tempSum = tempSum - arr[i - num] + arr[i];
    maxSum = Math.max(maxSum, tempSum);
  }
  return maxSum;
};

console.log(maxSubArraySum([5, 2, 3, 7, 42, 21, 14, 34, 45], 3));

// const maxSubArraySum = (arr, num) => {
//   if (num > arr.length) {
//     return null;
//   }

//   let max = -Infinity;

//   for (let i = 0; i < arr.length - num + 1; i++) {
//     let temp = 0;
//     for (let j = 0; j < num; j++) {
//       temp += arr[i + j];
//     }
//     max = Math.max(temp, max);
//     console.log(max, temp);
//   }
//   return max;
// };
