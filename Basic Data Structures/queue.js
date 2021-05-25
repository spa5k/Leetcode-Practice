class Queue {
  constructor() {
    this.items = [];
    this.count = 0;
  }

  // Add element to queue;
  push(element) {
    this.items[this.count] = element;
    console.log(`${element} added to count ${this.count}`);
    this.count++;
    console.log(this.items);
    return this.count - 1;
  }

  // Remove element from queue  and return it;
  remove() {
    if (this.count === 0) {
      return undefined;
    }

    const deletedItem = this.items.shift();
    this.count -= 1;
    console.log(`deleted item - ${deletedItem}`);
    return deletedItem;
  }

  // First element;
  first() {
    return this.items[0];
  }

  // size
  size() {
    return this.count;
  }
  // Clear;
  clear() {
    this.count = 0;
    this.items = [];
    return "cleared it";
  }

  // Print
  print() {
    let str = "";
    for (let i = 0; i < this.count; i++) {
      str += this.items[i] + " - ";
    }
    return str;
  }
}

const queue = new Queue();
queue.push(19);
queue.push(1111);
// queue.remove();
// queue.remove();
// queue.clear();
console.log(queue.print());
console.log(queue.size());
console.log(queue.first());
console.log(queue.items);
