// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com



/**
 *
 * @date 23.09.23
 * @authors Kohut Zahar, Dmytro Khamula
 *
**/

#include "mystring.hpp"

int main() {
    /**
     *
     * Part for @author Khamula methods and operators
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
    std::cout << "-----------------------" << std::endl;
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
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;

    // Shrink_to_fit testing
    std::cout << "Test shrink_to_fit() function" << std::endl;

    initstr.shrink_to_fit();
    std::cout << initstr.capacity() << " should be equal 14" << std::endl;
    initstr2.shrink_to_fit();
    std::cout << initstr2.capacity() << " should be equal 5" << std::endl;

    std::cout << "Done!" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;

    // Resizing testing
    std::cout << "Test shrink_to_fit() function" << std::endl;

    my_str_t resinit{"I hate C++"};
    my_str_t resinit2 = my_str_t(15, 'H');

    std::cout << "Old strings:" << std::endl;
    std::cout << resinit.c_str() << std::endl;
    std::cout << resinit2.c_str() << std::endl;

    resinit.resize(24, 'l');
    resinit2.resize(24, 'o');

    std::cout << "New strings:" << std::endl;
    std::cout << resinit.c_str() << std::endl;
    std::cout << resinit2.c_str() << std::endl;

    std::cout << "Done!" << std::endl;
    std::cout << "-----------------------" << std::endl;
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
    std::cout << "-----------------------" << std::endl;
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
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;

    // Testing erase
    std::cout << "Testing erase() func" << std::endl;

    my_str_t obj10{"I stop smoking cigars"};
    my_str_t obj11 = my_str_t(24, 'Q');

    std::cout << "Old strings:" << std::endl;
    std::cout << obj10.c_str() << std::endl;
    std::cout << obj11.c_str() << std::endl;
    std::cout << std::endl;


    std::cout << "Erased strings:" << std::endl;
    obj10.erase(6, 8);
    obj11.erase(7, 69);
    std::cout << obj10.c_str() << std::endl;
    std::cout << obj11.c_str() << std::endl;
    std::cout << "Done!" << std::endl;

    //Testing clear() function
    std::cout << "Testing clear() func" << std::endl;
    std::cout << std::endl;

    std::cout << "Size before:" << std::endl;
    std::cout << obj10.size() << std::endl;
    std::cout << obj11.size() << std::endl;

    obj10.clear();
    obj11.clear();

    std::cout << "Size after:" << std::endl;
    std::cout << obj10.size() << std::endl;
    std::cout << obj11.size() << std::endl;
    std::cout << "Done!" << std::endl;

    std::cout << std::endl;
    std::cout << "All test passed!" << std::endl;

    /**
     *
     * Part for @author Kohut methods and operators
     *
     */
    std::cout << "Test 1: Constructor (and << ostream-operator);" << '\n';
    my_str_t str1 (42, 'y');
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
    std::cout << "Initial string after copying:" << str4 << '\n' << "String we copied from after copying:" << str5 << "\n\n";

    std::cout << "Test 4.2: Copy assignment. Self-assignment handling;" << '\n';

    std::string testcppstring4 = "I am string to test self-assignment.";
    my_str_t str6 {testcppstring4};
    std::cout << "<str6=str6> works fine, but PVS does not like it." << "\n\n";

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

    std::cout << "Test 6: size() method;" << '\n';
    my_str_t str15 {4, 'g'};
    std::string testcppstring9 = "abcdefghi";
    my_str_t str16 {testcppstring9};

    std::cout << "String: " << str15 << "\nSize: " << str15.size() << "\n\n";
    std::cout << "String: " << str16 << "\nSize: " << str16.size() << "\n\n";

    std::cout << "Test 7: capacity() method;" << '\n';
    my_str_t str17 {16, 'c'};
    std::string testcppstring10 = "123456789";
    my_str_t str18 {testcppstring10};

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

    std::cout << "Test 9.1: non-const at();" << '\n';
    my_str_t str21 {5, 'a'};
    int ind5 = 3;
    int ind6 = 10;

    std::cout << "Character on index " << ind5 << " in string " << str21 << " is " << str21.at(ind5) << '\n';
    try {
        std::cout << str21.at(ind6);
    } catch (std::out_of_range& e) {
        std::cout << "str21.at(10) throws <" << e.what() << ">, because at() throw out_of_range." << '\n';
    }

    str21.at(ind5) = 'b';
    std::cout << "After change in string on index " << ind5 << ", character on index " << ind5 << " in string " << str21 << " is " << str21.at(ind5) << "\n\n";

    std::cout << "Test 9.2: const at();" << '\n';
    const my_str_t str22 {5, 'a'};
    int ind7 = 3;
    int ind8 = 10;

    std::cout << "Character on index " << ind7 << " in string " << str22 << " is " << str22[ind7] << '\n';
    try {
        std::cout << str22.at(ind8);
    } catch (std::out_of_range& e) {
        std::cout << "str22.at(10) throws <" << e.what() << ">, because at() throw out_of_range." << '\n';
    }
    std::cout << "Something like <str22.at(3) = 'b';> would not compile, because str22 is a const object." << "\n\n";

    std::cout << "Test 10: c_str() method;" << '\n';
    std::string testcppstring11 = "C_str() test string.";
    my_str_t str23 {testcppstring11};

    std::cout << "Output of str23.c_str(): " << testcppstring11.c_str() << "\n\n";

    std::cout << "Test 11: swap() method;" << '\n';
    my_str_t str24 {5, 't'};
    my_str_t str25 {10, 'r'};

    std::cout << "Before swap: " << '\n';
    std::cout << "str24 address: " << (void*) str24.c_str() << "\nstr24 data: " << str24 << '\n';
    std::cout << "str25 address: " << (void*) str25.c_str() << "\nstr25 data: " << str25 << "\n\n";

    str24.swap(str25);
    std::cout << "After swap: " << '\n';
    std::cout << "str24 address: " << (void*) str24.c_str() << "\nstr24 data: " << str24 << '\n';
    std::cout << "str25 address: " << (void*) str25.c_str() << "\nstr25 data: " << str25 << "\n\n";

    std::cout << "Test 12: substring() method;" << '\n';
    std::string testcppstring12 = "substr() test string.";
    my_str_t str26 {testcppstring12};
    int ind9 = 3;
    int size1 = 8;
    std::cout << "Substring with size " << size1 << ", beginning from index " << ind9 << " of string <" << testcppstring12 << "> is:" << '\n' << str26.substr(ind9, size1) << "\n\n";

    int size2 = 1000;
    std::cout << "Substring with size " << size2 << ", beginning from index " << ind9 << " of string <" << testcppstring12 << "> is:" << '\n' << str26.substr(ind9, size2) << "\n\n";

    int ind10 = 1000;
    try {
        std::cout << str26.substr(ind10, 5);
    } catch (std::out_of_range& e) {
        std::cout << "str26.substr(1000, 5) throws <" << e.what() << ">, because <begin> must be less than size of string." << "\n\n";
    }

    std::cout << "Test 13.1: find() method for char;" << '\n';
    std::string testcppstring13 = "abcdefghi";
    my_str_t str27 {testcppstring13};
    char ch1 = 'd';
    char ch2 = '+';

    int ind11 = 2;
    std::cout << "Finding " << ch1 << " from index " << ind11 << " in string " << str27 << "   -   " << str27.find(ch1, ind11) << '\n';

    int ind12 = 5;
    std::cout << "Finding " << ch1 << " from index " << ind12 << " in string " << str27 << "   -   " << str27.find(ch1, ind12) << '\n';

    int ind13 = 0;
    std::cout << "Finding " << ch2 << " from index " << ind3 << " in string " << str27 << "   -   " << str27.find(ch2, ind13) << "\n\n";

    std::cout << "Test 13.2: find() method for C-string;" << '\n';
    const char* testcstr6 = "efgh";
    const char* testcstr7 = "ershs";
    const char* testcstr8 = "weaiufheipugheiughieugh";

    int ind14 = 1;
    std::cout << "Finding " << testcstr6 << " from index " << ind14 << " in string " << str27 << "   -   " << str27.find(testcstr6, ind14) << '\n';

    int ind15 = 5;
    std::cout << "Finding " << testcstr6 << " from index " << ind15 << " in string " << str27 << "   -   " << str27.find(testcstr6, ind15) << '\n';

    int ind16 = 0;
    std::cout << "Finding " << testcstr7 << " from index " << ind16 << " in string " << str27 << "   -   " << str27.find(testcstr7, ind16) << '\n';

    int ind17 = 3;
    std::cout << "Finding " << testcstr8 << " from index " << ind17 << " in string " << str27 << "   -   " << str27.find(testcstr8, ind17) << "\n\n";

    std::cout << "Test 13.3: find() method for C++ string;" << '\n';
    const char* testcstr9 = "def";
    const char* testcstr10 = "dfgs";
    const char* testcstr11 = "hello_hello_hello";

    int ind18 = 3;
    std::cout << "Finding " << testcstr9 << " from index " << ind18 << " in string " << str27 << "   -   " << str27.find(testcstr9, ind18) << '\n';

    int ind19 = 2;
    std::cout << "Finding " << testcstr9 << " from index " << ind19 << " in string " << str27 << "   -   " << str27.find(testcstr9, ind19) << '\n';

    int ind20 = 0;
    std::cout << "Finding " << testcstr10 << " from index " << ind20 << " in string " << str27 << "   -   " << str27.find(testcstr10, ind20) << '\n';

    int ind21 = 6;
    std::cout << "Finding " << testcstr11 << " from index " << ind21 << " in string " << str27 << "   -   " << str27.find(testcstr11, ind21) << "\n\n";

    int ind22 = 1000;
    try {
        std::cout << str27.find('g', ind22);
    } catch (std::out_of_range& e) {
        std::cout << "str27.find('g', 1000) throws <" << e.what() << ">, because <idx> must be less than size of string." << '\n';
    }
}
