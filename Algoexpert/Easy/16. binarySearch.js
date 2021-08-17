// Time - O(Log(n)) | Space - O(1)

const binarySearch = (array, target) => {
  return binarySearchHelper(array, target, 0, array.length - 1);
};

const binarySearchHelper = (array, target, left, right) => {
  while (left <= right) {
    const middle = Math.floor((left + right) / 2);
    const potentialMatch = array[middle];

    if (target === potentialMatch) {
      return middle;
    } else if (target < potentialMatch) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
};
