const divide = (arr, num) => {
  let min = 0;
  let max = arr.length - 1;

  while (min <= max) {
    let middle = Math.floor((min + max) / 2);
    console.log(middle);
    if (arr[middle] < num) {
      min = middle + 1;
    } else if (arr[middle] > num) {
      max = middle - 1;
    } else {
      return middle;
    }
  }
  return -1;
};

console.log(divide([1, 2, 3, 4, 5, 67, 87, 92, 234, 235], 92));
