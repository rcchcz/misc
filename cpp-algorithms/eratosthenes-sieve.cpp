/**
 * The Sieve of Eratosthenes is an algorithm for finding all prime numbers up to any given limit. 
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */ 

#include <iostream>
#include <vector>

/**
 * Sieve of Eratosthenes.
 * @param n Limit.
 * @param v Vector to store all prime numbers up to n.
 */
void sieve(long long int n, std::vector<bool> &v) {
    for(long long int i = 2; i <= n; i++) {
        // eliminate all multiples of i within the range [i*i, n]
        for(long long int j = i * i; j <= n; j += i) {v[j - 1] = false; } 
    }
} 

/**
 * Simple print function.
 * @param n Limit.
 * @param v Vector to print.
 */
void print_p(long long int n, std::vector<bool> v) {
    std::cout << "[ ";
    for(int i = 2; i <= n; i++) { if(v[i - 1] == true) std::cout << i << " "; }
    std::cout << "]";
}

/**
 * Driver code.
 */ 
int main() {
    long long int n;
    std::cout << "Enter non-negative integer that will be the limit: ";
    std::cin >> n;
    std::cout << "Prime numbers smaller than or equal to " << n << ": ";
    // check if n > 0
    if(n <= 0) { std::cout << "[ ]"; }
    else {
        // initial assumption that all numbers up to n are prime
        std::vector<bool> v(n, true); 
        sieve(n, v);
        print_p(n, v);
    }
    std::cout << std::endl;

    return 0;
}