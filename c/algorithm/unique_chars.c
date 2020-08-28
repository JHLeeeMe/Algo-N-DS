#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool isUniqueStr(char* c_ptr);

int main(void)
{
    char* str1 = "Hello";
    char* str2 = "abcde";

    printf("Hello => ");
    printf(isUniqueStr(str1) ? "유니크" : "중복");
    printf("\n");
    printf("abcde => ");
    printf(isUniqueStr(str2) ? "유니크" : "중복");
    printf("\n");
}

bool isUniqueStr(char* c_ptr)
{
    char* str = c_ptr;

    uint32_t bit_bucket = 0;

    for (uint8_t i = 0; i < strlen(str); i++)
    {
        uint32_t n = str[i] - 'a';
        if ((bit_bucket & (1 << n)) > 0)
            return false;

        bit_bucket |= (1 << n);
    }
    return true;
}
