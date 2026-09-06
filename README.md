# Data Structures and Algorithms - C++

Data Structure and Algorithm (DSA) exercises solved in C++, considering time and space complexity.

> **Concepts and Tools:** C++, CMake, Standard Template Library (STL), Google Test (GTest), Data Structures & Algorithms, Big-O Complexity Analysis, Debugging.

### Prerequisites

- GNU/Linux OS: Developed and tested with Ubuntu 26.04, pending to verify it with other operating systems.
- Build-essential and CMake:
    ```bash
    sudo apt update && sudo apt install build-essential cmake -y
    ```

### Implementation

- Clone this repository locally:
    ```bash
    git clone https://github.com/alfonso-caoz/dsa-cpp.git
    ```
- Go to the cloned repository folder `dsa-cpp`: 
    ```bash
    cd dsa-cpp
    ```
- Create `build` folder, build source code, and change directory to `build`:
    ```bash
    cmake -B build && cmake --build build && cd build
    ```
- Run a specific test with the `test tag` from the table in the following section:
    ```bash
    ctest -R <test-tag> --output-on-failure
    ```
- Run all tests at once:
    ```bash
    ctest --output-on-failure

## DSA Exercises Solved

<!-- **Easy** -->

<div align="center">

| DSA Exercise | Test Tag |
| :--- | :---: |
| [1- Two Sum](./src/1-two-sum) | [`T1`](./test/1-two-sum/test-two-sum.cpp) |
| [13- Roman to Integer](.src/13-roman-to-integer) | [`T13`](./test/13-roman-to-integer/test-roman-to-integer.cpp) |
| [20- Valid Parentheses](.src/20-valid-parentheses) | [`T20`](./test/20-valid-parentheses/test-valid-parentheses.cpp) |
| [21- Merge Two Sorted Lists](./src/21-merge-two-sorted-lists) | [`T21`](./test/21-merge-two-sorted-lists/test-merge-two-sorted-lists.cpp) |
| [88- Merge Sorted Array](./src/88-merge-sorted-array) | [`T88`](./test/88-merge-sorted-array/test-merge-sorted-array.cpp) |
| [141- Linked List Cycle](./src/141-linked-list-cycle) | [`T141`](./test/141-linked-list-cycle/test-linked-list-cycle.cpp) |
| [160- Intersection of Two Linked Lists](./src/160-intersection-of-two-linked-lists) | [`T160`](./test/160-intersection-of-two-linked-lists/test-intersection-of-two-linked-lists.cpp) |
| [169- Majority Element](./src/169-majority-element) | [`T169`](./test/169-majority-element/test-majority-element.cpp) |
| [202- Happy Number](./src/202-happy-number) | [`T202`](./test/202-happy-number/test-happy-number.cpp) |
| [205- Isomorphic Strings](./src/205-isomorphic-strings) | [`T205`](./test/205-isomorphic-strings/test-isomorphic-strings.cpp) |
| [226- Invert Binary Tree](./src/226-invert-binary-tree) | [`T226`](./test/226-invert-binary-tree/test-invert-binary-tree.cpp) |
| [242- Valid Anagram](./src/242-valid-anagram) | [`T242`](./test/242-valid-anagram/test-valid-anagram.cpp) |
| [448- Find All Numbers Disappeared in an Array](./src/448-find-all-numbers-disappeared-in-an-array) | [`T448`](./test/448-find-all-numbers-disappeared-in-an-array/test-find-all-numbers-disappeared-in-an-array.cpp) |
| [557- Reverse Words in a String III](./src/557-reverse-words-in-a-string-iii) | [`T557`](./test/557-reverse-words-in-a-string-iii/test-reverse-words-in-a-string-iii.cpp) |
| [572- Subtree of Another Tree](./src/572-subtree-of-another-tree) | [`T572`](./test/572-subtree-of-another-tree/test-subtree-of-another-tree.cpp) |
| [589- N-ary Tree Preorder Traversal](./src/589-n-ary-tree-preorder-traversal) | --- |
| [605- Can Place Flowers](./src/605-can-place-flowers) | [`T605`](./test/605-can-place-flowers/test-can-place-flowers.cpp) |
| [674- Longest Continuous Increasing Subsequence](./src/674-longest-continuous-increasing-subsequence) | [`T674`](./test/674-longest-continuous-increasing-subsequence/test-longest-continuous-increasing-subsequence.cpp) |

</div>

<!-- **Medium** -->

<!-- **Difficult** -->

## Pending Work

- [ ] Solve 25 DSA Exercises: 18/25
- [ ] Implement Local Unit Tests with GTest: 17/18
