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

void find_successor(struct node *head, int value, struct node *&successor, struct node *&predecessor) {
	if (head == NULL) {
		return;
	}

	if (head -> value == value) {
		if (head -> right != NULL) {
			struct node *temp = head -> right;
			successor = temp;
			while (temp -> left != NULL) {
				temp = temp -> left;
				successor = temp;
			}
		}

		if (head -> left != NULL) {
			struct node *temp = head -> left;
			predecessor = temp;
			while (temp -> right != NULL) {
				temp = temp -> right;
				predecessor = temp;
			}
		}

		return;
	}

	if (value < head -> value) {
		successor = head;
		find_successor(head -> left, value, successor, predecessor);
	} else {
		predecessor = head;
		find_successor(head -> right, value, successor, predecessor);
	}
}

struct node* delete_node(struct node *head, int value) 
{
	if (value < head -> value) {
		head -> left = delete_node(head -> left, value);
		return head;
	}
	if (value > head -> value) {
		head -> right = delete_node(head -> right, value);
		return head;
	}


	if (head -> left == NULL && head -> right == NULL) {
		return NULL;
	}
	if (head -> left == NULL) {
		return head -> right;
	}
	if (head -> right == NULL) {
		return head -> left;
	}
	struct node *temp = head -> right;
	while (temp -> left != NULL) {
		temp = temp -> left;
	}
	head -> value = temp -> value;
	head -> right = delete_node(head -> right, temp -> value);
	return head;
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

	cout << " --------------------------------------------------- " << endl;

	for (int i = 0; i < 10; i++) {
		struct node *successor = NULL;
		struct node *predecessor = NULL;
		find_successor(head, a[i], successor, predecessor);
		cout << "Successor of " << a[i] << " is : ";
		if (successor != NULL) {
			cout << successor -> value << endl;
		} else {
			cout << "-1" << endl;
		}


		cout << "Predecessor of " << a[i] << " is : ";
		if (predecessor != NULL) {
			cout << predecessor -> value << endl;
		} else {
			cout << "-1" << endl;
		}
	}

	cout << " --------------------------------------------------- " << endl;

	for (int i = 0; i < 10; i++) {
		cout << "Deleting node value : " << a[i] << endl;
		head = delete_node(head, a[i]);
		inorder(head);
		cout << endl;
	}

	return 0;
}