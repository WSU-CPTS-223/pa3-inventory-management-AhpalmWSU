#pragma once
#include <stdlib.h>
#include <string> 

using namespace std;

template <class Template>
class Node {
private:
	Template data; 
	Node<Template>* pNext;
public:
	Node(Template& data); //Constructor
	void setNextPtr(Node<Template>* newNxtPtr); //set current Node pointer to the next Node
	Node<Template>* getNextPtr()const; //obtain the address of the next new Node
	Template getData(); 
};

//Constructor 
template<class Template>
inline Node<Template>::Node(Template& data)
{
	this->data = data; 
	this->pNext = nullptr; //Set null pNext to Null. Will be use to determine which Node is at the tail of the list or head depending how you look at it
}

template<class Template>
inline void Node<Template>::setNextPtr(Node* newNxtPtr)
{
	this->pNext = newNxtPtr;
}

template<typename Template>
Node<Template>* Node<Template>::getNextPtr() const
{
	return this->pNext;
}

template<class Template>
inline Template Node<Template>::getData()
{
	return this->data; 
}

