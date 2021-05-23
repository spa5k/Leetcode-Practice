let posts = [
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

function createPost(post) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      posts.push(post);
      const error = false;
      if (!error) {
        resolve();
      } else {
        reject("Error: promise messed up");
      }
    }, 2000);
  });
}

// A=ync await

const init = async () => {
  await createPost({ title: "Post Three", body: "This is post 3" });

  getPosts();
};
init();
// createPost({ title: "Post Three", body: "This is post 3" })
//   .then(getPosts())
//   .catch((err) => console.log(err));

// Promise all

// const promise1 = Promise.resolve("hello world");
// const promise2 = 10;
// const promise3 = new Promise((resolve, reject) =>
//   setTimeout(resolve, 2000, "Goodbte"),
// );

// Promise.all([promise1, promise2, promise3]).then((values) =>
//   console.log(values),
// );
