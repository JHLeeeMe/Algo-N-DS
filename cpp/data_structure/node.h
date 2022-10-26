namespace jhleeeme
{

template<typename T>
struct Node
{
	Node<T>* prev;
	Node<T>* next;
	T data;
};

}
