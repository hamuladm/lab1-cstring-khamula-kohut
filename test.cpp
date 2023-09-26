/**
 *
 * @date 23.09.23
 * @authors Kohut Zahar, Dmytro Khamula
 *
**/

#include "mystr.h"

int main() {
    /**
     *
     * Part for @author Khamula's methods and operators
     *
     */

    // Init strings
    std::cout << "Testing methods..." << std::endl;
    my_str_t initstr{"I love Python!"};
    my_str_t initstr2 = my_str_t(5, 'P');
    const char* tcstr = "Python, C++, Java";
    char ch = 'P';

    // Copying testing
    std::cout << "Test copying from my_str_t function" << std::endl;
    my_str_t cpystr1{initstr};
    std::cout << cpystr1.c_str() << std::endl;
    my_str_t cpystr2 = initstr;
    std::cout << cpystr2.c_str() << std::endl;
    std::cout << "Done!" << std::endl;
    std::cout << std::endl;

    // Reserve testing
    std::cout << "Test reserve() function" << std::endl;
    initstr.reserve(1);
    std::cout << initstr.capacity() << " should be the same as before: 16" << std::endl;
    initstr2.reserve(1);
    std::cout << initstr2.capacity() << " should be the same as before: 16" << std::endl;
    initstr.reserve(30);
    std::cout << initstr.capacity() << " should be equal 30" << std::endl;
    initstr2.reserve(30);
    std::cout << initstr2.capacity() << " should be equal 30" << std::endl;
    std::cout << "Done!" << std::endl;
    std::cout << std::endl;

    // Shrink_to_fit testing
    std::cout << "Test shrink_to_fit() function" << std::endl;
    initstr.shrink_to_fit();
    std::cout << initstr.capacity() << " should be equal 14" << std::endl;
    initstr2.shrink_to_fit();
    std::cout << initstr2.capacity() << " should be equal 5" << std::endl;
    std::cout << "Done!" << std::endl;
    std::cout << std::endl;

    // Resizing testing
    std::cout << "Test shrink_to_fit() function" << std::endl;
    my_str_t newinit{"I hate C++"};
    my_str_t newinit2 = my_str_t(15, 'H');
    std::cout << "Old strings:" << std::endl;
    std::cout << newinit.c_str() << std::endl;
    std::cout << newinit2.c_str() << std::endl;
    newinit.resize(24, 'l');
    newinit2.resize(24, 'o');
    std::cout << "New strings:" << std::endl;
    std::cout << newinit.c_str() << std::endl;
    std::cout << newinit2.c_str() << std::endl;
    std::cout << "Done!" << std::endl;
    std::cout << std::endl;

    // Inserting of my_str_t testing
    std::cout << "Test insert() function" << std::endl;

    my_str_t obj1{"Maybe, I will love C++..."};
    my_str_t inobj1{" tomorrow"};
    my_str_t obj2 = my_str_t(15, 'G');
    my_str_t inobj2 = my_str_t(5, 'E');

    std::cout << "Testing inserting of my_str_t..." << std::endl;
    std::cout << "Old strings:" << std::endl;
    std::cout << obj1.c_str() << std::endl;
    std::cout << obj2.c_str() << std::endl;
    obj1.insert(6, inobj1);
    obj2.insert(5, inobj2);
    std::cout << "Done (1/3)" << std::endl;
    std::cout << std::endl;

    std::cout << "New strings:" << std::endl;
    std::cout << obj1.c_str() << std::endl;
    std::cout << obj2.c_str() << std::endl;
    std::cout << std::endl;

    // Inserting of char testing
    std::cout << "Testing inserting of char..." << std::endl;
    obj1.insert(5, ch);
    obj2.insert(5, ch);
    std::cout << obj1.c_str() << std::endl;
    std::cout << obj2.c_str() << std::endl;
    std::cout << "Done (2/3)" << std::endl;
    std::cout << std::endl;

    // Inserting of cstring testing
    std::cout << "Testing inserting of cstring..." << std::endl;
    obj1.insert(5, tcstr);
    obj2.insert(5, tcstr);
    std::cout << obj1.c_str() << std::endl;
    std::cout << obj2.c_str() << std::endl;

    std::cout << "Done (3/3)" << std::endl;
    std::cout << std::endl;

    // Appending testing
    std::cout << "Testing append()" << std::endl;
    my_str_t obj5{"I need to append "};
    my_str_t obj7{"my_str_t"};
    my_str_t obj8{"I need to append "};
    my_str_t obj9{"I need to append "};
    const char* obj6 = "cstring";
    char chr = 'C';
    obj5.append(obj7);
    obj8.append(obj6);
    obj9.append(chr);
    std::cout << obj5.c_str() << std::endl;
    std::cout << obj8.c_str() << std::endl;
    std::cout << obj9.c_str() << std::endl;

    std::cout << "Done!" << std::endl;
    std::cout << std::endl;

    // Tests
    // Done: Kohut;
    std::cout << "Test 1: Constructor (and << ostream-operator);" << '\n';
    my_str_t str1 (100000, 'y');
    std::cout << str1 << "\n\n";

    std::cout << "Test 2: C-String Constructor;" << '\n';
    const char* testcstr1 = "Hello world! I was a c-string.";
    my_str_t str2 (testcstr1);
    std::cout << str2 << "\n\n";

    std::cout << "Test 3: C++ String Constructor;" << '\n';
    std::string testcppstring1 = "Hello world! I was a C++ string.";
    my_str_t str3 (testcppstring1);
    std::cout << str3 << "\n\n";

    std::cout << "Test 4.1: Copy assignment;" << '\n';
    std::string testcppstring2 = "I am initial string.";
    std::string testcppstring3 = "I am new string after copying.";
    my_str_t str4 {testcppstring2};
    my_str_t str5 {testcppstring3};

    std::cout << "String we copy to:" << str4 << '\n' << "String we copy from:" << str5 << '\n';
    str4 = str5;
    std::cout << "Initial string after copying:" << str4 << "\n\n";

    std::cout << "Test 4.2: Copy assignment. Self-assignment handling;" << '\n';

    std::string testcppstring4 = "I am string to test self-assignment.";
    my_str_t str6 {testcppstring4};
    std::cout << "String before copying:" << '\n' << str6 << '\n';
    str6 = str6;
    std::cout << "String after copying:" << '\n' << str6 << "\n\n";

    std::cout << "Test 5.1: bool operators (my_str_t);" << '\n';
    my_str_t str7 {7, 'a'};
    my_str_t str8 {6, 'b'};

    std::cout << str7 << '<' << str8 << "   -   " << (str7<str8) << '\n';
    std::cout << str7 << '>' << str8 << "   -   " << (str7>str8) << '\n';
    std::cout << str7 << "==" << str8 << "   -   " << (str7==str8) << '\n';
    std::cout << str7 << "!=" << str8 << "   -   " << (str7!=str8) << '\n';
    std::cout << str7 << ">=" << str8 << "   -   " << (str7>=str8) << '\n';
    std::cout << str7 << "<=" << str8 << "   -   " << (str7<=str8) << "\n\n";


    my_str_t str9 {2, 'a'};
    my_str_t str10 {2, 'a'};


    std::cout << str9 << '<' << str10 << "   -   " << (str9<str10) << '\n';
    std::cout << str9 << '>' << str10 << "   -   " << (str9>str10) << '\n';
    std::cout << str9 << "==" << str10 << "   -   " << (str9==str10) << '\n';
    std::cout << str9 << "!=" << str10 << "   -   " << (str9!=str10) << '\n';
    std::cout << str9 << ">=" << str10 << "   -   " << (str9>=str10) << '\n';
    std::cout << str9 << "<=" << str10 << "   -   " << (str9<=str10) << "\n\n";

    std::cout << "Test 5.2: bool operators (c-string);" << '\n';
    const char* testcstr2 = "app";
    const char* testcstr3 = "apple";
    my_str_t str11 {testcstr3};

    std::cout << str11 << '<' << testcstr2 << "   -   " << (str11<testcstr2) << '\n';
    std::cout << str11 << '>' << testcstr2 << "   -   " << (str11>testcstr2) << '\n';
    std::cout << str11 << "==" << testcstr2 << "   -   " << (str11==testcstr2) << '\n';
    std::cout << str11 << "!=" << testcstr2 << "   -   " << (str11!=testcstr2) << '\n';
    std::cout << str11 << ">=" << testcstr2 << "   -   " << (str11>=testcstr2) << '\n';
    std::cout << str11 << "<=" << testcstr2 << "   -   " << (str11<=testcstr2) << "\n\n";

    const char* testcstr4 = "hello";
    const char* testcstr5 = "hello";
    my_str_t str12 {testcstr5};

    std::cout << str12 << '<' << testcstr4 << "   -   " << (str12<testcstr4) << '\n';
    std::cout << str12 << '>' << testcstr4 << "   -   " << (str12>testcstr4) << '\n';
    std::cout << str12 << "==" << testcstr4 << "   -   " << (str12==testcstr4) << '\n';
    std::cout << str12 << "!=" << testcstr4 << "   -   " << (str12!=testcstr4) << '\n';
    std::cout << str12 << ">=" << testcstr4 << "   -   " << (str12>=testcstr4) << '\n';
    std::cout << str12 << "<=" << testcstr4 << "   -   " << (str11<=testcstr4) << "\n\n";

    std::cout << "Test 5.3: bool operators (C++ string);" << '\n';
    std::string testcppstring5 = "abc";
    std::string testcppstring6 = "abcdefg";
    my_str_t str13 {testcppstring6};

    std::cout << str13 << '<' << testcppstring5 << "   -   " << (str13<testcppstring5) << '\n';
    std::cout << str13 << '>' << testcppstring5 << "   -   " << (str13>testcppstring5) << '\n';
    std::cout << str13 << "==" << testcppstring5 << "   -   " << (str13==testcppstring5) << '\n';
    std::cout << str13 << "!=" << testcppstring5 << "   -   " << (str13!=testcppstring5) << '\n';
    std::cout << str13 << ">=" << testcppstring5 << "   -   " << (str13>=testcppstring5) << '\n';
    std::cout << str13 << "<=" << testcppstring5 << "   -   " << (str13<=testcppstring5) << "\n\n";

    std::string testcppstring7 = "hello";
    std::string testcppstring8 = "hello";
    my_str_t str14 {testcppstring8};

    std::cout << str14 << '<' << testcppstring7 << "   -   " << (str14<testcppstring7) << '\n';
    std::cout << str14 << '>' << testcppstring7 << "   -   " << (str14>testcppstring7) << '\n';
    std::cout << str14 << "==" << testcppstring7 << "   -   " << (str14==testcppstring7) << '\n';
    std::cout << str14 << "!=" << testcppstring7 << "   -   " << (str14!=testcppstring7) << '\n';
    std::cout << str14 << ">=" << testcppstring7 << "   -   " << (str14>=testcppstring7) << '\n';
    std::cout << str14 << "<=" << testcppstring7 << "   -   " << (str14<=testcppstring7) << "\n\n";

    std::cout << "Test 6: size() function;" << '\n';
    my_str_t str15 {4, 'g'};
    std::string testcppstring9 = "abcdefghi";
    my_str_t str16 {testcppstring9};

    std::cout << "String: " << str15 << "\nSize: " << str15.size() << "\n\n";
    std::cout << "String: " << str16 << "\nSize: " << str16.size() << "\n\n";

    std::cout << "Test 7: capacity() function;" << '\n';
    my_str_t str17 {16, 'c'};
    std::string testcppstring10 = "abcdefghi";
    my_str_t str18 {testcppstring9};

    std::cout << "String: " << str17 << "\nSize: " << str17.size() << "\nCapacity: " << str17.capacity() << "\n\n";
    std::cout << "String: " << str18 << "\nSize: " << str18.size() << "\nCapacity: " << str18.capacity() << "\n\n";

    std::cout << "Test 8.1: non-const []-operator;" << '\n';
    my_str_t str19 {5, 'a'};
    int ind1 = 3;
    int ind2 = 10;

    std::cout << "Character on index " << ind1 << " in string " << str19 << " is " << str19[ind1] << '\n';
    std::cout << "Character on index " << ind2 << " is " << str19[ind2] << " <- index is out of bounds, but []-operator does not throw out_of_range." << '\n' ;

    str19[ind1] = 'b';
    std::cout << "After change in string on index " << ind1 << ", character on index " << ind1 << " in string " << str19 << " is " << str19[ind1] << "\n\n";

    std::cout << "Test 8.2: const []-operator;" << '\n';
    const my_str_t str20 {5, 'a'};
    int ind3 = 3;
    int ind4 = 10;

    std::cout << "Character on index " << ind3 << " in string " << str20 << " is " << str20[ind3] << '\n';
    std::cout << "Character on index " << ind4 << " is " << str20[ind4] << " <- index is out of bounds, but []-operator does not throw out_of_range." << '\n';

    std::cout << "Something like <str20[3] = 'b';> would not compile, because str20 is a const object." << "\n\n";

    std::cout << "Test 8.1: non-const at();" << '\n';
    my_str_t str21 {5, 'a'};
    int ind5 = 3;
    int ind6 = 10;

    std::cout << "Character on index " << ind5 << " in string " << str21 << " is " << str21.at(ind5) << '\n';
    try {
        std::cout << str21.at(ind6);
    } catch (std::out_of_range& e) {
        std::cout << "str21.at(10) throws <" << e.what() << ">, because at() throw out_of_range." << '\n';
    }

    str11[ind5] = 'b';
    std::cout << "After change in string on index " << ind5 << ", character on index " << ind5 << " in string " << str21 << " is " << str21[ind5] << "\n\n";

    std::cout << "Test 8.2: const []-operator;" << '\n';
    const my_str_t str22 {5, 'a'};
    int ind7 = 3;
    int ind8 = 10;

    std::cout << "Character on index " << ind7 << " in string " << str22 << " is " << str22[ind7] << '\n';
    try {
        std::cout << str21.at(ind8);
    } catch (std::out_of_range& e) {
        std::cout << "str22.at(10) throws <" << e.what() << ">, because at() throw out_of_range." << '\n';
    }
    std::cout << "Something like <str22.at(3) = 'b';> would not compile, because str22 is a const object." << "\n\n";
}