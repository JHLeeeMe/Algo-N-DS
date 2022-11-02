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
    HashTable(const HashTable& h);
    //HashTable(HashTable&& h);
    //~HashTable();
public:
    size_t get_capacity() const;
    void put(const T& data);
    void remove(const T& data);
    const T& get(const T& data) const;
    void clear();
    std::vector<Node<T>*> _table;
private:
    size_t _hash(const std::string& data) const;
    bool _find(const T& data) const;
private:
    size_t _capacity;
};

template<typename T>
size_t HashTable<T>::get_capacity() const
{
    return _capacity;
}

template<typename T>
void HashTable<T>::put(const T& data)
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

template<typename T>
void HashTable<T>::remove(const T& data)
{
    size_t idx = _hash(data);
    Node<T>* prev = nullptr;
    Node<T>* curr = _table[idx];
    while (curr != nullptr)
    {
        if (curr->value != data)
        {
            prev = curr;
            curr = curr->next;
            continue;
        }

        if (curr->next != nullptr)
        {
            if (prev != nullptr)
            {
                prev->next = curr->next;
            }
            else
            {
                _table[idx] = curr->next;
            }
            delete curr;
        }
        else
        {
            if (prev != nullptr)
            {
                prev->next = nullptr;
            }
            else
            {
                _table[idx] = nullptr;
            }
            delete curr;
        }
        break;
    }
}

template<typename T>
const T& HashTable<T>::get(const T& data) const
{
    __ASSERT_MSG(_find(data), "data is not exists.");

    size_t idx = _hash(data);
    Node<T>* curr = _table[idx];
    while (curr != nullptr)
    {
        if (curr->value == data)
        {
            return curr->value;
        }
        curr = curr->next;
    }
}

template<typename T>
void HashTable<T>::clear()
{
    for (int i = 0; i < _capacity; ++i)
    {
        Node<T>* curr = _table[i];
        while (curr != nullptr)
        {
            Node<T>* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
        _table[i] = nullptr;
    }
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
bool HashTable<T>::_find(const T& data) const
{
    size_t idx = _hash(data);
    Node<T>* curr = _table[idx];
    while (curr != nullptr)
    {
        if (curr->value == data)
        {
            return true;
        }
        curr = curr->next;
    }

    return false;
}

int main()
{
    HashTable<int> h_int;
    HashTable<std::string> h_string(10);

    {  // capacity Test
        __ASSERT(h_int.get_capacity() == __DEFAULT_CAPACITY);
        __ASSERT(h_string.get_capacity() == 10);
    }
    {  // 중복 검사
        std::cout << "----- unique Test -----" << std::endl;
        h_string.put("a");
        h_string.put("a");
        h_string.put("a");
    }
    {  // remove Test
        std::cout << "----- remove Test -----" << std::endl;
        h_string.put("bbb");
        h_string.put("ccc");
        h_string.put("ddd");
        h_string.put("eee");
        h_string.put("fff");
        h_string.put("abc");
        h_string.put("bca");

        for (int i = 0; i < 10; ++i)
        {
            Node<std::string>* curr = h_string._table[i];
            if (curr == nullptr)
            {
                continue;
            }

            while (curr != nullptr)
            {
                std::cout << "key: " << i << std::endl
                          << "value: " << curr->value << std::endl;
                curr = curr->next;
            }
        }

        std::cout << "----------" << std::endl;

        h_string.remove("ppp");
        h_string.remove("kkka");
        h_string.remove("a");
        h_string.remove("hihihihihi");
        h_string.remove("fff");

        for (int i = 0; i < 10; ++i)
        {
            Node<std::string>* curr = h_string._table[i];
            if (curr == nullptr)
            {
                continue;
            }

            while (curr != nullptr)
            {
                std::cout << "key: " << i << std::endl
                          << "value: " << curr->value << std::endl;
                curr = curr->next;
            }
        }
    }
    {  // clear Test
        std::cout << "----- clear Test-----" << std::endl;
        h_string.clear();
    }
    {  // get Test
        h_string.put("aa");
        h_string.put("bb");
        h_string.put("cc");

        __ASSERT(h_string.get("aa") == "aa");
    }

    return 0;
}
