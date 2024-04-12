
#include "PriorityQueue.h"
#include <exception>
using namespace std;


PriorityQueue::PriorityQueue(Relation r) {
	//TODO - Implementation
    first = nullptr;
    relation = r;

}
// Best case complexity : Tetha(1)
//Worst case : O(1)


void PriorityQueue::push(TElem e, TPriority p) {
    //TODO - Implementation
    Node* newNode = new Node;
    newNode->value = e;
    newNode->priority = p;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (isEmpty()) {
        first = newNode;
    } else {
        Node* current = first;
        while (current != nullptr && relation(current->priority, p)) {
            current = current->next;
        }
        if (current == nullptr) {
            Node* last = first;
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = newNode;
            newNode->prev = last;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != nullptr) {
                current->prev->next = newNode;
            } else {
                first = newNode;
            }
            current->prev = newNode;
        }
    }
}

// Best case: Tetha(1)
//Worst case: O(n)


//throws exception if the queue is empty
Element PriorityQueue::top() const {
	//TODO - Implementation
    if (isEmpty()){
        throw exception();
    }
	return Element(first->value,first->priority);
}

//Best Tetha(1)
//Worst O(1)

Element PriorityQueue::pop() {
	//TODO - Implementation
    if (isEmpty()){
        throw exception();
    }
	Node* temp = first;
    first = first->next;
    if(first != nullptr){
        first->prev = nullptr;
    }
    Element removedElement = Element( temp->value, temp->priority);
    delete temp;
    return removedElement;
}

//Best Tetha(1)
//Worst O(1)


bool PriorityQueue::isEmpty() const {
	//TODO - Implementation
	return (first == nullptr);
}
//Best Tetha(1)
//Worst O(1)

PriorityQueue::~PriorityQueue() {
	//TODO - Implementation
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;

    }

};

// Best case: Tetha(n)




void PriorityQueue::mergePrioQueue(const PriorityQueue &other){
    Node* otherCurrent = other.first;
    while (otherCurrent != nullptr){
        Node *newNode= new Node;
        newNode -> value = otherCurrent -> value;
        newNode -> priority = otherCurrent ->priority;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;

        }

    }
