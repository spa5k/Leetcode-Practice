const logicAlbums = [
  "Bobby Tarantino",
  "The Incredible True Story",
  "Supermarket",
  "Under Pressure",
];

const withReduce = logicAlbums.reduce(function (a, b) {
  return a + " , " + b;
}, "Young Sinatra"); // Here we are initialising the array with value as 'Young Sinatra'

console.log(withReduce);

Array.prototype.albumReduce = function (callback, initialValue) {
  let accumulator = initialValue === undefined ? undefined : initialValue;

  for (let i = 0; i < this.length; i++) {
    if (accumulator !== undefined) {
      accumulator = callback.call(undefined, accumulator, this[i], i, this);
    } else {
      accumulator = this[i];
    }
  }
  return accumulator;
};

const newReduce = logicAlbums.albumReduce(function (a, b) {
  return a + " , " + b;
}, "Young ");

console.log(newReduce);
