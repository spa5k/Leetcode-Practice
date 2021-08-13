// Time - O(nlogn) | Space - O(1)

const minimumWaitingTime = (queries) => {
  queries.sort((a, b) => a - b);
  let totalWaitingTime = 0;

  for (let index = 0; index < queries.length; index++) {
    const duration = queries[index];
    const left = queries.length - (index + 1);
    totalWaitingTime += duration * left;
  }
  return totalWaitingTime;
};

console.log(minimumWaitingTime([1, 4, 5]));
