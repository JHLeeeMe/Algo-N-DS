/** Queue
 * 
 * bool is_empty(Queue* Q);
 * void clear(Queue* Q);
 * bool enqueue(Queue* Q, int32_t item);
 * int32_t dequeue(Queue* Q);
 * int32_t peek(Queue* Q);
 * uint32_t get_size(Queue* Q);
 * void print_queue(Queue* Q);
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
    int32_t size;
} Queue;

typedef struct Node {
    int32_t data;
    struct Node* next;
} Node;

/*
 * Function: create_queue
 * ----------------------
 * Create queue
 *
 *  params: void
 *  returns: Queue*
 */
Queue* create_queue(void)
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if (Q == NULL)
	{
		return NULL;
	}

    Q->front = NULL;
    Q->rear = NULL;
    Q->size = 0;

    return Q;
}

bool is_empty(Queue* Q);
void clear(Queue* Q);
bool enqueue(Queue* Q, int32_t item);
int32_t dequeue(Queue* Q);
int32_t peek(Queue* Q);
uint32_t get_size(Queue* Q);
void print_queue(Queue* Q);

int32_t main(void)
{
    Queue* Q = create_queue();
    if (Q == NULL)
	{
		return -1;
	}

    printf("empty Queue: %s\n", is_empty(Q) ? "true" : "false");  // true
    printf("clear(Q): ");
    clear(Q);  // "already empty Queue"

    printf("enqueue(Q, 10)\n");
    enqueue(Q, 10);
    printf("Q->front->data: %d\n", Q->front->data);                // 10
    printf("Q->rear->data: %d\n", Q->rear->data);                  // 10
    printf("(void*)Q->front->next: %p\n", (void*)Q->front->next);  // (nil)
    printf("empty Queue: %s\n", is_empty(Q) ? "true" : "false");   // false

    printf("enqueue(Q, 20)\n");
    enqueue(Q, 20);
    printf("Q->front->data: %d\n", Q->front->data);              // 10
    printf("Q->front->next->data: %d\n", Q->front->next->data);  // 20
    printf("Q->rear->data: %d\n", Q->rear->data);                // 20
    printf("(void*)Q->front->next: %p\n", (void*)Q->front->next);              // 0x?????
    printf("(void*)Q->front->next->next: %p\n", (void*)Q->front->next->next);  // (nil)
    printf("(void*)Q->rear->next: %p\n", (void*)Q->rear->next);                // (nil)
    printf("empty Queue: %s\n", is_empty(Q) ? "true" : "false");               // false

    clear(Q);
    printf("empty Queue: %s\n", is_empty(Q) ? "true" : "false");  // true

    printf("enqueue 0 to 9\n");
    uint32_t cnt = 0;
    while (cnt != 10)
	{
        enqueue(Q, cnt);
        cnt++;
    }

    printf("print_queue(Q): ");
    print_queue(Q);              // { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }

    printf("dequeue(Q): %d\n", dequeue(Q));  // 0
    printf("dequeue(Q): %d\n", dequeue(Q));  // 1
    printf("peek(Q): %d\n", peek(Q));        // 2
    printf("peek(Q): %d\n", peek(Q));        // 2

    printf("print_queue(Q): ");
    print_queue(Q);              // { 2, 3, 4, 5, 6, 7, 8, 9 }
    printf("get_size(Q): %d\n", get_size(Q));     // 8
}

/*
 * Function: is_empty
 * ------------------
 * Empty check
 *
 *  params: Queue* Q
 *  returns: bool
 */
bool is_empty(Queue* Q)
{
    return Q->size == 0;
}

/*
 * Function: clear
 * ---------------
 * Clear queue
 *
 *  params: Queue* Q
 *  returns: void
 */
void clear(Queue* Q)
{
    if (is_empty(Q))
	{
        printf("already empty Queue\n");
    }
	else
	{
        Node* tmp = Q->front;
        while (Q->size != 0)
		{
            tmp = tmp->next;
            Q->front = tmp;
            (Q->size)--;
        }
        Q->rear = NULL;
    }
}

/*
 * Function: enqueue
 * -----------------
 * Add data into queue
 *
 *  params: Queue* Q, int32_t item
 *  returns: bool
 */
bool enqueue(Queue* Q, int32_t item)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
	{
        return false;
    }
	else
	{
        new_node->data = item;
        new_node->next = NULL;
    }

    if (is_empty(Q))
	{
        Q->front = new_node;
    }
	else
	{
        Q->rear->next = new_node;
    }
    Q->rear = new_node;
    (Q->size)++;

    return true;
}

/*
 * Function: dequeue
 * -----------------
 * Return & Remove front data
 *
 *  params: Queue* Q
 *  returns: int32_t
 */
int32_t dequeue(Queue* Q)
{
    if (is_empty(Q))
	{
        printf("Queue is empty\n");
        return -1;
    }

    int32_t tmp = Q->front->data;
    Q->front = Q->front->next;
    (Q->size)--;

    return tmp;
}

/*
 * Function: peek
 * --------------
 * Return front data
 *
 *  params: Queue* Q
 *  returns: int32_t
 */
int32_t peek(Queue* Q)
{
    if (is_empty(Q))
	{
        printf("Queue is empty\n");
        return INT32_MIN;
    }

    return Q->front->data;
}

/*
 * Function: get_size
 * ------------------
 * Return number of elements
 *
 *  params: Queue* Q
 *  returns: uint32_t
 */
uint32_t get_size(Queue* Q)
{
    return Q->size;
}

/*
 * Function: print_queue
 * ---------------------
 * prints all elements
 *   e.g. { 1, 2, 3, ..., 10 }
 *
 *  params: Queue* Q
 *  returns: void
 */
void print_queue(Queue* Q)
{
    Node* tmp = Q->front;

    printf("{ ");
    while (tmp != NULL)
	{
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("}\n");
}
