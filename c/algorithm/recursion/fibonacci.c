/** Fibonacci
 *
 * 0, 1, 1, 2, 3, 5, 8, 13, ...
 */

#include <stdio.h>
#include <stdint.h>

uint32_t fibonacci(uint32_t n);
uint32_t fibonacci_tailrec(uint32_t n);
uint32_t __fibonacci_tailrec(uint32_t n, uint32_t a, uint32_t b);

int
main(void)
{
    for (uint32_t i = 0; i < 10; i++)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    for (uint32_t i = 0; i < 10; i++)
    {
        printf("%d ", fibonacci_tailrec(i));
    }
}

uint32_t
fibonacci(uint32_t n)
{
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 2) + fibonacci(n - 1);
}

uint32_t
fibonacci_tailrec(uint32_t n)
{
    return __fibonacci_tailrec(n, 0, 1);
}

uint32_t
__fibonacci_tailrec(uint32_t n, uint32_t a, uint32_t b)
{
    if (n == 0) {
        return a;
    }

    if (n == 1) {
        return b;
    }

    return __fibonacci_tailrec(n - 1, b, a + b);
}
