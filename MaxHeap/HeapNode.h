#pragma once
#include <cstdio>

class HeapNode {

	int key;

public:
	HeapNode(): key(0){ }
	HeapNode(int k): key(k) { }
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { printf("%4d", key); }

};