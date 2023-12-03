#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <any>

using namespace std;

struct Node{
    Node *next_node;
    any data;
};

class LinkedList {
private:
    Node *head;
    int size;
    const int index_offset = 1;

    /**
     * Creates the head node and increments the size.
     * @param data
     */

    void createHead(any data);

    /**
     * Removes the head node and decrements the size.
     */
    void removeHead();

    /**
     * Finds the tail node and returns it. Returns nullptr if there are no
     * node
     * @param current_node
     * @return Node or nullptr.
     */
    Node *findTail(Node *current_node);

    /**
     * Finds the parent of the child node. Throws invalid_argument
     * if passed the head.
     * @param child
     * @return Node
     */
    Node *findParent(Node *child);

    /**
     * Creates a new node.
     * @param data
     * @return Node
     */
    Node *newNode(any data);

    /**
     * Dumps the memory address information for the specified node.
     * @param node
     */
    void dumpNodeState(Node *node);

public:
    /**
     * Constructor ensures we start with a size of zero and no head.
     */
    LinkedList();

    /**
     * Returns an int containing the current size.
     * @return int
     */
    int getSize();

    Node *operator[](int index);

    /**
     * Checks if the list is empty.
     */
    bool isEmpty();

    /**
     * Throws out_of_range exception if the given index
     * exceeds the size of the list.
     */
    void rangeCheck(int index);

    /**
     * Gets the node at a specified position.
     * Returns nullptr if it doesn't exist.
     */
    Node *at(int index);

    /**
     * Gets the next node when given the last node.
     * Returns nullptr if one doesn't exist.
     */
    Node *getNextNode(Node *current_node);

    /**
     * Adds a node to the end of the linked list.
     */
    void append(any data);

    /**
     * Removes a node from the end of the list.
     */
    void remove();

    /**
     * Removes a node from a specified point in list.
     */
    void remove(int index);
    /**
     * Removes a node from a specified point in list.
     */
    void insertAfter(int position, any data);
    void insertBefore(int position, any data);

    /**
     * Dumps the state of the linked list chain.
     * Effectively calls dumpNodeState for each
     * node in the chain.
     */
    void dumpState();
};


#endif //LINKEDLIST_LINKEDLIST_H
