/*************************************************
* ADS Praktikum 2.2
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode {

private:
	///////////////////////////////////////
	// Ihr Code hier:	
	int NodePosID;
	int NodeID;
	bool Red = false;
	string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;
	//
	////////////////////////////////////

public:
	///////////////////////////////////////
	// Ihr Code hier:
	TreeNode();
	TreeNode(int NodePosID, int NodeID, string Name, int Alter, double Einkommen, int PLZ);
	int getNodePosID(void);
	//void setNodePosID(int NodePosID);
	int getNodeID(void);
	string getName(void);
	void setName(string name);
	int getAlter(void);
	void setAlter(int alter);
	double getEinkommen(void);
	void setEinkommen(double einkommen);
	int getPLZ(void);
	void setPLZ(int plz);
	bool getRed(void);
	void setRed(bool red);

	TreeNode* getParent(void) { if (this == nullptr) return nullptr; return parent; }
	TreeNode* getLeft(void) { if (this == nullptr) return nullptr;  return left; }
	TreeNode* getRight(void) { if (this == nullptr) return nullptr; return right; }
	//TreeNode* parent(TreeNode* tmp_anker, TreeNode* child);
	void setLeft(TreeNode* Left);
	void setRight(TreeNode* Right);
	void setParent(TreeNode* Parent);
	void print();

	/*void RedBlackInsert(TreeNode* &h, TreeNode x, int sw)
	{
		if (h == nullptr) //unterste Ebene erreicht, Knoten erzeugen und als roten Knoten einfuegen
		{
			//h = new TreeNode(x);
			h->setRed(true);
			return;

		}
		// Top Down : 4-Knoten in zwei 2-Knoten umwandeln, durch Umfaerben der Kanten
		if (h->left->getRed() && h->right->getRed())
		{
			h->setRed(true);
			h->left->setRed(false);
			h->right->setRed(false);
		}

		if (x.getNodePosID() < h->getNodePosID())
		{	// neues Element links einfügen
			RedBlackInsert(h->left, x, 0);
			//Bottom Up : Rotationen durchföhren
			if (h->getRed() && h->right->getRed() && sw) rightRotation(h);
			if (h->right->getRed() && h->left-left->getRed())
			{
				rightRotation(h);
				h->setRed(false);
				h->right->setRed(true);
			}
		}
		else
		{	// neues Element rechts einfügen
			RedBlackInsert(h->left, x, 1);
			//Bottom Up : Rotationen durchföhren
			if (h->getRed() && h->right && !sw) leftRotation(h);
			if (h->right->getRed() && h->right->right->getRed())
			{
				leftRotation(h);
				h->setRed(false);
				h->left->setRed(true);
			}
		}
	}*/

	


	//
	////////////////////////////////////
};
