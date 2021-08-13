// Time - O(v+e) Vertices + edge
// Space - O(v)

class Node {
  constructor(name) {
    this.name = name;
    this.children = [];
  }

  addChild(name) {
    this.children.push(new Node(name));
    return this;
  }

  depthFirstSearch(resultArray) {
    resultArray.push(this.name);
    for (const child of this.children) {
      child.depthFirstSearch(resultArray);
    }
    return resultArray;
  }
}
