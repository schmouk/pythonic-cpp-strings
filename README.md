# Library cpp-strings
 [![license](http://img.shields.io/github/license/schmouk/cpp-strings.svg?style=plastic&labelColor=blueviolet&color=lightblue)](https://github.com/schmouk/cpprandlib/license)  [![Latest release](http://img.shields.io/github/release/schmouk/cpp-strings.svg?style=plastic&labelColor=blueviolet&color=success)](https://github.com/schmouk/cpprandlib/releases)  [![code_coverage](https://img.shields.io/badge/code_coverage-100%25-success?style=plastic&labelColor=blueviolet)]()  [![tests](https://img.shields.io/badge/tests-passing-success?style=plastic&labelColor=blueviolet)]()

github repository: [https://github.com/schmouk/pythonic-cpp-strings](https://github.com/schmouk/pythonic-cpp-strings)

What if c++ strings where as easy to use as Python strings?

Let's just use c++ strings as are Python ones, with same API or as similar API as possible.  
Library **cpp-strings** is fully templated. Just download header file `cppstrings.h` and put it anywhere in your project. Notice: all of its stuff is declared and defined in namespace `pcs` - which stands for **P**ythonic **C**++ **S**trings.

* The templated class `pcs::CppStringT<>` defines all constructors and methods that implement the equivalent of Python strings API.  
* Class `pcs::CppString` specializes the templated class with `char` characters.
* Class `pcs::CppWString` specializes the templated class with `wchar_t` characters.

**cpp-strings** is implemented with the currently most recent c++ standard available with gcc, clang and msvc c++ compilers, i.e. standard **c++20**.

* directory `cpp-strings` contains the header file `cppstring.h`.  
This is the header file to include in your projects.
* directory `cpp-strings-tests` contains the unit-tests file `cpp-strings-tests.cpp`  
This file tests all the library stuff. It is a valuable code container with so many examples of use of the library, the classes, the methods and the functions it defines.

The code has been developed using VS2022 IDE. As such, unitary tests have been coded using Microsoft Visual Studio Cpp Unit Test Framework. The related VS project is provided with this library.

Notice: no clang, gcc or msvc specific declarations or goodies have been use to code library **cpp-strings**. It should then be compilable with any of these compilers. To be able to use it with your project, just ensure that the c++ standard used with you favorite compiler is **c++20**: 
* options `-std=c++20` or `-std=c++latest` for clang and gcc (v. 10 and above),  
or option `-std=c++2a` for clang and gcc (v. 9 and earlier);
* options `/std=c++20` or `/std=c++latest` for Visual Studio 2019 and later.

If you want to run the unitary tests, well, use the last version of Visual Studio (i.e. VS 2022, by July 2025). The Community free version will truly be fine.  
The vcproject associated with the unit tests in **cpp-strings** is already configured to use the option flag `/std:c++latest` since the implemented code uses a very few but very useful c++23 goodies.


---
## License

    Library cpp-strings
    "What if c++ strings where as easy to use as Python strings?"

    Copyright (C) 2023-2025 Philippe Schmouker
    contact - ph (dot) schmouker (at) gmail (dot) com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation,  either version 3  of the License,  or
    (at your option) any later version.

    This program is distributed in the hope  that  it  will  be  useful,
    but  WITHOUT  ANY  WARRANTY;  without  even  the implied warranty of
    MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.  See  the
    GNU General Public License for more details.

    You should have received a copy  of  the  GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.


---
## Intro
The creation of this library has been started with the aim at easing the use of strings in c++. Other projects exist, even aiming also to implement a Python-like strings API, but the only ones we have found were either started but not completed, or were not implementing the whole Python API.

So, we started to work on **Pythonic c++ strings**. Library **cpp-strings** is now ready. It fully implements the Python API (even with a c++ implementation of *slices*) and it is fully tested with *unitary tests*.

The implementation of library **cpp-strings** is fully templated and is contained into a single header file: `cpp-strings/cppstrings.h`. To take a whole benefit of it, just add this header file to your project and include it in your own files. It very fastly compiles. That's all!

Header file `cpp-strings/cppstrings.h` defines:
* templated class `template<typename CharT> class pcs::CppStringT` which implements all the stuff about pythonic c++ strings. It inherits from c++ STL class `std::basic_string<CharT>`, so it gets access to all c++ STL methods, functions and goodies about strings;
* this class is specialized by: `using pcs::CppString> = pcs::CppStringT<char>` for pythonic c++ strings based on `char` characters;
* it is also specialized by: `using pcs::CppWString> = pcs::CppStringT<wchar_t>` for pythonic c++ strings based on `wchar_t` characters.

The unitary tests are provided in directory `cpp-strings-tests/`. File `cpp-strings-tests/cpp-strings-tests.cpp` contains the related code. Tests have been coded using VS2022 IDE and as such, are using the Microsoft Visual Studio Cpp Unit Test Framework. The related VS project can be found in the same directory. It is already configured to create code for Release as well as for Debug configurations, and for 32-bits or 64-bits platforms at your choice.  
This `.cpp` file is a great place to see **cpp-strings** code in action. Each structure, class, method, litteral operator and function being unitary tested in here, you should find there many examples of its use for all **cpp-strings** stuff.


---
## Latest Release - Release 1.0 (1.0.0.229) 2025/07

The coding of this project started by March 2023 and had been put in standby mode for some months - no time to work on it. The very first release is now availble (since July 2025), as **Release 1.0**.

This release has been fully tested. Code coverage is 100%.

Release 1.0 implements all Python strings API but one feature (see below).

Python *slices* are implemented via c++ `operator()` as declared and defined in the templated class `pcs::CppStringT<>`. Python slices have next specific notation: `[start : stop : step]` and allow the running step by step through range [start, stop) (notice: stop is excluded from the range). Operator `(start, stop, step)` acts the same way while running through the content of pythonic c++ strings. A dedicated base class `Slice` is also provided and can be passed as argument to `operator()`. It is derived in many simpler slices classes, since Python slices may not define either `start`, `stop` or `step` which then get default values (resp. 0, *end-of-sequence*, and 1).


### Missing parts in Release 1.0
Python strings are based on Unicode chars. This is currently not the case for pythonic c++ strings in **cpp-strings**.  
Unicode encoding allows for a specific comparison mode on strings, the **casefold** mode. There, Unicode chars are transformed into their lower equivalent char in a standardized manner which is more "agressive" than the simpler lowering method `lower()`. Comparing strings without taking into account the case of their chars is then performed in a far more accurate manner.  
This feature is currently NOT implemented in library **cpp-strings**.

So up to now, if you want to compare pythonic c++ strings from **cpp-strings** on whatever the case is for each of their chars, compare them applying method `.lower()` to both strings. This will do the job for chars and for wchar_t also for a majority of languages (but might fail for very few signs of specific languages in this last case).

Notice: dealing with Unicode chars and implementing method `casefold()` as it is the case in Python is planned for a next release of library **cpp-strings**.  
N.B. "*planned for a next release*" does not imply that a fixed date is planned either.


---
## Documentation

The **cpp-strings** HTML documentation is available here: [html/index.html](html/index.html).

It has then been produced with the great utility **doxygen** developed by Vicente Hernando (the doxygen Github repository can be accessed [here](https://github.com/doxygen/doxygen), and the utility can be downloaded from there: [https://www.doxygen.nl/download.html](https://www.doxygen.nl/download.html)).

This is a short documentation of the library. For some of its part it is a copy of the Python original documentation on strings. For its other part it documents the c++ implementation of **cpp-strings**.

And remember: to better understand how to use this pythonic c++ strings library, have a look also at [`cpp-strings-tests/cpp-strings-tests.cpp`](cpp-strings-tests/cpp-strings-tests.cpp) to see **cpp-strings** library code in action!
