/** Factorial
 *
 *   n >= 2 인 자연수에서,
 *     n! = n * (n-1) * ... * 2
 *     (e.g. 3! = 3 * 2!)
 */
#include <cassert>

#define __ASSERT(expr) assert(expr)

typedef unsigned int uInt32;

uInt32 factorial(uInt32 a);
uInt32 factorial_tailrec(uInt32 a);
uInt32 _factorial_tailrec(uInt32 a, uInt32 result);

int main()
{
    __ASSERT(factorial(0) == 1);
    __ASSERT(factorial(1) == 1);
    __ASSERT(factorial_tailrec(0) == 1);
    __ASSERT(factorial_tailrec(1) == 1);

    __ASSERT(factorial(3) == 6);
    __ASSERT(factorial_tailrec(3) == 6);

    return 0;
}

uInt32 factorial(uInt32 a)
{
    if (a == 0 || a == 1)
    {
        return 1;
    }

    return a * factorial(a - 1);
}

uInt32 factorial_tailrec(uInt32 a)
{
    return _factorial_tailrec(a, 1);
}

uInt32 _factorial_tailrec(uInt32 a, uInt32 result)
{
    if (a == 0 || a == 1)
    {
        return result;
    }

    return _factorial_tailrec(a - 1, a * result);
}
