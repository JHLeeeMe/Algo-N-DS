/** Linked List
 *
 * bool add(LinkedList* L, int32_t item)
 * bool remove_by_item(LinkedList* L, int32_t item)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct LinkedList {
    struct Node* head;
} LinkedList;

typedef struct Node {
    int32_t data;
    struct Node* next;
} Node;

bool add(LinkedList* L, int32_t item);
bool remove_by_item(LinkedList* L, int32_t item);

int32_t 
main(void)
{
    // init
    LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
    if (L == NULL) {
        return -1;
    } else {
        L->head = NULL;
    }

    // add item
    add(L, 1);
    add(L, 2);
    add(L, 3);
    add(L, 4);
    add(L, 5);
    add(L, 6);
    add(L, 7);
    add(L, 8);
    add(L, 9);
    add(L, 10);

    // traversal
    for (Node* tmp = L->head; tmp != NULL; tmp = tmp->next) {
        printf("%i ", tmp->data);
    }
    printf("\n");

    remove_by_item(L, 4);
    for (Node* tmp = L->head; tmp != NULL; tmp = tmp->next) {
        printf("%i ", tmp->data);
    }
    printf("\n");

    // free
    while (L->head != NULL) {
        Node* tmp = L->head->next;
        free(L->head);
        L->head = tmp;
    }
}

/*
 * Function: add
 * -------------
 * Add item into LinkedList
 *
 *  params: LinkedList* L, int32_t item
 *  returns: bool
 */
bool 
add(LinkedList* L, int32_t item)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return false;

    newNode->data = item;
    newNode->next = NULL;

    if (L->head == NULL) {
        L->head = newNode;
    } else {
        Node* tmp = L->head;
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = newNode;
    }
    
    return true;
}

/*
 * Function: remove_by_item
 * -------------
 * Remove item in LinkedList
 *
 *  params: LinkedList* L, int32_t item
 *  returns: bool
 */
bool 
remove_by_item(LinkedList* L, int32_t item)
{
    if (L->head == NULL) {
        return false;
    }

    if (L->head->data == item) {
        L->head = L->head->next;
    } else {
        Node* before = NULL;
        Node* curr = L->head;

        while (curr->data != item) {
            if (curr->next == NULL) {
                printf("item is not exists.\n");
                return false;
            }
            before = curr;
            curr = curr->next;
        }
        before->next = curr->next;
        free(curr);
    }
    
    return true;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef struct Node
//{
//    int32_t data;
//    struct Node* next;
//} Node;
//
//bool add(Node** head, int32_t item);
//
//int32_t main(void)
//{
//    // init
//    Node* head = NULL;
//
//    // add item
//    add(&head, 1);        // head를 NULL로 초기화 했기 때문에 포인터의 주소를 쏨.
//    add(&head, 2);        // if malloc() 함수로 초기화를 하면? head->data가 할당된 메모리에 전부 0으로 들어감.
//    add(&head, 3);        // 그래서 안됨. 출력이 0 1 2 3 4 5 가 됨.
//    add(&head, 4);
//    add(&head, 5);
//
//    // traversal
//    for (Node* tmp = head; tmp != NULL; tmp = tmp->next)
//        printf("%i ", tmp->data);
//
//    // free
//    while (head != NULL)
//    {
//        Node* tmp = head->next;
//        free(head);
//        head = tmp;
//    }
//}
//
//bool add(Node** head, int32_t item)
//{
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (newNode == NULL) return false;
//
//    newNode->data = item;
//    newNode->next = NULL;
//
//    if (*head == NULL)
//        *head = newNode;
//    else
//    {
//        Node* tmp = *head;
//        while (tmp->next != NULL)
//            tmp = tmp->next;
//        tmp->next = newNode;
//    }
//    
//    return true;
//}
