#pragma once
/*************************************************
* ADS Praktikum 2.2
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

	using namespace std;

	class Tree {

	private:
		///////////////////////////////////////
		// Ihr Code hier:	
		TreeNode* anker;
		int NodeIDCounter;
		//
		////////////////////////////////////	

	public:
		///////////////////////////////////////
		// Ihr Code hier:	
		Tree();
		void addNode(string Name, int Alter, double Einkommen, int PLZ);
		//void deleteNode(int NodePosID);
		bool searchNode(string Name);
		bool Preorder(TreeNode* node, string Name);
		void printAll(void);
		void Preorder_ausgeben(TreeNode* node);
		bool balanceTree(TreeNode* node);
		void printLevelOrder(void);
		void printGivenLevel(TreeNode* root, int level);
		int height(TreeNode* node);
		bool rotateTreeRight(TreeNode* parent , TreeNode* child);
		bool rotateTreeLeft(TreeNode* parent, TreeNode* child);

		////////////////////////////////////
		// friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben! 
		friend TreeNode * get_anker(Tree& TN);
	};
