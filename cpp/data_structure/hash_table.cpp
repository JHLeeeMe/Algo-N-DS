#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <cstring>
#include <cassert>

#define __ASSERT(expr) assert(expr)
#define __ASSERT_MSG(expr, msg) assert(expr && msg)

#define __DEFAULT_CAPACITY 16

template<typename T>
struct Node
{
    T value;
    struct Node<T>* next;
};

template<typename T>
class HashTable
{
public:
    HashTable()
        : _table(std::vector<Node<T>*>(__DEFAULT_CAPACITY))
        , _capacity(__DEFAULT_CAPACITY) {}
    HashTable(size_t capacity)
        : _table(std::vector<Node<T>*>(capacity))
        , _capacity(capacity) {}
    //HashTable(const HashTable& h);
    //HashTable(HashTable&& h);
    //~HashTable();
public:
    size_t get_capacity() const;
    void put(T data);
private:
    size_t _hash(const std::string& data) const;
private:
    std::vector<Node<T>*> _table;
    size_t _capacity;
};

template<typename T>
size_t HashTable<T>::get_capacity() const
{
    return _capacity;
}

template<typename T>
size_t HashTable<T>::_hash(const std::string& data) const
{
    // djb2 function
    // (http://www.cse.yorku.ca/~oz/_hash.html)
    unsigned long _hash = 5381;
    int c;
    for (int i = 0; i < data.length(); i++)
    {
        c = data[i];
        _hash = ((_hash << 5) + _hash) + c;  // _hash * 33 + c
    }

    return _hash % _capacity;
}

template<typename T>
void HashTable<T>::put(T data)
{
    Node<T>* new_node = new Node<T>;
    new_node->next = nullptr;
    new_node->value = data;

    size_t idx = _hash(data);
    if (_table[idx] == nullptr)
    {
        _table[idx] = new_node;
    }
    else
    {
        Node<T>* prev = nullptr;
        Node<T>* curr = _table[idx];
        while (curr != nullptr)
        {
            if (curr->value == data)
            {
                std::cout << "key: \"" << curr->value << "\" 중복" << std::endl;
                delete new_node;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = new_node;
    }
}

int main()
{
    HashTable<int> h_int;
    HashTable<std::string> h_string(10);
    {  // capacity Test
        __ASSERT(h_int.get_capacity() == __DEFAULT_CAPACITY);
        __ASSERT(h_string.get_capacity() == 10);
    }
    {
        h_string.put("a");
        h_string.put("a");
        h_string.put("a");

        h_string.put("bca");
        h_string.put("cba");
        h_string.put("kkka");
    }

    return 0;
}
