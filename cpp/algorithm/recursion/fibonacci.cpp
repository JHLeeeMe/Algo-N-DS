/** Fibonacci
 *
 *   F(0) = 0;
 *   F(1) = 1;
 *   F(n) = F(n-2) + F(n-1)
 *
 *   (e.g. 0, 1, 1, 2, 3, 5, 8, 13, ...)
 */
#include <cassert>

#define __ASSERT(expr) assert(expr)

typedef unsigned int uInt32;

uInt32 fibonacci(uInt32 n);
uInt32 fibonacci_tailrec(uInt32 n);
uInt32 _fibonacci_tailrec(uInt32 n, uInt32 a, uInt32 b);

int main()
{
    __ASSERT(fibonacci(0) == 0);
    __ASSERT(fibonacci(1) == 1);
    __ASSERT(fibonacci_tailrec(0) == 0);
    __ASSERT(fibonacci_tailrec(1) == 1);

    __ASSERT(fibonacci(2) == 1);
    __ASSERT(fibonacci(3) == 2);
    __ASSERT(fibonacci(4) == 3);
    __ASSERT(fibonacci(5) == 5);
    __ASSERT(fibonacci_tailrec(2) == 1);
    __ASSERT(fibonacci_tailrec(3) == 2);
    __ASSERT(fibonacci_tailrec(4) == 3);
    __ASSERT(fibonacci_tailrec(5) == 5);

    return 0;
}

uInt32 fibonacci(uInt32 n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibonacci(n - 2) + fibonacci(n - 1);
}

uInt32 fibonacci_tailrec(uInt32 n)
{
    return _fibonacci_tailrec(n, 0, 1);
}

uInt32 _fibonacci_tailrec(uInt32 n, uInt32 a, uInt32 b)
{
    if (n == 0)
    {
        return a;
    }
    else if (n == 1)
    {
        return b;
    }

    return _fibonacci_tailrec(n - 1, b, a + b);
}
