function flatten(arr) {
  const newArr = [];
  for (let index = 0; index < arr.length; index++) {
    if (Array.isArray(arr[i])) {
      newArr = newArr.concat(flatten(arr[i]));
    } else {
      newArr.push(arr[i]);
    }
  }
  return newArr;
}
