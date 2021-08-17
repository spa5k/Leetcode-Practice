const uniqueInOrder = (array) => {
  let result = [];
  let lastElement = "";

  for (let index = 0; index < array.length; index++) {
    const element = array[index];
    if (lastElement !== element) {
      result.push(element);
      lastElement = element;
    }
  }
  return result;
};

console.log(uniqueInOrder("AAAABBBCCDAABBB"));
