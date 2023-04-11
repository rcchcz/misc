#include <iostream>

void bin(int n) {
    if(n == 0) std::cout << 0;
        else if(n == 1) std::cout << 1;
        else {   
            bin(n/2);
            std::cout << n%2;
        }
}

int main(void) {
    int n;
    std::cin >> n;
    bin(n);
    std::cout << std::endl;
    return 0;
}