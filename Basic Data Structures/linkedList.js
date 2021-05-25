// Rotate a linkedlist clockwise- 4 times;
// n=4;
// 2 fucntions
// one to insert, other to display some node
class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.size = 0;
  }

  // Remove last;
  removeLast() {
    let current = this.head;
    let previous;
    while (current.next) {
      previous = current;
      current = current.next;
    }
    current = null;
    previous.next = null;
  }
  // Insert first node
  insertFirst(data) {
    this.head = new Node(data, this.head);
    this.size++;
  }
  // Remove first;
  removeFirst() {
    this.head = this.head.next;
  }
  // Insert last node

  insertLast(data) {
    let node = new Node(data);
    let current;

    // if empty, make it headl
    if (!this.head) {
      this.head = node;
    } else {
      current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = node;
    }
    this.size++;
  }

  // Insert at index

  insertAt(data, index) {
    // If Index is out of range
    if (index > 0 && index > this.size) {
      return;
    }

    // iF first index
    if (index === 0) {
      this.insertFirst(data);
      return;
    }

    const node = new Node(data);
    let current;
    let previous;

    // Set current to first;
    current = this.head;
    let count = 0;
    while (count < index) {
      previous = current; // Node before index
      count++;
      current = current.next; // Node Adter index;
    }
    node.next = current;
    previous.next = node;
    this.size++;
  }

  // Get at Index

  getAt(index) {
    let current = this.head;
    let count = 0;
    while (current) {
      if (count === index) {
        console.log(current.data);
        return current.data;
      }
      count++;
      current = current.next;
    }
    return null;
  }

  // Remove at Index

  removeAt(index) {
    if (index > 0 && index > this.size) {
      return;
    }
    let current = this.head;
    let previous;
    let count = 0;

    // Remove first
    if (index === 0) {
      this.head = current.next;
    } else {
      while (count < index) {
        count++;
        previous = current;
        current = current.next;
      }
      previous.next = current.next;
    }
    this.size--;
  }

  // Clear list

  clearList() {
    this.head = null;
    this.size = 0;
  }

  // Print list data

  printListData() {
    let current = this.head;
    while (current) {
      console.log(current.data);
      current = current.next;
    }
  }
}

const ll = new LinkedList();
ll.insertFirst(100);
ll.insertLast(400);
ll.insertAt(200, 2);
// ll.removeAt(2);
ll.removeFirst();
// ll.removeLast();
// ll.clearList()
ll.printListData();
