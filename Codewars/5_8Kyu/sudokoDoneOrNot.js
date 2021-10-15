const correctGridDimensions = 9 * 9;

const doneOrNot = (sudokoGrid) => {
  return getGridTotal(sudokoGrid) === correctGridDimensions &&
    getGridTotal(transpose(sudokoGrid)) === correctGridDimensions &&
    getGridTotal(getRegions(sudokoGrid)) === correctGridDimensions
    ? "Finished!"
    : "Try again!";
};

const getGridTotal = (sudokoGrid) => {
  return sudokoGrid
    .map((row) => new Set(row))
    .map((row) => row.size)
    .reduce((tempGrid, cell) => tempGrid + cell);
};

const transpose = (sudokoGrid) => {
  return sudokoGrid.map((col, i) => sudokoGrid.map((row) => row[i]));
};

// TODO refactor this horror show
const getRegions = (sudokoGrid) => {
  let one = [];
  let two = [];
  let three = [];
  for (let i = 0; i < sudokoGrid.length; i++) {
    for (let j = 0; j < 3; j++) {
      one.push(sudokoGrid[i][j]);
      two.push(sudokoGrid[i][j + 3]);
      three.push(sudokoGrid[i][j + 6]);
    }
  }
  let cubes = [...one, ...two, ...three];
  return createRegionsGrid(cubes);
};

const createRegionsGrid = (regions) => {
  let i,
    j,
    cubesNew = [],
    chunk = 9;
  for (i = 0, j = regions.length; i < j; i += chunk) {
    cubesNew.push(regions.slice(i, i + chunk));
  }
  return cubesNew;
};

const x = [
  [5, 3, 4, 6, 7, 8, 9, 1, 2],
  [6, 7, 2, 1, 9, 5, 3, 4, 8],
  [1, 9, 8, 3, 4, 2, 5, 6, 7],
  [8, 5, 9, 7, 6, 1, 4, 2, 3],
  [4, 2, 6, 8, 5, 3, 7, 9, 1],
  [7, 1, 3, 9, 2, 4, 8, 5, 6],
  [9, 6, 1, 5, 3, 7, 2, 8, 4],
  [2, 8, 7, 4, 1, 9, 6, 3, 5],
  [3, 4, 5, 2, 8, 6, 1, 7, 9],
];
