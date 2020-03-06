#include <cstddef>

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node<K,V>* next;
};

template <typename K, typename V>
struct Map {
    Node<K,V>** table;
    int size;
};

int hash(int key, int size) 
{
    return key % size;
}

int hash(char key, int size)
{
    return key % size;
}
  
template <typename K, typename V>  
void initialize(Map<K,V>& map, int n)
{
	//make new node pointer array
	map.table = new Node<K,V>*[n];
	
	//make all the pointers point to NULL
	for(int i =0; i < n; i++)
		map.table[n] = NULL;
	map.size = n;
}

template <typename K, typename V>  
void destroy(Map<K,V>& map)
{
	// go through the link list with size
	for(int i = 0; i < map.size; i++)
	{
		Node<K,V>* walker = map.table[i];
		while(walker != NULL)
		{
			//make temp equal to walker then move walker, delete temp
			Node<K,V>* temp = walker;
			walker = walker->next;
			delete temp;
		}
		//after evething is deleted make table null because the list is empty
		map.table = NULL;
	}
	
}

template <typename K, typename V>  
void assign(Map<K,V>& map, K key, V value)
{
	//make hash for indexing
	int i = hash(key, map.size);
	
	//walker = the table[ hash ]
	Node<K,V>* walker = map.table[i];
	
	//go through the link list until NULL
	while(walker != NULL)
	{
		//if key is found reassign the value to new value
		if( walker-> key == key)
		{
			walker-> value = value;
			return;
		}
		// else move to next
		walker = walker -> next;
	}
	// go through list till NULL, make new node and assign the fields to the sent up data making this nodes next null
	walker = map.table[i];
	while(walker -> next != NULL)
		walker = walker -> next;
	
	walker-> next = new Node<K,V>; 
	walker-> key = key;
	walker-> value = value;
	walker-> next = NULL;
	
}

template <typename K, typename V>  
void remove(Map<K,V>& map, K key)
{
	//make hash for indexing
	int i = hash(key, map.size);
	
	Node<K,V>* walker = map.table[i];
	
	//if the link list first value is being removed make the hashtable
	//pointer point to the second in the link list
	if(map.table[i] -> key == key)
	{
		map.table[i] = map.table[i] -> next;
		delete walker;
	}
	else 
	{
		//check for the key in the next node
		while( walker -> next -> key == key)
		{
			walker = walker -> next;
			
			//make temp to delete later and set equal to walker -> next
			Node<K,V>* temp = walker -> next;
			//make walker -> nezt point 2 more
			walker -> next = walker -> next -> next;
			delete temp;
			
		}
		
	}
	
}

template <typename K, typename V>  
bool has_key(Map<K,V> map, K key)
{
	//make hash for indexing
	int i = hash(key, map.size);
	
	//walker equal the the table index
	Node<K,V>* walker = map.table[i];
	while(walker != NULL)
	{
		//if the key is found then return true if not return false
		if( walker -> key == key)
		{
			return true;
			walker = walker -> next;
		}
	}
	return false;
	
}

template <typename K, typename V>  
V    lookup(Map<K,V> map, K key)
{
	//make i equal to hash for indexing
	int i = hash(key, map.size);
	Node<K,V>* walker = map.table[i];
	
	while(walker != NULL)
	{
		//if the key is already their return the value
		if(walker -> key == key)
			return walker -> value;
		walker = walker -> next;
	}
	//should never reach this 
	return walker->value;
	
}