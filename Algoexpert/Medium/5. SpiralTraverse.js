// Time - O(n) | Space - O(n)

function spiralTraverse(array) {
  // Write your code here.
  const res = [];

  let startRow = 0;
  let endRow = array.length - 1;

  let startCol = 0;
  let endCol = array[0].length - 1;

  while (startRow <= endRow && startCol <= endCol) {
    for (let col = startCol; col <= endCol; col++) {
      res.push(array[startRow][col]);
    }

    for (let row = startRow + 1; row <= endRow; row++) {
      res.push(array[row][endCol]);
    }

    for (let col = endCol - 1; col >= startCol; col--) {
      if (startRow === endRow) break;
      res.push(array[endRow][col]);
    }

    for (let row = endRow - 1; row > startRow; row--) {
      if (startCol === endCol) break;
      res.push(array[row][startCol]);
    }

    startRow++;
    endRow--;
    startCol++;
    endCol--;
  }
  return result;
}
