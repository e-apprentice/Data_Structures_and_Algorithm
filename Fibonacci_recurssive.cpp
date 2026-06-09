#include <iostream>
using namespace std;

// Function to generate Fibonacci sequence up to n terms
void generateFibonacci(int n) {
    int first = 0, second = 1, next;
      cout << "Fibonacci Sequence up to " << n << " terms: ";

    for (int i = 0; i < n; ++i) {
        cout << first << " ";

        next = first + second;
        first = second;
        second = next;
    }

    std::cout << std::endl;
}

int main() {
    int n;

    // Get the number of terms from the user
    cout << "Enter the number of terms for Fibonacci sequence: ";
    cin >> n;

    // Check for valid input
    if (n <= 0) {
        cout << "Please enter a positive integer for the number of terms." <<endl;
        return 1; // Return an error code
    }

    // Generate and print the Fibonacci sequence
    generateFibonacci(n);

    return 0;
}
