const runLengthEncoding = (str) => {
  let output = "";
  let count = 1;
  for (let index = 1; index < str.length; index++) {
    const element = str[index];
    const previousElement = str[index - 1];
    if (previousElement !== element || count === 9) {
      output += `${count.toString()}${previousElement}`;
      count = 0;
    }
    count++;
  }

  output += `${count.toString()}${str[str.length - 1]}`;
  return output;
};
console.log(runLengthEncoding("aaaabcd"));
