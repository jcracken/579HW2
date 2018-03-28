#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "node.h"

int calcH(std::vector<char> state) {
	unsigned int i = 0;
	unsigned int j = 0;
	int num = 0;

	for (i = 0; i < state.size(); i++) {
		if (state.at(i) == 'W') {
			for (j = 0; j < i; j++) {
				if (state.at(j) == 'B') {
					num++;
					break;
				}
			}
		}
	}
	return num;
}

int findEmpty(std::vector<char> state) {
	unsigned int i = 0;
	for (i = 0; i < state.size(); i++) {
		if (state.at(i) == 'E') return i;
	}
	return -1;
}

int main(void) {

	std::string in;
	unsigned int i = 0, j = 0;

	std::vector<char> state;
	std::vector<char> temp;
	std::vector<node> past;
	std::vector<node> curr;

	int currCost = 0, stateNum = 0;
	int cost = 0, pred = 0;
	unsigned int costLoc;
	int loc;
	bool done = false;
	bool prev = false;

	std::cout << "Enter initial state: ";
	std::cin >> in;

	for (i = 0; i < in.size(); i++) {
		state.push_back(in.at(i));
	}

	for (i = 0; i < state.size(); i++) {
		temp.push_back(state.at(i));
	}

	pred = calcH(temp);

	if (pred == 0) {
		done = true;
	}

	for (i = 0; i < temp.size(); i++) {
		std::cout << temp.at(i);
	}
	std::cout << " : G(n) = " << currCost << " : h(n) = " << pred << std::endl;

	while (!done) {
		curr.clear();
		node* n = NULL;
		costLoc = 0;
		prev = false;
		stateNum++;

		loc = findEmpty(temp);
		if (loc != -1) {
			if ((unsigned)loc == temp.size() - 1) {
				std::swap(temp[temp.size() - 2], temp[temp.size() - 1]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 1);
				curr.push_back(*n);

				std::swap(temp[temp.size() - 2], temp[temp.size() - 1]);

				std::swap(temp[temp.size() - 3], temp[temp.size() - 1]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 2);
				curr.push_back(*n);
			} else if (loc == 0) {
				std::swap(temp[loc + 1], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 1);
				curr.push_back(*n);

				std::swap(temp[loc + 1], temp[loc]);

				std::swap(temp[loc + 2], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 2);
				curr.push_back(*n);
			} else if (loc == 1) {
				std::swap(temp[loc - 1], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 1);
				curr.push_back(*n);

				std::swap(temp[loc - 1], temp[loc]);

				std::swap(temp[loc + 1], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 1);
				curr.push_back(*n);

				std::swap(temp[loc + 1], temp[loc]);

				std::swap(temp[loc + 2], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 2);
				curr.push_back(*n);
			} else if ((unsigned)loc == temp.size() - 2) {
				std::swap(temp[loc - 1], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 1);
				curr.push_back(*n);

				std::swap(temp[loc - 1], temp[loc]);

				std::swap(temp[loc - 2], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 2);
				curr.push_back(*n);

				std::swap(temp[loc - 2], temp[loc]);

				std::swap(temp[loc + 1], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 1);
				curr.push_back(*n);
			} else {
				std::swap(temp[loc - 1], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 1);
				curr.push_back(*n);

				std::swap(temp[loc - 1], temp[loc]);

				std::swap(temp[loc - 2], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 2);
				curr.push_back(*n);

				std::swap(temp[loc - 2], temp[loc]);

				std::swap(temp[loc + 1], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 1);
				curr.push_back(*n);

				std::swap(temp[loc + 1], temp[loc]);

				std::swap(temp[loc + 2], temp[loc]);
				n = new node(temp);
				n->setPredCost(calcH(temp));
				n->setCurrCost(currCost + 2);
				curr.push_back(*n);
			}

			cost = curr.at(0).getPredCost() + curr.at(0).getCurrCost();

			for (i = 0; i < curr.size(); i++) {
				if (curr.at(i).getPredCost() == 0) {
					cost = curr.at(i).getPredCost() + curr.at(i).getCurrCost();
					costLoc = i;
					for (i = 0; i < temp.size(); i++) {
						temp.at(i) = curr.at(costLoc).getState().at(i);
					}
					goto over;
				}
				if (curr.at(i).getPredCost() + curr.at(i).getCurrCost() < cost) {
					cost = curr.at(i).getPredCost() + curr.at(i).getCurrCost();
					costLoc = i;
				}
			}
			for (i = 0; i < past.size(); i++) {
				if (past.at(i).getPredCost() + past.at(i).getCurrCost() < cost) {
					cost = past.at(i).getPredCost() + past.at(i).getCurrCost();
					costLoc = i;
					prev = true;
				}
			}
			for (i = 0; i < past.size(); i++) {
				for (j = 0; j < curr.size(); j++) {
					if (past.at(i).comp(&curr.at(j)) && j != costLoc) {
						curr.erase(curr.begin() + j);
						j--;
					} else if (past.at(i).comp(&curr.at(j)) && j == costLoc) {
						prev = true;
						costLoc = i;
					}
				}
			}
			for (i = 0; i < curr.size(); i++) {
				for (j = i + 1; j < curr.size(); j++) {
					if (curr.at(i).comp(&curr.at(j))) {
						curr.erase(curr.begin() + j);
						j--;
					}
				}
			}
			if (prev) {
				currCost = past.at(costLoc).getCurrCost();
				for (i = 0; i < temp.size(); i++) {
					temp.at(i) = past.at(costLoc).getState().at(i);
				}
				pred = past.at(costLoc).getPredCost();
				past.erase(past.begin() + costLoc);
				for (i = 0; i < curr.size(); i++) {
					past.push_back(curr.at(i));
				}
			} else {
				currCost = curr.at(costLoc).getCurrCost();
				for (i = 0; i < temp.size(); i++) {
					temp.at(i) = curr.at(costLoc).getState().at(i);
				}
				pred = curr.at(costLoc).getPredCost();
				for (i = 0; i < curr.size(); i++) {
					if (i != costLoc) {
						past.push_back(curr.at(i));
					}
				}
			}
			over:
			pred = calcH(temp);
			if (pred == 0) {
				done = true;
			}
			for (i = 0; i < temp.size(); i++) {
				std::cout << temp.at(i);
			}
			std::cout << " : G(n) = " << currCost << " : h(n) = " << pred << std::endl;
		} else {
			std::cout << "Error: Invalid Puzzle State" << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	std::cout << "Total cost = " << cost << std::endl;
	std::cout << "Number of states expanded = " << stateNum << std::endl;

	return 0;
}