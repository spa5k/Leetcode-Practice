class Stack {
  constructor() {
    this.items = [];
    this.count = 0;
  }
  // Add Element to the top of stack;
  push(element) {
    this.items[this.count] = element;
    console.log(`${element} add to ${this.count}`);

    console.log(this.items);
    this.count++;
    return this.count - 1;
  }

  // Return and remove the top most element;
  // return undefined if stack is empty
  pop() {
    if (this.count === 0) {
      return undefined;
    }
    const deletedItem = this.items[this.count - 1];
    this.count -= 1;
    console.log(`${deletedItem} got removed`);
    return deletedItem;
  }

  // Check top element in stack;

  peek() {
    console.log(`Top Element is ${this.items[this.count - 1]}`);
    return this.items[this.count - 1];
  }

  // Check if stack is empty

  empty() {
    let x = this.count === 0 ? true : false;
    console.log(x);
    return x;
  }

  // Check size;

  size() {
    console.log(`Count is ${this.count}`);
    return this.count;
  }

  // Print elements in Stack
  print() {
    let str = "";
    for (let i = 0; i < this.count; i++) {
      str += this.items[i] + " - ";
    }
    console.log(str);
    return str;
  }

  // clear Stack

  clear() {
    this.items = [];
    this.count = 0;
    console.log("Stack cleared");
    return this.items;
  }
}

const stack = new Stack();

stack.push(100);
stack.push(200);
stack.push(300);

// stack.pop();
stack.size();
// stack.print();
stack.clear();
stack.size();

console.log(stack.print());
// stack.pop();
// stack.pop();

// stack.peek();
// stack.empty();
