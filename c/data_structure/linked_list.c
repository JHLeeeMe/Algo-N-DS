/** Linked List
 *
 * bool add(linkedList* L, int32_t item)
 * bool removeByItem(linkedList* L, int32_t item)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct linkedList
{
    struct node* head;
} linkedList;

typedef struct node
{
    int32_t data;
    struct node* next;
} node;

bool add(linkedList* L, int32_t item);
bool removeByItem(linkedList* L, int32_t item);

int32_t main(void)
{
    // init
    linkedList* L = (linkedList*)malloc(sizeof(linkedList));
    L->head = NULL;

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
    for (node* tmp = L->head; tmp != NULL; tmp = tmp->next)
        printf("%i ", tmp->data);
    printf("\n");

    removeByItem(L, 4);
    for (node* tmp = L->head; tmp != NULL; tmp = tmp->next)
        printf("%i ", tmp->data);
    printf("\n");

    // free
    while (L->head != NULL)
    {
        node* tmp = L->head->next;
        free(L->head);
        L->head = tmp;
    }
}

bool add(linkedList* L, int32_t item)
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) return false;

    newNode->data = item;
    newNode->next = NULL;

    if (L->head == NULL)
        L->head = newNode;
    else
    {
        node* tmp = L->head;
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = newNode;
    }
    
    return true;
}

bool removeByItem(linkedList* L, int32_t item)
{
    if (L->head == NULL)
        return false;

    if (L->head->data == item)
        L->head = L->head->next;
    else
    {
        node* before = NULL;
        node* curr = L->head;

        while (curr->data != item)
        {
            if (curr->next == NULL)
            {
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
//typedef struct node
//{
//    int32_t data;
//    struct node* next;
//} node;
//
//bool add(node** head, int32_t item);
//
//int32_t main(void)
//{
//    // init
//    node* head = NULL;
//
//    // add item
//    add(&head, 1);        // head를 NULL로 초기화 했기 때문에 포인터의 주소를 쏨.
//    add(&head, 2);        // if malloc() 함수로 초기화를 하면? head->data가 할당된 메모리에 전부 0으로 들어감.
//    add(&head, 3);        // 그래서 안됨. 출력이 0 1 2 3 4 5 가 됨.
//    add(&head, 4);
//    add(&head, 5);
//
//    // traversal
//    for (node* tmp = head; tmp != NULL; tmp = tmp->next)
//        printf("%i ", tmp->data);
//
//    // free
//    while (head != NULL)
//    {
//        node* tmp = head->next;
//        free(head);
//        head = tmp;
//    }
//}
//
//bool add(node** head, int32_t item)
//{
//    node* newNode = (node*)malloc(sizeof(node));
//    if (newNode == NULL) return false;
//
//    newNode->data = item;
//    newNode->next = NULL;
//
//    if (*head == NULL)
//        *head = newNode;
//    else
//    {
//        node* tmp = *head;
//        while (tmp->next != NULL)
//            tmp = tmp->next;
//        tmp->next = newNode;
//    }
//    
//    return true;
//}
