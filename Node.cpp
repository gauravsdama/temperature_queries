# include <string>
# include "Node.h"

using std::string;

Node::Node() : next(nullptr) {
	
}

Node::Node(string id, int year, int month, double temperature) : data(id, year, month, temperature), next(nullptr)  {
	
}

bool Node::operator<(const Node& b) {	
	return this->data < b.data;
}
