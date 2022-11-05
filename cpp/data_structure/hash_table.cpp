#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <vector>
#include <cstring>
#include <cassert>

#define __ASSERT(expr) assert(expr)
#define __ASSERT_MSG(expr, msg) assert(expr && msg)
#define __STATIC_ASSERT(expr, msg) static_assert(expr, msg)

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
    HashTable();
    HashTable(size_t capacity);
    HashTable(const HashTable& h);
    HashTable(HashTable&& h);
    ~HashTable();
public:
    size_t get_capacity() const;
    void put(const T& data);
    void remove(const T& data);
    const T& get(const T& data) const;
    void clear();
    void print_all() const;
private:
    size_t _hash(const std::string& data) const;
    size_t _hash(const int& data) const;
    bool _find(const T& data) const;
private:
    std::vector<Node<T>*> _table;
    size_t _capacity;
};

template<typename T>
HashTable<T>::HashTable()
    : _table(std::vector<Node<T>*>(__DEFAULT_CAPACITY))
    , _capacity(__DEFAULT_CAPACITY)
{
    __STATIC_ASSERT(
        (std::is_same<T, int>::value ||
         std::is_same<T, std::string>::value ||
         std::is_same<T, const char*>::value)
        , "T = int || std::string || const char*"
    );
}

template<typename T>
HashTable<T>::HashTable(size_t capacity)
    : _table(std::vector<Node<T>*>(capacity))
    , _capacity(capacity)
{
    __STATIC_ASSERT(
        (std::is_same<T, int>::value ||
         std::is_same<T, std::string>::value ||
         std::is_same<T, const char*>::value)
        , "T = int || std::string || const char*"
    );
}

template<typename T>
HashTable<T>::HashTable(const HashTable& h)
{
    _capacity = h.get_capacity();
    _table = std::vector<Node<T>*>(_capacity);
    for (int i = 0; i < _capacity; ++i)
    {
        Node<T>* curr = h._table[i];
        while (curr != nullptr)
        {
            Node<T>* new_node = new Node<T>;
            new_node->value = curr->value;
            new_node->next = nullptr;
            if (_table[i] == nullptr)
            {
                _table[i] = new_node;
            }
            else
            {
                Node<T>* tmp = _table[i];
                while (tmp->next != nullptr)
                {
                    tmp = tmp->next;
                }
                tmp->next = new_node;
            }
            curr = curr->next;
        }
    }
}

template<typename T>
HashTable<T>::HashTable(HashTable&& h)
    : _table(std::move(h._table))
    , _capacity(h._capacity)
{
    h._table.clear();
    h._capacity = 0;
}

template<typename T>
HashTable<T>::~HashTable()
{
    clear();
}

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
void HashTable<T>::print_all() const
{
    std::cout << "{";
    for (int i = 0; i < _capacity; ++i)
    {
        Node<T>* curr = _table[i];
        if (curr == nullptr)
        {
            continue;
        }

        int node_idx = 0;
        while (curr != nullptr)
        {
            if (node_idx != 0)
            {
                std::cout << i << "-" << node_idx
                          << ": " << curr->value << ", ";
            }
            else
            {
                std::cout << i << ": " << curr->value << ", ";
            }
            curr = curr->next;
            node_idx++;
        }
    }
    std::cout << "}" << std::endl;
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
size_t HashTable<T>::_hash(const int& data) const
{
    return data % _capacity;
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

        h_string.print_all();

        std::cout << "----------" << std::endl;

        h_string.remove("ppp");
        h_string.remove("kkka");
        h_string.remove("a");
        h_string.remove("hihihihihi");
        h_string.remove("fff");

        h_string.print_all();
    }
    {  // clear Test
        std::cout << "----- clear Test-----" << std::endl;
        h_string.clear();
    }
    {  // get Test
        std::cout << "----- get Test-----" << std::endl;
        h_string.put("aa");
        h_string.put("bb");
        h_string.put("cc");
        h_string.put("abc");
        h_string.put("bca");
        h_string.put("bac");

        __ASSERT(h_string.get("aa") == "aa");
    }
    {  // copy constructor Test
       std::cout << "----- copy constructor Test-----" << std::endl;
       h_string.print_all();
       HashTable<std::string> h_copy = h_string;
       h_copy.print_all();
       h_string.print_all();
       h_copy.clear();
       h_copy.print_all();
       h_string.print_all();
    }
    {  // move constructor Test
       std::cout << "----- move constructor Test-----" << std::endl;

       h_string.print_all();
       HashTable<std::string> h_moved = std::move(h_string);
       h_moved.print_all();
    }
    {  // template type constraint (static_assert) Test
        HashTable<const char*> const_char_ptr_h;
        // static_assert 발생
        //HashTable<double> double_h;
    }

    return 0;
}
