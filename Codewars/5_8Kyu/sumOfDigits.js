const sumOfDigits = (num) => {
  const res = num
    .toString()
    .split("")
    .reduce((a, b) => {
      return parseInt(a) + parseInt(b);
    });
  if (res.toString().length > 1) {
    return sumOfDigits(res);
  }

  return parseInt(res);
};
console.log(sumOfDigits(0));
