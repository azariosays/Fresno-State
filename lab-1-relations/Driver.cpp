#include <iostream>
#include "Relation.h"
using namespace std;


void selectOption(int opt, Relation &relation);
void drawMenu();
bool quit = false;

int main() {


	cout << "Enter the number of elements in the relation: ";
	int n;
	cin >> n;

	Relation relation = Relation(n);

	while (!quit) {

		//Output user menu
		cout << "Menu:" << endl;
		cout << "1: Print relation" << endl;
		cout << "2: insert pair into relation" << endl;
		cout << "3: list pairs in relation" << endl;
		cout << "4: list successors of an element" << endl;
		cout << "5: list predecessors of an element" << endl;
		cout << "6: quit" << endl;
		cout << endl;
		cout << "Choose a function (1 - 6): ";

		int opt;
		cin >> opt;

		selectOption(opt, relation);
	}


	return 0;
}

void drawMenu() {



}

void selectOption(int opt, Relation &relation) {

	if (opt == 1) {
		cout << "Relation has " << relation.num_elts() << " elements and " << relation.num_pairs() << " pairs" << endl;
	}
	else if (opt == 2) {
		cout << "Enter two elements, separated by a space: ";
		int e1, e2;
		cin >> e1 >> e2;

		relation.insert_pair(e1, e2);

	}
	else if (opt == 3) {
		relation.list_pairs();
	}
	else if (opt == 4) {
		cout << "Enter the element to list all of the successors of: ";
		int e;
		cin >> e;
		relation.list_succs(e);
	}
	else if (opt == 5) {
		cout << "Enter the element to list all of the predecessors of: ";
		int e;
		cin >> e;
		relation.list_preds(e);
	}
	else if (opt == 6) {
		quit = true;
	}
	else {
		//Invalid input
	}


}
