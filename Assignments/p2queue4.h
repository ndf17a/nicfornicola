#include <cstddef>

template <typename T>
struct Queue {
    T*  data;	// array of values
    int size;	// size of data array
    int head;	// index from which the next value will be read (on Pop)
    int tail;	// index at which the next value will be written (on Push)
};

template <typename T>
void initialize(Queue<T> &q)
{
	//make everything 0 and size starts at 2
	q.size = 2;
	q.head = 0;
	q.tail = 0;
	q.data = new T [2];
}
template <typename T>
void destroy(Queue<T> &q)
{
	//make everything 0 and delete the array and point data to null
	q.size = 0;
	q.head = 0;
	q.tail = 0;
	delete [] q.data;
	q.data = NULL;
}
template <typename T>
int  getSize(Queue<T> q)
{
	//find difference of head and tail depending on which is bigger
	return (q.head > q.tail) ? q.size-(q.head-q.tail) : q.tail-q.head;
}

template <typename T>
bool isEmpty(Queue<T> q)
{
	//if they are equal its empty
	return q.head==q.tail;
}

template <typename T>
T    pop(Queue<T> &q)
{
	//pop from tail and increment head, wrap head if needs to be 
	T popped = q.data[q.head++];	
	q.head %= q.size;
	return popped;
}

template <typename T>
void push(Queue<T> &q, T value)
{
	q.data[q.tail] = value;

	//check if full
	if((q.tail+1) % q.size == q.head)
	{	
		//allocate new array
		T* tmp = new T[q.size*2];
		//set both arrays equal
		for(int i=0; i < q.size; i++)
			tmp[i] = pop(q);
		q.head = 0;
		q.tail = q.size-1;
		q.size *= 2;
		//deallocate the old array and sets data pointer to tmp which is the new and bigger array
		delete [] q.data;
		q.data = tmp;
		
	}	
	q.tail=(q.tail+1)%q.size;
}

