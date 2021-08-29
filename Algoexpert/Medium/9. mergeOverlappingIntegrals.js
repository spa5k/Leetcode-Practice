// Time - O(nlog(n)) | Space - O(n)

function mergeOverlappingIntervals(array) {
  const sortedIntervals = array.sort((a, b) => a[0] - b[0]);

  const output = [];
  let currentInterval = sortedIntervals[0];

  output.push(currentInterval);

  for (const nextInterval of sortedIntervals) {
    const currentEnd = currentInterval[1];
    const nextStart = nextInterval[0];
    const nextEnd = nextInterval[1];

    if (currentEnd >= nextStart) {
      currentInterval[1] = Math.max(currentEnd, nextEnd);
    } else {
      currentInterval = nextInterval;
      output.push(currentInterval);
    }
  }

  return output;
}
