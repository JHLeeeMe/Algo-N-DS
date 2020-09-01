/** Stack
 */

#define DEFAULT_STACK_SIZE (10)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Stack {
    int32_t* array;
    int32_t top;
    uint32_t capacity;
} Stack;

/*
 * Function: create_stack
 * ----------------------
 * Create stack
 *
 *  params: uint32_t capacity
 *  returns: Stack*
 */
Stack* create_stack(uint32_t capacity) {
    Stack* S = (Stack*)malloc(sizeof(Stack));
    if (S != NULL) {
        S->capacity = capacity;
        S->top = -1;
        S->array = malloc(S->capacity * sizeof(int32_t));
    }

    return S;
}

bool is_full(Stack* S);
bool is_empty(Stack* S);
bool push(Stack* S, int32_t item);
int32_t pop(Stack* S);
int32_t peek(Stack* S);

int32_t main(void)
{
    Stack* stack = create_stack(10);
    if (stack == NULL) { return -1; }

    printf("is_full: %s\n", (is_full(stack)) ? "true" : "false");   // false
    printf("is_empty: %s\n", (is_empty(stack)) ? "true" : "false"); // true

    printf("###################\n");
    printf("# Push item 0 ~ 9 #\n");
    printf("###################\n");
    for (int i = 0; i < 10; i++) {
        push(stack, i);
    }

    printf("is_full: %s\n", (is_full(stack)) ? "true" : "false");   // true
    printf("is_empty: %s\n", (is_empty(stack)) ? "true" : "false"); // false
}

/*
 * Function: is_full
 * -----------------
 * Full check
 *
 *  params: Stack* S
 *  returns: bool
 */
bool is_full(Stack* S)
{
    return S->top == (int32_t)(S->capacity - 1);
}

/*
 * Function: is_empty
 * -----------------
 * Empty check
 *
 *  params: Stack* S
 *  returns: bool
 */
bool is_empty(Stack* S)
{
    return S->top == -1;
}

/*
 * Function: push
 * -----------------
 * Push item into stack
 *
 *  params: Stack* S, int32_t item
 *  returns: bool
 */
bool push(Stack* S, int32_t item)
{
    if (is_full(S)) {
        printf("Stack is Full.\n");
        return false;
    }
    S->array[++(S->top)] = item;
    printf("Push %d into stack.\n", item);

    return true;
}

//int32_t pop(Stack* S);

//int32_t peek(Stack* S);
