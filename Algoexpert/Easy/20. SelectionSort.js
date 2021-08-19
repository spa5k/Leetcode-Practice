// Time - O(n^2) | Space - O(1)

function selectionSort(array) {
  let startIdx = 0;
  while (startIdx < array.length - 1) {
    let smallestIdx = startIdx;

    for (let index = startIdx + 1; index < array.length; index++) {
      const element = array[index];
      if (array[smallestIdx] > element) {
        smallestIdx = index;
      }
    }
    const temp = array[smallestIdx];
    array[smallestIdx] = array[startIdx];
    array[startIdx] = temp;
    startIdx++;
  }
  return array;
}

console.log(selectionSort([1, 2, 4, 5, 56, 7, 7]));
