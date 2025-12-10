#include <iostream>
#include <cstdint>


int A()
{
    std::cout << "called A" << std::endl;
    return 10;
}

int B()
{
    std::cout << "called B" << std::endl;
    return 20;
}

int C()
{
    std::cout << "called C" << std::endl;
    return 30;
}

int main()
{
    
    int a = A();   
    std::cout << a << std::endl;

    
    int b = B();
    std::cout << b << std::endl;

    
    int c = C();
    std::cout << c << std::endl;

    return 0;
}
