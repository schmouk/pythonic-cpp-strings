# Library cpp-strings [![license](http://img.shields.io/github/license/schmouk/cpp-strings.svg?style=plastic&labelColor=blueviolet&color=lightblue)](https://github.com/schmouk/cpprandlib/license)  [![Latest release](http://img.shields.io/github/release/schmouk/cpp-strings.svg?style=plastic&labelColor=blueviolet&color=success)](https://github.com/schmouk/cpprandlib/releases)  [![code_coverage](https://img.shields.io/badge/code_coverage-100%25-success?style=plastic&labelColor=blueviolet)]()  [![tests](https://img.shields.io/badge/tests-passing-success?style=plastic&labelColor=blueviolet)]()

What if c++ strings where as easy to use as Python strings?

Let's just use c++ strings as are Python ones, with same API or as similar API as possible.  
Library **cpp-strings** is fully templated. Just download header file `cppstrings.h` and put it anywhere in your project. Notice: all of its stuff is declared and defined in namespace `pcs` - which stands for **P**ythonic **C**++ **S**trings.

* The templated class `pcs::CppStringT<>` defines all constructors and methods that implement the equivalent of Python strings API.  
* Class `pcs::CppString` specializes the templated class with `char` characters.
* Class `pcs::CppWString` specializes the templated class with `wchar_t` characters.

**cpp-strings** is implemented with the currently most recent c++ standard available with gcc, clang and msvc c++ compilers, i.e. standard **c++20**.

* directory `cpp-strings` contains the header file `cppstring.h`.  
This is the header file to include in your projects.
* directory `cpp-strings-tests` contains the unit test file `cpp-strings-tests.cpp`  
This file tests all the library stuff. It is a valuable code container with so many examples of use of the library, the classes, the methods and the functions it defines.

The code has been developed using VS2022 IDE. As such, unitary tests have been coded using Microsoft Visual Studio Cpp Unit Test Framework. The related VS project is provided with this library.

Notice: no clang, gcc or msvc specific declarations or goodies have been use to code library **cpp-strings**. It should then be compilable with any of these compilers. To be able to use it with your project, just ensure that the c++ standard used with you favorite compiler is **c++20**: options `-std=c++20` or 
* options `-std=c++20` or `-std=c++latest` for clang and gcc (v. 10 and above),  
or option `-std=c++2a` for clang and gcc (v. 9 and earlier);
* options `/std=c++20` or `/std=c++latest` for Visual Studio 2019 and above

If you want to run the unitary tests, well, use Visual Studio 2022. The Community free version will truly be fine. The vcproject associated with the unit tests is already configured to use the option flag `/std:c++latest` since the implemented code uses a very few but very useful c++23 goodies.


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

... document creation still in progress ...
