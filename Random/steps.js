const steps = (num) => {
  let step = "";
  for (let index = 0; index < num; index++) {
    const hashes = "#";
    let x = "#" + hashes.repeat(index);
    console.log(x);
    console.log(hashes);
    step += x + " ";
    console.log(x);
  }
  return step;
};

console.log(steps(10));

const recursiveSteps = (n, row = 0, stair = "") => {
  if (n === row) {
    return;
  }
  if (n === stair.length) {
    console.log(stair);
    steps(n, row + 1);
    return;
  }

  if (stair.length <= row) {
    stair += "#";
  } else {
    star += "";
  }
  return steps(n, row, stair);
};

console.log(recursiveSteps(10));
