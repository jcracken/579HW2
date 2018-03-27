#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(void) {

	std::string in;
	unsigned int i = 0;
	std::vector<char> state;

	std::cout << "Enter initial state: ";
	std::cin >> in;

	for (i = 0; i < in.size(); i++) {
		state.push_back(in.at(i));
	}

	return 0;
}