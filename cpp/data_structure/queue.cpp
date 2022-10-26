#include <iostream>
#include <cassert>
#include <array>

#define Assert(expression) assert(expression)
#define Assert_msg(expression, message) assert(expression && message)

template<typename T, int arr_size>
class Queue
{
public:
    Queue();
    Queue(const Queue<T, arr_size>& q);
    //~Queue();

    unsigned int get_max_size() const;
private:
    T* _arr_ptr;
    unsigned int _max_size;
};

template<typename T, int arr_size>
Queue<T, arr_size>::Queue()
    : _arr_ptr(new T[arr_size])
    , _max_size(arr_size)
{}

template<typename T, int arr_size>
Queue<T, arr_size>::Queue(const Queue<T, arr_size>& q)
{
    T* new_arr = new T[_max_size];
    for (int i = 0; i < _max_size; i++)
    {
        new_arr[i] = *_arr_ptr[i];
    }
}
template<typename T, int arr_size>
unsigned int Queue<T, arr_size>::get_max_size() const
{
    return _max_size;
}

int main()
{
    Queue<int, 30> q;
    Assert(q.get_max_size() == 30);
    return 0;
}
