// Unit tests for the RB Tree utilities

#include <iostream>
#include "RB_TreeNode.h"
#include "RB_Tree.h"

int main(int argc, char** argv) {

	////////// VALIDATE RB_TREENODE_H //////////

	// Construction (should not fail here)
	RB_TreeNode<int>* node_1 = new RB_TreeNode<int>(17); 
	std::cout << "CONSTRUCTOR TYPE 1 :: SUCCESS" << std::endl;

	RB_TreeNode<int>* node_2 = new RB_TreeNode<int>(20, node_1);
	std::cout << "CONSTRUCTOR TYPE 2 :: SUCCESS" << std::endl;

	// Data Tests
	node_2->setBlack();
	if(node_2->isBlack()) {
		std::cout << "SET BLACK TEST :: SUCCESS" << std::endl;
	} else {
		std::cout << "SET BLACK TEST :: FAILURE" << std::endl;
	}

	node_2->setRed();
        if(node_2->isRed()) {
                std::cout << "SET RED TEST :: SUCCESS" << std::endl;
        } else {
		std::cout << "SET RED TEST :: FAILURE" << std::endl;
	}

	const int num = node_2->getData();
	if(num == 20) {
		std::cout << "GET DATA TEST :: SUCCESS" << std::endl;
	} else {
		std::cout << "GET DATA TEST :: FAILURE" << std::endl;
	}

	// Operator Definitions

	if(node_1 > node_2) {
		std::cout << "GREATER THAN TEST :: FAILURE" << std::endl;
	} else {
		std::cout << "GREATER THAN TEST :: SUCCESS" << std::endl;
	}

	if(node_1 < node_2) {
                std::cout << "LESS THAN TEST :: SUCCESS" << std::endl;
        } else {
                std::cout << "LESS THAN TEST :: FAILURE" << std::endl;
        }

	if(node_1 == node_2) {
                std::cout << "EQUAL TO TEST :: FAILURE" << std::endl;
        } else {
                std::cout << "EQUAL TO TEST :: SUCCESS" << std::endl;
        }

	delete node_1;
	delete node_2;

	// Tree Structure Tests
	
	RB_TreeNode<int>* root = new RB_TreeNode<int>(100);
	RB_TreeNode<int>* right_child = new RB_TreeNode<int>(100);
	RB_TreeNode<int>* left_child = new RB_TreeNode<int>(100);

	right_child->setParent(root);
	left_child->setParent(root);
	
	if( (right_child->getParent() == root) && (left_child->getParent() == root) ) {
		std::cout << "SET/GET PARENT :: SUCCESS" << std::endl;
	} else {
		std::cout << "SET/GET PARENT :: FAILURE" << std::endl;
	}

	root->setLeftChild(left_child);
	root->setRightChild(right_child);

	if( root->getRightChild() == right_child ) {
		std::cout << "SET/GET RIGHT CHILD :: SUCCESS" << std::endl;
	} else {
		std::cout << "SET/GET RIGHT CHILD :: FAILURE" << std::endl;
	}

        if( root->getLeftChild() == left_child ) {
                std::cout << "SET/GET LEFT CHILD :: SUCCESS" << std::endl;
        } else {
                std::cout << "SET/GET LEFT CHILD :: FAILURE" << std::endl << std::endl;
        }

	delete root;
	delete left_child;
	delete right_child;

	////////// VALIDATE RB_TREE_H //////////
	
	RB_Tree<int>* test_tree = new RB_Tree<int>();
	test_tree->insert(5);
        std::cout << "FIRST INSERT :: SUCCESS" << std::endl;

	test_tree->insert(56);
        std::cout << "SECOND INSERT :: SUCCESS" << std::endl;

        test_tree->insert(7);
        std::cout << "THIRD INSERT :: SUCCESS" << std::endl;

        test_tree->insert(23);
        std::cout << "FOURTH INSERT :: SUCCESS" << std::endl;

        test_tree->insert(45);
        std::cout << "FIFTH INSERT :: SUCCESS" << std::endl;

        test_tree->insert(3);
        std::cout << "SIXTH INSERT :: SUCCESS" << std::endl;
	
	delete test_tree;

	return 0;

}
