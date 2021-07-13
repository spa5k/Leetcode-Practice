const insertionSort = (array) => {
  for (let i = 1; i < array.length; i++) {
    const currentVal = array[i];
    let j = i - 1;
    console.log(j, i);
    for (j; j >= 0 && array[j] > currentVal; j--) {
      const element = array[j];
      array[j + 1] = element;
    }
    array[j + 1] = currentVal;
  }
  return array;
};

console.log(insertionSort([2, 1, 45, 12, 34, 454, 11, 36, 6, 156]));

// o(n)sqaure
