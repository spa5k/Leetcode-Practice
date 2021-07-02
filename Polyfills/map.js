const albums = ["nice", "abc", "asdasd", "asdw34134123", 4546456, 5654];

let x = albums.map((a) => a + a);
console.log(x);

Array.prototype.albumMap = function(callback) {
  let arr = [];
  for (let i = 0; i < this.length; i++) {
    arr.push(callback(this[i], i, this));
  }
  return arr;
};

let y = albums.albumMap((a) => a + a);
console.log(y);
