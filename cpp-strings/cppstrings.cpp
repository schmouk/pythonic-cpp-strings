/**
    Library cppstrings
    "What if c++ strings where as easy to use as Python strings?"
 
    Copyright (C) 2023 Philippe Schmouker
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
*/

#include <iostream>

#include "cppstrings.h"
using namespace pcs;

/**
* Notice: this module is for tests and validation purposes only.
*/
int main()
{
    CppString  s("-5.1");
    CppWString ws(L"-5.1");

    std::cout << ws.isupper() << std::endl;
    std::cout << s.zfill(10).c_str() << std::endl;

    return 0;
}
