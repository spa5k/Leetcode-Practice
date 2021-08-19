// Time - O(n^2) | Space - O(n)
// Iterative
// const isPalindrome = (str) => {
//   return str === str.split("").reverse().join("") ? true : false;
// };
// console.log(palindromeCheck("abcdcba"));

// Recursive
// Time - O(n) | Space - O(n)

// const isPalindrome = (str, i = 0) => {
//   const reversedCharacter = str.length - 1 - i;
//   return i >= reversedCharacter
//     ? true
//     : str[i] === str[reversedCharacter] && isPalindrome(str, i + 1);
// };
// console.log(isPalindrome("abcba"));

// Recursive
// Time - O(n) | Space - O(1)

const isPalindrome = (str) => {
  let leftIndex = 0;
  let rightIndex = str.length - 1;
  while (leftIndex < rightIndex) {
    if (str[leftIndex] !== str[rightIndex]) {
      return false;
    }
    leftIndex++;
    rightIndex--;
  }
  return true;
};
console.log(isPalindrome("abcba"));
