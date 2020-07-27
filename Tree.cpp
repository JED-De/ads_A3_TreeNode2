/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

////////////////////////////////////
// Ihr Code hier:
Tree::Tree()
{
	anker = nullptr;
	NodeIDCounter = 0;
}

void Tree::addNode(string Name, int Alter, double Einkommen, int PLZ)
{
	int NodePosID = Alter + PLZ + Einkommen;
	TreeNode* neuer_eintrag = new TreeNode(NodePosID, NodeIDCounter, Name, Alter, Einkommen, PLZ);
	neuer_eintrag->setRed(true);
	NodeIDCounter++;

	if (anker == nullptr) // intialisierung
	{
		anker = neuer_eintrag;
		anker->setParent(nullptr);
	}
	else if (anker != nullptr) // erwachsend
	{
		TreeNode* tmp_anker = anker;
		TreeNode* tmp_anker_parent = anker;
		while (tmp_anker != nullptr)
		{
			tmp_anker_parent = tmp_anker;
			neuer_eintrag->setParent(tmp_anker);
			if (tmp_anker->getNodePosID() < NodePosID) {
				tmp_anker = tmp_anker->getRight();
			}
			else {
				tmp_anker = tmp_anker->getLeft();
			}
		}
		if (neuer_eintrag->getNodePosID() >= tmp_anker_parent->getNodePosID()) {
			tmp_anker_parent->setRight(neuer_eintrag);
		}
		else {
			tmp_anker_parent->setLeft(neuer_eintrag);
		}
	}
	//while(!(balanceTree()));
	// root is always black
	balanceTree(neuer_eintrag);
}



bool Tree::searchNode(string Name)
{
	TreeNode* ptr = anker;
	if (Preorder(ptr, Name))
	{
		/*cout << "Fundstellen:\nNodeID : " << ptr->getNodeID()
			<< ", Name : " << ptr->getName() << ", Alter : " << ptr->getAlter()
			<< ", Einkommen : " << ptr->getEinkommen() << ", PLZ : " << ptr->getPLZ()
			<< ", PosID : " << ptr->getNodePosID();*/
		return true;
	}
	else
	{
		cout << "Datensatz konnte nicht gefunden werden." << endl << endl;
		return false;
	}
}

bool Tree::Preorder(TreeNode* node, string Name)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (Name.compare(node->getName()) == 0)
	{
		return true;
	}
	return Preorder(node->getLeft(), Name) ||
		Preorder(node->getRight(), Name);
}


bool Tree::balanceTree(TreeNode* z)
{
	// iterate until z is not the root and z's parent color is red
	while (z != anker && z->getParent()->getRed())
	{
		TreeNode *y;

		// Find uncle and store uncle in y
		if (z->getParent() == z->getParent()->getParent()->getLeft())
			y = z->getParent()->getParent()->getRight();
		else
			y = z->getParent()->getParent()->getLeft();

		// If uncle is RED, do following
		// (i)  Change color of parent and uncle as BLACK
		// (ii) Change color of grandparent as RED
		// (iii) Move z to grandparent
		if (y != nullptr && y->getRed())
		{
			y->setRed(false);
			z->getParent()->setRed(false);
			z->getParent()->getParent()->setRed(true);
			z = z->getParent()->getParent();
		}

		// Uncle is BLACK, there are four cases (LL, LR, RL and RR)
		else
		{
			// Left-Left (LL) case, do following
			// (i)  Swap color of parent and grandparent
			// (ii) Right Rotate Grandparent
			if (z->getParent() == z->getParent()->getParent()->getLeft() &&
				z == z->getParent()->getLeft())
			{
				bool ch = z->getParent()->getRed();
				z->getParent()->setRed(z->getParent()->getParent()->getRed());
				z->getParent()->getParent()->setRed(ch);
				rotateTreeRight(z->getParent()->getParent(), z->getParent());
			}

			// Left-Right (LR) case, do following
			// (i)  Swap color of current node  and grandparent
			// (ii) Left Rotate Parent
			// (iii) Right Rotate Grand Parent
			if (z->getParent() == z->getParent()->getParent()->getLeft() &&
				z == z->getParent()->getRight())
			{
				bool ch = z->getRed();
				z->setRed(z->getParent()->getParent()->getRed());
				z->getParent()->getParent()->setRed(ch);
				rotateTreeLeft(z->getParent(), z);
				rotateTreeRight(z->getParent(), z);
			}

			// Right-Right (RR) case, do following
			// (i)  Swap color of parent and grandparent
			// (ii) Left Rotate Grandparent
			if (z->getParent() == z->getParent()->getParent()->getRight() &&
				z == z->getParent()->getRight())
			{
				bool ch = z->getParent()->getRed();
				z->getParent()->setRed(z->getParent()->getParent()->getRed());
				z->getParent()->getParent()->setRed(ch);
				rotateTreeLeft(z->getParent()->getParent(), z->getParent());
			}

			// Right-Left (RL) case, do following
			// (i)  Swap color of current node  and grandparent
			// (ii) Right Rotate Parent
			// (iii) Left Rotate Grand Parent
			if (z->getParent() == z->getParent()->getParent()->getRight() &&
				z == z->getParent()->getLeft())
			{
				bool ch = z->getRed();
				z->setRed(z->getParent()->getParent()->getRed());
				z->getParent()->getParent()->setRed(ch);
				rotateTreeRight(z->getParent(), z);
				rotateTreeLeft(z->getParent(), z);
			}
		}
	}
	anker->setRed(false); //keep root always black
	return true;
}

void Tree::printAll(void)
{
	TreeNode* ptr = anker;
	cout << "ID | Name | Alter | Einkommen | PLZ | Pos\n";
	cout << "---+------------+-------+-----------+-------+-------\n";
	Preorder_ausgeben(ptr);

}

void Tree::Preorder_ausgeben(TreeNode* node)
{

	if (node != nullptr)
	{
		if (node->getNodeID() != NodeIDCounter)
		{
			cout << node->getNodeID() << " | " << node->getName() << " | " << node->getAlter() << " | " << node->getEinkommen() << " | " << node->getPLZ() << " | " << node->getNodePosID() << "\n";
		}
		Preorder_ausgeben(node->getLeft());
		Preorder_ausgeben(node->getRight());
	}

}

void Tree::printLevelOrder(void)
{
	cout << "ID | Name | Alter | Einkommen | PLZ | Pos\n";
	cout << "---+------------+-------+-----------+-------+-------\n";
	TreeNode* tmp_anker = anker;
	int h = height(anker);
	int i;
	for (i = 1; i <= h; i++)
		printGivenLevel(tmp_anker, i);
}

void Tree::printGivenLevel(TreeNode* node, int level)
{
	if (node == nullptr)
		return;
	if (level == 1)
		cout << node->getNodeID() << " | " << node->getName() << " | " << node->getAlter() << " | " << node->getEinkommen() << " | " << node->getPLZ() << " | " << node->getNodePosID() << "\n";
	else if (level > 1)
	{
		printGivenLevel(node->getLeft(), level - 1);
		printGivenLevel(node->getRight(), level - 1);
	}
}

int Tree::height(TreeNode* node)
{
	if (node == nullptr)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = height(node->getLeft());
		int rheight = height(node->getRight());

		/* use the larger one */
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}

bool Tree::rotateTreeRight(TreeNode* x, TreeNode* y)
{
	x->setLeft(y->getRight());

	if (x->getLeft() != nullptr)
		x->getLeft()->setParent(x);

	y->setParent(x->getParent());

	if (x->getParent() == nullptr) {
		anker = y;
	}
	else if (x == x->getParent()->getRight()) {
		x->getParent()->setRight(y);
	}
	else {
		x->getParent()->setLeft(y);
	}
	y->setRight(x);
	x->setParent(y);

	return true;
}

bool Tree::rotateTreeLeft(TreeNode* x, TreeNode* y)
{
	x->setRight(y->getLeft());

	if (x->getRight() != nullptr)
		x->getRight()->setParent(x);

	y->setParent(x->getParent());

	if (x->getParent() == nullptr) {
		anker = y;
	}
	else if (x == x->getParent()->getLeft()) {
		x->getParent()->setLeft(y);
	}
	else {
		x->getParent()->setRight(y);
	}
	y->setLeft(x);
	x->setParent(y);

	return true;
}


/*void TreeNode::print() {
	int l = -1;
	int r = -1;
	int p = -1;
	if (left != nullptr)
		l = left->getNodePosID();
	if (right != nullptr)
		r = right->getNodePosID();
	if (parent != nullptr)
		p = parent->getNodePosID();
	printf("[Node: %d | Left: %d | Right: %d | Parent: %d | %s]\n",
		NodePosID, l, r, p, Red ? "R" : "B");
	if (left != nullptr)
		left->print();
	if (right != nullptr)
		right->print();
}
void Tree::printAll(void) {
	if (anker != nullptr) {
		anker->print();
		printf("\n\n");
	}
}*/

//
////////////////////////////////////
