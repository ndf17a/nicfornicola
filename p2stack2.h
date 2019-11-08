#include <cstddef>

template <typename T>
struct Node {
	T value;
	Node<T>* next;
};

template <typename T>
struct Stack {
	Node<T>* top;
};

template <typename T>
void initialize(Stack<T> &s)
{
	//start the list at NULL because if it is NULL its empty
	s.top = NULL;
}

template <typename T>
void destroy(Stack<T> &s)
{
	//make new pointer to put to top that goes through the list
	//make hold each time cat != NULL move cat then delete hold
	Node<T>* cat = s.top;
	while(cat != NULL)
	{
		Node<T>* hold = cat;
		cat = cat->next;
		delete hold;
	}	
}

template <typename T>
T isEmpty(Stack<T> &s)
{
 return(s.top == NULL);
}

template <typename T>
T pop(Stack<T> &s)
{
	//get the first value into a variable then make s.top point to next in list making it the first
	//return the value that
	T ret = s.top->value;
	Node<T>* hold = s.top;
	s.top = s.top->next;
	delete hold;
	return ret;
}

template <typename T>
void push(Stack<T> &s, T v)
{
	//make add, point add to the old top then make s.top point to the newest value, then put the value in to the node
	Node<T>* add = new Node<T>;
	add = s.top; 
	s.top = add;
	s.top->value = v;
}
