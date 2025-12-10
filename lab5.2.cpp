#include <iostream>
#include <string_view>
#include <cassert>

std::string_view secondWord(std::string_view s)
{
    size_t firstSpace = s.find(' ');
    if (firstSpace == std::string_view::npos)
        return "";
    size_t start = s.find_first_not_of(' ', firstSpace + 1);
    if (start == std::string_view::npos)
        return "";
    size_t end = s.find(' ', start);
    if (end == std::string_view::npos)
        return s.substr(start);
    return s.substr(start, end - start);
}

void runTests()
{
    assert(secondWord("Hello world") == "world");
    assert(secondWord("Hello my dear") == "my");
    assert(secondWord("Hello") == "");
    assert(secondWord("") == "");
    assert(secondWord(" ") == "");
    assert(secondWord("a ") == "");
    assert(secondWord(" a") == "");
    assert(secondWord("a  b") == "");
    assert(secondWord("hello   world   dear") == "world");
}

int main()
{
    runTests();
    std::cout << "All tests passed!\n";
    return 0;
}
