/**
 * @typedef {string} str
 */

const reverse = (str) => {
  if (str.length <= 1) return str;
  return palindrome(str.slice(1)) + str[0];
};
console.log(palindrome("abc"));
