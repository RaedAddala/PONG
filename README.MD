# Pong

I am creating a Pong game with particle effects, LAN based two player mode, shared scoring system based on rooms, Player vs AI mode.

I am building this game using:

- C++ 23
- CMake
- OpenGL
- Raylib
- Enet

------

## Table Of Contents

1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Main Features](#main-features)
4. [Preparing the environment](#preparing-the-environment)
5. [Building the Project](#building-the-project)
6. [Future Plan](#future-plan)
        1. [History](#history)
        2. [TODO](#todo)
7. [Explaining Used Libraries](#explaining-used-libraries)
    1. [Raylib](#raylib)
        1. [What is Raylib](#what-is-raylib)
        2. [Why use Raylib](#why-use-raylib)
    2. [Enet](#enet)
        1. [What is Enet](#what-is-enet)
        2. [Why use Enet](#why-use-enet)
8. [Performance-related Tips](#performance-related-tips)
9. [Ressources to learn X](#ressources-to-learn-x)
    1. [Ressources to learn Raylib](#ressources-to-learn-raylib)
    1. [Ressources to learn OpenGL](#ressources-to-learn-opengl)
    1. [Ressources to learn Enet](#ressources-to-learn-enet)
10. [Contribution](#contribution)
11. [License](./LICENSE)

------

## Introduction

## Project Structure

This is the project structure that I follow in most of my projects:

```plain
PONG/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/                # Header files
│   ├── core/
│   ├── graphics/
│   ├── networking/
│   └── ...
├── src/                    # Source files
│   ├── main.cpp
│   ├── core/
│   ├── graphics/
│   ├── networking/
│   └── ...
├── lib/                   # External precompiled libraries (optional)
│   └── ...
├── third_party/           # External sources managed by CMake (Raylib, ENet, etc.)
│   ├── raylib/
│   ├── enet/
│   └── ...
├── assets/                # Shaders, textures, models, etc.
│   ├── shaders/
│   ├── textures/
│   └── ...
├── build/                 # Build output (gitignored)
├── tests/                 # Unit tests
│   ├── CMakeLists.txt
│   └── test_main.cpp
├── cmake/                 # Custom CMake modules
|    └── ...    
└── ...                    # other specific folders depending on context
```

## Main Features

## Preparing the environment

## Building the Project

## Future Plan

### History

### TODO

## Explaining Used Libraries

### Raylib

#### What is Raylib

#### Why use Raylib

### Enet

#### What is Enet

#### Why use Enet

## Performance-related Tips

These Tips are more general rather than specific but you can apply them using any programming language that has low level feature:

- People undermine how important the algorithm and data structure choice is for performance. My Python code using an optimized algorithm beats any brute force highly optimized C code. I know this is generic but sometimes people think too much about micro optimization that they forget the most important type of optimization.
- Moving on to the most important tip, **Design your software well**:
  - choose your algorithms well.
  - a code that does less is faster.
  - precomputations are your friends. Do not compute the same thing multiple times.
  - do you think this part of the code is necessary? think again.
  - Always go for simplicity.
- Do not move big objects around and copy them all over the place (people in the C++ world are like sometimes): always use pointers to structs (64 bits are nothing compared to the 1KB struct you are moving around).
- Remember **I/O is the bottleneck**. Try to reduce memory allocations and make good use of the cache.
- **Only optimise when you feel the program is slow**.
- **When you need to optimise, use** ***a profiler***. Identify what you need to optimise first.
- **Sometimes you don't need to optimise the program, you just have to give the user the illusion it is fast.**
- [This is a conference talk](https://www.youtube.com/watch?v=FJJTYQYB1JQ) that has a lot of great insights about optimisation. He tackles the problems around sorting algorithms with great depth and new insights. The fundamental ideas treated here can be universally adapted.
- Here is a course that I am following right now and which is very helpful to me: [MIT 6.172 Performance Engineering of Software Systems](https://www.youtube.com/playlist?list=PLUl4u3cNGP63VIBQVWguXxZZi0566y7Wf). It is mostly in C and assembly but applied elsewhere too.
- I can't bring up performance without talking about **Agner Fog** and his performance-related publications. He is a computer scientist who experiments with performance that is more architecture-related. Here they are: [Software Optimization Resources](https://agner.org/optimize/)

## Ressources to learn X

### Ressources to learn Raylib

### Ressources to learn OpenGL

### Ressources to learn Enet

## Contribution

This pong version is still a small project done to learn more about Computer Graphics, Raylib and Network Programming. Contributions would help me improve and learn.

Contributions, Criticism, and Suggestions are all welcome!

Whether you have ideas for improvements, encounter issues, or want to submit pull requests to enhance the functionality, your input is appreciated and welcomed.

### How to Contribute

1. **Issues**: If you encounter any bugs, have feature requests, or want to discuss potential improvements, please open an issue on the [issue tracker](https://github.com/RaedAddala/Pong/issues/new).

2. **Pull Requests**: If you'd like to contribute directly to the codebase, feel free to fork the repository, make changes and submit a [pull request](https://github.com/RaedAddala/Pong/compare).

**Otherwise,** all contributions and suggestions are welcome.

### Note

Your contributions play a vital role in helping me grow as a programmer. Thank you for your interest and support! :)
