#include "Tree.h"

TREE::TREE(char symbol[], int prob[], int size) {
	this->size = size;
	this->symbol = new char[size];
	this->prob = new int[size];
	root = nullptr;
	for (int i = 0; i < size; i++) {
		this->symbol[i] = symbol[i];
		this->prob[i] = prob[i];
	}

	int* tmp = new int[size * 2];
	for (int i = 0; i < size; i++) {
		tmp[i] = prob[i];
	}
	for (int i = size; i < size * 2; i++) {
		tmp[i] = 0;
	}

	Node* node = new Node[size * 2];
	int t = size;
	for (int i = 0; i < size; i++) {
		node[i].prob = prob[i];
		node[i].symbol = symbol[i];
	}
	while (t != 2 * size - 1) {
		int t1 = FINDMINPROB(tmp);
		int t2 = FINDMINPROB(tmp);

		node[t].prob = node[t1].prob + node[t2].prob;
		node[t].symbol = node[t1].symbol + node[t2].symbol;

		if (node[t1].prob < node[t2].prob) {
			node[t].left = &node[t1];
			node[t].right = &node[t2];
		}
		else {
			node[t].left = &node[t2];
			node[t].right = &node[t1];
		}

		tmp[t] = node[t].prob;

		root = &node[t];
		t++;
	}
}

TREE::~TREE() {
	if (root == NULL) {
		return;
	}
	DELETENODE(root->left);
	DELETENODE(root->right);
	root = nullptr;
}

void TREE::PRINT() {
	for (int i = 0; i < size; i++) {
		std::cout << symbol[i] << " = " << FINDCODE(symbol[i]) << std::endl;
	}
}

std::string TREE::CODING(std::string line) {
	std::string r;
	for (int i = 0; i < line.size(); i++) {
		r += FINDCODE(line[i]);
	}
	return r;
}

std::string TREE::DECODING(std::string line) {
	std::string r;
	while (line.size() != 0) {
		Node* tmp = root;
		while (tmp->left != nullptr && tmp->right != nullptr) {
			if (line[0] == '0') {
				tmp = tmp->left;
				line.erase(0, 1);
			}
			else if (line[0] == '1') {
				tmp = tmp->right;
				line.erase(0, 1);
			}
			else {
				return r;
			}
		}
		r += tmp->symbol;
	}
	return r;
}

std::string TREE::FINDCODE(char t) {
	std::string r;
	Node* tmp = root;
	while (tmp->left != nullptr && tmp->right != nullptr) {
		if (tmp->left->symbol.find(t) != std::string::npos) {
			tmp = tmp->left;
			r += '0';
		}
		else if (tmp->right->symbol.find(t) != std::string::npos) {
			tmp = tmp->right;
			r += '1';
		}
		else {
			return r;
		}
	}
	return r;
}

int TREE::FINDMINPROB(int* tmp) {
	int minIn = 0, minD = tmp[0];
	int i = 1;
	while (minD == 0) {
		minD = tmp[i];
		minIn = i;
		i++;
	}
	for (int i = 0; i < size * 2; i++) {
		if (tmp[i] < minD && tmp[i] != 0) {
			minD = tmp[i];
			minIn = i;
		}
	}
	tmp[minIn] = 0;
	return minIn;
}

void TREE::DELETENODE(Node* node) {
	if (node == NULL) {
		return;
	}
	DELETENODE(node->left);
	DELETENODE(node->right);
}