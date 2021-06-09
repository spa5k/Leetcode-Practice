const top = (a) => {
  const c = 2;
  return function bottom(b) {
    console.log("top", a);
    console.log("bottom", b);
    console.log("c", c);
  };
};

const newFunction = top("nice");
newFunction("hey");

class MyClass {
  myFunction = () => {
    console.log(this instanceof MyClass);
  };
}
const myInstance = new MyClass();
const myFunction = myInstance.myFunction;
myFunction();
