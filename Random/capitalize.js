const capitalize = (str) => {
  const strArray = str.split("");
  let string = "";
  string += strArray[0].toUpperCase();
  for (let index = 1; index < strArray.length; index++) {
    if (strArray[index - 1] === " ") {
      string += strArray[index].toUpperCase();
    } else {
      string += strArray[index];
    }
  }
  return string;
};

console.log(capitalize("nice one Lol"));
