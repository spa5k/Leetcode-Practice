// Time - O(2^n) | Space - O(n)

// function getNthFib(n) {
//   if (n === 1) {
//     return 0;
//   }
//   if (n === 2) {
//     return 1;
//   }
//   return getNthFib(n - 1) + getNthFib(n - 2);
// }

// Time - O(n) | Space - O(n)
// function getNthFib(n, memoize = { 1: 0, 2: 1 }) {
//   if (n in memoize) {
//     return memoize[n];
//   }
//   memoize[n] = getNthFib(n - 1, memoize) + getNthFib(n - 2, memoize);
//   return memoize[n];
// }

// Time - O(n) | Space - O(1)

function getNthFib(n) {
  const arr = [0, 1]; // for 0/1/2 case;

  let counter = 3;

  while (counter <= n) {
    const nextFib = arr[0] + arr[1];
    arr[0] = arr[1];
    arr[1] = nextFib;
    counter++;
  }
  return n > 1 ? arr[1] : arr[0];
}
console.log(getNthFib(6));
