#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	char ch;
	int end;
	struct node *next[26];
};

struct node* create()
{
	struct node *head = (node*)malloc(sizeof(node));
	head -> end = 0;
	for (int i = 0; i < 26; i++) head -> next[i] = NULL;
	return head;
}

struct node *root;

struct node* create(struct node *root, string s, int index) 
{
	int now = s[index] - 'a';
	if (root -> next[now] == NULL) {
		root -> next[now] = create();
	}

	if (index == s.size() - 1) {
		root -> next[now] -> end = 1;
		return root;
	}

	root -> next[now] = create(root -> next[now], s, index + 1);
	return root;
}

int find(struct node *root, string s, int index) 
{
	int now = s[index] - 'a';
	if (root -> next[now] == NULL) {
		return 0;
	}

	if (index != s.size() - 1) {
		return find(root -> next[now], s, index + 1);
	}

	if (root -> next[now] -> end == 1) {
		return 1;
	}
	return 0;
}

int main() 
{
	root = create();

	root = create(root, "aman", 0);
	root = create(root, "ashika", 0);
	root = create(root, "laxmi", 0);

	cout << "Find : aman " << find(root, "aman", 0) << endl;
	cout << "Find : amaan " << find(root, "amaan", 0) << endl;
	cout << "Find : ashika " << find(root, "ashika", 0) << endl;
	cout << "Find : laxmi " << find(root, "laxmi", 0) << endl;
	cout << "Find : laxami " << find(root, "laxami", 0) << endl;


	return 0;
}