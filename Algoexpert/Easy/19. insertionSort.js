// Time - O(n^2) | Space - O(1)

const insertionSort = (array) => {
  for (let index = 1; index < array.length; index++) {
    let j = index;

    while (j > 0 && array[j] < array[j - 1]) {
      let temp = array[j];
      array[j] = array[j - 1];
      array[j - 1] = temp;
      j--;
    }
  }
  return array;
};

console.log(insertionSort([1, 2, 1, 4, 3, 2, 2, 4, 45, 4, 23, 234]));
