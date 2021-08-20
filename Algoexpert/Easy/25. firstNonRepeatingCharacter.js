const firstNonRepeatingCharacter = (str) => {
  let count = {};

  for (const char of str) {
    if (count[char]) {
      count[char] += 1;
    } else {
      count[char] = 1;
    }
  }

  for (let index = 0; index < str.length; index++) {
    const element = str[index];
    if (count[element] === 1) {
      return index;
    }
  }

  return -1;
};

console.log(firstNonRepeatingCharacter("aaaaaabcd"));
