const linearSearch = (arr, val) => {
  for (let index = 0; index < arr.length; index++) {
    const element = arr[index];
    if (element === val) {
      return index;
    }
  }
  return -1;
};

console.log(linearSearch([1, 2, 3], 1));
