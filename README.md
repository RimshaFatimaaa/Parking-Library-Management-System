# Parking & Library Management System

A C++ Data Structures and Algorithms project featuring two console-based management systems: a Parking Management System and a Library Management System.

The project demonstrates the practical use of stacks, queues, linked lists, and AVL trees to organize and manage data efficiently.

## Projects Overview

### 1. Parking Management System

**Language:** C++

**Data Structures:** Stack, Queue, Linked List

A console-based parking management system that manages vehicles across multiple parking floors.

**Features**
- Configure the number of parking floors and parking spaces per floor.
- Park vehicles when spaces are available.
- Remove a vehicle from a parking floor.
- Maintain a waiting queue with a maximum capacity of five cars.
- Add additional vehicles to an overflow waitlist when the queue is full.
- Expand parking capacity by adding a new floor.
- Display the status of parking floors, the waiting queue, and the overflow waitlist.

**Data structure implementation**
- **Stack:** Stores parked cars on each floor.
- **Queue:** Maintains the order of waiting vehicles.
- **Linked list:** Organizes parking floors and the overflow waitlist.

**Source file:** `parking_system.cpp`

### 2. Library Management System

**Language:** C++

**Data Structure:** AVL Tree (Self-Balancing Binary Search Tree)

A console-based library management program that organizes book records using their ISBN numbers.

Each book record contains an ISBN, title, author, and tree-related information.

**Features**
- Insert books into the library's data structure.
- Search for a book using its ISBN.
- Delete a book record.
- Display books in sorted ISBN order.
- Maintain tree balance using rotations after insertion and deletion.

**AVL tree operations**
- Left and right rotations.
- Height and balance-factor calculations.
- Recursive insertion and deletion.
- In-order traversal for sorted book listings.

**Source file:** `library_management.cpp`

The current program demonstrates these operations using sample book records.

## Technologies Used

- C++
- Object-oriented programming concepts
- Stack and queue operations
- Linked lists
- Binary search trees
- AVL tree balancing
- Dynamic memory allocation
- Recursion

## Project Structure

```text
parking-library-management-system/
├── README.md
├── parking_system.cpp
└── library_management.cpp
```

## Requirements

- A C++ compiler, such as GCC or MinGW.
- A code editor or IDE, such as Visual Studio Code, Code::Blocks, or Visual Studio.

## How to Run

### Parking Management System

Compile the source file:

```bash
g++ -std=c++11 parking_system.cpp -o parking_system
```

Run on Windows:

```bash
parking_system.exe
```

### Library Management System

Compile the source file:

```bash
g++ -std=c++11 library_management.cpp -o library_management
```

Run on Windows:

```bash
library_management.exe
```

## Sample Commands: Parking System

After starting the parking program, enter the number of floors and parking spaces per floor.

Available commands:

| Command | Description |
|---|---|
| `entry` | Add a vehicle to the parking system |
| `exit` | Remove a vehicle from its parking floor |
| `status` | Display current parking status |
| `expand` | Add another parking floor |
| `quit` | Exit the program |

## Learning Outcomes

This project provides practical experience with:

- Selecting appropriate data structures for real-world problems.
- Implementing stack and queue operations.
- Managing dynamic memory using pointers.
- Organizing records in a binary search tree.
- Implementing AVL rotations and balance-factor calculations.
- Applying recursion to searching, insertion, and deletion.
- Building interactive, menu-driven console applications in C++.

## Author

**Rimsha Fatima**

GitHub: [RimshaFatimaaa](https://github.com/RimshaFatimaaa)

---

*Developed as a Data Structures and Algorithms learning project.*
