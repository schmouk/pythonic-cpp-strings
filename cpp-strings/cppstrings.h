#pragma once
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

//=============================================================
#include <string>
#include <vector>
//#include <initializer_list>


//=============================================================
// Forward declarations
template<
    class CharT,
    class TraitsT = std::char_traits<CharT>,
    class AllocatorT = std::allocator<CharT>
> class CppStringT;                     //!< The templated base class. Use its belowing specializations instead!

using CppString  = CppStringT<char>;    //!< Specialization of basic class with template argument 'char'
using CppWString = CppStringT<wchar_t>; //!< Specialization of basic class with template argument 'wchar_t'


//=====   CppStringT<>   ======================================
/**
* \brief This is the templated base class for all CppString
* classes.
* 
* Users should instantiate any specialization of this  base  class
* rather than this base class itself:
*   - \see CppString for CppStringT<char>.
*   - \see CppWString for CppStringT<wchar_t>.
* 
* This base class inherits from std::basic_string<CharT>. As such,
* it  gets  direct access to all public methods of its base class.
* \see  https://en.cppreference.com/w/cpp/string/basic_string  for
* a full list of such methods, for instance.
* 
* You may specialize it by your own with any of the next char
* types:
*   - char8_t  (C++20)
*   - char16_t (C++11)
*   - char32_t (C++11)
*/
template<class CharT, class TraitsT, class AllocatorT>
class CppStringT : public std::basic_string<CharT>
{
public:
    //===   Wrappers   ========================================
    using MyBaseClass = std::basic_string<CharT>;

    using traits_type            = MyBaseClass::traits_type;
    using value_type             = MyBaseClass::value_type;
    using allocator_type         = MyBaseClass::allocator_type;
    using size_type              = MyBaseClass::size_type;
    using difference_type        = MyBaseClass::difference_type;
    using reference              = MyBaseClass::reference;
    using const_reference        = MyBaseClass::const_reference;
    using pointer                = MyBaseClass::pointer;
    using const_pointer          = MyBaseClass::const_pointer;
    using iterator               = MyBaseClass::iterator;
    using const_iterator         = MyBaseClass::const_iterator;
    using reverse_iterator       = MyBaseClass::reverse_iterator;
    using const_reverse_iterator = MyBaseClass::const_reverse_iterator;


    //===   Constructors   ====================================
    inline CppStringT() : MyBaseClass() {}
    inline CppStringT(const CppStringT& other) : MyBaseClass(other) {}
    inline CppStringT(const CppStringT& other, const AllocatorT& alloc) : MyBaseClass(other, alloc){}
    inline CppStringT(CppStringT&& other) : MyBaseClass(other) {}
    inline CppStringT(CppStringT&& other, const AllocatorT& alloc) : MyBaseClass(other, alloc) {}
    inline CppStringT(MyBaseClass::size_type count, CharT ch) : MyBaseClass(count, ch) {}
    inline CppStringT(const CppStringT& other, size_type pos) : MyBaseClass(other, pos) {}
    inline CppStringT(const CppStringT& other, size_type pos, size_type count) noexcept : MyBaseClass(other, pos, count) {}
    inline CppStringT(const CharT* s) : MyBaseClass(s) {}
    inline CppStringT(const CharT* s, size_type count) : MyBaseClass(s, count) {}
    inline CppStringT(std::initializer_list<CharT> ilist) : MyBaseClass(ilist) {}

    template<class InputIt>
    inline CppStringT(InputIt first, InputIt last) : MyBaseClass(first, last) {}

    template<class StringViewLike>
    explicit CppStringT(const StringViewLike& svl) : MyBaseClass(svl) {}

    template<class StringViewLike>
    CppStringT(const StringViewLike& svl, size_type pos, size_type n) : MyBaseClass(svl, pos, n) {}


    //===   Methods   =========================================

    //---   is_punctuation   ----------------------------------
    /** \brief Returns true if a character belongs to ASCII punctuation set. */
    inline const bool is_punctuation(const value_type ch) noexcept
    {
        return _ASCII_PUNCT_DATA.contains(ch);
    }


protected:


private:
    //===   DATA   ============================================
    static inline constexpr std::vector<value_type> _ASCII_PUNCT_DATA{ '!', ',', '.', ':', ';', '?' };

};
