// Time - O(n) | Space - O(n)

const generateDocument = (characters, document) => {
  const obj = {};
  for (const character of characters) {
    if (!obj[character]) {
      obj[character] = 1;
    } else {
      obj[character] += 1;
    }
  }

  for (const char of document) {
    if (!obj[char]) {
      return false;
    } else {
      obj[char] -= 1;
    }
  }
  return true;
};

console.log(generateDocument("me", "me"));
