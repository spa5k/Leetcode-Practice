const minimumWaitingTime = (queries) => {
  queries.sort((a, b) => a - b);
  let currentWaitingTime = 0;
  for (let index = 0; index < queries.length; index++) {
    const element = queries[index];
    const queriesLeft = queries.length - (index + 1);
    currentWaitingTime += element * queriesLeft;
  }
  return currentWaitingTime;
};

console.log(minimumWaitingTime([1, 4, 5, 10, 1, 1, 2, 2]));
