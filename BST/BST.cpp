#include "BST.h"
#include <iostream>
#include <stack>
#include <queue>

void BST::Insert(int value)
{
	//CREATE THE NEW NODE
	BSTNode* pNewNode = new BSTNode(value);

	//EMPTY TREE SO NEW NODE BECOMES THE ROOT
	if (IsEmpty())
	{
		pRoot = pNewNode;
		return;
	}

	//WALK DOWN THE TREE AND REMEMBER THE PARENT
	BSTNode* pCurrent = pRoot;
	BSTNode* pParent = nullptr;

	while (pCurrent != nullptr)
	{
		pParent = pCurrent;

		//SMALLER GOES LEFT, EQUAL OR BIGGER GOES RIGHT
		if (value < pCurrent->key)
		{
			pCurrent = pCurrent->pLeft;
		}
		else
		{
			pCurrent = pCurrent->pRight;
		}
	}

	//ATTACH THE NEW NODE UNDER THE PARENT
	if (value < pParent->key)
	{
		pParent->pLeft = pNewNode;
	}
	else
	{
		pParent->pRight = pNewNode;
	}
}

bool BST::Delete(int value)
{
	//FIND THE NODE AND ITS PARENT
	BSTNode* pCurrent = pRoot;
	BSTNode* pParent = nullptr;

	while (pCurrent != nullptr)
	{
		pParent = pCurrent;
		if (value < pCurrent->key) 
		{
			pCurrent = pCurrent->pLeft;
		}
		else 
		{
			pCurrent = pCurrent->pRight;
		}
	}

	//RETURN FALSE IF VALUE IS NOT IN THE TREE
	if (pCurrent == nullptr)
		return false;

	//NODE HAS TWO CHILDREN
	if (pCurrent->pLeft != nullptr && pCurrent->pRight != nullptr)
	{
		//FIND THE SMALLEST NODE IN THE RIGHT SUBTREE
		BSTNode* pMinParent = pCurrent;
		BSTNode* pMin = pCurrent->pRight;

		while (pMin->pLeft != nullptr)
		{
			pMinParent = pMin;
			pMin = pMin->pLeft;
		}

		//COPY ITS KEY HERE AND DELETE THE SMALLEST NODE INSTEAD
		pCurrent->key = pMin->key;
		pParent = pMinParent;
		pCurrent = pMin;
	}

	//NODE NOW HAS 0 OR 1 CHILD
	BSTNode* pChild = (pCurrent->pLeft != nullptr) ? pCurrent->pLeft : pCurrent->pRight;

	//CONNECT THE PARENT TO THE CHILD
	if (pParent == nullptr)
	{
		pRoot = pChild;
	}
	else if (pParent->pLeft == pCurrent) {
		pParent->pLeft = pChild;
	}
	else 
	{
		pParent->pRight = pChild;
	}

	//FREE THE MEMORY
	delete pCurrent;
	return true;

}

bool BST::Find(int value)
{
	BSTNode* pCurrent = pRoot;

	//LOOP WHILE NOT NULL
	while (pCurrent != nullptr)
	{
		//RETURN WITH CORRECT KEY VALUE
		if (value == pCurrent->key)
		{
			return true;
		}
		else if (value < pCurrent->key)
		{
			//VALUE IS SMALLER, CONTINUE
			pCurrent = pCurrent->pLeft;
		}
		else 
		{
			//VALUE IS GREATER, CONTINUE
			pCurrent = pCurrent->pRight;
		}
	}

	return false;
}

void BST::Print()
{
	//RETURN IF TREE IS EMPTY
	if (IsEmpty())
	{
		std::cout << "Empty tree" << std::endl;
		return;
	}

	//CREATE A QUEUE OF TREE NODES
	std::queue<BSTNode*> nodes;

	//MAKE ROOT THE FIRST ONE
	nodes.push(pRoot);
	int level = 0;

	//LOOPING UNTIL EMPTY
	while (!nodes.empty())
	{
		int countOnThisLevel = nodes.size();
		std::cout << "Level " << level << ": ";

		for (int i = 0; i < countOnThisLevel; i++) 
		{
			//FIRST OF QUEUE
			BSTNode* pNode = nodes.front();

			//DELETE IT
			nodes.pop();
			std::cout << pNode->key << " ";

			//ADD LEFT CHILDREN TO QUEUE
			if (pNode->pLeft != nullptr) 
			{
				nodes.push(pNode->pLeft);
			}

			//ADD RIGHT CHILDREN TO QUEUE
			if (pNode->pRight != nullptr) 
			{
				nodes.push(pNode->pRight);
			}

		}

		//ADD TO THE LEVEL
		std::cout << std::endl;
		level++;
	}
}

int BST::CountNodes()
{
	//RETURN ZERO IF EMPTY
	if (IsEmpty()) return 0;

	//CREATE THE TREE NODE STACK
	int count = 0;
	std::stack<BSTNode*> nodes;
	nodes.push(pRoot);

	//LOOPING UNTIL EMPTY
	while (!nodes.empty())
	{
		//CREATE A NODE
		BSTNode* pNode = nodes.top();

		//DELETE FROM THE TOP
		nodes.pop();

		//ADD TO COUNT
		count++;

		//ADD LEFT CHILDREN TO STACK
		if (pNode->pLeft != nullptr)
		{
			nodes.push(pNode->pLeft);
		}

		//ADD RIGHT CHILDREN TO STACK
		if (pNode->pRight != nullptr)
		{
			nodes.push(pNode->pRight);
		}
	}

	return count;
}

int BST::CountLeaves()
{
	//RETURN ZERO IF EMPTY
	if (IsEmpty())
		return 0;

	//CREATING TREE NODE STACK
	int count = 0;
	std::stack<BSTNode*> nodes;
	nodes.push(pRoot);

	//LOOPING UNTIL EMPTY
	while (!nodes.empty())
	{
		//TOP NODE
		BSTNode* pNode = nodes.top();
		nodes.pop();

		//IF NEITHER NODE HAS CHILDREN -> ITS LEAF
		if (pNode->pLeft == nullptr && pNode->pRight == nullptr) 
		{
			count++;
		}
        
		//ADD LEFT CHILDREN TO STACK
		if (pNode->pLeft != nullptr)
		{
			nodes.push(pNode->pLeft);
		}

		//ADD RIGHT CHILDREN TO STACK
		if (pNode->pRight != nullptr) 
		{
			nodes.push(pNode->pRight);
		}
	}

	//RETURN LEAF COUNT
	return count;
}