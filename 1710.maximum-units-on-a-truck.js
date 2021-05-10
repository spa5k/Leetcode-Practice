/*
 * @lc app=leetcode id=1710 lang=javascript
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
/**
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
const maximumUnits = (boxTypes, truckSize) => {
  boxTypes.sort((a, b) => b[1] - a[1]);

  let units = 0;

  for (const [boxes, boxUnits] of boxTypes) {
    if (truckSize === 0) return units;
    const boxesToPlace = Math.min(truckSize, boxes);
    truckSize -= boxesToPlace;
    units += boxesToPlace * boxUnits;
  }

  return units;
};
// @lc code=end
