// Time - O(nlogn) | Space - O(n) // Will be O(1) if only original array is sorted
const nonConstrictuleChange = (arr) => {
  const sortedArr = arr.sort((a, b) => a - b);
  if (sortedArr[0] > 1) {
    return 1;
  }

  let change = 0;
  // because one will be the minimal change that can not be returned if a coin is bigger;

  for (let index = 0; index < sortedArr.length; index++) {
    const coin = sortedArr[index];
    if (coin > change + 1) {
      return change + 1;
    }
    change += coin;
  }

  return change + 1;
};

console.log(nonConstrictuleChange([5, 7, 1, 1, 2, 3, 22]));
