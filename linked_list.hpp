#include<string>
#include <iostream>
#include <string>
#include"node.hpp"

using namespace std; 

template <class Template> 
class Link_List 
{
private: 
	Node<Template>* pHead; 

public: 
	Link_List(Node<Template>* newpHead = nullptr); //set phead as nullptr for now
	Link_List(Link_List& list); //deep copy. Will be needed for rehash
	~Link_List(); //deconstructor
	Node<Template>* gethead();  
	void clearLink_List();
	bool isEmpty(); 
	void insertAtFront(Template& newData);
	void displayLink_List(); 
};

template <typename Template>
inline void Link_List<Template>::insertAtFront(Template& newData)
{
	Node<Template>* pMem = new Node<Template>(newData);
	if (pMem != nullptr)
	{
		pMem->setNextPtr(this->pHead);
		this->pHead = pMem; 
	}
}

template<class Template>
inline void Link_List<Template>::displayLink_List()
{
	if (isEmpty()){
		cout << "*Link_List IS EMPTY*\n\n"; 
	}
	else  {
		int x = 1;
		Node<Template>* pCur = this->pHead;
		cout << "Link_List\n"; 
		do {
			cout << x << ". " << pCur->getData() << "\n";
			pCur = pCur->getNextPtr();
			x++; 
		} while (pCur != nullptr);

		cout << "\n\n"; 
	}
}


template<class Template>
inline Link_List<Template>::Link_List(Node<Template>* newpHead)
{
	this->pHead = newpHead; 
}

template <class Template>
inline Link_List<Template>::Link_List(Link_List &list)
{
	this->pHead = nullptr; 
	Node<Template>* pCur = list.gethead();  
	Node<Template>* tail = nullptr; 

	while (pCur != nullptr){
		Node<Template>* newNode = new Node<Template>(pCur->getData()); 

		if (pHead == nullptr) {
			pHead = newNode; 
		}
		else 
		{
			tail->setNextPtr(newNode); 
		}
		tail = newNode; 
		pCur = pCur->getNextPtr(); 
	}
}

template<class Template>
inline Link_List<Template>::~Link_List()
{
	clearLink_List(); 
}

template<class Template>
inline Node<Template>* Link_List<Template>::gethead()
{
	return this->pHead; 
}

template<class Template>
inline void Link_List<Template>::clearLink_List()
{
	Node<Template>* pCur = this->pHead; 
	while (pCur != nullptr)
	{
		Node<Template>* pNext = pCur->getNextPtr(); 
		delete pCur; 
		pCur = pNext; 
	}
	this->pHead = nullptr; //set Link_List phead to its default address, NULL
}

template<class Template>
inline bool Link_List<Template>::isEmpty()
{
	if (this->pHead == nullptr)
	{
		return true; //Link_List is empty
	}
	else
		return false;
}


