/** Hash Table
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DEFAULT_CAPACITY (10)

typedef struct Node {
    int32_t key;
    char value[100];
    struct Node* next;
} Node;

Node* create_node(int32_t key, char* item) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) { return NULL; }

    node->key = key;
    strcpy(node->value, item);
    node->next = NULL;

    return node;
}

uint32_t hash(int32_t key);
bool put(int32_t key, char* item);
char* get(int32_t item);
bool delete(int32_t key);
void print(void);

// create hash_table
Node* hash_table[DEFAULT_CAPACITY];

int32_t main(void)
{
    print();
    put(515, "Hello World");
    put(11, "Hello Hash Table");
    put(-24, "abcde");
    put(11, "aaabbbcccccccccoiu");
    print();

    char* tmp = get(515);
    (tmp == NULL)
        ? printf("WTF\n")
        : printf("%s\n", tmp);

    bool tmp2 = delete(-24);
    (tmp2 == true)
        ? printf("ok\n")
        : printf("WTF\n");

    char* tmp3 = get(-24);
    (tmp3 == NULL)
        ? printf("ok\n")
        : printf("%s\n", tmp3);
}

uint32_t hash(int32_t key)
{
    uint32_t hash_idx = 0;
    // for uint
    hash_idx = (key & 0x7fffffff) * 31;

    return hash_idx % DEFAULT_CAPACITY;
}

bool put(int32_t key, char* item)
{
    uint32_t idx = hash(key);
    Node* new_node = create_node(key, item);
    if (new_node == NULL) { return false; }

    if (hash_table[idx] == NULL) {
        hash_table[idx] = new_node;
    } else {
        Node* curr = hash_table[idx];
        
        do {
            if (curr->key == key) {
                strcpy(curr->value, item);
            }
            curr = curr->next;
        } while (curr != NULL);
        curr = new_node;
    }

    return true;
}

char* get(int32_t key)
{
    uint32_t idx = hash(key);

    if (hash_table[idx] == NULL) {
        printf("Not Found.\n");
        return NULL;
    } else {
        Node* curr = hash_table[idx];
        do {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        } while (curr != NULL);

        printf("Not Found.\n");
        return NULL;
    }
}

bool delete(int32_t key)
{
    uint64_t idx = hash(key);

    if (hash_table[idx] == NULL) {
        printf("Not Found.\n");
        return false;
    } else {
        Node* curr = hash_table[idx];
        do {
            if (curr->key == key) {
                hash_table[idx] = curr->next;
                free(curr);
                return true;
            }
            curr = curr->next;
        } while (curr != NULL);

        printf("Not Found.\n");
        return false;
    }
}

void print(void)
{
    printf("{ ");
    for (uint32_t i = 0; i < DEFAULT_CAPACITY; i++) {
        Node* tmp = hash_table[i];
        while (tmp != NULL) {
            printf("(key: %d, value: %s) ", tmp->key, tmp->value);
            tmp = tmp->next;
        }
    }
    printf("}\n");
}
