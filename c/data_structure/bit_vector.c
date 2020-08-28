/** Bit Vector
 */

#include <stdio.h>
#include <stdint.h>

void set_bit(uint8_t* arr, uint32_t k);
void clear_bit(uint8_t* arr, uint32_t k);
void test_bit(uint8_t* arr, uint32_t k);
uint32_t max(uint32_t* arr, uint32_t size);

int main()
{
    uint32_t test[] = {1, 82, 32, 9, 3, 103};
    uint32_t max_value = max(test, sizeof(test) / sizeof(uint32_t));
    uint8_t arr[max_value / sizeof(uint8_t)];

    //uint8_t arr[10];
    for (uint32_t i = 0; i < sizeof(uint8_t) * sizeof(arr); i++)
    {
        set_bit(arr, i);
    }

    for (uint32_t i = 0; i < sizeof(uint8_t) * sizeof(arr); i++)
    {
        test_bit(arr, i);
    }

    for (uint32_t i = 0; i < sizeof(uint8_t) * sizeof(arr); i++)
    {
        clear_bit(arr, i);
    }

    for (uint32_t i = 0; i < sizeof(uint8_t) * sizeof(arr); i++)
    {
        test_bit(arr, i);
    }
}

void set_bit(uint8_t* arr, uint32_t k)
{
    arr[k / 8] |= 1 << (k % 8);
}

void clear_bit(uint8_t* arr, uint32_t k)
{
    arr[k / 8] &= ~(1 << (k % 8));
}

void test_bit(uint8_t* arr, uint32_t k)
{
    if ((arr[k / 8] & (1 << (k % 8))) != 0)
    {
        printf("%d-th bit is 1\n", k);
    }
    else
    {
        printf("%d-th bit is 0\n", k);
    }
}

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
