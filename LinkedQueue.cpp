#include "LinkedQueue.h"

//ADDENDUM: ADD CODE FOR:
//peekFront,
//copy constructor, and 
//destructor

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
}//end default constructor

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue) :
item(anItem), next(nextNodePtr)
{
}//end copy constructor

template <class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	while (frontptr != nullptr)
	{
		Node<ItemType>* nodeToDeletePtr = frontPtr;
		frontPtr = frontPtr->getNext();
		delete nodeToDeletePtr;
	}

	nodeToDeletePtr = nullptr;
}//end destructor

template <class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
	return (backPtr == frontPtr == nullptr);
}

template <class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // The queue was empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty
	backPtr = newNodePtr; // New node is at back
	return true;
} // end enqueue

template <class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		// Queue is not empty; remove front
		Node<ItemType>* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr)
		{ // Special case: one node in queue
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr->getNext();
		// Return deleted node to system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		result = true;
	} // end if
	return result;
} // end dequeue

template <class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw (PrecondViolatedExcep)
{
	if (frontPtr->getItem() != NULL)
		return frontPtr->getItem();
	else PrecondViolatedExcep("No item at front of queue");
}