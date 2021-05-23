const posts = [
  {
    title: "Post One",
    body: "This is post one",
  },
  {
    title: "Post two",
    body: "This is post two",
  },
];

function getPosts() {
  setTimeout(() => {
    let output = "";
    posts.forEach((post) => {
      output += `<li>
      Title-${post.title}, Body-${post.body}
      </li>`;
    });
    document.body.innerHTML = output;
  }, 1000);
}

function createPost(post, callback) {
  setTimeout(() => {
    posts.push(post);
    callback();
  }, 2000);
}
