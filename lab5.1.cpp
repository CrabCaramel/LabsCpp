#include <iostream>
#include <string_view>
#include <cassert>

int countOnes(std::string_view s)
{
    int count = 0;
    for (char c : s)
    {
        if (c == '1')
            count++;
    }
    return count;
}

void runTests()
{
   
    assert(countOnes("00000") == 0);

    
    assert(countOnes("01000") == 1);

   
    assert(countOnes("0011001") == 3);

   
    assert(countOnes("11111") == 5);

    
    assert(countOnes("") == 0);
}

int main()
{
    runTe
