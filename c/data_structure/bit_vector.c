/** Bit Vector
 *
 * void set_bit(char* bit_vector, uint32_t k);
 * void clear_bit(char* bit_vector, uint32_t k);
 * void clear_bit_all(char* bit_vector, uint32_t max_value);
 * uint32_t max(uint32_t* arr, uint32_t size);
 * void test_bit(char* bit_vector, uint32_t k);
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

void set_bit(char* bit_vector, uint32_t k);
void clear_bit(char* bit_vector, uint32_t k);
void clear_bit_all(char* bit_vector, uint32_t max_value);
uint32_t max(uint32_t* arr, uint32_t size);
void test_bit(char* bit_vector, uint32_t k);

int main()
{
    uint32_t test[] = {1, 20, 32, 9, 3, 10, 7, 19, 16};
    uint32_t max_value = max(test, sizeof(test) / sizeof(uint32_t));

    // Init bit_vector to zero.
    char bit_vector[max_value / sizeof(char)];
    memset(bit_vector, 0, max_value / sizeof(char));

    printf("###################\n");
    printf("# Init bit_vector #\n");
    printf("###################\n");
    for (uint32_t i = 0; i < sizeof(bit_vector) * sizeof(char) + 1; i++)
    {
        test_bit(bit_vector, i);
    }

    printf("\n");

    printf("##################\n");
    printf("# Set bit_vector #\n");
    printf("##################\n");
    for (uint32_t i = 0; i < sizeof(test) / sizeof(uint32_t); i++)
    {
        set_bit(bit_vector, test[i]);
    }

    for (uint32_t i = 0; i < sizeof(bit_vector) * sizeof(char) + 1; i++)
    {
        test_bit(bit_vector, i);
    }

    printf("\n");

    printf("####################\n");
    printf("# Clear bit_vector #\n");
    printf("####################\n");

    clear_bit_all(bit_vector, max_value);

    for (uint32_t i = 0; i < sizeof(bit_vector) * sizeof(char) + 1; i++)
    {
        test_bit(bit_vector, i);
    }
}

/*
 * Function: set_bit
 * ------------------
 * Set kth-bit (0 -> 1)
 *
 *  params: char* bit_vector, uint32_t k
 *  returns: void
 */
void set_bit(char* bit_vector, uint32_t k)
{
    bit_vector[k / 8] |= 1 << (k % 8);
}

/*
 * Function: clear_bit
 * ------------------
 * Clear kth-bit (1 -> 0)
 *
 *  params: char* bit_vector, uint32_t k
 *  returns: void
 */
void clear_bit(char* bit_vector, uint32_t k)
{
    bit_vector[k / 8] &= ~(1 << (k % 8));
}

/*
 * Function: clear_bit_all
 * ------------------
 * Clear all bit_vector (1 -> 0)
 *
 *  params: char* bit_vector, uint32_t max_value
 *  returns: void
 */
void clear_bit_all(char* bit_vector, uint32_t max_value)
{
    //for (int32_t i = max_value / 8; i >= 0; i--)
    //    bit_vector[i] &= ~(bit_vector[i]);
    memset(bit_vector, 0, max_value / sizeof(char));
}

/*
 * Function: max
 * ------------------
 * Return max value in array
 *
 *  params: char* bit_vector, uint32_t k
 *  returns: uint32_t
 */
uint32_t max(uint32_t* arr, uint32_t size)
{
    uint32_t max_value = arr[0];
    for (uint32_t i = 0; i < size; i++)
    {
        if (max_value < arr[i])
        {
            max_value = arr[i];
        }
    }

    return max_value;
}

/*
 * Function: test_bit
 * ------------------
 * Print bit_vector elements
 *
 *  params: char* bit_vector, uint32_t k
 *  returns: void
 */
void test_bit(char* bit_vector, uint32_t k)
{
    if ((bit_vector[k / 8] & (1 << (k % 8))) != 0)
    {
        printf("%d-th bit is 1\n", k);
    }
    else
    {
        printf("%d-th bit is 0\n", k);
    }
}
