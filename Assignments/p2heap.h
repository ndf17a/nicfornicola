#include <cstddef>

const int HEAPSIZE = 128;

template <typename T>
struct Heap 
{
	T  data[HEAPSIZE];
	int size;
};
    
template <typename T>
void initialize(Heap<T>& h)
{
	h.size = 0;
}

template <typename T>
void destroy(Heap<T>& h)
{
	h.size = 0;
}

template <typename T>
void put(Heap<T>& h, T input)
{
	//make size +1
	h.size++;
	//input the into the next open spot
	h.data[h.size] = input;
	
	for( int i = h.size; i != 1 && input < h.data[i/2]; i/=2)
	{
		h.data[i] = h.data[i/2];
		h.data[i/2] = input;
	}
	

}

template <typename T>
T    get(Heap<T>& h)
{
	//get the root value
	T ret = h.data[1];
	
	//start index at root
	int index = 1;
	
	//make root the last value 
	h.data[1] = h.data[h.size--];

	T temp; 
	//while the index is less the size their is atleast a left child
	while(index * 2 <= h.size)
	{
		// make left and right variables
		int left = (index * 2 < h.size) ? h.data[index * 2] : h.data[index];
		int right = (index * 2 + 1 < h.size) ? h.data[index * 2 + 1] : h.data[index];

		//if left < right swap them
		if(left <= right && left < h.data[index])
		{
			temp = h.data[index];
			h.data[index] = h.data[index * 2];
			h.data[index * 2] = temp;
			index *= 2;
		}
		// if right < left swap
		else if(right <= left && right < h.data[index])
		{
			temp = h.data[index];
			h.data[index] = h.data[index * 2 + 1];
			h.data[index * 2 + 1] = temp;
			index = index * 2 + 1;
		}
		else 
			break;
		
	}
	return ret;
}

template <typename T>
bool isEmpty(Heap<T> h)
{
	return h.size == 0;
}