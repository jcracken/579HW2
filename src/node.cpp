#include "node.h"

node::node() {
	//constructor
}

node::node(std::vector<char> state) {
	unsigned int i = 0;
	for (i = 0; i < state.size(); i++) {
		this->state.push_back(state.at(i));
	}
}

void node::setPredCost(int c) {
	this->predCost = c;
}

void node::setCurrCost(int c) {
	this->currCost = c;
}

int node::getPredCost() {
	return this->predCost;
}

int node::getCurrCost(){
	return this->currCost;
}

std::vector<char> node::getState() {
	return this->state;
}

bool node::comp(node * other) {
	unsigned int i = 0;
	for (i = 0; i < this->state.size(); i++) {
		if (this->state.at(i) != other->getState().at(i)) return false;
	}
	return true;
}
