#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

typedef Node* NodePtr;

void in_order{ NodePtr p } {
	if (p) {
		in_order(p->left);
		cout << p->val << " ";
		in_order(p->right);
	}
}


//NodePtr root = nullptr;
//insert1(root, value);

void insert1(NodePtr& p, int newValue) {
	if (!p) {
		p = new Node(newValue);
		return;
	}

	if (p->val < newValue)
		insert1(p->right, newValue);
	else if (p->val > newValue)
		insert1(p->left, newValue);

	//when newValue == val, return implicitly
	return;
}



//this function will insert a node to the given tree
//to call mind the return val
//Node *root = nullptr;
//root = insert2(root, 10);
//root = insert2(root, 20);
NodePtr insert2(NodePtr p, int newValue) {
	if (!p)
		return new Node(newValue);

	if (p->val < newValue)
		p->right = insert2(p->right, newValue); //need to take care of left right child addr properly
	else if (p->val > newValue)
		p->left = insert2(p->left, newValue);

	return p;
}



bool search1()(NodePtr p, int target){
	if (!p)
		return false;

	if (p->val < target)
		return search1(p->right, target);	//search result for 5 on the whole BST relies on result
	else if (p->val > target)
		return search1(p->left, target);

	//matching condition
	return true;
}

NodePtr search2(NodePtr p, int target) {
	if (!p)
		return nullptr;

	if (p->val < target)
		return search2(p->right, target);
	else if (p->val > target)
		return search2(p->left, target);

	//matching condition
	return p;
}

//helper func for del node
int largestleft(NodePtr p)


void deleteTree(node* node)
{
	if (node == NULL) return;
	deleteTree(node->left);
	deleteTree(node->right);
	cout << node->data;
	delete node;
}









//root = del (root, 100);


NodePtr del(NodePtr& p, int target) {
	//target not found (including empty tree)
	if (!p) {
		cerr << "Target not found. " << endl;
		return p;
	}

	if (target < p->val)
		p->left = del(p->left, target);
	else if (target > p->val)
		p->right = del(p->right, target);
	else { //we are on the node to be deleted: three cases"
	
		//case 1: the node is a leaf node.
		if (p->left == nullptr && p->right == nullptr) {
			delete p;
			return nullptr;
		}

		//case 2: the node has one child node.
		if (p->left == nullptr) {     //has only right child
			Node* temp = p->right;
			delete p;
			return temp;
		}
		if (p->right == nullptr) {	  //has onLy left child
			Node* temp = p->left;
			delete p;
			return temp;
		}

		//case 3: the node has two child nodes
		
		p->val = largestleft(p->left);
		p->left = del(p->left, p->val);
	}

	return p;
}





int main()
{
	vector<int> vec = { 11, 6, 8, 19, 4, 10, 5, 17, 43, 49, 3 };

	NodePtr bst = nullptr;

	for (auto i : vec) {
		bst = insert2(bst, i);
		in_order(bst); cout << endl;
	}


	//cout << search1(bst, 5) << endl;

	//cout << search1(bst, 18) << endl;

}