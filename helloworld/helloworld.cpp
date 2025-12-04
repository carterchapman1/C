#include <iostream>
#include <vector>
#include <string>

using namespace std;

// test function to 
int multiply_by_ten(int iV)
{

    return iV * 10;

}

// declaration of function after the main, otherwise the main() doesn't know about it
void test_function_a();

// main entry point
int main()
{

    test_function_a();

    int v = 10;
    v++;
    printf("v=%i\n", v);
    v--;
    printf("v=%i\n", v);

    v *= 10;
    v /= 10;
    v += 10;
    v -= 10;

    return 0;
}

// function declared above
void test_function_a()
{

    for (int i=0; i<10; i++)
    {
        int iRes = multiply_by_ten(i);
        printf("Hello World. %i * 10 = %i!\n", i, iRes);
    }

}
