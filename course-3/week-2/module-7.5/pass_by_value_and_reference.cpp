#include <bits/stdc++.h>
using namespace std;

// Pass by value & reference

void fun_pass_by_value(int *p)
{
    int y = 200;
    p = NULL;
    // Will Not replace the addressed stored main pointer -> X
}
void fun_pass_by_reference(int *&p)
{
    int y = 200;
    p = NULL;
    // Will replace the addressed stored main pointer ✔
}

void custom_swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{

    int x = 100;
    int *p = &x;

    std::cout << "Main Function: " << p << std::endl;

    fun_pass_by_value(p);

    std::cout << "Main Function after fun_pass_by_value: " << p << std::endl;

    fun_pass_by_reference(p);

    std::cout << "Main Function after fun_pass_by_reference: " << p << std::endl;

    int a = 1234, b = 4321;

    custom_swap(a, b); // Example of pass by reference

    cout << a << " " << b << endl;

    return 0;
}