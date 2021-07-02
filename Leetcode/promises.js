const abc = (timeout) => {
  new Promise((resolve, reject) => {
    resolve(
      setTimeout(() => {
        console.log("wait a min1");
      }, timeout),
    );
  });
};

console.log(abc(10000));
