#include <cstddef>

template <typename T>
struct Node {
	T data;         // Data held at this node in tree
	Node<T>* left;  // Pointer to left child
	Node<T>* right; // Pointer to right child
};

template <typename T>
struct Tree {
	Node<T>* root; // Pointer to topmost (root) node
};

template <typename T>
void initialize(Tree<T> &t)
{
	t.root = NULL;
}

// This is the recursive destroy function, accepting a Node* argument.
template <typename T>
void destroy(Node<T>* n)
{
	if( n == NULL )
		return;
    
	destroy(n->left);  // Recursively destroy left subtree
	destroy(n->right); // Recursively destroy right subtree
	delete n;          // Delete this node
}

// This is the function called by the user, to destroy a Tree.
// It will call the recursive function, beginning with the root node.
template <typename T>
void destroy(Tree<T> &t)
{
	destroy(t.root);
	t.root = NULL;
}

template <typename T>
void insert(Tree<T> &t, T value)
{
	// Create new node to add to the tree
	Node<T>* newNode = new Node<T>;
	newNode->data  = value;
	newNode->left  = NULL;
	newNode->right = NULL;
    
	if( t.root == NULL ) 
	{ // empty tree
		t.root = newNode;
		return;
	}
        
	Node<T>* walker = t.root;
	while( true )
	{
		if( value < walker->data )
		{
			if( walker->left == NULL )
			{
				walker->left = newNode;
				return;
			}
			else
				walker = walker->left;
		}
		else // value >= walker->data
		{
			if( walker->right == NULL )
			{	
				walker->right = newNode;
				return;
			}
			else
				walker = walker->right;            
		}
	}
}

// Return depth (level) at which value appears
//    or 0 if value is not in tree
template <typename T>
int contains(Tree<T> &t, T value)
{
	Node<T>* walker = t.root;
	int depth = 1;
	while( walker != NULL )
	{
		if( walker->data == value )
			return depth;
		else if( value < walker->data )
			walker = walker->left;
		else // value >= walker->data
			walker = walker->right;
		depth++;
	}
	return 0;
}


//implement these functions
template <typename T>
int  countNodes(Tree<T> &t) 
{
	//counts all the nodes in t.root
    if(t.root == NULL)
    {
        return 0;
    }
    return countNodes(t.root);
}
template <typename T>
int  countNodes(Node<T>* &t) 
{
	//base
    if(t == NULL)
    {
        return 0;
    }
	//counts all nodes from t.root by calling the function with left and right side
    return countNodes(t->left) + countNodes(t->right) + 1;
}
template <typename T>
int  height(Tree<T> &t) 
{
    if(t.root == NULL)
    {
        return 0;
    }
	//get height from root
    return height(t.root);
}
template <typename T>
int  height(Node<T>* &t) 
{
    if(t == NULL)
    {
        return 0;
    }
	//check and compare the right and left side with ternary operator, return which ever is bigger + 1
    return 1 + ((height(t->left) > height(t->right)) ? height(t->left) : height(t->right));
}
template <typename T>
int  countLeaf(Tree<T> t) 
{
    if(t.root == NULL)
        return 0;
	//counts leaves from root
    return countLeaf(t.root);
}
template <typename T>
int  countLeaf(Node<T>* t) //counts as 1 if it is a leaf, otherwise branches out to look for a leaf, if it's NULL returns 0
{
    if(t == NULL)
        return 0;
	//checks for child on right side or left
    if(t->left != NULL || t->right != NULL)
		//if their are children still go their and check for children recursivly
        return countLeaf(t->left) + countLeaf(t->right);
	//if no children are found then return one because it is a leafe
    return 1;
}
template <typename T>
int  countDouble(Tree<T> t) 
{
    if(t.root == NULL)
        return 0;
	//count parents with exactly two children
    return countDouble(t.root);
}
template <typename T>
int  countDouble(Node<T>* t) 
{
    if(t == NULL)
        return 0;
	//make sure both children are there and return left + right + 1
    if(t->left != NULL && t->right != NULL)
        return 1 + countDouble(t->left) + countDouble(t->right);
    return countDouble(t->left) + countDouble(t->right);
}
template <typename T>
T    kthValue(Tree<T> t, int k) 
{
	//look for kth value from root
    return kthValue(t.root, k);
    
}
template <typename T>
T    kthValue(Node<T>* t, int k) 
{
	//if already at kth value return that node
    if(countNodes(t->left)+1 == k) 
        return t->data;
    else if(countNodes(t->left)+1 < k) 
		//if at the left look right for the kth
        return kthValue(t->right, k-(countNodes(t->left)+1));
    else 
		//at the right node and need to look left for kth
        return kthValue(t->left, k);
}