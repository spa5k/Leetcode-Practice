const arr = [1, 2, 3, 4, 5, 6];

const x = arr.find((item) => item > 4);
console.log(x);

Array.prototype.myFind = function(callback) {
  for (let index = 0; index < this.length; index++) {
    if (callback(this[index], index, this)) {
      return this[index];
    }
  }
};

const y = arr.myFind((item) => item > 3);
console.log(y);
