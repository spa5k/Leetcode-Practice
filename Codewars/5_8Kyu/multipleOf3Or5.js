function solution(number) {
  let output = 0;
  for (let index = 0; index < number; index++) {
    if (index % 3 === 0) {
      output += index;
      continue;
    } else if (index % 5 === 0) {
      output += index;
    } else {
      continue;
    }
  }
  return output;
}

console.log(solution(10));
