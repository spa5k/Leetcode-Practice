// Time - O(n) | Space - O(1)

const find3LargestNumbers = (array) => {
  let one, two, three;

  for (let index = 0; index < array.length; index++) {
    const element = array[index];

    if (!three || three < element) {
      if (one < two) {
        one = two;
      }
      two = three;
      three = element;
      continue;
    }

    if (!two || two < element) {
      one = two;
      two = element;
      continue;
    }

    if (!one || one < element) {
      one = element;
    }
  }
  return [one, two, three];
};

console.log(find3LargestNumbers([141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]));
