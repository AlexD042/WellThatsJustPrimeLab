#include <vector>
#include <iostream>
#include <cassert>

std::vector<int> calculatePrimeFactors(int n);
void test_calculatePrimeFactors();

int main() {
    test_calculatePrimeFactors();

    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    std::vector<int> primeFactors = calculatePrimeFactors(number);

    std::cout << "Prime factors: ";
    if (primeFactors.empty()) {
        std::cout << "None";
    }
    else {
        for (int factor : primeFactors) {
            std::cout << factor << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}

std::vector<int> calculatePrimeFactors(int n) {
    // Base Case 1
    if (n <= 1) {
        return {};
    }

    // Recursive Case
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            std::vector<int> factors = { i };

            std::vector<int> remainingFactors = calculatePrimeFactors(n / i);

            factors.insert(factors.end(), remainingFactors.begin(), remainingFactors.end());
            return factors;
        }
    }

    // Base Case 2
    return { n };
}

void test_calculatePrimeFactors() {
    assert(calculatePrimeFactors(1) == std::vector<int>({}));
    assert(calculatePrimeFactors(0) == std::vector<int>({}));
    assert(calculatePrimeFactors(-5) == std::vector<int>({}));
    assert(calculatePrimeFactors(2) == std::vector<int>({ 2 }));
    assert(calculatePrimeFactors(13) == std::vector<int>({ 13 }));
    assert(calculatePrimeFactors(100) == std::vector<int>({ 2, 2, 5, 5 }));
    assert(calculatePrimeFactors(12) == std::vector<int>({ 2, 2, 3 }));
    assert(calculatePrimeFactors(315) == std::vector<int>({ 3, 3, 5, 7 }));

    std::cout << "test_calculatePrimeFactors PASSED\n";
}