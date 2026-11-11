# CSC 301: Data Structures - Lab Assessment

This repository contains the C++ implementations for the **CSC 301: Data Structures** Tutor-Marked Assessment (MIVA Open University).

## 📁 Repository Structure

```text
.
├── linked_list.cpp      # Question 1: Custom Singly Linked List Implementation
├── recursion.cpp        # Question 2: Recursive Algorithms (Factorial, Fibonacci, Reversal, Search)
└── README.md            # Repository documentation
```

---

## Features & Scope

### 1. Custom Singly Linked List (`linked_list.cpp`)

- **Dynamic Memory Management:** Custom node structure with explicit allocation (`new`) and clean heap memory release (`delete`).
- **Core Operations:**
  - Insertion at beginning, end, and specific index positions.
  - Deletion by specific value and index position.
  - Complete list traversal and display.
- **Error Handling:** Robust checks for empty lists, non-existent values, and out-of-bounds indices.
- **Test Datasets:** Verified with 3 distinct input scenarios.

### 2. Recursive Algorithms (`recursion.cpp`)

- **Factorial Calculation:** $O(N)$ time recursive evaluation with negative input validation.
- **Fibonacci Sequence:** $O(2^N)$ standard naive recursion generating first $n$ terms.
- **String Reversal:** Divide-and-conquer string reversal logic.
- **Binary Search:** $O(\log N)$ recursive lookup on sorted array bounds with edge-case handling for empty vectors.

---

## Compilation and Execution

Ensure you have a C++ compiler (`g++` or `clang++`) supporting **C++11** or later.

### Compiling & Running Question 1 (Linked List)

```bash
g++ -std=c++11 linked_list.cpp -o linked_list
./linked_list
```

### Compiling & Running Question 2 (Recursion)

```bash
g++ -std=c++11 recursion.cpp -o recursion
./recursion
```

---

## Requirements

- **Language:** C++11 or higher
- **Compiler:** GCC / Clang / MSVC
