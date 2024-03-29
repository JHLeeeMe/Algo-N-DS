/** Factorial
 */

#include <stdio.h>
#include <stdint.h>

uint32_t factorial(uint32_t n);
uint32_t factorial_tailrec(uint32_t n);
uint32_t _factorial_tailrec(uint32_t n, uint32_t result);

int32_t main(void)
{
    uint32_t test0 = factorial(0);
    uint32_t test1 = factorial(1);
    uint32_t test2 = factorial(2);
    uint32_t test3 = factorial(3);
    uint32_t test4 = factorial(4);
    printf("%d %d %d %d %d", test0, test1, test2, test3, test4);
    printf("\n");

    uint32_t test0_tailrec = factorial_tailrec(0);
    uint32_t test1_tailrec = factorial_tailrec(1);
    uint32_t test2_tailrec = factorial_tailrec(2);
    uint32_t test3_tailrec = factorial_tailrec(3);
    uint32_t test4_tailrec = factorial_tailrec(4);
    printf("%d %d %d %d %d", test0_tailrec, test1_tailrec, test2_tailrec, test3_tailrec, test4_tailrec);
    printf("\n");
}

uint32_t factorial(uint32_t n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

uint32_t factorial_tailrec(uint32_t n)
{
    return _factorial_tailrec(n, 1);
}

uint32_t _factorial_tailrec(uint32_t n, uint32_t result)
{
    if (n == 0)
    {
        return result;
    }

    return _factorial_tailrec(n - 1, n * result);
}
