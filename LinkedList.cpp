# include <iostream>
# include <string>
# include "LinkedList.h"
# include "Node.h"
# include <sstream>

using std::string, std::ostream;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	
}

LinkedList::~LinkedList() {
	
	clear();
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) {
	// TODO: implement this function
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	
	if (this != &source) {
        clear();  // Deallocate existing nodes
        // Copy nodes from source if needed
    }
    return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	
	Node* newNode = new Node(location, year, month, temperature);

    if (!head) {
        // Empty list
        head = tail = newNode;
    } else if (*newNode < *head) {
        // Insert at the beginning
        newNode->next = head;
        head = newNode;
    } else {
        // Traverse the list to find the correct position
        Node* current = head;
        while (current->next && !(*newNode < *(current->next))) {
            current = current->next;
        }

        // Insert after current
        newNode->next = current->next;
        current->next = newNode;

        if (current == tail) {
            // Update tail if the new node is inserted at the end
            tail = newNode;
        }
	}
}

void LinkedList::clear() {
	
	Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;  // Deallocate the node
        current = next;
    }
    head = tail = nullptr;
}

Node* LinkedList::getHead() const {
	
	return head;
}

string LinkedList::print() const {
	string outputString;

	
	Node* current = head;
	while (current) {
        std::ostringstream tempStream;
        tempStream << std::fixed << current->data.temperature;
        std::string temperatureString = tempStream.str();

        // Remove trailing zeros after the decimal point
        size_t dotPos = temperatureString.find('.');
        if (dotPos != std::string::npos) {
            size_t lastNonZero = temperatureString.find_last_not_of('0');
            if (lastNonZero > dotPos) {
                temperatureString.erase(lastNonZero + 1, std::string::npos);
            } else {
                // If there are no non-zero digits after the decimal point, remove it
                temperatureString.erase(dotPos, 1);
            }
        }
        outputString += current->data.id + " " +
                        std::to_string(current->data.year) + " " +
                        std::to_string(current->data.month) + " " +
                        temperatureString + "\n";

        /*
        // Convert temperature to string with fixed precision
        std::ostringstream tempStream;
        tempStream << std::fixed << std::setprecision(2) << current->data.temperature;
        std::string temperatureString = tempStream.str();

        // Remove trailing zeros from the temperature string
        temperatureString.erase(temperatureString.find_last_not_of('0') + 1, std::string::npos);

        // Append node information to the output string
        if (temperatureString == "5."){
            temperatureString = "5";
        }

        outputString += current->data.id + " " +
                        std::to_string(current->data.year) + " " +
                        std::to_string(current->data.month) + " " +
                        temperatureString + "\n";

        current = current->next;
        std::string temperatureStr = std::to_string(current->data.temperature);
        double truncatedTemperature = std::stod(temperatureStr);

        outputString += current->data.id + " " +
                        std::to_string(current->data.year) + " " +
                        std::to_string(current->data.month) + " " +
                        std::to_string(truncatedTemperature) + "\n";
        current = current->next;
        */
    }

	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
