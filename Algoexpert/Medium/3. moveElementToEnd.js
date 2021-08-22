// Time - O(n) | Space - O(1)

const moveElementToEnd = (arr, num) => {
  let i = 0;
  let j = arr.length - 1;

  while (i < j) {
    while (i < j && arr[j] === num) j--;
    if (arr[i] === num) {
      let temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
    }
    i++;
  }
  return arr;
};
console.log(moveElementToEnd([1, 2, 3, 42, 2, 2, 21, 2, 3, 34], 2));
