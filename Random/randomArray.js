const a1 = Array.from({ length: 5 }, (n) => Math.random());
console.log(a1);

const a2 = new Array(5).fill(1).map((n) => Math.random());
console.log(a2);
