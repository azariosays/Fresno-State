
//One node of a linked list
struct Node {
int value; //value stored in node
Node *next; //pointer to next node(or NULL)
};
//Linked list with cached length
struct List {
Node *head; //pointer to first node (or NULL)
int length; //number of nodes in list
List(); //default constructor
bool lookup(int e); //is in the list?
void cons(int e); //add to beginning of list
};
//Main class
class Relation {
private:
int nelts; //number of elements
int npairs; //number of pairs
List *succs; //array of successor lists

public:
Relation(int n); //constructor(assumes n>0)
int num_elts(); //number of elements
int num_pairs(); //number of pairs
int num_succs(int e); //number of successors of
void insert_pair(int e1, int e2); //insert pair (e1,e2)
void list_pairs(); //list all pairs in the relation
void list_succs(int e); //list all successors of
void list_preds(int e); //list all predecessors of
};
