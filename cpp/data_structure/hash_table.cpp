#include <iostream>
#include <typeinfo>
#include <vector>

#define __INIT_CAPACITY 16

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
        : _table(std::vector<Node<T>*>(__INIT_CAPACITY))
        , _capacity(__INIT_CAPACITY){}
    HashTable(size_t capacity)
        : _table(std::vector<Node<T>*>(capacity))
        , _capacity(capacity) {}
    //HashTable(const HashTable& h);
    //HashTable(HashTable&& htb);
    //~HashTable();
public:
    size_t get_capacity() const;
    size_t hash(T data) const;
    void put(T data);
    //bool find(T data) const;
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
size_t HashTable<T>::hash(T data) const
{
    // hasing
    // if char* -> void stoi(int* buf, const char* s, size_t s_len = 0)
    // if std::string -> void stoi(int* buf, const std::string& s)
    // return index key
    return 0;
}

template<typename T>
void HashTable<T>::put(T data)
{
    // idx = hash(data)
    // vec[idx]
    // push_back new node
}

void stoi(int* buf, const std::string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        buf[i] = int(s[i]);
    }
}

size_t char_arr_length(const char* s)
{
    size_t cnt = 0;
    while (*s != '\0')
    {
        s++;
        cnt++;
    }
    return cnt;
}

int main()
{
    HashTable<int> h;
    std::cout << h.get_capacity() << std::endl;

    {  // string to int Test
        const char* s1 = "abcd";
        size_t s1_len = char_arr_length(s1);
        int ascii_buf1[s1_len];
        //stoi(ascii_buf1, s1, s1_len);
        stoi(ascii_buf1, s1);

        const std::string s2 = "abcd";
        int ascii_buf2[s2.length()];
        stoi(ascii_buf2, s2);

        std::cout << "-------- ascii_buf1 -------------" << std::endl;
        for (const auto& e : ascii_buf1)
        {
            std::cout << e << std::endl;
        }
        std::cout << "-------- ascii_buf2 -------------" << std::endl;
        for (const auto& e : ascii_buf2)
        {
            std::cout << e << std::endl;
        }
    }

    int a;
    double b;
    std::string s = "sdfsdf";
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(s).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;

    return 0;
}
