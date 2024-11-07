#include <iostream>
using namespace std;

int fibonacciIterative(int n)
{
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Iterative Fibonacci(" << n << ") = " << fibonacciIterative(n) << endl;
    cout << "Recursive Fibonacci(" << n << ") = " << fibonacciRecursive(n) << endl;
    return 0;
}
