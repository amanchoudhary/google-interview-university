#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
	int value;
	struct node *next;
};

struct node *head = NULL;


void print_linked_list(struct node *root) {
	while (root != NULL) {
		cout << root -> value << " ";
		root = root -> next;
	}
	cout << endl;
}


int get_size(struct node *root) {
	int sum = 0;
	while (root != NULL) {
		root = root -> next;
		sum += 1;
	}
	return sum;
}

void insert(struct node **root, int value, int position) 
{
	struct node *temp = (node*) malloc (sizeof(node));
	temp -> value = value;
	temp -> next = NULL;

	if (position == 0) {
		temp -> next = (*root);
		(*root) = temp;
		return;
	}

	struct node *now = (*root);
	for (int i = 0; i < position - 1; i++) {
		now = now -> next;
	}
	temp -> next = now -> next;
	now -> next = temp;
}

struct node* reverse_linked_list(struct node *head) 
{	
	struct node *previous = NULL;

	while (head != NULL) {
		struct node *next = head -> next;
		head -> next = previous;
		previous = head;
		head = next;
	}
	return previous; 
}


void remove(struct node **head, int position) 
{
	if (position == 0) {
		(*head) = (*head) -> next;
		return;
	}

	struct node *temp = (*head);
	for (int i = 0; i < position - 1; i++) {
		temp = temp -> next;
	}

	temp -> next = temp -> next -> next;	
}

int main() 
{
	head = (node*) malloc (sizeof(node));
	head -> value = 5;
	head -> next = NULL;

	print_linked_list(head);
	cout << "Size now: " << get_size(head) << endl;

	for (int i = 0; i < 2; i++) {
		insert(&head, i, 0);
	}

	print_linked_list(head);
	for (int i = 0; i < 5; i++) {
		print_linked_list(head);
		cout << "Inserting at position: " << i << " with value : " << 2 * i << endl;
		int value = 2 * i;

		insert(&head, value, i);
	}
	print_linked_list(head);


	int size = get_size(head);
	insert(&head, 10000, size);
	print_linked_list(head);

	cout << " --------------- reverse -------------------------- " << endl;
	head = reverse_linked_list(head);
	print_linked_list(head);

	cout << " --------------------------------------------------------------------- " << endl;
	for (int i = 0; i < 5; i++) {
		print_linked_list(head);
		cout << "Removing at position: " << i << endl;
		remove(&head, i);
	}
	print_linked_list(head);

	return 0;
}