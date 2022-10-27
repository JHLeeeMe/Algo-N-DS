#define Assert_msg(expression, message) assert(expression && message)
#define Assert(expression) assert(expression)

#include <iostream>
#include <cassert>



template<typename T>
class Vector
{
public:
    class Iterator
    {
    friend class Vector;
    public:
        Iterator next();
        Iterator prev();
        //bool has_next() const;

        T& operator*() const;
        bool operator!=(const Iterator& itr) const;
        Iterator operator++();
        Iterator operator++(int);
        Iterator operator--();
        Iterator operator--(int);
    private:
        Iterator(const Vector& v) : _v(v), _cursor(0) {}
    private:
        const Vector& _v;
        mutable unsigned int _cursor;
    };

    Vector();
    ~Vector();

    void reverse(const unsigned int capacity);
    void resize(const unsigned int capacity, const T data = T());
    void push_back(const T& data);
    T pop_back();
    unsigned int get_size() const;
    unsigned int get_capacity() const;
    bool is_empty() const;
    void clear();

    Iterator begin() const;
    Iterator end() const;
private:
    T* _arr_ptr;
    unsigned int _size;
    unsigned int _capacity;
};

template<typename T>
Vector<T>::Vector()
    : _arr_ptr(new T[16])
    , _size(0)
    , _capacity(16)
{}

template<typename T>
Vector<T>::~Vector()
{
    delete[] _arr_ptr;
}

template<typename T>
void Vector<T>::reverse(const unsigned int capacity)
{
    Assert_msg(_size <= capacity,
        "capacity parameter must be greater than or equal to the vector size");

    T* tmp = new T[capacity];
    for (int i = 0; i < _size; i++)
    {
        tmp[i] = _arr_ptr[i];
    }
    delete[] _arr_ptr;
    _arr_ptr = tmp;
    _capacity = capacity;
}

template<typename T>
void Vector<T>::resize(const unsigned int capacity, const T data)
{
    Assert_msg(_size <= capacity,
        "capacity parameter must be greater than or equal to the vector size");

    T* tmp = new T[capacity];
    for (int i = 0; i < _size; i++)
    {
        tmp[i] = _arr_ptr[i];
    }
    while (_size != capacity)
    {
        tmp[_size] = data;
        _size++;
    }
    delete[] _arr_ptr;
    _arr_ptr = tmp;
    _capacity = capacity;
}

template<typename T>
void Vector<T>::push_back(const T& data)
{
    if (_size == _capacity)
    {
        T* tmp = new T[_capacity * 2];
        for (int i = 0; i < _capacity; i++)
        {
            tmp[i] = _arr_ptr[i];
        }
        delete[] _arr_ptr;
        _arr_ptr = tmp;
        _capacity *= 2;
    }
    _arr_ptr[_size] = data;
    _size++;
}

template<typename T>
T Vector<T>::pop_back()
{
    Assert_msg(_size != 0, "Vector is Empty!");

    T ret = _arr_ptr[_size - 1];
    _arr_ptr[_size - 1] = T();
    _size--;
    return ret;
}

template<typename T>
unsigned int Vector<T>::get_size() const
{
    return _size;
}

template<typename T>
unsigned int Vector<T>::get_capacity() const
{
    return _capacity;
}

template<typename T>
bool Vector<T>::is_empty() const
{
    return _size == 0;
}

template<typename T>
void Vector<T>::clear()
{
    delete[] _arr_ptr;
    _arr_ptr = new T[_capacity];
    _size = 0;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::next()
{
    _cursor++;
    return *this;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::prev()
{
    _cursor--;
    return *this;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::begin() const
{
    Iterator itr = Iterator(*this);
    return itr;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::end() const
{
    Iterator itr = Iterator(*this);
    itr._cursor += _size;
    return itr;
}

template<typename T>
T& Vector<T>::Iterator::operator*() const
{
    return _v._arr_ptr[_cursor];
}

template<typename T>
bool Vector<T>::Iterator::operator!=(const Iterator& itr) const
{
    return _cursor != itr._cursor;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++()
{
    _cursor++;
    return *this;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int)
{
    Iterator tmp = *this;
    _cursor++;
    return tmp;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator--()
{
    _cursor--;
    return *this;
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator--(int)
{
    Iterator tmp = *this;
    _cursor--;
    return tmp;
}

//template<typename T>
//bool Vector<T>::Iterator::has_next() const
//{
//    return _size;
//}

int main()
{
    {
        Vector<int> v;
        Assert(v.get_size() == 0);
        Assert(v.get_capacity() == 16);
        for (int i = 0; i < 16; i++)
        {
            v.push_back(i);
        }
        Assert(v.get_size() == 16);
        Assert(v.get_capacity() == 16);
        v.push_back(17);
        Assert(v.get_size() == 17);
        Assert(v.get_capacity() == 32);
        v.clear();
        Assert(v.get_size() == 0);
        Assert(v.get_capacity() == 32);
    }
    {
        Vector<int> v;
        for (int i = 0; i < 16; i++)
        {
            v.push_back(i);
        }
        Assert(v.get_capacity() == 16);

        v.push_back(17);
        Assert(v.get_capacity() == 32);

        for (int i = 0; i < 16; i++)
        {
            v.push_back(i);
        }
        Assert(v.get_size() == 33);
        Assert(v.get_capacity() == 64);

        v.reverse(100);
        Assert(v.get_size() == 33);
        Assert(v.get_capacity() == 100);

        v.reverse(33);
        Assert(v.get_size() == 33);
        Assert(v.get_capacity() == 33);

        Assert(v.pop_back() == 15);
        Assert(v.get_size() == 32);
        Assert(v.get_capacity() == 33);

        while (!v.is_empty())
        {
            v.pop_back();
        }
        Assert(v.get_size() == 0);

        v.resize(25, 9999);
        Assert(v.get_size() == 25);
        Assert(v.get_capacity() == 25);

        v.push_back(10101);
        Assert(v.get_size() == 26);
        Assert(v.get_capacity() == 50);

        Vector<int>::Iterator itr = v.begin();
        Assert(*itr == 9999);

        //v.reverse(32);
    }
    {
        Vector<int> v;
        for (int i = 0; i < 10; i++)
        {
            v.push_back(i);
        }
        auto itr = v.begin();
        std::cout << *itr << std::endl;

        for (auto itr = v.begin(); itr != v.end(); itr++)
        {
            std::cout << *itr << std::endl;
        }
    }

    return 0;
}
