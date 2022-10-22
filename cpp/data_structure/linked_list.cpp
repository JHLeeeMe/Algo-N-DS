#include <iostream>
#include <cassert>

#define Assert_msg(expression, message) assert(expression, message)
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
	LinkedList(const LinkedList& l);

	T front() const;
	T back() const;
	void insert(T data);
	void push_front();
	void push_back();
	T pop_front();
	T pop_back();
	void remove(int idx);
	int get_size() const;
	bool is_empty() const;
	void clear();
private:
	struct Node<T>* head;
	int size;

	Node<T>* _create_node(T data);
	void _insert(T data, int idx);
};

int main()
{
	return 0;
}
