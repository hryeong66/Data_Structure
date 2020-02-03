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
		//삽입 연산은 말단 사원으로 들어가 승진하는 것과 유사
		//내가 들어갈 위치가 size
		if (isFull()) return;
		int i = ++size; // size는 0부터 heap의 인덱스는 1부터 시작하기 때문
		
		// 트리를 거슬러 올라가면서 부모 노드와 비교
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
			//자식 노드 중 더 큰 노드 선택
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
				level *= 2; // 각 레벨의 첫 시작이 1,2,4,8,16
			}
			node[i].display();
		}
		printf("\n----------------------------\n");
	}

};