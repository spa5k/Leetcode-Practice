const prime = (num) => {
  // Create new Array with same size as the number
  const numArr = new Array(num + 1);
  // Fill all values with true;
  numArr.fill(true);
  // Flase the values at index 0 and 1
  numArr[0] = numArr[1] = false;
  // Loop from 2 to square root of the num
  for (let i = 2; i <= Math.sqrt(num); i++) {
    // false all multiples of this number
    for (let j = 2; i * j <= num; j++) {
      numArr[i * j] = false;
    }
  }
  // console.log(numArr);

  return numArr.reduce((accumulator, value, index) => {
    // console.log(ind)
    // console.log(acc);
    if (value === true) {
      return accumulator.concat(index);
    } else {
      return accumulator;
    }
  }, []);
};

console.log(prime(100));
