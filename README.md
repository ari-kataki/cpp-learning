# cpp-learning

My exercises from the C++ course (ITS), units 1 to 6, going from the basics to object oriented programming. It was made while learning, so it is a record of the course and not a polished project.

## Folders

| Folder | What it is | Approx. date | What I was learning |
|---|---|---|---|
| 00-first-steps | One small file printing a table of the sizes and limits of the basic types | Apr 2026 | First program, `numeric_limits`, `sizeof` |
| 01-U1-basics | Unit 1 exercises | Apr 2026 | Variables, types, input/output, bitset |
| 02-U2-control-structures | Unit 2 exercises (16 exercises) | Apr 2026 | if/switch, loops, random numbers, GCD, factorial, binary conversion |
| 03-U3-functions | Unit 3 exercises | May 2026 | Functions, pointers, references, menus |
| 04-U4-data-structures | Unit 4 exercises | May 2026 | Arrays, vector, list, struct, a text display drawn with dynamic memory |
| 05-U5-oop-basics | Unit 5 exercises | May 2026 | Classes, constructors, static members, objects |
| 06-U6-inheritance-and-files | Unit 6: identity cards, garage, university | Jun 2026 | Inheritance, polymorphism, virtual methods, saving and loading files |

## Stack

C++17, no external libraries. `libreriaITS` (in folder 06) is the small helper library given by the course (safe user input, split a string, bubble sort and so on). It is only here because the code in that folder does not compile without it.

## How to run

Units 1 to 5 are a single file each, with all the exercises of the unit inside. The exercise that gets compiled is chosen with the `#define ESERCIZIO` line at the top of the file (for example `#define ESERCIZIO ESERCIZIO_3`), the other exercises are skipped by the preprocessor.

```
cd 02-U2-control-structures
g++ -std=c++17 U2.cpp -o main
./main
```

Unit 6 is split in classes (one .h/.cpp pair each). `ESERCIZIO` in `main.cpp` picks which part runs (1 identity cards, 2 car workshop, 3 garage, 4 university) and `TIPO_TEST` picks whether the program saves to a file or loads from it (save first, then load).

```
cd 06-U6-inheritance-and-files
g++ -std=c++17 *.cpp -o main
./main
```

## Notes

- The course PDFs with the exercise texts are not included.
- Everything is console input/output, text is in Italian.
- Some exercises were left with simple solutions on purpose (for example no input validation beyond what the helper does).
