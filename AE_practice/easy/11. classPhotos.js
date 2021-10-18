function classPhotos(redShirtHeights, blueShirtHeights) {
  redShirtHeights.sort((a, b) => a - b);
  blueShirtHeights.sort((a, b) => a - b);

  const firstRowColor =
    redShirtHeights[0] > blueShirtHeights[0] ? "blue" : "red";

  for (let index = 0; index < redShirtHeights.length; index++) {
    const red = redShirtHeights[index];
    const blue = blueShirtHeights[index];

    if (firstRowColor === "red") {
      if (red >= blue) return false;
    } else if (red <= blue) return false;
  }
  return true;
}
