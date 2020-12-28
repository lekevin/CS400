#include <iostream>

using std::cout;
using std::endl;

struct Node {
public:
	int data;
	Node* next;
	Node(int data) : data{ data }, next{ nullptr } {}	//inline function
};

//create another name for Node* for convenience
typedef Node* NodePtr;


//add at head
void add_at_head(const NodePtr& head, int value) {
	NodePtr newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

//add at tail

//traverse
void traverse(const NodePtr) {
	NodePtr temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;		//IMPORTANT: this is the way to go to next node.
	}
	cout << endl;
}

bool deleteNode(struct Node **head, Node *ptrDel) {
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	
	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

int main()
{
	Node* head = nullptr;

	//manually create a linked list
	head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(25);
	head->next->next->next = new Node(44);


	//Systematically
	add_at_head(head, 44);
	add_at_head(head, 25);
	add_at_head(head, 20);
	add_at_head(head, 10);

	traverse(head);





}
