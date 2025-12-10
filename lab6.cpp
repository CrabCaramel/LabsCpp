#include <iostream>

int hello(int);


int hello(int x) {
    return x + 5;
}

int main() {
    int x = 5;
    std::cout << hello(x) << std::endl; 
    return 0;
}
