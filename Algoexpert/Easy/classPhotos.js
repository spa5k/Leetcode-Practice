// Time - O(nlog(n)) | Space - O(1)

const classPhotos = (red, blue) => {
  red.sort((a, b) => a - b);
  blue.sort((a, b) => a - b);

  let firstRowColor = red[0] > blue[0] ? "blue" : "red";

  for (let index = 0; index < red.length; index++) {
    const redIndex = red[index];
    const blueIndex = blue[index];

    if (firstRowColor === "red") {
      if (redIndex >= blueIndex) return false;
    } else if (blueIndex >= redIndex) return false;
  }

  return true;
};

console.log(
  classPhotos([4, 4, 4, 4, 4, 4, 5, 20], [1, 1, 1, 1, 1, 19, 19, 21])
);
