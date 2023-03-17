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
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cwctype>
#include <format>
#include <map>
#include <ranges>
#include <span>
#include <stdexcept>
#include <string_view>
#include <type_traits>
#include <vector>


namespace pcs // i.e. "pythonic c++ strings"
{
    //=============================================================
    // Forward declarations

    // base class -- not to be directly instantiated, see belowing specializations instead
    template<
        class CharT,
        class TraitsT = std::char_traits<CharT>,
        class AllocatorT = std::allocator<CharT>
    > class CppStringT;

    // specializations of the base class -- these are the ones that should be instantiated by user.
    using CppString  = CppStringT<char>;                        //!< Specialization of basic class with template argument 'char'
    using CppWString = CppStringT<wchar_t>;                     //!< Specialization of basic class with template argument 'wchar_t'

    // litteral operators
#pragma warning(disable: 4455)
    inline const CppString operator""cs(const char* str, std::size_t len);          //!< Forms a CppString literal. 
    inline const CppString operator""csv(const char* str, std::size_t len);         //!< Forms a CppString view literal. 
    inline const CppWString operator""cs(const wchar_t* str, std::size_t len);      //!< Forms a CppWString literal. 
    inline const CppWString operator""csv(const wchar_t* str, std::size_t len);     //!< Forms a CppWString view literal.

    // chars classifications -- not to be directly called, see respective specializations at the very end of this module.
    template<class CharT>
    inline const bool is_alpha(const CharT ch) noexcept;        //!< Returns true if character ch is alphabetic, or false otherwise.

    template<class CharT>
    inline const bool is_ascii(const CharT ch) noexcept;        //!< Returns true if character ch gets ASCII code, or false otherwise.

    template<class CharT>
    inline const bool is_id_continue(const CharT ch) noexcept;  //!< Returns true if character is a continuing char for identifiers, or false otherwise.

    template<class CharT>
    inline const bool is_decimal(const CharT ch) noexcept;      //!< Returns true if character is a decimal digit, or false otherwise.

    template<class CharT>
    inline const bool is_id_start(const CharT ch) noexcept;     //!< Returns true if character is a starting char for identifiers, or false otherwise.

    template<class CharT>
    inline const bool is_lower(const CharT ch) noexcept;        //!< Returns true if character is lowercase, or false otherwise.

    template<class CharT>
    inline const bool is_printable(const CharT ch) noexcept;    //!< Returns true if character ch is printable, or false otherwise.

    template<class CharT>
    inline const bool is_punctuation(const CharT ch) noexcept;  //!< Returns true if character ch is punctuation, or false otherwise.

    template<class CharT>
    inline const bool is_space(const CharT ch) noexcept;        //!< Returns true if character ch is white space, or false otherwise.

    template<class CharT>
    inline const bool is_upper(const CharT ch) noexcept;        //!< Returns true if character is uppercase, or false otherwise.

    template<class CharT>
    inline const CharT swap_case(const CharT ch) noexcept;      //!< Returns the swapped case form of character ch if it exists, or ch itself otherwise.

    template<class CharT>
    inline const CharT to_lower(const CharT ch) noexcept;       //!< Returns the lowercase form of character ch if it exists, or ch itself otherwise.

    template<class CharT>
    inline const CharT to_upper(const CharT ch) noexcept;       //!< Returns the uppercase form of character ch if it exists, or ch itself otherwise.


    //=====   CppStringT<>   ======================================
    /** \brief This is the templated base class for all CppString classes.
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
        using MyBaseClass  = std::basic_string<CharT>;
        using MyStringView = std::basic_string_view<CharT>;

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


        //===   Constructors / Destructor   ===================
        inline CppStringT()                                                                 : MyBaseClass() {}
        inline CppStringT(const CppStringT& other)                                          : MyBaseClass(other) {}
        inline CppStringT(const CppStringT& other, const AllocatorT& alloc)                 : MyBaseClass(other, alloc) {}
        inline CppStringT(CppStringT&& other)                                               : MyBaseClass(other) {}
        inline CppStringT(CppStringT&& other, const AllocatorT& alloc)                      : MyBaseClass(other, alloc) {}
        inline CppStringT(MyBaseClass::size_type count, CharT ch)                           : MyBaseClass(count, ch) {}
        inline CppStringT(const CppStringT& other, size_type pos)                           : MyBaseClass(other, pos) {}
        inline CppStringT(const CppStringT& other, size_type pos, size_type count) noexcept : MyBaseClass(other, pos, count) {}
        inline CppStringT(const CharT* s)                                                   : MyBaseClass(s) {}
        inline CppStringT(const CharT* s, size_type count)                                  : MyBaseClass(s, count) {}
        inline CppStringT(std::initializer_list<CharT> ilist)                               : MyBaseClass(ilist) {}

        inline CppStringT(const MyBaseClass& other)                                         : MyBaseClass(other) {}
        inline CppStringT(const MyBaseClass& other, const AllocatorT& alloc)                : MyBaseClass(other, alloc) {}
        inline CppStringT(MyBaseClass&& other)                                              : MyBaseClass(other) {}
        inline CppStringT(MyBaseClass&& other, const AllocatorT& alloc)                     : MyBaseClass(other, alloc) {}

        template<class InputIt>
        inline CppStringT(InputIt first, InputIt last)                                      : MyBaseClass(first, last) {}

        template<class StringViewLike>
        explicit CppStringT(const StringViewLike& svl)                                      : MyBaseClass(svl) {}

        template<class StringViewLike>
        CppStringT(const StringViewLike& svl, size_type pos, size_type n)                   : MyBaseClass(svl, pos, n) {}

        inline ~CppStringT() = default;


        //===   Exceptions   ======================================
        class NotFoundException : public std::logic_error
        {
        public:
            using MyBaseClass = std::logic_error;

            inline NotFoundException(const std::string& what_arg) : MyBaseClass(what_arg) {}
            inline NotFoundException(const char* what_arg) : MyBaseClass(what_arg) {}
        };


        //===   Methods   =========================================

        //---   capitalize()   ------------------------------------
        /** \brief In-place modifies the string with its first character capitalized and the rest lowercased. Returns a reference to the string*/
        inline CppStringT& capitalize() noexcept
        {
            if (!this->empty()) {
                this->lower();
                (*this)[0] = pcs::to_upper((*this)[0]);
            }
            return *this;
        }


        //---   center()   ----------------------------------------
        /** \brief Returns the string centered in a string of length width.
        *
        * Padding is done using the specified fillchar (default is an ASCII space).
        * A copy of the original string is returned if width is less than or  equal
        * to the length of the string. The original string remains unchanged.
        */
        inline CppStringT center(const size_type width, const value_type fillch = value_type(' ')) const noexcept
        {
            const size_type l{ this->size() };
            if (l <= width)
                return CppStringT(*this);
            const size_type half{ (width - l) / 2 };
            return CppStringT(fillch, half) + *this + CppStringT(fillch, width - half - l);
        }


        //---   count()   -----------------------------------------
        /** \brief Returns the number of non-overlapping occurrences of substring sub in the range [start, end]. */
        inline constexpr size_type count(const CppStringT& sub, const size_type start = 0, const size_type end = 0) const noexcept
        {
            const size_type length{ this->size() };
            const size_type end_{ (end == 0) ? length : end };

            size_type n = 0;
            size_type start_ = start;
            while ((start_ = find(sub, start_, end_)) != CppStringT::npos)
                n++;

            return n;
        }


        //---   count_n()   ---------------------------------------
        /** \brief Returns the number of non-overlapping occurrences of substring sub in the range [start, start+length-1]. */
        inline constexpr size_type count_n(const CppStringT& sub, const size_type start, const size_type length) const noexcept
        {
            return count(sub, start, start + length - 1);
        }

        /** \brief Returns the number of non-overlapping occurrences of substring sub in the range [0, length-1]. */
        inline constexpr size_type count_n(const CppStringT& sub, const size_type length) const noexcept
        {
            return count(sub, 0, length - 1);
        }


        //---   endswith()   --------------------------------------
        /** Returns true if the string ends with the specified suffix, otherwise returns false. Test begins at start position and stops at end position. */
        inline const bool endswith(const CppStringT& suffix, const size_type start, const size_type end) const noexcept
        {
            return endswith(std::span{ suffix }, start, end);
        }

        /** Returns true if the string ends with the specified suffix, otherwise returns false. Test begins at start position and stops at end of string. */
        inline const bool endswith(const CppStringT& suffix, const size_type start) const noexcept
        {
            return endswith(std::span{ suffix }, start, this->size() - 1);
        }

        /** Returns true if the string ends with the specified suffix, otherwise returns false. Test runs on the whole string. */
        inline const bool endswith(const CppStringT& suffix) const noexcept
        {
            return this->ends_with(suffix);
        }

        /** Returns true if the string ends with any of the specified suffixes, otherwise returns false. Test begins at start position and stops at end of string. */
        inline const bool endswith(const std::span<CppStringT>& suffixes, const size_type start, const size_type end) const noexcept
        {
            if (start > end)
                return false;
            else
                return std::any_of(suffixes.cbegin(), suffixes.cend(), this->substr(start, end).ends_with);
            /*
            for (auto& suffix : suffixes) {
                if (this->substr(start, end).ends_with(suffix))
                    return true;
            }

            return false;
            */
        }


        //---   endswith_n()   ------------------------------------
        /** Returns true if the string ends with the specified suffix, otherwise returns false. Test begins at start position and stops after count positions. */
        inline const bool endswith_n(const CppStringT& suffix, const size_type start, const size_type count) const noexcept
        {
            return endswith(std::span{ suffix }, start, start + count - 1);
        }

        /** Returns true if the string ends with the specified suffix, otherwise returns false. Test begins at position 0 and stops after count positions. */
        inline const bool endswith_n(const CppStringT& suffix, const size_type count) const noexcept
        {
            return endswith(std::span{ suffix }, 0, count - 1);
        }

        /** Returns true if the string ends with any of the specified suffixes, otherwise returns false. Test begins at start position and stops after count positions. */
        inline const bool endswith_n(const std::span<CppStringT>& suffixes, const size_type start, const size_type count) const noexcept
        {
            return endswith(suffixes, start, start + count - 1);
        }


        //---   expand_tabs()   -----------------------------------
        /** Returns a copy of the string where all tab characters are replaced by one or more spaces, depending on the current column and the given tab size. */
        CppStringT expand_tabs(const size_type tabsize = 8) const noexcept
        {
            const size_type tabsize_{ tabsize == 0 ? 1 : tabsize };
            CppStringT ret{};

            std::size_t current_pos{ 0 };
            for (const value_type ch : *this) {
                if (ch == value_type('\t')) {
                    do {
                        ret += value_type(' ');
                        current_pos++;
                    } while (current_pos % tabsize_ != 0);
                }
                else if (ch == value_type('\n') || ch == value_type('\r')) {
                    ret += ch;
                    current_pos = 0;
                }
                else {
                    ret += ch;
                    current_pos++;
                }
            }

            return ret;
        }


        //---   find()   ------------------------------------------
        /** Returns the lowest index in the string where substring sub is found within the slice str[start:end], or -1 (i.e. 'npos') if sub is not found.
        *
        * Note: this method should be used only if you need to know the position of
        * sub.  To check if sub is a substring or not, use the method contains_n().
        *
        * \see find_n(), rfind() and rfind_n().
        * \see index(), index_n(), rindex() and rindex_n().
        */
        inline constexpr size_type find(const CppStringT& sub, const size_type start, const size_type end) const noexcept
        {
            if (start > end)
                return CppStringT::npos;
            else
                return find_n(sub, start, end - start + 1);
        }


        //---   find_n()   ----------------------------------------
        /** Returns the lowest index in the string where substring sub is found within the slice str[start:start+count-1], or -1 (i.e. 'npos') if sub is not found.
        *
        * Note: this method should be used only if you need to know the position of
        * sub.  To check if sub is a substring or not, use the method contains_n().
        *
        * \see find(), rfind() and rfind_n().
        * \see index(), index_n(), rindex() and rindex_n().
        */
        inline constexpr size_type find_n(const CppStringT& sub, const size_type start, const size_type count) const noexcept
        {
            try {
                return this->substr(start, count).find(sub);
            }
            catch (...) {
                return CppStringT::npos;
            }
        }

        /** Returns the lowest index in the string where substring sub is found within the slice str[0:count-1], or -1 (i.e. 'npos') if sub is not found.
        *
        * Note: this method should be used only if you need to know the position of
        * sub.  To check if sub is a substring or not, use the method contains_n().
        *
        * \see find(), rfind() and rfind_n().
        * \see index(), index_n(), rindex() and rindex_n().
        */
        inline constexpr size_type find_n(const CppStringT& sub, const size_type count) const noexcept
        {
            return find_n(sub, 0, count);
        }


        //---   index()   -----------------------------------------
        /** Like find(), but raises NotFoundException when the substring is not found.
        *
        * \see index_n(), rindex() and rindex_n().
        * \see find(), find_n(), rfind() and rfind_n().
        */
        inline constexpr size_type index(const CppStringT& sub, const size_type start, const size_type end) const
        {
            const size_type ret_value = find(sub, start, end);
            if (size_type == CppStringT::npos)
                throw NotFoundException(std::format("substring \"{}\" not found in string \"{}\"", sub, this->c_str()));
            else
                return ret_value;
        }


        //---   index_n()   ---------------------------------------
        /** Like find_n(sub, start, count), but raises NotFoundException when the substring is not found.
        *
        * \see index_n(), rindex() and rindex_n().
        * \see find(), find_n(), rfind() and rfind_n().
        */
        inline constexpr size_type index_n(const CppStringT& sub, const size_type start, const size_type count) const
        {
            return index(sub, start, start + count - 1);
        }

        /** Like find_n(sub, count), but raises NotFoundException when the substring is not found.
        *
        * \see index_n(), rindex() and rindex_n().
        * \see find(), find_n(), rfind() and rfind_n().
        */
        inline constexpr size_type index_n(const CppStringT& sub, const size_type count) const
        {
            return index(sub, 0, count);
        }


        //---   isalnum()   ---------------------------------------
        /** \brief Returns true if all characters in the string are alphanumeric and there is at least one character, or false otherwise. */
        inline const bool isalnum() const noexcept
        {
            return this->isalpha() || this->isdecimal() || this->isdigit() || this->isnumeric();
        }


        //---   isalpha()   --------------------------------------
        /** \brief Returns true if all characters in the string are alphabetic and there is at least one character, or false otherwise. */
        inline const bool isalpha() const noexcept
        {
            return !this->empty()  &&  std::all_of(this->cbegin(), this->cend(), [](const value_type ch) { return pcs::is_alpha<CharT>(ch); });
        }


        //---   isascii()   ---------------------------------------
        /** \brief Returns true if the string is empty or all characters in the string are ASCII, or false otherwise. */
        #if defined(isascii)  // may be already defined in header file <ctype.h>
            #undef isascii
        #endif
        inline const bool isascii() const noexcept
        {
            return this->empty()  ||  std::all_of(this->cbegin(), this->cend(), pcs::is_ascii<CharT>);
        }


        //---   isdecimal()   -------------------------------------
        /** \brief Returns true if all characters in the string are decimal characters and there is at least one character, or false otherwise.
        *
        * Decimal characters are those that can be used to form numbers  in 
        * base 10, e.g. U+0660, ARABIC-INDIC DIGIT ZERO. Formally a decimal 
        * character is a character in the Unicode General Category “Nd”.
        */
        inline const bool isdecimal() const noexcept
        {
            return !this->empty()  &&  std::all_of(this->cbegin(), this->cend(), pcs::is_decimal<CharT>);
        }


        //---   isdigit()   ---------------------------------------
        /** \brief Returns true if all characters in the string are digits and there is at least one character, or false otherwise.
        *
        * Digits include decimal characters and digits that need special 
        * handling,  such as the compatibility superscript digits.  This 
        * covers digits which cannot be used to form numbers in base 10, 
        * like the Kharosthi numbers.  Formally,  a digit is a character 
        * that has the property value Numeric_Type=Digit or Numeric_Type
        * =Decimal.
        * 
        * CAUTION: current implementation of  library  cpp-strings  does
        * not implement above algorithm. It just returns the same result
        * as 'isdecimal()' which is NOT what Python str library does.
        */
        inline const bool isdigit() const noexcept
        {
            return isdecimal();
        }


        //---   isidentifier()   ----------------------------------
        /** \brief Returns true if the string is not empty and is a valid identifier according to the language definition, or false otherwise.
        *
        * CAUTION:  the current implementation of this method does not deal with the proper c++
        * defintiion of identifiers (see https://en.cppreference.com/w/cpp/language/identifiers 
        * and https://www.unicode.org/reports/tr31/#Table_Lexical_Classes_for_Identifiers).
        *
        * While the specification of identifiers in c++ is this one:
        * 
        *    identifier   ::= XID_Start XID_Continue*
        *    XID_Start    ::= ID_Start XID_Continue*
        *    ID_Start     ::= <characters derived from the Unicode General_Category of uppercase letters, lowercase letters, titlecase letters, modifier letters, other letters, letter numbers, plus Other_ID_Start, minus Pattern_Syntax and Pattern_White_Space code points>
        *    XID_Continue ::= <characters  derived from ID_Continue as per Unicode specs Section 5.1, NFKC Modifications (https://www.unicode.org/reports/tr31/#NFKC_Modifications)>
        *    ID_Continue  ::= ID_Start | <characters having the Unicode General_Category of nonspacing marks, spacing combining marks, decimal number, connector punctuation, plus Other_ID_Continue, minus Pattern_Syntax and Pattern_White_Space code points>
        * 
        * the currently implemented rule is this simpler one:
        * 
        *    identifier   ::= ID_Start id_continue*
        *    id_continue  ::= ID_Start | <decimal number>
        */
        inline const bool isidentifier() const noexcept
        {
            return !this->empty() && pcs::is_id_start((*this)[0]) && (this->size() == 1 || std::all_of(this->cbegin() + 1, this->cend(), pcs::is_id_continue));
        }


        //---   islower()   ---------------------------------------
        /** \brief Returns true if all cased characters in the string are lowercase and there is at least one cased character, or false otherwise. */
        inline const bool islower() const noexcept
        {
            return !this->empty() && std::all_of(this->cbegin(), this->cend(), pcs::is_lower<CharT>);
        }


        //---   isnumeric()   -------------------------------------
        /** \brief Returns true if all characters in the string are numeric characters, and there is at least one character, or false otherwise.
        *
        * CAUTION:  current implementation just returns isdecimal() result,
        * while the description of isnumeric() should be this one:
        * Numeric  characters  include digit characters, and all characters 
        * that have the Unicode numeric value property.  Formally,  numeric
        * characters  are those with the property value Numeric_Type=Digit,
        * Numeric_Type=Decimal or Numeric_Type=Numeric.
        */
        inline const bool isnumeric() const noexcept
        {
            return isdecimal();
        }


        //---   isprintable()   -----------------------------------
        /** \brief Returns true if all characters in the string are printable or if the string is empty, or false otherwise.
        *
        * Nonprintable characters are those characters defined in the Unicode 
        * character  database as “Other” or “Separator”,  excepting the ASCII 
        * space (0x20) which is considered printable.
        */
        inline const bool isprintable() const noexcept
        {
            return this->empty() || std::all_of(this->cbegin(), this->cend(), pcs::is_printable<CharT>);
        }


        //---   ispunctuation()   ---------------------------------
        /** \brief Returns true if the string contains only one character and if this character belongs to the ASCII punctuation set. */
        inline const bool ispunctuation() const noexcept
        {
            return this->size() == 1 && pcs::is_punctuation((*this)[0]);
        }


        //---   isspace()   ---------------------------------------
        /** \brief Returns true if there are only whitespace characters in the string and there is at least one character, or false otherwise. */
        inline const bool isspace() const noexcept
        {
            return !this->empty() && std::all_of(this->cbegin(), this->cend(), pcs::is_space<CharT>);
        }


        //---   istitle()   ---------------------------------------
        /** \brief Returns true if the string is a titlecased string and there is at least one character, or false otherwise.
        *
        * For instance uppercase characters may only follow uncased 
        * characters and lowercase characters only cased ones.
        */
        inline const bool istitle() const noexcept
        {
            return !this->empty && this->title() == *this;
        }


        //---   isupper()   ---------------------------------------
        /** \brief Returns true if all cased characters in the string are uppercase and there is at least one cased character, or false otherwise. */
        inline const bool isupper() const noexcept
        {
            return !this->empty() && std::all_of(this->cbegin(), this->cend(), pcs::is_upper<CharT>);
        }


        //---   is_words_sep()   ----------------------------------
        /** \brief Returns true if there are only whitespace and punctuation characters in the string and there is at least one character, or false otherwise. */
        inline const bool is_words_sep() const noexcept
        {
            return isspace() || ispunctuation();
        }


        //---   join()   ------------------------------------------
        /** \brief Returns a string which is the concatenation of the strings in the parameters list. 
        *
        * The separator between elements is the string to which this method is applied.
        */
        template<class... NextCppStringsT>
        inline CppStringT join(const CppStringT& first, const NextCppStringsT... others) const noexcept
            requires (sizeof...(others) > 0)
        {
            return first + *this + this->join(others...);
        }

        /** \brief Single parameter signature. Returns a copy of this parameter. */
        inline const CppStringT join(const CppStringT& s) const noexcept
        {
            return s;
        }

        /** \brief Empty parameters list signature. Returns a copy of current string. */
        inline const CppStringT join() const noexcept
        {
            return *this;
        }


        //---   ljust()   -----------------------------------------
        /** \brief Returns the string left justified in a string of length width.
        *
        * Padding is done using the specified fillchar (default is an ASCII space). 
        * The original string is returned if width is less than or equal to len(s).
        */
        inline CppStringT ljust(const size_type width, const value_type fillch = value_type(' ')) const noexcept
        {
            if (this->size() >= width)
                return *this;
            else
                return *this + CppStringT(width - this->size(), fillch);
        }


        //---   lower ()  -----------------------------------------
        /** \brief In-place replaces all characters of the string with their lowercase conversion. Returns a reference to string.
        *
        * Notice: uses the currently set std::locale, which is the "C" one
        * by default or any other one as previously set by the user.
        */
        inline CppStringT& lower() noexcept
        {
            std::transform(this->begin(), this->end(),
                           this->begin(),
                           [](value_type ch) { return this->lower(ch); });
            return *this;
        }

        /** \brief Returns lowercase conversion of the character.
        *
        * Notice: uses the currently set std::locale, which is the "C" one
        * by default or any other one as previously set by the user.
        */
        static inline const value_type lower(const value_type ch) noexcept
        {
            return value_type(std::tolower(ch));
        }
        

        //---   lstrip()   ----------------------------------------
        /** \brief Returns a copy of the string with leading characters removed.
        *
        * The passed string specifies the set of characters to be removed. 
        * The chars argument is not a prefix;  rather, all combinations of 
        * its values are stripped.
        * To remove a prefix, rather call method 'removeprefix()'.
        */
        inline CppStringT lstrip(const CppStringT& prefix) const noexcept
        {
            for (auto it = this->cbegin(); it != this->cend(); ++it)
                if (std::none_of(prefix.cbegin(), prefix.cend(), [it](const value_type ch) { *it == ch; }))
                    return CppStringT(it, this->cend());
            return CppStringT();
        }

        /** \brief Returns a copy of the string with leading whitespaces removed. */
        inline CppStringT lstrip() const noexcept
        {
            for (auto it = this->cbegin(); it != this->cend(); ++it)
                if (*it != value_type(' '))
                    return CppStringT(it, this->cend());
            return CppStringT();
        }


        //---   partition()   -------------------------------------
        /** Split the string at the first occurrence of sep, and returns a 3-items vector containing the part before the separator, the separator itself, and the part after the separator.
        *
        * If the separator is not  found,  returns  a  3-items  vector
        * containing the string itself, followed by two empty strings. 
        */
        std::vector<CppStringT> partition(const CppStringT& sep) const noexcept
        {
            const size_type sep_index = find(sep);
            if (sep_index == CppStringT::npos) {
                const CppStringT empty{};
                return std::vector<CppStringT>({ *this, empty, empty });
            }
            else {
                const size_type third_index = sep_index + sep.size();
                const size_type third_size = this->size() - third_index + 1;
                return std::vector<CppStringT>({ this->substr(0, sep_index), sep, this->substr(third_index, third_size) });
            }
        }


        //---   removeprefix()   ----------------------------------
        /** \brief If the string starts with the prefix string, returns a new string with the prefix removed. Otherwise, returns a copy of the original string. */
        inline CppStringT removeprefix(const CppStringT& prefix) const noexcept
        {
            if (this->startswith(prefix)) {
                const size_type prefix_length = prefix.size();
                return this->substr(prefix_length, this->size() - prefix_length + 1);
            }
            else
                return *this;
        }


        //---   removesuffix()   ----------------------------------
        /** \brief If the string ends with the suffix string, returns a new string with the suffix removed. Otherwise, returns a copy of the original string. */
        inline CppStringT removesuffix(const CppStringT& suffix) const noexcept
        {
            if (this->endswith(suffix)) {
                const size_type suffix_length = suffix.size();
                return this->substr(0, this->size() - suffix_length + 1);
            }
            else
                return *this;
        }


        //---   replace()   ---------------------------------------
        /** \brief Returns a copy of the string with all occurrences of substring old replaced by new. */
        CppStringT replace(const CppStringT& old, const CppStringT& new_) const noexcept
        {
            if (!this->contains(old))
                return *this;

            CppStringT res{};
            size_type last_index = 0;
            size_type current_index = 0;
            while ((current_index = this->find(old)) != CppStringT::npos) {
                res += this->substr(last_index, current_index - last_index) + new_;
                last_index = current_index;
            }

            if (last_index != this->size())
                res += this->substr(last_index, this->size - last_index);
            
            return res;
        }

        /** \brief Returns a copy of the string with first count occurrences of substring old replaced by new. */
        CppStringT replace(const CppStringT& old, const CppStringT& new_, size_type count) const noexcept
        {
            if (!this->contains(old) || count == 0)
                return *this;

            CppStringT res{};
            size_type last_index = 0;
            size_type current_index = 0;
            while (count > 0 && (current_index = this->find(old)) != CppStringT::npos) {
                res += this->substr(last_index, current_index - last_index) + new_;
                last_index = current_index;
                --count;
            }

            if (last_index != this->size())
                res += this->substr(last_index, this->size - last_index);

            return res;
        }


        //---   rfind()   -----------------------------------------
        /** Returns the highest index in the string where substring sub is found within the slice str[start:end], or -1 (i.e. 'npos') if sub is not found.
        *
        * Note that this is an offset from the start of the string, not the end.
        *
        * Note: this method should be used only if you need to  know  the  position
        * of sub. To check if sub is a substring or not, use the method contains().
        *
        * \see find(), find_n() and rfind_n().
        * \see index(), index_n(), rindex() and rindex_n().
        */
        inline constexpr size_type rfind(const CppStringT& sub, const size_type start, const size_type end) const noexcept
        {
            if (start > end)
                return CppStringT::npos;
            else
                return this->substr(start, end - start + 1).rfind(sub);
        }

        /** Returns the highest index in the string where substring sub is found starting at start position in string, or -1 (i.e. 'npos') if sub is not found.
        *
        * Note that this is an offset from the start of the string, not the end.
        *
        * Note: this method should be used only if you need to  know  the  position
        * of sub. To check if sub is a substring or not, use the method contains().
        *
        * \see find(), find_n() and rfind_n().
        * \see index(), index_n(), rindex() and rindex_n().
        */
        inline constexpr size_type rfind(const CppStringT& sub, const size_type start) const noexcept
        {
            return rfind(sub, start, this->size() - start + 1);
        }

        /** Returns the highest index in the string where substring sub is found in the whole string, or -1 (i.e. 'npos') if sub is not found.
        *
        * Note that this is an offset from the start of the string, not the end.
        *
        * Note: this method should be used only if you need to  know  the  position
        * of sub. To check if sub is a substring or not, use the method contains().
        *
        * \see find(), find_n() and rfind_n().
        * \see index(), index_n(), rindex() and rindex_n().
        */
        inline constexpr size_type rfind(const CppStringT& sub) const noexcept
        {
            return MyBaseClass::rfind(sub);
        }


        //---   rfind_n()   ---------------------------------------
        /** Returns the highest index in the string where substring sub is found within the slice str[start:start+count-1], or -1 (i.e. 'npos') if sub is not found.
        *
        * Note: this method should be used only if you need to  know  the  position
        * of sub. To check if sub is a substring or not, use the method contains_n().
        *
        * \see find(), find_n() and rfind().
        * \see index(), index_n(), rindex() and rindex_n().
        */
        inline constexpr size_type rfind_n(const CppStringT& sub, const size_type start, const size_type count) const noexcept
        {
            return rfind(sub, start, start + count - 1);
        }

        /** Returns the highest index in the string where substring sub is found within the slice str[0:count-1], or -1 (i.e. 'npos') if sub is not found.
         *
         * Note: this method should be used only if you need to  know  the  position
         * of sub. To check if sub is a substring or not, use the method contains_n().
         *
         * \see find(), find_n() and rfind().
         * \see index(), index_n(), rindex() and rindex_n().
         */
        inline constexpr size_type rfind_n(const CppStringT& sub, const size_type count) const noexcept
        {
            return rfind(sub, 0, count);
        }


        //---   rindex()   ----------------------------------------
        /** Like rfind(sub, start, end), but raises NotFoundException when the substring is not found.
        *
        * \see index(), index_n() and rindex_n().
        * \see find(), find_n(), rfind() and rfind_n().
        */
        inline constexpr size_type rindex(const CppStringT& sub, const size_type start, const size_type end) const
        {
            const size_type ret_value = rfind(sub, start, end);
            if (size_type == CppStringT::npos)
                throw NotFoundException(std::format("substring \"{}\" not found in string \"{}\"", sub, this->c_str()));
            else
                return ret_value;
        }

        /** Like rfind(sub, start), but raises NotFoundException when the substring is not found.
         *
         * \see index(), index_n() and rindex_n().
         * \see find(), find_n(), rfind() and rfind_n().
         */
        inline constexpr size_type rindex(const CppStringT& sub, const size_type start) const
        {
            return rindex(sub, start, this->size() - 1);
        }

        /** Like rfind(sub), but raises NotFoundException when the substring is not found.
         *
         * \see index(), index_n() and rindex_n().
         * \see find(), find_n(), rfind() and rfind_n().
         */
        inline constexpr size_type rindex(const CppStringT& sub) const
        {
            return rindex(sub, 0, this->size() - 1);
        }


        //---   rindex_n()   --------------------------------------
        /** Like rfind_n(sub, start, count), but raises NotFoundException when the substring is not found.
        *
        * \see index_n(), rindex() and rindex_n().
        * \see find(), find_n(), rfind() and rfind_n().
        */
        inline constexpr size_type rindex_n(const CppStringT& sub, const size_type start, const size_type count) const
        {
            return rindex(sub, start, start + count - 1);
        }

        /** Like rfind_n(sub, count), but raises NotFoundException when the substring is not found.
        *
        * \see index_n(), rindex() and rindex_n().
        * \see find(), find_n(), rfind() and rfind_n().
        */
        inline constexpr size_type rindex_n(const CppStringT& sub, const size_type count) const
        {
            return rindex(sub, 0, count);
        }


        //---   rjust()   -----------------------------------------
        /** \brief Returns the string right justified in a string of length width.
        *
        * Padding is done using the specified fillchar (default is an ASCII space).
        * The original string is returned if width is less than or equal to len(s).
        */
        inline CppStringT rjust(const size_type width, const value_type fillch = value_type(' ')) const noexcept
        {
            if (this->size() >= width)
                return *this;
            else
                return CppStringT(width - this->size(), fillch) + *this;
        }


        //---   rpartition()   -------------------------------------
        /** Splits the string at the last occurrence of sep, and returns a 3-items vector containing the part before the separator, the separator itself, and the part after the separator.
        *
        * If the separator is not  found,  returns  a  3-items  vector
        * containing the string itself, followed by two empty strings.
        */
        std::vector<CppStringT> rpartition(const CppStringT& sep) const noexcept
        {
            const size_type sep_index = rfind(sep);
            if (sep_index == CppStringT::npos) {
                const CppStringT empty{};
                return std::vector<CppStringT>({ *this, empty, empty });
            }
            else {
                const size_type third_index = sep_index + sep.size();
                const size_type third_size = this->size() - third_index + 1;
                return std::vector<CppStringT>({ this->substr(0, sep_index), sep, this->substr(third_index, third_size) });
            }
        }


        //---   rsplit()   ----------------------------------------
        /** \brief Returns a vector of the words in the whole string, as seperated with whitespace strings.
        *
        * Notice: runs of consecutive whitespace are regarded as a single
        * separator,  and the result will contain no empty strings at the 
        * start or end if the string has leading or trailing  whitespace.
        * Consequently,  splitting an empty string or a string consisting 
        * of just whitespace with a whitespace separator returns an ampty
        * vector.
        */
        inline std::vector<CppStringT> rsplit() const noexcept
        {
            return split();
        }

        /** \brief Returns a vector of the words in the whole string, using sep as the delimiter string. */
        inline std::vector<CppStringT> rsplit(const CppStringT& sep) const noexcept
        {
            return split(sep);
        }

        /** \brief Returns a vector of the words in the string, as seperated with whitespace strings. At most maxsplit splits are done, the rightmost ones. */
        std::vector<CppStringT> rsplit(const size_type maxsplit) const noexcept
        {
            std::vector<CppStringT> res{};

            if (maxsplit == 0) {
                res.push_back(*this);
            }
            else {
                const CppStringT whitespace(value_type(' '));
                std::vector<CppStringT> all_words{ this->split(whitespace) };

                size_type count = maxsplit;
                auto word_it = all_words.crbegin();
                size_type last_split_index = all_words.size();
                while (count > 0 && word_it != all_words.crend()) {
                    if (!word_it->empty()) {
                        res.insert(res.cbegin(), *word_it);
                        --count;
                        --last_split_index;
                    }
                    word_it++;
                }
                
                size_type chars_count = last_split_index;
                while (last_split_index > 0) {
                    chars_count += all_words[last_split_index].size();
                    --last_split_index;
                }
                if (chars_count > 0)
                    res.insert(res.cbegin(), this->substr(0, chars_count));
                /*
                constexpr CppStringT spc2("  ");
                constexpr CppStringT spc(value_type(' '));
                CppStringT tmp = *this;
                while (tmp.contains(spc2))
                    tmp = tmp.replace(spc2, spc);

                res = tmp->rsplit(spc, maxsplit);
                */
            }

            return res;
        }

        /** \brief Returns a vector of the words in the string, using sep as the delimiter string. At most maxsplit splits are done, the rightmost ones. */
        std::vector<CppStringT> rsplit(const CppStringT& sep, const size_type maxsplit) const noexcept
        {
            std::vector<CppStringT> res{};

            if (maxsplit == 0) {
                res.push_back({ *this });
            }
            else {
                std::vector<CppStringT> all_words{ this->split(sep) };

                size_type count = maxsplit;
                auto word_it = all_words.crbegin();
                size_type last_split_index = all_words.size();
                while (count > 0 && word_it != all_words.crend()) {
                    res.insert(res.cbegin(), *word_it);
                    --count;
                    --last_split_index;
                    word_it++;
                }

                size_type chars_count = last_split_index;
                while (last_split_index > 0) {
                    chars_count += all_words[last_split_index].size();
                    --last_split_index;
                }
                if (chars_count > 0)
                    res.insert(res.cbegin(), this->substr(0, chars_count));
                /*
                std::vector<CppStringT> indexes{};
                CppStringT tmp = *this;
                size_type count = maxsplit;
                size_type index;
                while ((index = tmp.rfind(sep)) != CppStringT::npos  &&  count > 0) {
                    indexes.insert(indexes.begin(), index);
                    if (index == 0)
                        break;
                    tmp = tmp.substr(0, index-1);
                    count--;
                }

                if (indexes.size() == 0)
                    res.push_back(*this);
                else {
                    index = 0;
                    for (const size_type ndx: indexes) {
                        res.push_back(this->substr(index, ndx - index));
                        index = ndx + 1;
                }
                res.push_back(this->substr(index, this->size() - index));
                */
            }

            return res;
        }


        //---   rstrip()   ----------------------------------------
        /** \brief Returns a copy of the string with trailing characters removed.
        *
        * The passed string specifies the set of characters to be removed.
        * The chars argument is not a prefix;  rather, all combinations of
        * its values are stripped.
        * To remove a suffix, rather call method 'removesuffix()'.
        */
        inline CppStringT rstrip(const CppStringT& prefix) const noexcept
        {
            for (auto it = this->crbegin(); it != this->crend(); ++it)
                if (std::none_of(prefix.cbegin(), prefix.cend(), [it](const value_type ch) { *it == ch; }))
                    return CppStringT(this->cbegin(), it);
            return CppStringT();
        }

        /** \brief Returns a copy of the string with trailing whitespaces removed. */
        inline CppStringT rstrip() const noexcept
        {
            for (auto it = this->crbegin(); it != this->crend(); ++it)
                if (*it != value_type(' '))
                    return CppStringT(this->cbegin(), it);
            return CppStringT();
        }


        //---   split()   -----------------------------------------
        /** \brief Returns a vector of the words in the whole string, as seperated with whitespace strings.
        *
        * Notice: runs of consecutive whitespace are regarded as a single
        * separator,  and the result will contain no empty strings at the
        * start or end if the string has leading or trailing  whitespace.
        * Consequently,  splitting an empty string or a string consisting
        * of just whitespace with a whitespace separator returns an ampty
        * vector.
        */
        inline std::vector<CppStringT> split() const noexcept
        {
            std::vector<std::string> res;
            constexpr CppStringT whitespace(value_type(' '));
            for (const auto& word : *this | std::views::split(whitespace))
                if (!word.empty())
                    res.push_back(CppStringT(word.begin(), word.end()));
            return res;
        }

        /** \brief Returns a vector of the words in the whole string, using sep as the delimiter string.
        *
        * Notice: consecutive delimiters are not grouped together  and  are
        * deemed  to delimit empty strings  (for example, "1,,2".split(",") 
        * returns {"1", "", "2"}). The sep argument may consist of multiple 
        * characters (for example, "1<>2<>3".split("<>") returns {"1", "2", 
        * "3"]).  Splitting  an  empty  string  with  a specified separator 
        * returns {""}.
        */
        inline std::vector<CppStringT> split(const CppStringT& sep) const noexcept
        {
            std::vector<std::string> res;
            for (const auto& word : *this | std::views::split(sep))
                res.push_back(CppStringT(word.begin(), word.end()));
            return res;
        }

        /** \brief Returns a vector of the words in the string, as seperated with whitespace strings. At most maxsplit splits are done, the leftmost ones. */
        std::vector<CppStringT> split(const size_type maxsplit) const noexcept
        {
            std::vector<CppStringT> res{};

            if (maxsplit == 0) {
                res.push_back(*this);
            }
            else {
                const CppStringT whitespace(value_type(' '));
                std::vector<CppStringT> all_words{ this->split(whitespace) };

                size_type count = maxsplit;
                auto word_it = all_words.cbegin();
                while (count > 0 && word_it != all_words.cend()) {
                    if (!word_it->empty()) {
                        res.insert(res.cbegin(), *word_it);
                        --count;
                    }
                    word_it++;
                }

                size_type chars_count = 0;
                for (auto it = word_it; it != all_words.cend(); ++it) {
                    chars_count += it->size() + 1;
                }
                if (chars_count > 0)
                    res.insert(res.cbegin(), this->substr(this->cbegin() + chars_count - 1, this->cend()));
            }

            return res;
        }

        /** \brief Returns a vector of the words in the string, using sep as the delimiter string. At most maxsplit splits are done, the leftmost ones. */
        std::vector<CppStringT> split(const CppStringT& sep, const size_type maxsplit) const noexcept
        {
            std::vector<CppStringT> res{};

            if (maxsplit == 0) {
                res.push_back(*this);
            }
            else {
                const CppStringT whitespace(value_type(' '));
                std::vector<CppStringT> all_words{ this->split(sep) };

                size_type count = maxsplit;
                auto word_it = all_words.cbegin();
                while (count > 0 && word_it != all_words.cend()) {
                    res.insert(res.cbegin(), *word_it);
                    --count;
                    word_it++;
                }

                size_type chars_count = 0;
                for (auto it = word_it; it != all_words.cend(); ++it) {
                    chars_count += it->size() + 1;
                }
                if (chars_count > 0)
                    res.insert(res.cbegin(), this->substr(this->cbegin() + chars_count - 1, this->cend()));
            }

            return res;
        }


        //---   splitlines()   ------------------------------------
        /** \brief Return a list of the lines in the string, breaking at line boundaries.
        *
        * Line breaks are not included in the resulting list unless keepends is given and true.
        *
        * This method splits on the following line boundaries. In particular, the boundaries are a superset of universal newlines:
        * \n 	        Line Feed
        * \r 	        Carriage Return
        * \r\n 	        Carriage Return + Line Feed
        * \v or \x0b 	Line Tabulation
        * \f or \x0c 	Form Feed
        * \x1c 	        File Separator
        * \x1d 	        Group Separator
        * \x1e 	        Record Separator
        * \x85 	        Next Line (C1 Control Code)
        * \u2028 	    Line Separator
        * \u2029 	    Paragraph Separator
        */
        std::vector<CppStringT> splitlines(const bool keep_end = false) const noexcept
        {
            std::vector<CppStringT> res{};
            CppStringT current{};
            bool prev_cr = false;

            for (const value_type& ch : *this) {
                switch (ch) {
                case value_type('\v'):      // Line Tabulation
                case value_type('\x0b'):    // Line Tabulation
                case value_type('\f'):      // Form Feed
                case value_type('\x0c'):    // Form Feed
                case value_type('\x1c'):    // File Separator
                case value_type('\x1d'):    // Group Separator
                case value_type('\x1e'):    // Record Separator
                case value_type('\x85'):    // Next Line (C1 Control Code)
#pragma warning(push)
#pragma warning(disable: 4566)  // to get no warning when current page code is not compatible with next unicode points
                case value_type('\u2028'):  // Line Separator
                case value_type('\u2029'):  // Paragraph Separator
#pragma warning(pop)
                    if (prev_cr) {
                        res.push_back(current);
                        current.clear();
                    }
                    if (keep_end)
                        current += ch;
                    res.push_back(current);
                    current.clear();
                    prev_cr = false;
                    break;

                case value_type('\r'):      // Line Feed
                    if (prev_cr) {
                        res.push_back(current);
                        current.clear();
                    }
                    if (keep_end)
                        current += ch;
                    prev_cr = true;
                    break;

                case value_type('\n'):      // Line Feed
                    if (keep_end)
                        current += ch;
                    res.push_back(current);
                    current.clear();
                    prev_cr = false;
                    break;


                default:
                    if (prev_cr) {
                        res.push_back(current);
                        current.clear();
                    }
                    current += ch;
                    break;
                }
            }

            return res;
        }


        //---   startswith()   ------------------------------------
        /** Returns true if the string starts with the specified suffix, otherwise returns false. Test begins at start position and stops at end position. */
        inline const bool startswith(const CppStringT& suffix, const size_type start, const size_type end) const noexcept
        {
            return startswith(std::span{ suffix }, start, end);
        }

        /** Returns true if the string starts with the specified suffix, otherwise returns false. Test begins at start position and stops at end of string. */
        inline const bool startswith(const CppStringT& suffix, const size_type start) const noexcept
        {
            return startswith(std::span{ suffix }, start, this->size() - 1);
        }

        /** Returns true if the string starts with the specified suffix, otherwise returns false. Test runs on the whole string. */
        inline const bool startswith(const CppStringT& suffix) const noexcept
        {
            return this->starts_with(suffix);
        }

        /** Returns true if the string starts with any of the specified suffixes, otherwise returns false. Test begins at start position and stops at end of string. */
        inline const bool startswith(const std::span<CppStringT>& suffixes, const size_type start, const size_type end) const noexcept
        {
            if (start > end)
                return false;
            else
                return std::any_of(suffixes.cbegin(), suffixes.cend(), this->substr(start, end).starts_with);
            /*
            for (auto& suffix : suffixes) {
                if (this->substr(start, end).starts_with(suffix))
                    return true;
            }

            return false;
            */
        }


        //---   startswith_n()   ----------------------------------
        /** Returns true if the string starts with the specified suffix, otherwise returns false. Test begins at start position and stops after count positions. */
        inline const bool startswith_n(const CppStringT& suffix, const size_type start, const size_type count) const noexcept
        {
            return startswith(std::span{ suffix }, start, start + count - 1);
        }

        /** Returns true if the string starts with the specified suffix, otherwise returns false. Test begins at position 0 and stops after count positions. */
        inline const bool startswith_n(const CppStringT& suffix, const size_type count) const noexcept
        {
            return startswith(std::span{ suffix }, 0, count - 1);
        }

        /** Returns true if the string starts with any of the specified suffixes, otherwise returns false. Test begins at start position and stops after count positions. */
        inline const bool startswith_n(const std::span<CppStringT>& suffixes, const size_type start, const size_type count) const noexcept
        {
            return startswith(suffixes, start, start + count - 1);
        }


        //---   strip()   -----------------------------------------
        /** \brief Returns a copy of the string with the leading and trailing characters removed.
        *
        * The passed string specifies the set of characters to be removed.
        * The chars argument is not a prefix;  rather, all combinations of
        * its values are stripped.
        */
        inline CppStringT strip(const CppStringT& prefix) const noexcept
        {
            return this->rstrip(prefix).lstrip(prefix);
        }

        /** \brief Returns a copy of the string with the leading and trailing whitespaces removed. */
        inline CppStringT strip() const noexcept
        {
            return this->rstrip().lstrip();
        }


        //---   substr()   ----------------------------------------
        /** \brief Returns acopy of the string, starting at index start and ending after count characters. */
        inline CppStringT substr(const size_type start, const size_type count) const noexcept
        {
            if (start > this->size())
                return *this;
            const size_type width = std::min(count, this->size() - start);
            return CppStringT(MyBaseClass::substr(start, width));
        }


        //---   swapcase()   --------------------------------------
        /** \brief Returns a copy of the string with uppercase characters converted to lowercase and vice versa.
        *
        * Note that it is not necessarily true that s.swapcase().swapcase() == s.
        */
        inline CppStringT swapcase() const noexcept
        {
            /*
            CppStringT res(*this);
            std::transform(this->cbegin(), this->cend(), res.begin(), pcs::swap_case);
            return res;
            */
            CppStringT res;
            std::ranges::copy(std::views::transform(*this, pcs::swap_case), std::back_inserter(res));
            return res;
        }


        //---   title()   -----------------------------------------
        /** \brief Returns a titlecased copy of the string where words start with an uppercase character and the remaining characters are lowercase. */
        CppStringT title() const noexcept
        {
            constexpr CppStringT whitespace(value_type(' '));

            CppStringT res(*this);
            std::vector<CppStringT> words = res.split(whitespace);

            for (CppStringT& word : words)
                word.capitalize();

            return whitespace.join(words);
        }


        //---   upper ()  -----------------------------------------
        /** \brief In-place replaces all characters of the string with their uppercase conversion. Returns a reference to string.
        *
        * Notice: uses the currently set std::locale, which is the "C" one
        * by default or any other one as previously set by the user.
        */
        inline CppStringT& upper() noexcept
        {
            std::transform(this->begin(), this->end(),
                           this->begin(),
                           [](value_type ch) { return this->upper(ch); });
            return *this;
        }

        /** \brief Returns uppercase conversion of the character.
        *
        * Notice: uses the currently set std::locale, which is the "C" one
        * by default or any other one as previously set by the user.
        */
        static inline const value_type upper(const value_type ch) noexcept
        {
            return value_type(std::toupper(ch));
        }


        //---   zfill()   -----------------------------------------
        /** \brief Returns a copy of the string left filled with ASCII '0' digits to make a string of length width.
        *
        * A leading sign prefix ('+'/'-') is handled by inserting the padding 
        * after the sign character rather than before. The original string is 
        * returned if width is less than or equal to len(s).
        */
        inline CppStringT zfill(const size_type width) const noexcept
        {
            if (this->size() >= width)
                return *this;

            const size_type padding_width = width - this->size();
            if ((*this)[0] == '+' || (*this)[0] == '-')
                return (*this)[0] + this->substr(1, this->size() - 1).ljust(padding_width, value_type('0'));
            else
                return this->ljust(padding_width, value_type('0'));
        }


        //===   Translation Table   ===============================
        /** \brief The internal class of translation tables, used with methods CppStringT::maketrans and CppStringT::translate. */
        class TransTable
        {
        public:
            //---   wrappers   ------------------------------------
            using key_type   = CharT;             
            using value_type = CppStringT;

            //---   Constructors / destructor   -------------------
            /** \brief Creates a TransTable from a standard map. */
            inline TransTable(const std::map<key_type, value_type> trans_table)
                : m_table{ trans_table }
            {}

            /** \brief Creates a TransTable from two strings.
            *
            * Parameters keys and values must have the same size. The i-th
            * character in key is associated in the translation table with
            * the i-th character in values.
            */
            TransTable(const CppStringT& keys, const CppStringT& values)
            {
                assert(keys.size() == values.size());
                auto val_it = values.cbegin();
                for (const auto k : keys)
                    m_table[k] = value_type(*val_it++);
            }

            /** \brief Creates a TransTable from three strings.
            *
            * Parameters keys and values must have the same size. The i-th
            * character in key is associated in the translation table with
            * the i -th  character  in  values.  Finally,  the  characters
            * contained  in  string  not_translated  are associated in the
            * translation table with the empty string.
            */
            TransTable(const CppStringT& keys, const CppStringT& values, const CppStringT& not_translated)
            {
                assert(keys.size() == values.size());
                auto val_it = values.cbegin();
                for (const auto k : keys)
                    m_table[k] = value_type(*val_it++);
                for (const auto k : not_translated)
                    m_table[k] = CppStringT();
            }

            /** \brief Creates a TransTable from two initalization lists.
            *
            * Parameters keys and values must have the same size. The i-th
            * character in key is associated in the translation table with
            * the i-th character in values.
            */
            inline TransTable(const std::initializer_list<CppStringT> keys,
                              const std::initializer_list<CppStringT> values)
            {
                assert(keys.size() == values.size());
                auto val_it = values.cbegin();
                for (const auto k : keys)
                    m_table[(*k)[0]] = *val_it++;
            }

            /** \brief Creates a TransTable from three initalization lists.
            *
            * Parameters keys and values must have the same size. The i-th
            * character in key is associated in the translation table with
            * the i -th  character  in  values.  Finally,  the  characters
            * contained  in  string  not_translated  are associated in the
            * translation table with the empty string.
            */
            inline TransTable(const std::initializer_list<CppStringT> keys,
                              const std::initializer_list<CppStringT> values,
                              const CppStringT&                       not_translated)
            {
                assert(keys.size() == values.size());
                auto val_it = values.cbegin();
                for (const auto k : keys)
                    m_table[(*k)[0]] = *val_it++;
                for (const auto k : not_translated)
                    m_table[k] = CppStringT();
            }

            /** \brief Creates a TransTable from two pointers to null-terminated lists of characters.
            *
            * Parameters keys and values must have the same size. The i-th
            * character in key is associated in the translation table with
            * the i-th character in values.
            */
            inline TransTable(const CharT* keys, const CharT* values)
            {
                while (*keys && *values)
                    m_table[*keys++] = value_type(*values++);
            }

            /** \brief Creates a TransTable from three pointers to null-terminated lists of characters.
            *
            * Parameters keys and values must have the same size. The i-th
            * character in key is associated in the translation table with
            * the i -th  character  in  values.  Finally,  the  characters
            * contained  in  string  not_translated  are associated in the
            * translation table with the empty string.
            */
            inline TransTable(const CharT* keys, const CharT* values, const CharT* not_translated)
            {
                while (*keys && *values)
                    m_table[*keys++] = value_type(*values++);
                while (*not_translated)
                    m_table[*not_translated++] = CppStringT();
            }

            /** \brief Creates a TransTable from two containers iterators.
            *
            * Both  containers  should  have  the  same  size.   The  i-th
            * character in key is associated in the translation table with
            * the i-th character in values.
            */
            template<class KeyIt, class ValueIt>
            inline TransTable(KeyIt first_key, KeyIt last_key, ValueIt first_value, ValueIt last_value)
            {
                KeyIt key_it{ first_key };
                ValueIt val_it{ first_value };
                while (key_it != last_key && val_it != last_value)
                    m_table[*key_it++] = value_type(*val_it++);
            }

            /** \brief Creates a TransTable from three containers iterators.
            *
            * Both  containers  should  have  the  same  size.   The  i-th
            * character in key is associated in the translation table with
            * the i -th  character  in  values.  Finally,  the  characters
            * contained  in  string  not_translated  are associated in the
            * translation table with the empty string.
            */
            template<class KeyIt, class ValueIt>
            inline TransTable(KeyIt first_key, KeyIt last_key,
                              ValueIt first_value, ValueIt last_value, 
                              KeyIt first_not_translated, KeyIt last_not_translated)
            {
                KeyIt key_it{ first_key };
                ValueIt val_it{ first_value };
                while (key_it != last_key && val_it != last_value)
                    m_table[*key_it++] = value_type(*val_it++);
                key_it = first_not_translated;
                while (key_it != last_not_translated)
                    m_table[*key_it++] = CppStringT();
            }

            /** \brief Creates a TransTable from two string views.
            *
            * Parameters keys and values must have the same size. The i-th
            * character in key is associated in the translation table with
            * the i-th character in values.
            */
            template<class StringViewLike>
            explicit TransTable(const StringViewLike& keys, const StringViewLike& values)
            {
                assert(keys.size() == values.size());
                auto val_it = values.cbegin();
                for (const auto k : keys)
                    m_table[(*k)[0]] = value_type(*val_it++);
            }

            /** \brief Creates a TransTable from three string views.
            *
            * Parameters keys and values must have the same size. The i-th
            * character in key is associated in the translation table with
            * the i -th  character  in  values.  Finally,  the  characters
            * contained  in  string  not_translated  are associated in the
            * translation table with the empty string.
            */
            template<class StringViewLike>
            TransTable(const StringViewLike& keys, const StringViewLike& values, const StringViewLike& not_translated)
            {
                assert(keys.size() == values.size());
                auto val_it = values.cbegin();
                for (const auto k : keys)
                    m_table[k] = value_type(*val_it++);
                for (const auto k : not_translated)
                    m_table[k] = CppStringT();
            }

            inline TransTable() noexcept = default;                     //!< Default empty constructor.
            inline TransTable(const TransTable&) noexcept = default;    //!< Default copy constructor.
            inline TransTable(TransTable&&) noexcept = default;         //!< Default move constructor.

            inline ~TransTable() noexcept = default;                    //!< Default descrtuctor

            //---   operators   -----------------------------------
            inline TransTable& operator= (const TransTable&) noexcept = default;    //!< Default copy assignment
            inline TransTable& operator= (TransTable&&) noexcept = default;         //!< Default move assignment

            /** \brief Assignment operator with a standard map. */
            inline TransTable& operator= (const std::map<key_type, value_type>& trans_table) noexcept
            {
                m_table = trans_table;
                return *this;
            }

            /** \biref Indexing operator. */
            inline CppStringT operator[] (const key_type ch) const noexcept
            {
                try {
                    return m_table[ch];
                }
                catch (...) {
                    return CppStringT();
                }
            }

        private:
            std::map<key_type, value_type> m_table{};  // the itnernal storage of the translation table. Access it via the indexing operator.
        };

    };


    //=====   litteral operators   ============================
    /** \brief  Forms a CppString literal. */
    inline const CppString operator""cs(const char* str, std::size_t len)
    {
        return CppString(CppString::MyBaseClass(str, len));
    }

    /** \brief  Forms a CppString view literal. */
    inline const CppString operator""csv(const char* str, std::size_t len)
    {
        return CppString(CppString::MyStringView(str, len));
    }

    /** \brief Forms a CppWString literal. */
    inline const CppWString operator""cs(const wchar_t* str, std::size_t len)
    {
        return CppWString(CppWString::MyBaseClass(str, len));
    }

    /** \brief Forms a CppWString view literal. */
    inline const CppWString operator""csv(const wchar_t* str, std::size_t len)
    {
        return CppWString(CppWString::MyStringView(str, len));
    }


    //=====   templated chars classes   ===========================
    //---   is_alpha()   ------------------------------------------
    /** \brief SHOULD NEVER BE USED. Use next specializations instead. */
    template<class CharT>
    inline const bool is_alpha(const CharT ch) noexcept
    { return false; }

    /** \brief Returns true if character ch is alphabetic, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_alpha<char>(const char ch) noexcept
    { return std::isalpha(static_cast<unsigned char>(ch)); }

    /** \brief Returns true if character ch is alphabetic, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_alpha<wchar_t>(const wchar_t ch) noexcept
    { return std::iswalpha(ch); }


    //---   is_ascii()   ------------------------------------------
    /** \brief Returns true if character has code point in the range U+0000-U+007F. */
    template<class CharT>
    inline const bool is_ascii(const CharT ch) noexcept
    { return CharT(0x00) <= ch && ch <= CharT(0x7f); }


    //---   is_decimal()   ----------------------------------------
    /** \brief SHOULD NEVER BE USED. Use next specializations instead. */
    template<class CharT>
    inline const bool is_decimal(const CharT ch) noexcept
    { return false; }

    /** \brief Returns true if character is a decimal digit, or false otherwise. */
    template<>
    inline const bool is_decimal<char>(const char ch) noexcept
    { return std::isdigit(static_cast<unsigned char>(ch)); }

    /** \brief Returns true if character is a decimal digit, or false otherwise. */
    template<>
    inline const bool is_decimal<wchar_t>(const wchar_t ch) noexcept
    { return std::iswdigit(ch); }


    //---   is_id_continue()   ------------------------------------
    /** \brief Returns true if character is a continuing char for identifiers, or false otherwise. */
    template<class CharT>
    inline const bool is_id_continue(const CharT ch) noexcept
    { return pcs::is_id_start(ch) || pcs::is_decimal(ch); }


    //---   is_id_start()   ---------------------------------------
    /** \brief Returns true if character is a starting char for identifiers, or false otherwise. */
    template<class CharT>
    inline const bool is_id_start(const CharT ch) noexcept
    { return pcs::is_alpha(ch) || ch == CharT('_'); }


    //---   is_lower()   ------------------------------------------
    /** \brief SHOULD NEVER BE USED. Use next specializations instead. */
    template<class CharT>
    inline const bool is_lower(const CharT ch) noexcept
    {
        return false;
    }

    /** \brief Returns true if character ch is lowercase, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_lower<char>(const char ch) noexcept
    {
        return std::islower(static_cast<unsigned char>(ch));
    }

    /** \brief Returns true if character ch is lowercase, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_lower<wchar_t>(const wchar_t ch) noexcept
    {
        return std::iswlower(ch);
    }


    //---   is_printable()   --------------------------------------
    /** \brief SHOULD NEVER BE USED. Use next specializations instead. */
    template<class CharT>
    inline const bool is_printable(const CharT ch) noexcept
    { return false; }
    
    /** \brief Returns true if character ch is printable, or false otherwise. */
    template<>
    inline const bool is_printable<char>(const char ch) noexcept
    {
        return std::isprint(static_cast<unsigned char>(ch));
    }

    /** \brief Returns true if character ch is punctuation, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_printable<wchar_t>(const wchar_t ch) noexcept
    {
        return std::iswprint(ch);
    }


    //---   is_punctuation()   ------------------------------------
    /** \brief SHOULD NEVER BE USED. Use next specializations instead. */
    template<class CharT>
    inline const bool is_punctuation(const CharT ch) noexcept
    { return false; }

    /** \brief Returns true if character ch is punctuation, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_punctuation<char>(const char ch) noexcept
    { return std::ispunct(static_cast<unsigned char>(ch)); }

    /** \brief Returns true if character ch is punctuation, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_punctuation<wchar_t>(const wchar_t ch) noexcept
    { return std::iswpunct(ch); }


    //---   is_space()   ------------------------------------------
    /** \brief SHOULD NEVER BE USED. Use next specializations instead. */
    template<class CharT>
    inline const bool is_space(const CharT ch) noexcept
    { return false; }

    /** \brief Returns true if character ch is alphabetic, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_space<char>(const char ch) noexcept
    { return std::isspace(static_cast<unsigned char>(ch)); }

    /** \brief Returns true if character ch is alphabetic, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_space<wchar_t>(const wchar_t ch) noexcept
    { return std::iswspace(ch); }


    //---   is_upper()   ------------------------------------------
    /** \brief SHOULD NEVER BE USED. Use next specializations instead. */
    template<class CharT>
    inline const bool is_upper(const CharT ch) noexcept
    {
        return false;
    }

    /** \brief Returns true if character ch is uppercase, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_upper<char>(const char ch) noexcept
    {
        return std::isupper(static_cast<unsigned char>(ch));
    }

    /** \brief Returns true if character ch is uppercase, or false otherwise. Conforms to the current locale settings. */
    template<>
    inline const bool is_upper<wchar_t>(const wchar_t ch) noexcept
    {
        return std::iswupper(ch);
    }


    //---   swap_case()   -----------------------------------------
    /** \brief Returns the swapped case form of character ch if it exists, or ch itself otherwise. */
    template<class CharT>
    inline const CharT swap_case(const CharT ch) noexcept
    {
        if (pcs::is_lower(ch))
            return pcs::to_upper(ch);
        else if (pcs::is_upper(ch))
            return pcs::to_lower(ch);
        else
            return ch;
    }


    //---   to_lower()   ------------------------------------------
    /** \brief SHOULD NEVER BE USED. Use next specializations instead. */
    template<class CharT>
    inline const CharT to_lower(const CharT ch) noexcept
    {
        return ch;
    }

    /** \brief Returns the lowercase form of character ch if it exists, or ch itself otherwise. Conforms to the current locale settings. */
    template<>
    inline const char to_lower<char>(const char ch) noexcept
    {
        return std::tolower(static_cast<unsigned char>(ch));
    }

    /** \brief Returns the lowercase form of character ch if it exists, or ch itself otherwise. Conforms to the current locale settings. */
    template<>
    inline const wchar_t to_lower<wchar_t>(const wchar_t ch) noexcept
    {
        return std::towlower(ch);
    }


    //---   to_upper()   ------------------------------------------
    /** \brief SHOULD NEVER BE USED. Use next specializations instead. */
    template<class CharT>
    inline const CharT to_upper(const CharT ch) noexcept
    {
        return ch;
    }

    /** \brief Returns the uppercase form of character ch if it exists, or ch itself otherwise. Conforms to the current locale settings. */
    template<>
    inline const char to_upper<char>(const char ch) noexcept
    {
        return std::toupper(static_cast<unsigned char>(ch));
    }

    /** \brief Returns the uppercase form of character ch if it exists, or ch itself otherwise. Conforms to the current locale settings. */
    template<>
    inline const wchar_t to_upper<wchar_t>(const wchar_t ch) noexcept
    {
        return std::towupper(ch);
    }


} // end of namespace pcs  // (pythonic c++ strings)