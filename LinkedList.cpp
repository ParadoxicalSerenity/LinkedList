#include <iostream>
#include <any>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

bool LinkedList::isEmpty() {
    if (head == nullptr) return true;
    return false;
}

void LinkedList::append(any data) {
    if (isEmpty()) {
        createHead(data);
        return;
    } else {
        Node *tail = findTail(head);
        tail->next_node = newNode(data);
    }
    size++;
}

void LinkedList::insertAfter(int position, any data) {
    Node *nodeAtPosition = at(position);
    Node *oldChild = nodeAtPosition->next_node;

    Node *nodeToAdd = newNode(data);
    nodeToAdd->next_node = oldChild;
    nodeAtPosition->next_node = nodeToAdd;
    size++;
}

void LinkedList::insertBefore(int position, any data) {
    Node *nodeAtPosition = at(position);
    Node *parent = findParent(nodeAtPosition);

    Node *nodeToAdd = newNode(data);

    nodeToAdd->next_node = nodeAtPosition;
    parent->next_node = nodeToAdd;
    size++;
}

Node *LinkedList::operator[](int index) {
    return at(index);
}

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

Node *LinkedList::findTail(Node *current_node) {
    if (isEmpty()) return nullptr;
    Node *node = current_node;

    while(node->next_node != nullptr){
        node = getNextNode(node);
    }
    return node;
}

Node *LinkedList::getNextNode(Node *current_node) {
    return current_node->next_node;
}

Node *LinkedList::newNode(any data) {
    return new Node{nullptr, data};
}

void LinkedList::rangeCheck(int index) {
    if (index > size) throw out_of_range("Attempted to access out of range element.");
}

Node *LinkedList::at(int index) {
    rangeCheck(index);
    Node *current = head;
    for (auto i = 0; i < index - index_offset; i++) {
        if (current->next_node == nullptr) return nullptr;
        current = getNextNode(current);
    }
    return current;
}

void LinkedList::dumpState() {
    cout << endl << "Dumping State..." << endl << endl;
    if (head == nullptr) return; //Nothing to dump.

    Node *current = head;

    dumpNodeState(current);
    while (getNextNode(current) != nullptr){
        current = current->next_node;
        dumpNodeState(current);
    }
    cout << endl;
}

void LinkedList::dumpNodeState(Node *node) {
    if (node == nullptr) throw invalid_argument("dumpNodeState got a nullptr.");
    cout << "Node:      " << node << endl;
    cout << "Points to: " << node->next_node << endl;
}

void LinkedList::remove() {
    if (isEmpty()) return;
    Node *nodeToRemove = findTail(head);
    if (head->next_node != nullptr) {
        Node *parent = findParent(nodeToRemove);
        delete nodeToRemove;
        parent->next_node = nullptr;
        size--;
        return;
    }
    removeHead();
}

Node *LinkedList::findParent(Node *child) {
    Node *current = head;
    if (child == head) throw invalid_argument("Can't locate parent of head.");
    while (current->next_node != child)
        current = getNextNode(current);
    return current;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::remove(int index) {
    Node *nodeToRemove = at(index);
    Node *nodesChild = nodeToRemove->next_node;
    Node *parent = findParent(nodeToRemove);
    delete nodeToRemove;
    parent->next_node = nodesChild;
    size--;
}

void LinkedList::createHead(any data) {
    head = newNode(data);
    size++;
}

void LinkedList::removeHead() {
    delete head;
    head = nullptr;
    size--;
}