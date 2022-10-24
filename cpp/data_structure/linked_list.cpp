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
	class Iterator
	{
	friend class LinkedList;
	public:
		Iterator next() {
			_cursor = _cursor->next;
			return *this;
		}
		Iterator prev() {
			_cursor = _cursor->prev;
			return *this;
		}
		T& operator*() const {
			return _cursor->data;
		}

		bool operator!=(const Iterator& itr) const {
			return _cursor != itr._cursor;
		}

		Iterator operator++(int) {
			Iterator tmp = *this;
			_cursor = _cursor->next;
			return tmp;
		}
	private:
		Iterator(struct Node<T>* node) : _cursor(node) {}
	private:
		struct Node<T>* _cursor;
	};

	LinkedList();
	//LinkedList(const LinkedList& l);
	~LinkedList();

	T front() const;
	T back() const;

	void remove(const unsigned int idx);

	void push_front(const T data);
	void push_back(const T data);

	T pop_front();
	T pop_back();

	Iterator begin() const;
	Iterator end() const;
	//Iterator insert(Iterator position, const T data);

	unsigned int get_size() const;
	bool is_empty() const;
	void clear();
private:
	struct Node<T>* _create_node(T data);
private:
	struct Node<T>* _head;
	struct Node<T>* _tail;
	unsigned int _size;
};

template<typename T>
LinkedList<T>::LinkedList()
	: _head(nullptr)
	, _tail(nullptr)
	, _size(0)
{}

template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

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

//template<typename T>
//struct Node<T>* LinkedList<T>::begin() const
//{
//	Assert_msg(!is_empty(), "List is empty!");
//
//	return _head;
//}

//template<typename T>
//struct Node<T>* LinkedList<T>::Iterator::end() const
//{
//	Assert_msg(!is_empty(), "List is empty!");
//
//	return _tail;
//}

template<typename T>
void LinkedList<T>::remove(const unsigned int idx)
{
	Assert_msg(!is_empty(), "List is empty!");
	Assert_msg(_size > idx, "Out of index!");

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
void LinkedList<T>::push_front(const T data)
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
void LinkedList<T>::push_back(const T data)
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
typename LinkedList<T>::Iterator LinkedList<T>::begin() const
{
	return Iterator(_head);
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const
{
	return Iterator(_tail);
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
struct Node<T>* LinkedList<T>::_create_node(const T data)
{
	struct Node<T>* new_node = new struct Node<T>;
	new_node->prev = nullptr;
	new_node->next = nullptr;
	new_node->data = data;

	return new_node;
}

int main()
{
	//LinkedList<int> l;
	//Assert(l.is_empty());
	//Assert(l.get_size() == 0);
	//l.push_back(0);
	//l.push_back(1);
	//l.push_back(2);
	//Assert(!l.is_empty());
	//Assert(l.get_size() == 3);
	//Assert(l.front() == 0);
	//Assert(l.back() == 2);
	//Assert(l.begin()->data == 0);
	//Assert(l.end()->data == 2);
	//l.remove(0);
	//Assert(l.get_size() == 2);
	//Assert(l.front() == 1);
	//Assert(l.begin()->data == 1);

	//l.clear();
	//Assert(l.is_empty());
	//Assert(l.get_size() == 0);

	//l.push_front(0);
	//l.push_front(1);
	//l.push_front(2);
	//Assert(l.get_size() == 3);
	//Assert(l.front() == 2);
	//Assert(l.begin()->data == 2);
	//Assert(l.end()->data == 0);
	//Assert(l.pop_front() == 2);
	//Assert(l.pop_back() == 0);
	//Assert(l.get_size() == 1);
	//Assert(l.begin()->data == 1);
	//Assert(l.end()->data == 1);

	LinkedList<int> l;
	l.push_back(0);
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	//LinkedList<int>::Iterator itr = l.begin();
	//std::cout << *itr.next().next().prev() << std::endl;

	for (auto it = l.begin(); it != l.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}
