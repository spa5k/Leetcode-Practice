class Node {
  constructor(data, prev = null, next = null) {
    this.data = data;
    this.prev = prev;
    this.next = next;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  insertFirst(data) {
    // current head prev=new node;
    // this.head= new node;
    // new node ->next = current head;

    const newNode = new Node(data, null, this.head);
    this.head.prev = newNode;
    this.head = newNode;
    this.size++;
  }

  // Insert at first
  insertLast(data) {
    const newNode = new Node(data);
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      newNode.prev = this.tail;
      this.tail = newNode;
    }
    this.size++;
    return this;
  }

  // Remove last node;
  removeLast() {
    let current = this.head;
    let previous;
    while (current.next) {
      previous = current;
      current = current.next;
    }
    current = null;
    previous.next = null;
    this.size--;
  }
  // Remove the first element;
  removeFirst() {
    this.head = this.head.next;
  }

  printList() {
    if (this.head) {
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
    } else {
      console.log("empty list");
    }
  }
  // get node at index;
  nodeAtIndex(index) {
    if (index >= this.size || index < 0) {
      return false;
    }
    let currentIndex = 0;
    let currentNode = this.head;

    while (currentIndex !== index) {
      currentNode = currentNode.next;
      currentIndex++;
    }

    return currentNode;
  }

  // set node at index;
  setNodeAtIndex(index, data) {
    const theNode = this.nodeAtIndex(index);
    const prevNode = this.nodeAtIndex(index - 1);

    const newNode = new Node(data, prevNode, theNode);
    prevNode.next = newNode;
    theNode.prev = newNode;

    this.size++;
  }

  // Remove from index;

  removeFromIndex(index) {
    const prevNode = this.nodeAtIndex(index - 1);
    const nextNode = this.nodeAtIndex(index + 1);
    prevNode.next = nextNode;
    nextNode.prev = prevNode;
    this.size--;
  }
}
const linkedList = new LinkedList();
linkedList.insertLast(1111);
linkedList.insertLast(2222);
linkedList.insertLast(3333);
linkedList.insertLast(4444);
// linkedList.insertFirst(1234);
linkedList.setNodeAtIndex(1, 9098);
linkedList.removeFromIndex(2);
// linkedList.removeFirst();

// linkedList.removeLast();
console.log(linkedList);
// linkedList.printList();
console.log(linkedList.nodeAtIndex(2).data);
