// // Time - O(n) | Space - O(n)

// function arrayOfProducts(array) {
//   const leftArray = new Array(array.length).fill(1);
//   const rightArray = new Array(array.length).fill(1);

//   const products = new Array(array.length).fill(1);

//   let leftRunningProduct = 1;
//   for (let i = 0; i < array.length; i++) {
//     const element = array[i];
//     leftArray[i] = leftRunningProduct;
//     leftRunningProduct *= element;
//   }

//   let rightRunningProduct = 1;
//   for (let i = array.length - 1; i > -1; i--) {
//     const element = array[i];
//     rightArray[i] = rightRunningProduct;
//     rightRunningProduct *= element;
//   }

//   for (let i = 0; i < array.length; i++) {
//     const element = leftArray[i];
//     const element2 = rightArray[i];
//     products[i] = element * element2;
//   }

//   return products;
// }

// Time - O(n) | Space - O(n)

function arrayOfProducts(array) {
  const products = new Array(array.length).fill(1);

  let leftRunningProduct = 1;
  for (let i = 0; i < array.length; i++) {
    const element = array[i];
    products[i] = leftRunningProduct;
    leftRunningProduct *= element;
  }

  let rightRunningProduct = 1;
  for (let i = array.length - 1; i > -1; i--) {
    const element = array[i];
    products[i] *= rightRunningProduct;
    rightRunningProduct *= element;
  }

  return products;
}
