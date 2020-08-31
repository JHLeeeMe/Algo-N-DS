/** Queue
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct Node
{
    int32_t data;
    struct Node* next;
} Node;

bool is_empty(Node* front);
void clear(Node* front);
void enqueue(int32_t item);
int32_t dequeue();
int32_t peek();

int32_t main(void)
{
    Node* front = NULL;
    printf("empty Queue: %s\n", is_empty(front) ? "true" : "false");

}

bool is_empty(Node* front)
{
    return front == NULL;
}

void clear(Node* front)
{
    Node* tmp = NULL;
    while (front->next != NULL) {
        tmp = front->next;
        front = tmp;
    }
    front = NULL;
}
