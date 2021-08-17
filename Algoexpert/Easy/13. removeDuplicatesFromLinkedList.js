const removeDuplicates = (ll) => {
  let currentNode = ll;
  while (currentNode) {
    let nextNode = currentNode.next;
    while (nextNode && nextNode.value === currentNode.value) {
      nextNode = nextNode.next;
    }

    currentNode.next = nextNode;
    currentNode = nextNode;
  }
  return ll;
};
