// For Loop
// O(n) time | O(1) space
const validatingSubFor = (arr, sequence) => {
  let two = 0;
  for (const num of arr) {
    if (two === sequence.length) {
      break;
    }
    if (sequence[two] === num) {
      two++;
    }
  }

  if (two === sequence.length) {
    return true;
  }
  return false;
};

// While Loop
// O(n) time | O(1) space
const validatingSubWhile = (arr, sequence) => {
  let one = 0;
  let two = 0;
  while (one < arr.length && two < sequence.length) {
    if (sequence[two] === arr[one]) {
      two++;
    }
    one++;
  }
  if (two === sequence.length) {
    return true;
  }
  return false;
};

console.log(
  validatingSubFor([1, 2, 5, 6, 8, 3, 1, 3, 45, 4, 51], [2, 6, 3, 45])
);
