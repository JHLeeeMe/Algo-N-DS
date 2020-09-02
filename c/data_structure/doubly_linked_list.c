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

/*
 * Function: create_node
 * ---------------------
 * Create node
 *
 *  params: int32_t item
 *  returns: Node*
 */
Node* create_node(int32_t item)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) { return false; }

    node->data = item;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

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

/*
 * Function: is_empty
 * ------------------
 * Empty check
 *
 *  params: DoublyLinkedList* DL
 *  returns: bool
 */
bool is_empty(DoublyLinkedList* DL)
{
    return DL->size == 0;
}

/*
 * Function: add_first
 * ------------------
 * Add item to first index
 *
 *  params: DoublyLinkedList* DL, int32_t item
 *  returns: bool
 */
bool add_first(DoublyLinkedList* DL, int32_t item)
{
    Node* new_node = create_node(item);
    if (new_node == NULL) { return false; }

    new_node->next = DL->head;
    DL->head = new_node;
    (DL->size)++;

    return true;
}

/*
 * Function: add_last
 * ------------------
 * Add item to last index
 *
 *  params: DoublyLinkedList* DL, int32_t item
 *  returns: bool
 */
bool add_last(DoublyLinkedList* DL, int32_t item)
{
    Node* new_node = create_node(item);
    if (new_node == NULL) { return false; }

    new_node->prev = DL->tail;
    DL->tail = new_node;
    (DL->size)++;

    return true;
}

/*
 * Function: add_to_index
 * ------------------
 * Add item to param index
 *
 *  params: DoublyLinkedList* DL, uint32_t idx, int32_t item
 *  returns: bool
 */
bool add_to_index(DoublyLinkedList* DL, uint32_t idx, int32_t item)
{
    bool flag = false;
    if (idx <= (DL->size - 1)) {
        if (idx == 0) {
            flag = add_first(DL, item);
        } else if (idx == (DL->size - 1)) {
            flag = add_last(DL, item);
        } else {
            Node* new_node = create_node(item);
            if (new_node == NULL) { return false; }

            Node* prev = node(DL, idx - 1);
            prev->next = new_node;
            new_node->next = node(DL, idx);
            (DL->size)++;

            flag = true;
        }
    }

    return flag;
}

/*
 * Function: node
 * ------------------
 * Return node of index
 *
 *  params: DoublyLinkedList* DL, uint32_t idx
 *  returns: Node*
 */
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
