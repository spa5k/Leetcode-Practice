// Time - O(nlog(n) mlog(m)) | Space - O(1)

const smallestNumber = (arr1, arr2) => {
  arr1.sort((a, b) => a - b);
  arr2.sort((a, b) => a - b);

  let output = [];
  let smallest = Infinity;
  let arr1Index = 0;
  let arr2Index = 0;

  while (arr1Index < arr1.length && arr2Index < arr2.length) {
    let firstNum = arr1[arr1Index];
    let secondNum = arr2[arr2Index];

    if (firstNum < secondNum) {
      const sum = secondNum - firstNum;
      if (smallest > sum) {
        smallest = sum;
        output = [firstNum, secondNum];
      }
      arr1Index++;
    } else if (firstNum > secondNum) {
      const sum = firstNum - secondNum;
      if (smallest > sum) {
        smallest = sum;
        output = [firstNum, secondNum];
      }
      arr2Index++;
    } else {
      return [firstNum, secondNum];
    }
  }
  return output;
};

console.log(smallestNumber([11, 5, 10, 20, 28, 3], [26, 134, 135, 15, 17]));
