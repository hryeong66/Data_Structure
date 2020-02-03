#include "MaxHeap.h"

int main() {

	MaxHeap heap;

	heap.insert(10);
	heap.insert(5);
	heap.insert(30);
	heap.insert(8);
	heap.insert(9);
	heap.insert(50);
	heap.insert(3);
	heap.insert(22);

	heap.display();

	heap.remove();	heap.display();
	heap.remove();	heap.display();

	return 0; 
}