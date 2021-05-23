const songs = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

// * Algo problem: list of songs, playNext() to implement, with few constraints
// ?[- Play randomly - don't play already played songs - O(1) extra space allowed - don't delete elements from list]-- - Took 30 + minutes to solve with O(n) time complexity, expecting O(1).

const alreadyPlayed = [];

const playNext = () => {
  if (alreadyPlayed.length === songs.length) {
    return "You have already played everything mate";
  }

  const randomNumber = Math.floor(Math.random() * songs.length);
  // If its already played, generate random number again

  if (alreadyPlayed.includes(songs[randomNumber])) {
    return playNext();
  }
  alreadyPlayed.push(songs[randomNumber]);
  return songs[randomNumber];
};

console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
console.log(playNext());
