/** Hash Table
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DEFAUlT_CAPACITY (10)

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

Node* create_node(char* item) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) { return NULL; }

    strcpy(node->data, item);
    node->next = NULL;

    return node;
}

uint64_t hash(char* item);
bool put(char* item);
char* get(char* item);
void print(void);

// create hash_table
Node* hash_table[DEFAUlT_CAPACITY];

int32_t main(void)
{
    print();
    put("Hello World");
    put("Hello Hash Table");
    put("abcde");
    put("aaabbbcccccccccoiu");
    print();

    uint32_t idx = hash("Hello World");
    printf("%s\n", hash_table[idx]->data);

    char* tmp = get("Hello World");
    (tmp == NULL)
        ? printf("WTF\n")
        : printf("%s\n", tmp);
}

uint64_t hash(char* item)
{
    uint64_t hash_idx = 0;
    while (*item != '\0') {
        hash_idx += (*item) * 31;
        item++;
    }

    return hash_idx % DEFAUlT_CAPACITY;
}

bool put(char* item)
{
    uint64_t idx = hash(item);
    Node* new_node = create_node(item);
    printf("%s \n", new_node->data);

    if (hash_table[idx] == NULL) {
        hash_table[idx] = new_node;
    } else {
        Node* curr = hash_table[idx];
        do {
            if (strcmp(curr->data, item)) {
                printf("중복된 item이 있으므로 put하지 않음.\n");
                return false;
            }
            curr = curr->next;
        } while (curr != NULL);
        curr = new_node;
    }

    return true;
}

char* get(char* item)
{
    uint64_t idx = hash(item);

    if (hash_table[idx] == NULL) {
        printf("Not Found.\n");
        return NULL;
    } else {
        Node* curr = hash_table[idx];
        do {
            if (strcmp(curr->data,item) == 0) {
                return curr->data;
            }
            curr = curr->next;
        } while (curr != NULL);

        printf("Not Found.\n");
        return NULL;
    }
}

void print(void)
{
    printf("{ ");
    for (uint32_t i = 0; i < DEFAUlT_CAPACITY; i++) {
        Node* tmp = hash_table[i];
        while (tmp != NULL) {
            printf("%s ", tmp->data);
            tmp = tmp->next;
        }
    }
    printf("}\n");
}
