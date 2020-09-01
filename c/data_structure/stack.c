/** Stack
 *
 * bool is_full(Stack* S);
 * bool is_empty(Stack* S);
 * bool push(Stack* S, int32_t item);
 * int32_t pop(Stack* S);
 * int32_t peek(Stack* S);
 * int32_t size(Stack* S);
 * void print_stack(Stack* S);
 */

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
        S->array = (int32_t*)malloc(S->capacity * sizeof(int32_t));
    }

    return S;
}

bool is_full(Stack* S);
bool is_empty(Stack* S);
bool push(Stack* S, int32_t item);
int32_t pop(Stack* S);
int32_t peek(Stack* S);
int32_t size(Stack* S);
void print_stack(Stack* S);

int32_t main(void)
{
    Stack* stack = create_stack(10);
    if (stack == NULL) { return -1; }

    printf("is_full: %s\n", (is_full(stack)) ? "true" : "false");   // false
    printf("is_empty: %s\n", (is_empty(stack)) ? "true" : "false"); // true
    printf("size: %d\n", size(stack));  // 10
    print_stack(stack);

    printf("###################\n");
    printf("# Push item 0 ~ 9 #\n");
    printf("###################\n");
    for (int i = 0; i < 10; i++) {
        push(stack, i);
    }
    printf("is_full: %s\n", (is_full(stack)) ? "true" : "false");   // true
    printf("is_empty: %s\n", (is_empty(stack)) ? "true" : "false"); // false
    printf("size: %d\n", size(stack));  // 10
    print_stack(stack);

    push(stack, 123);   // prints "Stack is Full."

    printf("#######\n");
    printf("# Pop #\n");
    printf("#######\n");
    for (int i = 0; i < 3; i++) {
        pop(stack);
    }
    printf("is_full: %s\n", (is_full(stack)) ? "true" : "false");   // false
    printf("is_empty: %s\n", (is_empty(stack)) ? "true" : "false"); // false
    printf("size: %d\n", size(stack));  // 7
    print_stack(stack);


    printf("########\n");
    printf("# Peek #\n");
    printf("########\n");
    printf("peek: %d\n", peek(stack));  // 6
    printf("peek: %d\n", peek(stack));  // 6
    printf("size: %d\n", size(stack));  // 7
    print_stack(stack);
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
 * --------------
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

/*
 * Function: pop
 * -------------
 * Return & Remove last pushed element 
 *
 *  params: Stack* S
 *  returns: int32_t
 */
int32_t pop(Stack* S)
{
    if (is_empty(S)) {
        printf("Stack is Empty.\n");
        return INT32_MIN;
    }
    int32_t tmp = S->array[S->top];
    S->array[(S->top)--] = INT32_MIN;
    printf("Pop !\n");
    
    return tmp;
}

/*
 * Function: peek
 * -----------------
 * Return last pushed element
 *
 *  params: Stack* S
 *  returns: int32_t
 */
int32_t peek(Stack* S)
{
    if (is_empty(S)) {
        printf("Stack is Empty.\n");
        return INT32_MIN;
    }

    return S->array[S->top];
}

/*
 * Function: size
 * --------------
 * Return number of elements
 *
 *  params: Stack* S
 *  returns: int32_t
 */
int32_t size(Stack* S)
{
    return (S->top) + 1;
}

/*
 * Function: print_stack
 * -----------------
 * Print stack
 *  e.g. { 1 2 ... 9 10 }
 *
 *  params: Stack* S
 *  returns: void
 */
void print_stack(Stack* S)
{
    printf("{ ");
    for (int32_t i = 0; i <= S->top; i++) {
        printf("%d ", S->array[i]);
    }
    printf("}\n");
}
