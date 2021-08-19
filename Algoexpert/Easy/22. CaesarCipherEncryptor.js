// Time - O(n) | Space - O(n)

const caesarCipherEncryptor = (str, key) => {
  let output = "";
  const newKey = key % 26;
  for (let letter of str) {
    output += getNewLetter(letter, newKey);
  }
  return output;
};

function getNewLetter(letter, key) {
  const newLetterCode = letter.charCodeAt() + key;
  return newLetterCode <= 122
    ? String.fromCharCode(newLetterCode)
    : String.fromCharCode(96 + (newLetterCode % 122));
}
console.log(caesarCipherEncryptor("abcd"));
