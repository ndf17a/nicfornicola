#include <cstddef>

template <typename T>
struct Set
{
    T* data;
    int size;        
    int count;
};
	
template <typename T>
void initialize(Set<T> &set)
{
	set.size = 2;
	set.data = new T[set.size];
	set.count = 0;
}

template <typename T>
void destroy(Set<T> &set)
{
	//make everything zero and deallocate the dynamicoly allocated array
    delete [] set.data;
	set.data = NULL;
	set.size = 0;
	set.count = 0;	
}

template <typename T>
bool isEmpty(Set<T> set)
{
	//if the count is 0 then there are no items in the array... its empty
	return (set.count == 0);
}

template <typename T>
int getSize(Set<T> set)
{
	//checks what index is count at
	return set.count;
}

template <typename T>
bool contains(Set<T> set, T value)
{
	//goes through array and	checks if value is equal too what is in array 
	//if value is already in array do return true else return false
	for( int i = 0; i < set.count; i++)
		if(value==set.data[i])
			return true;
	return false;
}

template <typename T>
void remove(Set<T> &set, T value)
{
	for(int i = 0; i < set.count; i++)
		if(value == set.data[i])
		{
			//move the last one to the space where the removed value was
			set.data[i]=set.data[set.count-1];
			set.count--;
		}
}

template <typename T>
void insert(Set<T> &set, T value)
{	
	//check if the value is already in array
	if(!contains(set, value))
	{
		//if not  in array and there is no more space double array with some pointer magic
		if(set.size==set.count)
		{
			T* tmp = new T[set.size*2];
			for(int i=0; i < set.size; i++)
				tmp[i] = set.data[i];

				delete [] set.data;
				set.data = tmp;
				set.size*=2;
		}
		//assign the index a value and increment count
		set.data[set.count++] = value;
	}
}

template <typename T>
Set<T> operator&&(Set<T> A,Set<T> B)  // intersection
{
	Set<T> ret;
	initialize(ret);
	//if the values are in A and B then put them in the returning set
	for(int i = 0; i < getSize(A); i++)
	{
		if(contains(B, A.data[i]))
			insert(ret, A.data[i]);
	}
	return ret;		
}

template <typename T>
Set<T> operator||(Set<T> A,Set<T> B) // union
{
	Set<T> ret;
	initialize(ret);
	//get values that are in both sets elimantes duplicates
	for(int i = 0; i < getSize(A); i++)
		insert(ret, A.data[i]);
	for(int i = 0; i < getSize(B); i++)
		insert(ret, B.data[i]);
	
	return ret;
}

template <typename T>
Set<T> operator-(Set<T> A,Set<T> B)  // difference
{
	Set<T> ret;
	initialize(ret);
	//get only the values that are one set
	for(int i = 0; i < getSize(A); i++)
		if(!contains(B, A.data[i]))
			insert(ret, A.data[i]);
		
	return ret;
}