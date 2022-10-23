#include <iostream>
#include <cassert>

#define Assert_msg(expression, message) assert(expression && message)
#define Assert(expression) assert(expression)

template<typename T>
struct Node
{
	Node<T>* prev;
	Node<T>* next;
	T data;
};

template<typename T>
class LinkedList
{
public:
	LinkedList();
	//LinkedList(const LinkedList& l);

	T front() const;
	T back() const;
	struct Node<T>* begin() const;
	struct Node<T>* end() const;

	//void insert(T data, unsigned int idx);
	void remove(unsigned int idx);

	void push_front(T data);
	void push_back(T data);

	T pop_front();
	T pop_back();

	unsigned int get_size() const;
	bool is_empty() const;
	void clear();
private:
	struct Node<T>* _head;
	struct Node<T>* _tail;
	unsigned int _size;

	struct Node<T>* _create_node(T data);
};

template<typename T>
LinkedList<T>::LinkedList()
	: _head(nullptr)
	, _tail(nullptr)
	, _size(0)
{}

template<typename T>
T LinkedList<T>::front() const
{
	Assert_msg(!is_empty(), "List is empty!");

	return _head->data;
}

template<typename T>
T LinkedList<T>::back() const
{
	Assert_msg(!is_empty(), "List is empty!");

	return _tail->data;
}

template<typename T>
struct Node<T>* LinkedList<T>::begin() const
{
	Assert_msg(!is_empty(), "List is empty!");

	return _head;
}

template<typename T>
struct Node<T>* LinkedList<T>::end() const
{
	Assert_msg(!is_empty(), "List is empty!");
	
	return _tail;
}

//template<typename T>
//void LinkedList<T>::insert(T data, unsigned int idx)
//{
//	Assert_msg(_size >= idx, "out of index!");
//
//	struct Node<T>* new_node = _create_node(data);
//	if (is_empty())
//	{
//		_head = new_node;
//		_tail = new_node;
//	}
//	else
//	{
//		struct Node<T>* cursor = _head;
//		for (int i = 0; i < idx - 1; i++)
//		{
//			cursor = cursor->next;
//		}
//		new_node->prev = cursor;
//		cursor->next = new_node;
//	}
//	_size++;
//}

template<typename T>
void LinkedList<T>::remove(unsigned int idx)
{
	Assert_msg(!is_empty(), "List is empty!");
	Assert_msg(_size > idx, "out of index!");

	if (_size == 1)
	{
		clear();
	}
	else
	{
		struct Node<T>* cursor = _head;
		for (int i = 0; i < idx; i++)
		{
			cursor = cursor->next;
		}

		if (idx == 0)
		{
			cursor->next->prev = nullptr;
			_head = cursor->next;
		}
		else if (idx == _size - 1)
		{
			cursor->prev->next = nullptr;
			_tail = cursor->prev;
		}
		else
		{
			cursor->prev->next = cursor->next;
			cursor->next->prev = cursor->prev;
		}
		delete cursor;
	}
	_size--;
}

template<typename T>
void LinkedList<T>::push_front(T data)
{
	struct Node<T>* new_node = _create_node(data);
	if (is_empty())
	{
		_tail = new_node;
	}
	else
	{
		new_node->next = _head;
		_head->prev = new_node;
	}
	_head = new_node;
	_size++;
}

template<typename T>
void LinkedList<T>::push_back(T data)
{
	struct Node<T>* new_node = _create_node(data);
	if (is_empty())
	{
		_head = new_node;
	}
	else
	{
		new_node->prev = _tail;
		_tail->next = new_node;
	}
	_tail = new_node;
	_size++;
}

template<typename T>
T LinkedList<T>::pop_front()
{
	Assert_msg(!is_empty(), "List is empty!");

	struct Node<T>* tmp = _head;
	T ret = tmp->data;
	_head = tmp->next;
	_head->prev = nullptr;
	delete tmp;
	_size--;

	return ret;
}

template<typename T>
T LinkedList<T>::pop_back()
{
	Assert_msg(!is_empty(), "List is empty!");

	struct Node<T>* tmp = _tail;
	T ret = tmp->data;
	_tail = tmp->prev;
	_tail->next = nullptr;
	delete tmp;
	_size--;

	return ret;
}

template<typename T>
unsigned int LinkedList<T>::get_size() const
{
	return _size;
}

template<typename T>
bool LinkedList<T>::is_empty() const
{
	return _size == 0;
}

template<typename T>
void LinkedList<T>::clear()
{
	while (_head != nullptr)
	{
		struct Node<T>* tmp = _head;
		_head = _head->next;
		delete tmp;
	}
	_size = 0;
}

template<typename T>
struct Node<T>* LinkedList<T>::_create_node(T data)
{
	struct Node<T>* new_node = new struct Node<T>;
	new_node->prev = nullptr;
	new_node->next = nullptr;
	new_node->data = data;

	return new_node;
}

int main()
{
	LinkedList<int> l;
	Assert(l.is_empty());
	Assert(l.get_size() == 0);
	l.push_back(0);
	l.push_back(1);
	l.push_back(2);
	Assert(!l.is_empty());
	Assert(l.get_size() == 3);
	Assert(l.front() == 0);
	Assert(l.back() == 2);
	Assert(l.begin()->data == 0);
	Assert(l.end()->data == 2);

	l.clear();
	Assert(l.is_empty());
	Assert(l.get_size() == 0);

	//l.insert(100, 0);


	//void insert(T data, unsigned int idx);
	//void remove(unsigned int idx);

	//void push_front(T data);
	//void push_back(T data);

	//T pop_front();
	//T pop_back();

	return 0;
}
