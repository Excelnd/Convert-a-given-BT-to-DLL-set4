// Convert a given BT to DLL set4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};



Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void BToDLL(Node* root, Node** head_ref)
{
	if (root == NULL)
		return;

	BToDLL(root->right, head_ref);

	root->right = *head_ref;

	if (*head_ref != NULL)

		(*head_ref)->left = root;

	*head_ref = root;

	BToDLL(root->left, head_ref);


}

void printList(Node* head)
{
	cout << "Extracted Double Linked list is:\n";
	while (head)
	{
		cout << " " << head->data;
		head = head->right;
	}
		
}

int main()
{
	Node* root = newNode(5);
	root->left = newNode(3);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->right->right = newNode(8);
	root->left->left->left = newNode(0);
	root->left->left->right = newNode(2);
	root->right->right->left = newNode(7);
	root->right->right->right = newNode(9);

	Node* head = NULL;
	BToDLL(root, &head);

	printList(head);

    return 0;
}

