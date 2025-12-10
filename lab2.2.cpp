#include <iostream>

struct Prices
{
    int drink;
    int first;
    int second;
};

struct Choices
{
    int drink;
    int first;
    int second;
};

int customerTotal(Prices prices, Choices choices)
{
    return prices.drink * choices.drink +
           prices.first * choices.first +
           prices.second * choices.second;
}

int main()
{
    Prices prices{10, 20, 30};

    Choices customer1{1, 2, 0};
    Choices customer2{0, 1, 3};

    int total1 = customerTotal(prices, customer1);
    int total2 = customerTotal(prices, customer2);

    std::cout << total1 << std::endl;
    std::cout << total2 << std::endl;

    return 0;
}
