#pragma once
#include "HeapNode.h"
#define MAX_ELEMENT 200

class MaxHeap{
	HeapNode node[MAX_ELEMENT];
	int size;

public:
	MaxHeap():size(0){ }
	bool isEmpty() { return  size == 0; }
	bool isFull() { return size == MAX_ELEMENT-1; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	HeapNode find() { return node[1]; }

	void insert(int key) {
		//���� ������ ���� ������� �� �����ϴ� �Ͱ� ����
		//���� �� ��ġ�� size
		if (isFull()) return;
		int i = ++size; // size�� 0���� heap�� �ε����� 1���� �����ϱ� ����
		
		// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ��
		while (i != 1 && getParent(i).getKey() < key) {
			node[i] = getParent(i).getKey();
			i = i / 2;
		} 
		node[i].setKey(key);
	}

	HeapNode remove() {
		if (isEmpty()) node[0];

		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		
		while (child <= size) {
			//�ڽ� ��� �� �� ū ��� ����
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
				child++;

			
			if (last.getKey() >= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}

		node[parent] = last;
		return item;
	}




	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if(i == level) {
				printf("\n");
				level *= 2; // �� ������ ù ������ 1,2,4,8,16
			}
			node[i].display();
		}
		printf("\n----------------------------\n");
	}

};