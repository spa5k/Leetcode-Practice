function binarySearch(arr, target) {
  return helper(arr, target, 0, arr.length - 1);
}

function helper(arr, target, left, right) {
  while (left <= right) {
    let middleLength = Math.floor((left + right) / 2);
    let middle = arr[middleLength];
    if (middle === target) {
      return middleLength;
    } else if (middle > target) {
      right = middleLength - 1;
    } else {
      left = middleLength + 1;
    }
  }
  return -1;
}

console.log(binarySearch([0, 1, 21, 33, 45, 45, 61, 72, 73], 33));
