/**
 * CSC 301 - Data Structures: Question 2
 * Recursive Algorithms: Factorial, Fibonacci, String Reversal, Binary Search
 */

#include <iostream>
#include <string>
#include <vector>

// 1. Recursive Factorial Calculation
long long factorial(int n) {
    // Edge case: Negative numbers
    if (n < 0) return -1;
    // Base Case
    if (n == 0 || n == 1) return 1;
    // Recursive Case
    return n * factorial(n - 1);
}


// Helper function for Fibonacci calculation at index n
long long fibonacciTerm(int n) {
    // Base Cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    // Recursive Case
    return fibonacciTerm(n - 1) + fibonacciTerm(n - 2);
}

// 2. Recursive Fibonacci Sequence Generation (Prints first n terms)
void printFibonacciSequence(int n) {
    if (n <= 0) {
        std::cout << "[Empty Sequence]";
        return;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << fibonacciTerm(i) << (i == n - 1 ? "" : ", ");
    }
}

// 3. Recursive String Reversal
std::string reverseString(const std::string& str) {
    // Base Case
    if (str.length() <= 1) return str;
    // Recursive Case: process sub-problem (remainder of string) + head character
    return reverseString(str.substr(1)) + str[0];
}

// 4. Recursive Binary Search
int binarySearch(const std::vector<int>& arr, int low, int high, int target) {
    // Base Case 1: Target not found / Empty array bound
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    // Base Case 2: Target found
    if (arr[mid] == target) return mid;

    // Recursive Cases
    if (target < arr[mid]) {
        return binarySearch(arr, low, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, high, target);
    }
}



int main() {
    std::cout << "==================================================\n";
    std::cout << "  RECURSIVE TASK 1: FACTORIAL CALCULATION\n";
    std::cout << "==================================================\n";
    int factInputs[] = {0, 5, 7, -3}; // Inputs including edge cases
    for (int n : factInputs) {
        long long res = factorial(n);
        if (res == -1) {
            std::cout << "Factorial(" << n << ") = Undefined (Negative Input)\n";
        } else {
            std::cout << "Factorial(" << n << ") = " << res << "\n";
        }
    }

    std::cout << "\n==================================================\n";
    std::cout << "  RECURSIVE TASK 2: FIBONACCI SEQUENCE\n";
    std::cout << "==================================================\n";
    int fibInputs[] = {0, 5, 8}; // Inputs including edge cases
    for (int count : fibInputs) {
        std::cout << "First " << count << " Fibonacci numbers: ";
        printFibonacciSequence(count);
        std::cout << "\n";
    }

    std::cout << "\n==================================================\n";
    std::cout << "  RECURSIVE TASK 3: STRING REVERSAL\n";
    std::cout << "==================================================\n";
    std::string strInputs[] = {"", "A", "DataStructures", "Recursion"}; // Inputs including edge cases
    for (const auto& s : strInputs) {
        std::cout << "Original: \"" << s << "\" --> Reversed: \"" << reverseString(s) << "\"\n";
    }

    std::cout << "\n==================================================\n";
    std::cout << "  RECURSIVE TASK 4: BINARY SEARCH\n";
    std::cout << "==================================================\n";
    std::vector<int> sortedArr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    std::vector<int> emptyArr = {};

    // Test Case 1: Existing element
    int idx1 = binarySearch(sortedArr, 0, (int)sortedArr.size() - 1, 23);
    std::cout << "Search 23 in sorted array: Found at Index " << idx1 << "\n";

    // Test Case 2: Non-existent element
    int idx2 = binarySearch(sortedArr, 0, (int)sortedArr.size() - 1, 10);
    std::cout << "Search 10 in sorted array: Return " << idx2 << " (Not Found)\n";

    // Test Case 3: Search on empty array (Edge Case)
    int idx3 = binarySearch(emptyArr, 0, (int)emptyArr.size() - 1, 5);
    std::cout << "Search 5 in empty array: Return " << idx3 << " (Not Found)\n";

    return 0;
}