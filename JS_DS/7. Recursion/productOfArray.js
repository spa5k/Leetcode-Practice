// Helper way
const productOfArray = (arr) => {
  let sum = 1;

  function helper(arr) {
    if (arr.length === 0) {
      return 1;
    }

    sum = sum * arr[0];
    helper(arr.slice(1));
  }

  helper(arr);

  return sum;
};
// Normal way
function productOfArray1(arr) {
  if (arr.length === 0) {
    return 1;
  }
  return arr[0] * productOfArray1(arr.slice(1));
}

console.log(productOfArray1([1, 2, 3]));

console.log(productOfArray([1, 2, 3]));
