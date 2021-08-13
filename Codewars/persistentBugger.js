// Time - O(n) | Space - O(1)

function persistence(num) {
  let count = 0;
  while (num.toString().length > 1) {
    const split = num.toString().split("");
    const multiplication = split.reduce((a, b) => a * b);
    count++;
    num = multiplication;
  }
  return count;
}

console.log(persistence(39));
