/** Linked List
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linkedList
{
    struct node *head;
} linkedList;

typedef struct node
{
    int data;
    struct node *next;
} node;


bool add(linkedList *L, int item);

int main(void)
{
    // init
    linkedList *L = malloc(sizeof(linkedList));
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
    for (node *tmp = L->head; tmp != NULL; tmp = tmp->next)
        printf("%i ", tmp->data);

    // free
    while (L->head != NULL)
    {
        node *tmp = L->head->next;
        free(L->head);
        L->head = tmp;
    }
}

bool add(linkedList *L, int item)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
        return false;
    newNode->data = item;
    newNode->next = NULL;

    if (L->head == NULL)
        L->head = newNode;
    else
    {
        node *tmp = L->head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = newNode;
        //free(tmp);
    }
    
    return true;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef struct node
//{
//    int data;
//    struct node *next;
//} node;
//
//bool add(node **head, int item);
//
//int main(void)
//{
//    // init
//    node *head = NULL;
//
//    // add item
//    add(&head, 1);
//    add(&head, 2);
//    add(&head, 3);
//    add(&head, 4);
//    add(&head, 5);
//
//    // traversal
//    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
//        printf("%i ", tmp->data);
//
//    // free
//    while (head != NULL)
//    {
//        node *tmp = head->next;
//        free(head);
//        head = tmp;
//    }
//}
//
//bool add(node **head, int item)
//{
//    node *newNode = malloc(sizeof(node));
//    if (newNode == NULL)
//        return false;
//    newNode->data = item;
//    newNode->next = NULL;
//
//    if (*head == NULL)
//        *head = newNode;
//    else
//    {
//        node *tmp = *head;
//        while (tmp->next != NULL)
//            tmp = tmp->next;
//        tmp->next = newNode;
//    }
//    
//    return true;
//}
