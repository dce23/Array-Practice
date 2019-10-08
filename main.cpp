#include<iostream>
using namespace std;

int main() {
	//Static Array Lists
	const int SIZE = 100;
	int DataArr[SIZE];
	int counter = 0;
	int newData = 0;	//For Insert
	
	//Insert Front of Static Array
	if (counter < SIZE) {
		for (int i = counter; i >= 0; i--) {
			DataArr[i] = DataArr[i - 1];
		}
		DataArr[0] = newData;
		counter++;
	}

	//Insert Back of Static Array
	if (counter < SIZE) {
		counter++;
	}
	DataArr[counter] = newData;

	//Delete Front of Static Array
	if (counter > 0) {
		for (int i = 0; i < counter; i++) {
			DataArr[i] = DataArr[i + 1];
		}
		counter--;
	}

	//Delete Back of Static Array
	if (counter > 0) {
		counter--;
	}


	/**************************************
	Dynamic Array Lists
	**************************************/
	int *dataArr = 0;
	int Count = 0;
	int newdata = 0;	//To Insert

	//Insert Front of Dynamic Array
	int *a = new int[Count + 1];
	for (int i = 0; i < Count + 1; i--) {
		a[i] = dataArr[i - 1];

		a[0] = newdata;
		Count++;
		delete[]dataArr;
		dataArr = a;
	}

	//Insert Back of Dynamic Array
	int *newArr;
	newArr = new int[Count + 1];

	for (int i = 0; i < Count; i++) {
		newArr[i] = dataArr[i];
	}

	newArr[Count] = newdata;
	Count++;
	delete[] dataArr;
	dataArr = newArr;

	//Delete Front of Dynamic Array
	if (Count > 0) {
		int *temp = new int[Count - 1];

		for (int i = 1; i < Count; i++) {
			temp[i - 1] = dataArr[i];
		}
		delete[] dataArr;
		dataArr = temp;
		Count--;
	}

	//Delete Back of Dynamic Array
	if (Count > 0) {
		Count--;
		int *temp = new int[Count];

		for (int i = 0; i <= Count; i++) {
			temp[i] = dataArr[i];
		}
		
		delete[] dataArr;
		dataArr = temp;
	}


	/**************************************
	Linked Lists
	**************************************/
	struct Node
	{
		int data;
		Node* next;
	};

	Node *Head = 0;		//Points to the first Node
	int new_data = 0;	//To Insert

	/*
	Assume a list is already created where Head points to the first node.
	The last node has the next pointer equal to NULL.
	

	//For Deleting Empty List
	if (Head == NULL) {
		return -1;			//Empty
	}*/

	//Insert Front of Linked List
	Node *temp = new Node;
	temp->data = new_data;

	if (Head == NULL) {
		Head = temp;
		temp->next = NULL;
	}

	temp->next = Head;
	Head = temp;

	//Delete Front of Linked List
	Node *Temp;

	if (Head != NULL) {
		Temp = Head;
		Head = Head->next;
		delete Temp;
	}

	//Insert Back of Linked List
	Node * tempa = new Node;
	Node *curr = new Node;
	tempa->data = new_data;
	tempa->next = NULL;

	if (Head = NULL) {
		Head = tempa;
	}
	else {
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		tempa->next = curr;
		curr->next = tempa;
		tempa->next = NULL;
	}

	//Delete Back of Linked List
	if (Head != NULL) {
		Node *cur = Head;
		if (Head->next != NULL) {
			while (cur->next->next != NULL)
			{
				cur = cur->next;
			}
			Node *t = cur->next;
			if (t != NULL) {
				delete t;
				cur->next = NULL;
			}
		}
		else {
			delete Head->next;
			Head->next = NULL;
		}
	}

	return 0;
}