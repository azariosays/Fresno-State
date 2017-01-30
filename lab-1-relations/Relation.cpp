#include <iostream>
#include "Relation.h"
using namespace std;

List::List() {
	//default constructor
	this->head = NULL;
	this->length = 0;

}

bool List::lookup(int e) {
	// is e in the list?

	Node *p = head;

	while (p) {

		if (p->value == e)
			return true;

		p = p->next;
	}

	return false;
}

void List::cons(int e) {
	// add e to beginning of list

	Node *newNode = new Node();
	newNode->value = e;
	newNode->next = this->head;
	this->length++;

	this->head = newNode;
}


Relation::Relation(int n) {
	//constructor (assumes n > 0)
	this->nelts = n;
	this->succs = new List[n];
}

int Relation::num_elts() {
	// number of elements

	return this->nelts;
}

int Relation::num_pairs() {
	// number of pairs

	return this->npairs;
}

int Relation::num_succs(int e) {
	// number of successors of e

	return this->succs[e].length;
}

void Relation::insert_pair(int e1, int e2) {
	// insert pair (e1, e2)

	//Check for invalid input values
	if (e1 >= this->nelts || e1 < 0
		|| e2 >= this->nelts || e2 < 0) {
		cerr << "Error: non-existent element(s)\n";
		return;
	}

	//Check if this pair already exists
	if (this->succs[e1].lookup(e2)) {
		return;
	}

	this->succs[e1].cons(e2);
	this->npairs++;
}

void Relation::list_pairs() {
	// list all pairs in the relation

	cout << "Pairs: ";

	for (int i = 0; i < this->nelts; i++) {

		Node *p = this->succs[i].head;


		while (p) {

			cout << "(" << i << ", " << p->value << ") ";
			p = p->next;
		}
	}

	cout << endl;
}

void Relation::list_succs(int e) {
	// list all successors of e

	if (e >= this->nelts || e < 0) {
		cerr << "Error: non-existent element(s)\n";
		return;
	}

	Node *p = this->succs[e].head;

	cout << "Successors: ";

	while (p) {

		cout << p->value << " ";

		p = p->next;
	}

	cout << endl;
}

void Relation::list_preds(int e) {
	// list all predecessors of e

	if (e >= this->nelts || e < 0) {
		cerr << "Error: non-existent element(s)\n";
		return;
	}

	cout << "Predecessors: ";

	for (int i = 0; i < this->nelts; i++) {

		if (this->succs[i].lookup(e)) {
			cout << i << " ";
		}

	}

	cout << endl;
}
