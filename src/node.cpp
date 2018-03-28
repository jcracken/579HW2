#include "node.h"

node::node() {
	//constructor
}

node::node(std::vector<char> state) {
	unsigned int i = 0;
	for (i = 0; i < state.size(); i++) {
		this->state.at(i) = state.at(i);
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
