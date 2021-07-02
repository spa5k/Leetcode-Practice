const logicAlbums = [
  {
    name: "Bobby Tarantino",
    rating: 5,
  },
  { name: "The Incredible True Story", rating: 4.5 },
  {
    name: "Supermarket",
    rating: 4.9,
  },
  { name: "Under Pressure", rating: 5 },
];

logicAlbums.filter((album) => {
  return album.rating > 4.9;
});
console.log(logicAlbums);

Array.prototype.myFilter = function(callback) {
  let arr = [];
  for (let i = 0; i < this.length; i++) {
    console.log(callback(this[i], i, this), this[i]);
    if (callback(this[i], i, this)) {
      arr.push(this[i]);
    }
  }
  return arr;
};

const x = logicAlbums.myFilter((album) => album.rating > 4.9);

console.log(x);
