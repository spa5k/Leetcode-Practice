const albums = ["a", "b", "c", "d", "e"];

albums.forEach((a) => {
  console.log(a);
});
albums.forEach((currentValue, index, array) => {
  console.log(currentValue);
  console.log(index);
  // console.log(array);
});

Array.prototype.eachAlbum = function (callback) {
  // callback here is the callback function
  // which actual .forEach() function accepts
  console.log(this);
  for (let i = 0; i < this.length; i++) {
    console.log(this[i], i);
    callback(this[i], i, this); //current value, index, array
  }
};

albums.eachAlbum((a) => {
  console.log(a);
});
