/** Doubly Linked List
 *
 * bool add_first(DoublyLinkedList* DL, int32_t item);
 * bool add_last(DoublyLinkedList* DL, int32_t item);
 * bool add_to_index(DoublyLinkedList* DL, uint32_t idx, int32_t item);
 * int32_t remove_by_index(DoublyLinkedList* DL, uint32_t idx);
 * int32_t remove_by_item(DoublyLinkedList* DL, int32_t item);
 * bool set(DoublyLinkedList* DL, uint32_t idx, int32_t item);
 * bool get(DoublyLinkedList* DL, uint32_t idx);
 * DoublyLinkedList* node(DoublyLinkedList* DL, uint32_t idx);
 * int32_t index_of(DoublyLinkedList* DL, int32_t item);
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
    uint32_t size;
} DoublyLinkedList;

typedef struct Node {
    int32_t data;
    struct Node* prev;
    struct Node* next;
} Node;

bool is_empty(DoublyLinkedList* DL);
bool add_first(DoublyLinkedList* DL, int32_t item);
bool add_last(DoublyLinkedList* DL, int32_t item);
bool add_to_index(DoublyLinkedList* DL, uint32_t idx, int32_t item);
int32_t remove_by_index(DoublyLinkedList* DL, uint32_t idx);
int32_t remove_by_item(DoublyLinkedList* DL, int32_t item);
bool set(DoublyLinkedList* DL, uint32_t idx, int32_t item);
bool get(DoublyLinkedList* DL, uint32_t idx);
Node* node(DoublyLinkedList* DL, uint32_t idx);
int32_t index_of(DoublyLinkedList* DL, int32_t item);

int32_t main(void)
{
    DoublyLinkedList* DL = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (DL == NULL) {
        return -1; 
     } else {
         DL->head = NULL;
         DL->tail = NULL;
         DL->size = 0;
     }
}

bool is_empty(DoublyLinkedList* DL)
{
    return DL->size == 0;
}

Node* node(DoublyLinkedList* DL, uint32_t idx)
{
    if (is_empty(DL)) {
        printf("Empty List.\n");
        return NULL;
    }

    if (idx > (DL->size - 1)) {
        return NULL;
    }

    Node* tmp = DL->head;
    while (idx > 0) {
        tmp = tmp->next;
        idx--;
    }

    return tmp;
}

/*
 * Function: index_of
 * ------------------
 * Return index of item
 *
 *  params: DoublyLinkedList* DL, int32_t item
 *  returns: int32_t
 */
int32_t index_of(DoublyLinkedList* DL, int32_t item)
{
    if (is_empty(DL)) {
        printf("Empty List.\n");
        return INT32_MIN;
    }
    
    uint32_t idx = 0;
    Node* tmp = DL->head;
    while (tmp->data != item) {
        if (tmp->next == NULL) {
            return INT32_MIN;
        }
        tmp = tmp->next;
        idx++;
    }

    return idx;
}
