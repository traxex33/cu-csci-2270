/*
	Trees
	=====

	Each node has one parent and multiple children.
	Create a hierarchical structure

	Binary trees
	------------
	Each node has upto 2 children
	Each node has 3 pointers (to nodes of same type)
	- parent
	- left child
	- right child
	Top of the tree is the root => parent of root = NULL
	If node doesn't have left child, that pointer is NULL
	If node doesn't have right child, that pointer is NULL

	struct node{
	int key;
	node* parent;
	node* left;
	node* right;
	};

	Finding the bottom of the tree:
	-------------------------------
	Search tree by traversing each branch until we reach bottom of that branch
	When left == NULL, no more nodes in that branch. Same for right == NULL

	Subtrees
	--------
	Each tree is defined by subtrees

	Self-similarity: An object is similar to a part of itself
	Computationally we can examine smaller and smaller subtrees

	Recurisve structure: A structure that is defined in terms of itself
	Recursive algorithm: An algorithm that calls itself on smaller units until smallest case can be reached

	Printing nodes in binary tree
	-----------------------------

	void printNode(node *n){
	cout << n->key << endl;
	if (n->left != NULL) {
	printNode(n->left);
	}
	if (n->right != NULL) {
	printNode(n->right);
	}
	return;
	}

*/

/*
	Recursion
	=========
	- Base case - no further recursive calls
	- Reduce all cases to base case

	Binary Search Trees (BST)
	=========================
	- Special binary tree
	- for any node in a tree:
	nodes in left sub-tree will have values lesser than that node
	nodes in right sub-tree will have values greater than or equal to that node
	- Tree is constructed as data is read ~ same data in different order can generate different trees ~ tree balancing

	Building BST
	------------
	Ex: 4, 2, 6, 9, 1, 3
	4
	 2	   6
		 1   3	 9

	If built correctly, data can be retrieved quickly

	Operations on BST
	-----------------
	- Inserting new node
	- Search for value / node
	- Delete node
	- Print contents of tree

	1. Inserting new node
	---------------------

	void insert(value) {									//node information
	node* parent = NULL;
	node* temp = root;									//root is a known property
	node* n = new Node(value, NULL, NULL, NULL);		//(key, parent, left, right)
	while (temp != NULL) {								//find where node is to be placed
	parent = temp;
	if (n->key < temp->key) {
	temp = temp->left;
	}
	else {
	temp = temp->right;
	}
	}
	if (parent == NULL) {								//tree is empty
	root = n;
	}
	else if (n->key < parent->key) {
	parent->left = n;
	n->parent = parent;
	}
	else {
	parent->right = n;
	n->parent = parent;
	}
	}

	2. Search BST
	-------------

	a. Iterative:

	node* search(searchKey) {
	node* n = root;
	while (n != NULL) {						//go through the tree
	if (n->key > searchKey) {
	n = n->left;
	}
	else if (n->key < searchKey) {
	n = n->right;
	}
	else {								//value is found
	return n;
	}
	}
	return NULL;
	}

	b. Recursive:
	Call search on left or right child until node is found or we get to NULL

	node* search(n, searchKey) {
	if (n == NULL || n->key == searchKey) {
	return n;
	}
	else if (n->key > searchKey) {
	return search(n->left, searchKey);
	}
	else {
	return search(n->right, searchKey);
	}
	}

	3.Deleting node
	---------------
	Remove node
	Find replacement (child needs new parent and parent needs new child)
	Update parent and child pointers

	Cases:
	1. Node has no children
	2. Node has one child
	3. Node has two children

	delete(value) {
	node* n = search(value);								//return pointer to node to delete

	if (n != root) {

	//no children
	if (n->left == NULL && n->right == NULL) {			//no children
	if (n == n->parent->left) {
	n->parent->left = NULL;
	}
	else if (n == n->parent->right) {
	n->parent->right = NULL;
	}
	delete n;
	}
	/end no children

	//two children
	else if (n->left != NULL && n->right != NULL) {		//two children
	//Replacement is minimum value in the right subtree
	//Find minimum value in right subtree
	node* min = treeMinimum(n->right);

	//if min is right child
	if (min == n->right) {
	if (n == n->parent->left) {					//other case to consider is right child
	n->parent->left = min;
	min->parent = n->parent;
	min->left = n->left;
	min->left->parent = min;
	}
	if (n == n->parent->right) {
	n->parent->right = min;
	min->parent = n->parent;
	min->left = n->left;
	min->left->parent = min;
	}
	}

	//if min is not right child ~ further down the right subtree
	else {
	//put the right child of min to min's parent
	min->parent->left = min->right;
	min->right->parent = min->parent;
	//put min to n's parent
	min->parent = n->parent;
	min->parent->left = min;
	//put min in place of n
	min->left = n->left;
	min->right = n->right;
	n->right->parent = min;
	n->left->parent = min;
	}

	delete n;
	}
	//end two children

	//one child
	else {												//one child
	if (n == n->parent->left) {
	if (n->left != NULL) {
	node* x = n->left;
	n->parent->left = x;
	x->parent = n->parent;
	delete n;
	}
	else if (n->right != NULL) {
	node* x = n->right;
	n->parent->left = x;
	x->parent = n->parent;
	delete n;
	}
	}
	else if (n == n->parent->right) {
	if (n->left != NULL) {
	node* x = n->left;
	n->parent->right = x;
	x->parent = n->parent;
	delete n;
	}
	else if (n->right != NULL) {
	node* x = n->right;
	n->parent->right = x;
	x->parent = n->parent;
	delete n;
	}
	}
	}
	}
	//end one child

	//need to set a root with parent = NULL
	else {

	if (n->left == NULL && n->right == NULL) {			//no children

	}

	else if (n->left != NULL && n->right != NULL) {		//two children

	}

	else {												//one child

	}
	}
	}

	//find minimum value of tree where q is the root
	node* treeMinimum(node* q){
	node* x = q;
	while (x->left != NULL) {
	x = x->left;
	}
	return x;
	}

*/

/*
	Design a recursive algorithm that only searches branches where a value in given range could exist
	-------------------------------------------------------------------------------------------------

	Cases to consider
	 - node is in range => left and right children could also be in range => check those
	 - node value > high value => left child could be in range => check those
	 - node value < low value => right child could be in range => check those

	 void checkNode(Node* n, int low, int high){
		if (n != NULL){
			if (n->key >= low && n->key <= high){
				checkNode(n->left, low, high);
				cout << n->key << endl;
				checkNode(n->right, low, high);
			}
			else if (n->key < low){
				checkNode(n->right, low, high);
			}
			else if (n->key > high) {
				checkNode(n->left, low, high);
			}
		}
	 }

*/
