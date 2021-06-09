const arr = [1, 2, 3, 4, 5, 6];
let pointer = arr.length-1;

const playNext = () => {
  if (pointer ===-1) {
    console.log('here');
    return 'nope';
  };
  console.log(pointer)
  // get randomNumber;
  const randomNumber = Math.floor(Math.random() * pointer);
  // swap the randomNumber on array to last number;

  const toBeSwapped = arr[randomNumber];
  const b = arr[pointer];
  arr[randomNumber] = b;
  arr[pointer] = toBeSwapped;
  pointer--;

  console.log(toBeSwapped)
}

playNext();
playNext();
playNext();
playNext();
playNext();
playNext();
playNext();
playNext();
playNext();
playNext();
playNext();

