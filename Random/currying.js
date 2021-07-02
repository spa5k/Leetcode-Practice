// let multiply = function (x, y) {
//   return x * y;
// };

let multiply = function(x) {
  return function(y) {
    console.log(x);
    console.log(y);
    console.log(x * y);
    return x * y;
  };
};

// console.log(multiply(2)(2));

let multiplyByTwo = multiply(2);
console.log(multiplyByTwo(4));

let multipleByThree = multiply(3);
console.log(multipleByThree(5));
