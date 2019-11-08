#include <cstddef>

template <typename V, typename R>
struct Node {
	V value;
	R priority;
	Node<V,R>* next;
	Node<V,R>* prev;    
};

template <typename V, typename R>
struct PriorityQueue {
	Node<V,R>* head;
};


template <typename V, typename R>
void initialize(PriorityQueue<V,R>& pq)
{
	//makes sure head is null making the PQ empty
	pq.head = NULL;
}

template <typename V, typename R>
void destroy(PriorityQueue<V,R>& pq)
{
	//node walker goes through list, delete the walker prev before reassigning walker
	Node<V,R>* walker = pq.head -> next;
	while(walker != pq.head)
	{
		delete walker -> prev;
		walker = walker -> next;
    }
    //delete walker
	delete walker;
}

template <typename V, typename R>
bool isEmpty(PriorityQueue<V,R> pq)
{
	return(pq.head == NULL);
}


template <typename V, typename R>
void push(PriorityQueue<V,R>& pq, V value, R priority)
{
	Node<V, R>* walker = pq.head;
	//check if priority is less then head
	if(priority < pq.head -> priority)
	{
		//new node point to head and head prev
		Node<V,R>* node = new Node<V,R>;
		node -> next = pq.head;
		node -> prev = pq.head -> prev;
		//make next and prev point to the new node
		node -> next -> prev = node;
		node -> prev -> next = node;
		pq.head = node;
	}
	
	while(priority >= walker -> priority && walker != pq.head)
	{
	walker = walker -> next;
	Node<V,R>* node = new Node<V, R>;
	
	node -> value = value;
	node -> priority = priority;
	node -> next = walker;
	node -> prev = walker -> prev;
	node -> next -> prev = node;
	node -> prev -> next = node;
	}
}

template <typename V, typename R>
V	 pop(PriorityQueue<V,R>& pq)
{
	//move head to next
	pq.head = pq.head -> next;
	//return the prev value
	return pq.head -> prev -> value;
}