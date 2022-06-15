#pragma once
#include <iostream>
#include <string>

class TREE {
private:
	class Node {
	public:
		Node* left, * right;
		std::string symbol;
		int prob;

		Node() {
			left = nullptr;
			right = nullptr;
		}
		Node(int prob, std::string symbol) {
			this->prob = prob;
			this->symbol = symbol;
		}
	};

	Node* root;
	char* symbol;
	int* prob;
	int size;
	std::string FINDCODE(char);
	int FINDMINPROB(int*);
	void DELETENODE(Node*);

public:
	TREE(char[],int[], int);
	~TREE();

	void PRINT();

	std::string CODING(std::string);
	std::string DECODING(std::string);
};