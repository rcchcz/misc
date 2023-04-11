#include <iostream>
#include <vector>

/*! 
 * Takes a positive integer value n and stores the terms of the
 * Fibonacci series less than n in a vector of type std::vector.
 *
 * @param n unsigned int that upper bounds the generated terms.
 * @return std::vector with Fibonaci terms less than n.
 */
std::vector<unsigned int> fib_below_n(unsigned int n) {
    std::vector<unsigned int> fib;

    unsigned int number; 
    int index = 0;          // Fibonacci sequence index
    bool fibBelowN = true;  // control if the current number is less than n

    while(fibBelowN) {
        if(index == 0 || index == 1) {
            if(n > 1) fib.push_back(1); 
            else return fib; // if n == 1, there is no term less than n in the sequence
        } else {  
            number = fib[index-1] + fib[index-2];
            if(number < n) fib.push_back(number);
            else fibBelowN = false;
        }
        index++;
    }

    return fib;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<unsigned int> fib = fib_below_n(n);

    for(auto f : fib) { std::cout << f << " "; }
    std::cout << std::endl;

    return 0;
}
