# 🧠 Problem 2 - Accumulate Operation (In a Fun, Simple Way)

Welcome to the second problem of the Lancey Engineering Challenge! 🎉

In this one, we’re doing something really useful taking a collection of numbers and doing *something* to each number (like squaring them). It’s kind of like the `.map()` method you might’ve seen in higher-level languages but here we’re doing it from scratch in **pure C++** no standard library, no shortcuts.

---

## 📝 Problem Statement (Explained Casually)

You have:

- A list of numbers like `[1, 2, 3, 4, 5]`
- An operation you want to do to each number like squaring it (turning 2 into 4, 3 into 9, etc.)

Your task?

👉 Write a function that applies that operation to every number and gives you a brand new list of results. That’s called **accumulating** or **mapping**.

---

## 🤖 What i'm Building

We wrote:

- A function that takes in:
  - An original list of numbers
  - An operation function (like `square`)
  - And gives us back a new list where the operation has been applied to every item

This is done using:

- A function pointer in C++ for the operation
- Manual arrays (no vector, no `std::transform`, etc.)

---

## 🧑‍💻 Code Overview

```cpp
// Function to square a number
int f(int x) {
    return x * x;
}
