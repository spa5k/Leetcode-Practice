const longestPeak = (array) => {
  let longestPeakLength = 0;
  let i = 1;
  while (i < array.length - 1) {
    const isPeak = array[i - 1] < array[i] && array[i + 1] < array[i];

    if (!isPeak) {
      i++;
      continue;
    }

    let leftIndex = i - 2;
    while (leftIndex >= 0 && array[leftIndex] < array[leftIndex + 1]) {
      leftIndex--;
    }

    let rightIdex = i + 2;
    while (
      rightIdex < array.length &&
      array[rightIdex] < array[rightIdex - 1]
    ) {
      rightIdex++;
    }

    const currentPeak = rightIdex - leftIndex - 1;

    longestPeakLength = Math.max(currentPeak, longestPeakLength);
    i = rightIdex;
  }
  return longestPeakLength;
};
