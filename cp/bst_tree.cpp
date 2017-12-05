#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	struct node *left;
	struct node *right;
	int value;
};

struct node* insert(struct node *head, int value) {
	if (head == NULL) {
		head = (node*) malloc (sizeof(node));
		head -> value = value;
		head -> left = NULL;
		head -> right = NULL;
		return head;
	}

	if (value < head -> value) {
		head -> left = insert(head -> left, value);
	} else {
		head -> right = insert(head -> right, value);
	}
	return head;
}

bool is_in_tree(struct node *head, int value) {
	if (head == NULL) {
		return false;
	}
	if (head -> value == value) {
		return true;
	}
	if (head -> value > value) {
		return is_in_tree(head -> left, value);
	}
	return is_in_tree(head -> right, value);
}

void inorder(struct node *head) {
	if (head == NULL) {
		return;
	}
	inorder(head -> left);
	cout << head -> value << " ";
	inorder(head -> right);
}

int main() {
	struct node *head = NULL;
	int a[10] = {32, 13, 23, 20, 30, 0, 1, 99, 10, 2};

	for (int i = 0; i < 10; i++) {
		head = insert(head, a[i]);
	}

	cout << "Inorder traversal" << endl;
	inorder(head);
	cout << endl;

	cout << "Is 20 present in BST: " << is_in_tree(head, 20) << endl;
	cout << "Is 21 present in BST: " <<  is_in_tree(head, 21) << endl;
}