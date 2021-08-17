const getNthFib = (num) => {
  if (num === 1) {
    return 0;
  } else if (num === 2) {
    return 1;
  } else {
    return getNthFib(num - 1) + getNthFib(num - 2);
  }
};

console.log(getNthFib(10));
