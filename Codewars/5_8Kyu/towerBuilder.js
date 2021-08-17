// 1 - 1
// 2 - 3
// 3 - 5
// 4 - 7
// 5 - 9
// 6 - 11

function towerBuilder(floors) {
  let space,
    star,
    tower = [];
  for (i = 1; i <= floors; i++) {
    space = " ".repeat(floors - i);
    star = "*".repeat(2 * i - 1);
    tower.push(`${space}${star}${space}`);
  }
  return tower;
}

console.log(towerBuilder(5));
