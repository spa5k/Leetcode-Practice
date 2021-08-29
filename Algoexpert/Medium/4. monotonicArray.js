// const isMonotonic = (array, two = 1) => {
//   if (array.length <= 2) return true;
//   console.log(array.length);
//   if (two >= array.length) {
//     return true;
//   }
//   const one = 0;
//   if (array[one] === array[two]) {
//     return isMonotonic(array, (two += 1));
//   }

//   const type = array[one] < array[two] ? "increasing" : "decreasing";
//   console.log(array[one], array[two], type);
//   for (let index = 2; index < array.length; index++) {
//     const currentElement = array[index];
//     const previousElement = array[two];
//     console.log(currentElement, previousElement, type);
//     if (currentElement === previousElement) continue;

//     if (currentElement > previousElement && type === "increasing") continue;
//     if (currentElement < previousElement && type === "decreasing") continue;

//     return false;
//   }
//   return true;
// };

// console.log(isMonotonic([-1, -5, -10, -1100, -900, -1101, -1102, -9001]));

const isMonotonic = (array) => {
  if (array.length <= 2) return true;

  let direction = array[1] - array[0];
  console.log(direction);

  for (let i = 2; i < array.length; i++) {
    const element = array[i];
    const previousElement = array[i - 1];
    if (direction === 0) {
      direction = element - previousElement;
      continue;
    }

    if (breakDirection(direction, previousElement, element)) {
      return false;
    }
  }
  return true;
};

function breakDirection(direction, prev, curr) {
  const diff = curr - prev;
  if (direction > 0) {
    return diff < 0;
  }
  return diff > 0;
}

console.log(isMonotonic([2, 2, 2, 1, 4, 5]));
