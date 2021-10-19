function tandemBicyle(red, blue, fastest) {
  blue.sort((a, b) => a - b);
  if (fastest) {
    red.sort((a, b) => b - a);
  } else {
    red.sort((a, b) => a - b);
  }

  let total = 0;
  for (let index = 0; index < blue.length; index++) {
    const element = blue[index];
    const redd = red[index];

    total += Math.max(redd, element);
  }

  return total;
}
