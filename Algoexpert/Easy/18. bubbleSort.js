// Time - O(n^2) | Space - O(1)

const bubbleSort = (array) => {
  let isSorted = false;
  let counter = 0;
  while (!isSorted) {
    isSorted = true;
    for (let index = 0; index < array.length - 1 - counter; index++) {
      let element = array[index];
      let elementSecond = array[index + 1];
      if (element > elementSecond) {
        const temp = element;
        array[index] = elementSecond;
        array[index + 1] = temp;
        isSorted = false;
      }
    }
    counter += 1;
  }
  return array;
};

console.log(bubbleSort([4, 2, 5, 1, 4, 6, 5, 3]));
