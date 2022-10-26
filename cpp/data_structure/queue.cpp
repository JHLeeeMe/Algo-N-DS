#define Assert(expression) assert(expression)
#define Assert_msg(expression, message) assert(expression && message)

#include <iostream>
#include <cassert>
#include <array>

#include "node.h"

template<typename T>
class Queue
{
public:
    Queue();
    Queue(const Queue<T>& q)=delete;
    ~Queue();

    void enqueue(T data);
    T dequeue();
    const T& peek() const;

    const unsigned int get_size() const;
    const bool is_empty() const;
    void clear();
private:
    jhleeeme::Node<T>* _create_node(T data) const;
private:
    jhleeeme::Node<T>* _front;
    jhleeeme::Node<T>* _rear;
    unsigned int _size;
};

template<typename T>
Queue<T>::Queue()
    : _front(nullptr)
    , _rear(nullptr)
    , _size(0)
{}

template<typename T>
Queue<T>::~Queue()
{
    clear();
}

template<typename T>
void Queue<T>::enqueue(T data)
{
    jhleeeme::Node<T>* new_node = _create_node(data);
    if (_size == 0)
    {
        _front = new_node;
    }
    else
    {
        new_node->prev = _rear;
        _rear->next = new_node;
    }
    _rear = new_node;
    _size++;
}

template<typename T>
T Queue<T>::dequeue()
{
    Assert_msg(_size != 0, "Queue is Empty!");

    jhleeeme::Node<T>* tmp = _front;
    T ret = tmp->data;
    _front = _front->next;
    delete tmp;
    _size--;

    return ret;
}

template<typename T>
const T& Queue<T>::peek() const
{
    Assert_msg(_size != 0, "Queue is Empty!");

    return _front->data;
}

template<typename T>
const unsigned int Queue<T>::get_size() const
{
    return _size;
}

template<typename T>
const bool Queue<T>::is_empty() const
{
    return _size == 0;
}

template<typename T>
void Queue<T>::clear()
{
    if (_size == 0)
    {
        return;
    }
    else
    {
        while (_size != 0)
        {
            jhleeeme::Node<T>* tmp = _front;
            _front = _front->next;
            delete tmp;
            _size--;
        }
    }
}

template<typename T>
jhleeeme::Node<T>* Queue<T>::_create_node(T data) const
{
    jhleeeme::Node<T>* new_node = new jhleeeme::Node<T>;
    new_node->prev = nullptr;
    new_node->next = nullptr;
    new_node->data = data;
    return new_node;
}

int main()
{
    {
        Queue<int> q;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        Assert(q.get_size() == 3);
        Assert(q.dequeue() == 10);
        Assert(q.get_size() == 2);
        Assert(q.dequeue() == 20);
        Assert(q.get_size() == 1);
        Assert(q.dequeue() == 30);
        q.enqueue(50);
        q.enqueue(100);
        q.enqueue(92);
        Assert(q.get_size() == 3);
        Assert(q.dequeue() == 50 && q.get_size() == 2);
    }
    {
        Queue<int> q;
        for (int i = 0; i < 10; i++)
        {
            q.enqueue(i);
        }
        Assert(q.get_size() == 10);
        Assert(q.dequeue() == 0);
        q.clear();
        q.clear();
        Assert(q.get_size() == 0);
        Assert(q.is_empty());
    }
    {
        Queue<int> q;
        for (int i = 0; i < 10; i++)
        {
            q.enqueue(i);
        }
        Assert(!q.is_empty());
        Assert(q.peek() == 0);
        Assert(q.peek() == 0);
        Assert(q.get_size() == 10);
    }

    return 0;
}
