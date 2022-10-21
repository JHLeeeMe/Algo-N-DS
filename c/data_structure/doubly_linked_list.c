/** Doubly Linked List
 *
 * bool add_first(DoublyLinkedList* DL, int32_t item);
 * bool add_last(DoublyLinkedList* DL, int32_t item);
 * bool add_to_index(DoublyLinkedList* DL, uint32_t idx, int32_t item);
 * int32_t remove_by_index(DoublyLinkedList* DL, uint32_t idx);
 * int32_t remove_by_item(DoublyLinkedList* DL, int32_t item);
 * bool set(DoublyLinkedList* DL, uint32_t idx, int32_t item);
 * Node* get(DoublyLinkedList* DL, uint32_t idx);
 * DoublyLinkedList* node(DoublyLinkedList* DL, uint32_t idx);
 * int32_t index_of(DoublyLinkedList* DL, int32_t item);
 * void print(DoublyLinkedList* DL);
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
    if (node == NULL) 
	{
		return NULL;
	}

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
Node* get(DoublyLinkedList* DL, uint32_t idx);
Node* node(DoublyLinkedList* DL, uint32_t idx);
int32_t index_of(DoublyLinkedList* DL, int32_t item);
void print(DoublyLinkedList* DL);

int32_t main(void)
{
    DoublyLinkedList* DL = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (DL == NULL)
	{
        return -1; 
    }
	else
	{
        DL->head = NULL;
        DL->tail = NULL;
        DL->size = 0;
    }
    printf("size: %d\n", DL->size);  // 0

    printf("#############\n");
    printf("# add_first #\n");
    printf("#############\n");
    for (uint32_t i = 0; i < 10; i++)
	{
        add_first(DL, i);
    }
    print(DL);  // { 9 8 7 6 5 4 3 2 1 0 }
    printf("size: %d\n", DL->size);  // 10
    printf("\n");

    printf("############\n");
    printf("# add_last #\n");
    printf("############\n");
    for (uint32_t i = 0; i < 10; i++)
	{
        add_last(DL, i);
    }
    print(DL);  // { 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9 }
    printf("size: %d\n", DL->size);  // 20
    printf("\n");

    printf("################\n");
    printf("# add_to_index #\n");
    printf("################\n");
    for (uint32_t i = 0; i < 3; i++)
	{
        add_to_index(DL, i, -1);
    }
    print(DL);  // { -1 -1 -1 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9 }
    printf("size: %d\n", DL->size);  // 23
    printf("\n");

    printf("###################\n");
    printf("# remove_by_index #\n");
    printf("###################\n");
    printf("Removed element: %d\n", remove_by_index(DL, 0));   // -1
    printf("Removed element: %d\n", remove_by_index(DL, 21));  // 9
    printf("Removed element: %d\n", remove_by_index(DL, 5));   // 6
    print(DL);  // { -1 -1 9 8 7 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 }
    printf("size: %d\n", DL->size);  // 20
    printf("\n");

    printf("##################\n");
    printf("# remove_by_item #\n");
    printf("##################\n");
    printf("Removed element: %d\n", remove_by_item(DL, 1));   // 1
    printf("Removed element: %d\n", remove_by_item(DL, 8));   // 8
    printf("Removed element: %d\n", remove_by_item(DL, 8));   // 8
    printf("Removed element: %d\n", remove_by_item(DL, -1));  // -1
    print(DL);  // { -1 9 7 5 4 3 2 0 0 1 2 3 4 5 6 7 }
    printf("size: %d\n", DL->size);  // 16
    printf("\n");


    printf("############\n");
    printf("# get, set #\n");
    printf("############\n");
    printf("get(DL, 3)->data: %d\n", get(DL, 3)->data);  // 5
    printf("get(DL, 3)->data: %d\n", get(DL, 3)->data);  // 5

    printf("set(DL, 3, 123)\n");
    set(DL, 3, 123);
    printf("get(DL, 3)->data: %d\n", get(DL, 3)->data);  // 123

    print(DL);  // { -1 9 7 123 4 3 2 0 0 1 2 3 4 5 6 7 }
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
    if (new_node == NULL)
	{
		return false;
	}

    if(is_empty(DL))
	{
        DL->head = DL->tail = new_node;
    }
	else
	{
        DL->head->prev = new_node;
        new_node->next = DL->head;
        DL->head = new_node;
    }
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
    if (new_node == NULL)
	{
		return false;
	}

    if (is_empty(DL))
	{
        DL->tail = DL->head = new_node;
    }
	else
	{
        DL->tail->next = new_node;
        new_node->prev = DL->tail;
        DL->tail = new_node;
    }
    (DL->size)++;

    return true;
}

/*
 * Function: add_to_index
 * ------------------
 * Add item to index
 *
 *  params: DoublyLinkedList* DL, uint32_t idx, int32_t item
 *  returns: bool
 */
bool add_to_index(DoublyLinkedList* DL, uint32_t idx, int32_t item)
{
    bool flag = false;
    if (idx <= (DL->size - 1))
	{
        if (idx == 0)
		{
            flag = add_first(DL, item);
        }
		else if (idx == (DL->size - 1))
		{
            flag = add_last(DL, item);
        }
		else
		{
            Node* new_node = create_node(item);
            if (new_node == NULL)
			{
				return false;
			}

            Node* prev = node(DL, idx - 1);
            Node* curr = node(DL, idx);

            new_node->next = curr;
            curr->prev = new_node;

            new_node->prev = prev;
            prev->next = new_node;

            (DL->size)++;

            flag = true;
        }
    }

    return flag;
}

/*
 * Function: remove_by_index
 * -------------------------
 * Remove item of index
 *
 *  params: DoublyLinkedList* Dl, uint32_t idx
 *  returns: int32_t
 */
int32_t remove_by_index(DoublyLinkedList* DL, uint32_t idx)
{
    if (idx > (DL->size - 1))
	{
		return INT32_MIN;
	}

    Node* curr = node(DL, idx);
    if (curr == NULL)
	{
		return INT32_MIN;
	}

    int32_t data = curr->data;
    Node* prev = curr->prev;
    Node* next = curr->next;

    if (prev == NULL)
	{  // Remove head node 
        DL->head = next;
    }
	else
	{
        prev->next = next;
    }

    if (next == NULL)
	{  // Remove tail node
        DL->tail = prev;
    }
	else
	{
        next->prev = prev;
    }
    (DL->size)--;
    free(curr);

    return data;
}

/*
 * Function: remove_by_item
 * ------------------------
 * Remove by item
 *
 *  params: DoublyLinkedList* DL, int32_t item
 *  returns: int32_t
 */
int32_t remove_by_item(DoublyLinkedList* DL, int32_t item)
{
    int32_t idx = index_of(DL, item);
    if (idx < 0)
	{
		return idx;
	}

    return remove_by_index(DL, idx);
}

/*
 * Function: set
 * -------------
 * Set item of idx to param item
 *
 *  params: DoublyLinkedList* Dl, uint32_t idx, int32_t item
 *  returns: bool
 */
bool set(DoublyLinkedList* DL, uint32_t idx, int32_t item)
{
    Node* tmp = node(DL, idx);
    if (tmp == NULL)
	{
		return false;
	}

    tmp->data = item;

    return true;
}

/*
 * Function: get
 * ------------------
 * Return node of index
 *
 *  params: DoublyLinkedList* DL, uint32_t idx
 *  returns: Node*
 */
Node* get(DoublyLinkedList* DL, uint32_t idx)
{
    Node* tmp = node(DL, idx);
    if (tmp == NULL)
	{
		return NULL;
	}

    return tmp;
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
    if (is_empty(DL))
	{
        printf("Empty List.\n");
        return NULL;
    }

    if (idx > (DL->size - 1))
	{
        return NULL;
    }

    Node* tmp = NULL;
    if (idx < (DL->size >> 1))
	{
        tmp = DL->head;
        for (uint32_t i = 0; i < idx; i++)
		{
            tmp = tmp->next;
        }
    }
	else
	{
        tmp = DL->tail;
        for (uint32_t i = (DL->size - 1); i > idx; i--)
		{
            tmp = tmp->prev;
        }
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
    if (is_empty(DL))
	{
        printf("Empty List.\n");
        return INT32_MIN;
    }
    
    uint32_t idx = 0;
    Node* tmp = DL->head;
    while (tmp->data != item)
	{
        if (tmp->next == NULL)
		{
            return INT32_MIN;
        }
        tmp = tmp->next;
        idx++;
    }

    return idx;
}

/*
 * Function: print
 * ---------------
 * Print all
 *  e.g. { 0 1 2 3 4 5 ... }
 *
 *  params: DoublyLinkedList* DL
 *  returns: void
 */
void print(DoublyLinkedList* DL)
{
    printf("{ ");
    Node* tmp = DL->head;
    while(tmp != NULL)
	{
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("}\n");
}
