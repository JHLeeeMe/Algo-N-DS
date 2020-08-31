/** Queue
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool is_empty();
void clear();
void enqueue(int32_t item);
int32_t dequeue();
int32_t peek();

typedef struct Node
{
    int32_t data;
    struct Node* next;
} Node;

int32_t main(void)
{
}
