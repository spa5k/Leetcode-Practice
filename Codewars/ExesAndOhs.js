const exesAndOhs = (string) => {
  if (!string) return true;
  let oCount = 0;
  let xCount = 0;

  for (let index = 0; index < string.length; index++) {
    const element = string[index].toLowerCase();
    if (element === "o") {
      oCount++;
      continue;
    }

    if (element === "x") {
      xCount++;
      continue;
    }
  }

  if (oCount === xCount || (oCount === 0 && xCount === 0)) {
    return true;
  }

  return false;
};

console.log(exesAndOhs("x"));
