/**
 * This program receives one integer number and prints the sum of its digits.
 */ 

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int sum = 0;

    while(n >= 1)
    {
        sum += (n % 10);
        n = (n/10) - ((n%10)/10);
    } 

    std::cout << sum;
    std::cout << std::endl;

    return 0;
}
