#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 1)
        return 1;

    return n * fact(n - 1);
}


int fibonacci(int n) /*  O(2^N ) */
{
    if (n < 2)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

vector<long long int> fib_sum(1000005, -1);

int fibonacci_optimized(int n) /*  O(N) */ /* TOP DOWN */
{
    if (n < 2)
        return n;

    if(fib_sum[n] != -1)
        return fib_sum[n];

    fib_sum[n] = fibonacci_optimized(n - 1) + fibonacci_optimized(n - 2);
    return fib_sum[n];
}

int main()
{
    // cout << "Introduction to dynamic programming\n";
    // cout << "Recursion + Optimization\n";
    // cout << "https://quanticdev.com/tools/recursion-visualization/" << endl;

    // cout << fact(5) << endl;
    long long int fib_val = fibonacci_optimized(1000);
    cout << fib_val << endl;

    return 0;
}