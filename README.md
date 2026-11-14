# AVL Tree Student Records

A self-balancing **AVL tree** in C++ that stores student records (name and 8-digit ID)
and keeps them sorted by ID. Commands are read from standard input. All four rotation
cases are handled, so every insert, search and remove stays O(log n).

## Example

```
$ ./Main
7
insert "Brandon" 45674567
insert "Brian" 35455565
insert "Briana" 87878787
insert "Bella" 95462138
printInorder
printLevelCount
removeInorder 1
```
```
successful
successful
successful
successful
Brian, Brandon, Briana, Bella
3
successful
```

## Commands

The first line is the number of commands that follow.

| Command | What it does |
|---|---|
| `insert "NAME" ID` | Add a student. Names are letters and spaces only, IDs are exactly 8 digits and must be unique. |
| `remove ID` | Remove the student with that ID. |
| `search ID` | Print the name for that ID. |
| `search "NAME"` | Print the IDs of every student with that name, in pre-order. |
| `printInorder` / `printPreorder` / `printPostorder` | Print names in that traversal order. |
| `printLevelCount` | Print the height of the tree. |
| `removeInorder N` | Remove the Nth student in in-order (0-indexed). |

Invalid commands or input print `unsuccessful`.

## How it works

- **Balancing:** after each insert or remove, node heights are updated and the
  balance factor is checked. LL, RR, LR and RL cases are fixed with single or double rotations.
- **Removal:** a node with two children is replaced by its in-order successor.
- **Parsing:** each command is validated with a regular expression before it reaches the tree.

## Build and run

Requires CMake 3.22+ and a C++14 compiler.

```bash
cmake -S . -B build
cmake --build build
./build/Main < test-io/input-files/1.txt
```

Unit tests ([Catch2](https://github.com/catchorg/Catch2)):

```bash
./build/Tests
```

Sample input and expected output files are in `test-io/`.

## Project structure

```
src/
  AVL.cpp/.h        tree, rotations, traversals
  Student.cpp/.h    student record
  helpers.cpp/.h    command parsing and validation
  main.cpp          reads commands from stdin
test/test.cpp       Catch2 unit tests
test-io/            sample inputs and expected outputs
```

Built for a Data Structures & Algorithms course.
