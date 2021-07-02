let arr = ["x", "y", [1, 2], [3, 4], [5, 6, 7, 8, 9], [10, 11, 12, [1, 2, 3]]];

const flattened = [].concat.apply([], arr);
console.log([].concat(...arr));
console.log(flattened);
console.log(arr.flat(2));

Array.prototype.myFlat = function(depth) {
  if (depth === undefined) {
    depth = 1;
  }

  const flatten = function(arr, depth) {
    // If depth is 0, return the array as-is
    if (depth < 1) {
      return arr.slice();
    }

    // Otherwise, concatenate into the parent array
    return arr.reduce(function(acc, val) {
      console.log(acc, val, Array.isArray(val));
      return acc.concat(Array.isArray(val) ? flatten(val, depth - 1) : val);
    }, []);
  };
  return flatten(this, depth);
};

console.log(arr.myFlat(3));
