#ifndef NODE_H
#define NODE_H

#include<vector>

class node {
private:
	std::vector<char> state;
	int predCost;
	int currCost;
public:
	node();
	node(std::vector<char> state);
	void setPredCost(int c);
	void setCurrCost(int c);
	int getPredCost();
	int getCurrCost();
	std::vector<char> getState();
};
#endif