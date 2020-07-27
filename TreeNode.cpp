/*************************************************
* ADS Praktikum 2.2
* TreeNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>
using namespace std;


////////////////////////////////////
// Ihr Code hier:
	TreeNode::TreeNode(){}
	TreeNode::TreeNode(int NodePosID, int NodeID, string Name, int Alter, double Einkommen, int PLZ)
	{
		this->NodePosID = NodePosID;
		this->NodeID = NodeID;
		this->Name = Name;
		this->Alter = Alter;
		this->Einkommen = Einkommen;
		this->PLZ = PLZ;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	int TreeNode::getNodePosID(void) { return NodePosID; }
	int TreeNode::getNodeID(void) { return NodeID; }
	string TreeNode::getName(void) { return Name; }
	void TreeNode::setName(string name) { Name = name; }
	int TreeNode::getAlter(void) { return Alter; }
	void TreeNode::setAlter(int alter) { Alter = alter; }
	double TreeNode::getEinkommen(void) { return Einkommen; }
	void TreeNode::setEinkommen(double einkommen) { Einkommen = einkommen; }
	int TreeNode::getPLZ(void) { return PLZ; }
	void TreeNode::setPLZ(int plz) { PLZ = plz; }
	bool TreeNode::getRed(void) 
	{ 
		if (this == nullptr)
			return false;
		return Red;
	}
	void TreeNode::setRed(bool red) { Red = red; }
	void TreeNode::setParent(TreeNode* Parent) { parent = Parent; }

	void TreeNode::setLeft(TreeNode* Left)
	{
		this->left = Left;
	}
	void TreeNode::setRight(TreeNode* Right)
	{
		this->right = Right;
	}
	
	/*TreeNode* TreeNode::parent(TreeNode* tmp_anker,TreeNode* child)
	{
		if (child == nullptr)
		{
			return false;
		}
		else if (tmp_anker->getRight() == child || tmp_anker->getLeft() == child)
		{
			// tmp_anker ist child parent
			return tmp_anker;
		}
		parent(tmp_anker->getLeft(), child);
		parent(tmp_anker->getRight(), child);
	}*/
//
////////////////////////////////////
