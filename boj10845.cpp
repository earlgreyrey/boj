nclude <iostream>
#include <fstream>

// create queue class and several methodes
class Queue {
private:
	int size;
	int front;
	int rear;
	int data[size];

public:
	Queue();
	~Queue();
	Push(int val);
	Pop();
	Size();
	Empty();
	Front();
	Back();
}

Queue::Queue() {
	front = 0;
	rear = 0;
}

Queue::~Queue() {
	delete[] Queue;
}

void Queue::Push(int val) {

}

void Queue::Pop() {

}

int Queue::Size() {

}

// Umm... wait a miniute... is this function necessary?
// can I use value directly? private -> public


int main(int argc, char** argv) {
	// what is input file type?
	string inFile = "input";
	// anyway open file
	ifstream ifs(inFile);

	// first line is number of commands
	int n;
	ifs >> n;


}


