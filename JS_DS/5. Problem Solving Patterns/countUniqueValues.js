// 2 pointers
const uniqueNumbers = (arr) => {
  let p1 = 2;
  let p2 = 1;

  while (p2 < arr.length) {
    if (arr[p1] !== arr[p2]) {
      p1++;
      arr[p1] = arr[p2];
    }
    p2++;
  }
  console.log(arr);
  console.log(p1);
};

console.log(uniqueNumbers([1, 2, 3, 4, 5, 5, 6, 6, 6, 7, 8, 9, 76, 91]));

// Simple way
// const uniqueNumbers = (arr) => {
//   const uniquearr = [];
//   arr.map((i) => {
//     if (uniquearr.indexOf(i) === -1) {
//       uniquearr.push(i);
//     }
//   });
//   return uniquearr.length;
// };

// console.log(uniqueNumbers([1, 2, 3, 4, 4, 4, 7, 7, 12, 12, 14]));
