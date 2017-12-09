#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

map <int, struct node*> m;

struct node
{
	int value;
	struct node *next;
	struct node *previous;	
};


void print(struct node *root) 
{
	struct node *first = root;
	cout << "Printing --> ";
	while (root != NULL) {
		cout << root->value << " ";
		root = root -> next;
		if (root == first) break;
	}
	cout << endl;
}

void removefirst(struct node **root)
{
	(*root) -> next -> previous = (*root) -> previous;
	(*root) -> previous -> next = (*root) -> next;
	(*root) = (*root) -> next;
}

void del(struct node **root)
{
	if ((*root) == NULL)  {
		return;
	}
	m.erase((*root) -> value);
	if ((*root) -> next == (*root)) {
		(*root) = NULL;
		return;
	}

	removefirst(root);
}

void insertatend(struct node **root, struct node *temp)
{
	struct node *currentlast = (*root) -> previous;
	currentlast -> next = temp;
	temp -> previous = currentlast;
	temp -> next = (*root);
	(*root) -> previous = temp;
}

void insert(struct node **root, int value) 
{
	if (m.find(value) == m.end()) {
		struct node *temp = (node*)malloc(sizeof(node));
		temp -> value = value;
		temp -> next = temp;
		temp -> previous = temp;
		m[value] = temp;

		if ((*root) == NULL) {
			(*root) = temp;
			return;
		}	

		if ((*root) -> next == (*root)) {
			(*root) -> next = temp;
			temp -> previous = (*root);
			(*root) -> previous = temp;
			temp -> next = (*root);
			return;
		}

		insertatend(root, temp);
		return;
	}

	if ((*root) -> next == (*root)) {
		return;
	}
	struct node *nodeposition = m[value];
	if (nodeposition == (*root)) {
		removefirst(root);
		struct node *currentlast = (*root) -> previous;
		currentlast -> next = (nodeposition);
		(nodeposition) -> previous = currentlast;
		(nodeposition) -> next = (*root);
		(*root) -> previous = (nodeposition);
		return;
	}

	if ((*root) -> previous == nodeposition) {
		return;
	}

	nodeposition -> previous -> next = nodeposition -> next;
	nodeposition -> next -> previous = nodeposition -> previous;
	insertatend(root, nodeposition);

}

int main()
{
	struct node *root = NULL;
	while(1) {
		int op;
		cin >> op;
		if (op == 1) {
			del(&root);
		} else {
			int value;
			cin >> value;
			insert(&root, value);
		}
		print(root);
	}
	return 0;
}