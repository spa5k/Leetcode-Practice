const selectionSort = (arr) => {
  const swap = (arr, idx1, idx2) => ([arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]]);
  for (let i = 0; i < arr.length; i++) {
    let smallest = i;
    for (let j = i + 1; j <= arr.length; j++) {
      if (arr[j] < arr[smallest]) {
        smallest = j;
      }
    }

    i !== smallest && swap(arr, i, smallest);
  }
  return arr;
};

console.log(selectionSort([1, 2, 4, 10, 3, 4, 5, 6]));

// o(n)sqaure
