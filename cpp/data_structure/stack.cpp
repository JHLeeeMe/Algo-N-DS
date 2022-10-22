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
class Stack
{
public:
	Stack();
	Stack(const Stack<T>& s);

	void push(T data);
	T pop();
	T peek() const;
	void clear();
	int get_size() const;
	bool is_empty() const;
private:
	struct Node<T>* _top;
	int _size;

	struct Node<T>* _create_node(T data);
};

template<typename T>
Stack<T>::Stack()
	: _top(nullptr)
	, _size(0)
{}

template<typename T>
Stack<T>::Stack(const Stack<T>& s)
	: _size(s._size)
{
	_top = nullptr;
	struct Node<T>* tmp = s._top;
	struct Node<T>* top_node = _create_node(tmp->data);
	tmp = tmp->prev;

	while (tmp != nullptr)
	{
		struct Node<T>* new_node = _create_node(tmp->data);
		new_node->next = top_node;
		top_node->prev = new_node;

		top_node = top_node->prev;
		tmp = tmp->prev;
	}
	_top = top_node;
}

template<typename T>
void Stack<T>::push(T data)
{
	struct Node<T>* new_node = _create_node(data);

	if (is_empty())
	{
		new_node->prev = nullptr;
	}
	else
	{
		new_node->prev = _top;
		_top->next = new_node;
	}
	_top = new_node;
	_size++;
}

template<typename T>
T Stack<T>::pop()
{
	Assert_msg(!is_empty(), "Stack is empty");

	struct Node<T>* tmp = _top;
	T ret = tmp->data;
	_top = tmp->prev;
	_size--;
	delete tmp;
	return ret;
}

template<typename T>
T Stack<T>::peek() const
{
	Assert_msg(!is_empty(), "Stack is empty");

	return _top->data;
}

template<typename T>
void Stack<T>::clear()
{
	Assert_msg(!is_empty(), "Stack is empty");

	while (_top != nullptr)
	{
		struct Node<T>* tmp = _top;
		_top = _top->prev;
		delete tmp;
	}
	_size = 0;
}

template<typename T>
int Stack<T>::get_size() const
{
	return _size;
}

template<typename T>
bool Stack<T>::is_empty() const
{
	return _size == 0;
}

template<typename T>
struct Node<T>* Stack<T>::_create_node(T data)
{
	Node<T>* node = new Node<T>;
	node->prev = nullptr;
	node->next = nullptr;
	node->data = data;
	return node;
}

int main()
{
	Stack<int> stack;

	Assert(stack.get_size() == 0);
	stack.push(0);
	Assert(stack.get_size() == 1);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	Assert(stack.get_size() == 5);

	Stack<int> tmp = stack;
	tmp.push(123);
	Assert(tmp.peek() == 123);
	Assert(tmp.get_size() == 6);

	stack.pop();
	Assert(stack.pop() == 3);
	Assert(stack.get_size() == 3);
	stack.pop();
	Assert(stack.peek() == 1);
	Assert(stack.get_size() == 2);
	stack.push(32);
	stack.clear();
	Assert(stack.get_size() == 0);
	Assert(stack.is_empty());

	tmp.push(1010);
	Assert(tmp.get_size() == 7);
	Assert(tmp.peek() == 1010);
	tmp.clear();

	return 0;
}
