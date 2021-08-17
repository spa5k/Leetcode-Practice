// Time - O(nlog(n)) | Space - O(1)

const tandemBicycle = (blue, red, fastest) => {
  blue.sort((a, b) => a - b);
  let total = 0;

  if (fastest) {
    red.sort((a, b) => b - a);
  } else {
    red.sort((a, b) => a - b);
  }

  for (let index = 0; index < blue.length; index++) {
    const blueRider = blue[index];
    const redRider = red[index];
    total += Math.max(blueRider, redRider);
  }

  return total;
};

console.log(tandemBicycle([3, 6, 7, 2, 1], [5, 5, 3, 9, 2], false));
