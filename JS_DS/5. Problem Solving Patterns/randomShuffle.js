const numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

const alreadyUsed = [];

const useNext = () => {
  if (alreadyUsed.length === numbers.length) {
    return "You have already used everything mate";
  }

  const randomNumber = Math.floor(Math.random() * numbers.length);

  if (alreadyUsed.includes(numbers[randomNumber])) {
    return useNext();
  };

  alreadyUsed.push(numbers[randomNumber]);
  return numbers[randomNumber];
};

console.log(useNext());
console.log(useNext());
console.log(useNext());
console.log(useNext());
console.log(useNext());



// randomNumber();