#ifndef RB_TREE_H
#define RB_TREE_H

#include "RB_TreeNode.h"

////////// INTERFACE //////////

template <class T>
class RB_Tree {

	public:
		RB_Tree();
		RB_Tree(const T&);
		~RB_Tree();

		void insert(T);
		void remove(T&);

		RB_TreeNode<T>* search(RB_TreeNode<T>*, T&);
		RB_TreeNode<T>* minimum(RB_TreeNode<T>*);
		RB_TreeNode<T>* maximum(RB_TreeNode<T>*);

	private:
		void insert_type1(RB_TreeNode<T>*);
		void insert_type2(RB_TreeNode<T>*);
                void insert_type3(RB_TreeNode<T>*);
                void insert_type4(RB_TreeNode<T>*);
                void insert_type5(RB_TreeNode<T>*);

		bool remove_type1(T&);
                bool remove_type2(T&);
                bool remove_type3(T&);
                bool remove_type4(T&);
                bool remove_type5(T&);
                bool remove_type6(T&);

		RB_TreeNode<T>* bst_emplace(RB_TreeNode<T>*, RB_TreeNode<T>*, T);
		RB_TreeNode<T>* get_sibling(RB_TreeNode<T>*);

		RB_TreeNode<T>* rootNode;

};

////////// PUBLIC IMPLEMENTATION //////////

template <class T>
RB_Tree<T>::RB_Tree():
	rootNode(NULL) {

}

template <class T>
RB_Tree<T>::RB_Tree(const T& data) {
	rootNode = new RB_TreeNode<T>(data);
}

template <class T>
RB_Tree<T>::~RB_Tree() {

}

template <class T>
void RB_Tree<T>::insert(T value) {

	RB_TreeNode<T>* new_node = bst_emplace(rootNode, NULL, value);
	insert_type1(new_node);

} 

template <class T>
void RB_Tree<T>::remove(T value) {

	remove_type1(T value);	

}

template <class T>
RB_TreeNode<T>* RB_Tree<T>::search(RB_TreeNode<T>* startNode, T& value) {

	T& data = startNode->getData();
	if(data == value) {
		return startNode;
	}
	else if((data > value) && (startNode->getRightChild() != NULL)) {
		return search(startNode->getRightChild(), value);
	}	
	else if((data < value) && (startNode->getLeftChild() != NULL)) {
		return search(startNode->getLeftChild(), value);
	}
	else {
		return NULL;
	}
	
}

template <class T>
RB_TreeNode<T>* RB_Tree<T>::minimum( RB_TreeNode<T>* startNode ) {

	RB_TreeNode<T>* minNode = startNode;
	while( minNode->getLeftChild() != NULL ) {
		minNode = minNode->getLeftChild();
	}	
	return minNode;

} 

template <class T>
RB_TreeNode<T>* RB_Tree<T>::maximum( RB_TreeNode<T>* startNode ) {

        RB_TreeNode<T>* maxNode = startNode;
        while( maxNode->getRightChild() != NULL ) {
                maxNode = maxNode->getRightChild();
        }
        return maxNode;

}

////////// PRIVATE IMPLEMENTATION //////////

////////// INSERTION METHODS //////////

template <class T>
void RB_Tree<T>::insert_type1(RB_TreeNode<T>* new_node) {
	if(new_node->getParent() == NULL) {
		new_node->setBlack();
		return;
	} else {
		insert_type2(new_node);
	}
}

template <class T>
void RB_Tree<T>::insert_type2(RB_TreeNode<T>* new_node) {
	RB_TreeNode<T>* parent = new_node->getParent();
	if(parent->isBlack()) {
		return;
	} else {
		insert_type3(new_node);
	}	
}

template <class T>
void RB_Tree<T>::insert_type3(RB_TreeNode<T>* new_node) {
	RB_TreeNode<T>* parent = new_node->getParent();
	RB_TreeNode<T>* uncle = get_sibling(parent);
	RB_TreeNode<T>* grandparent = parent->getParent();

	if((uncle != NULL) && (uncle->isRed())) {
		parent->setBlack();
		uncle->setBlack();
		grandparent->setRed();
		insert_type1(grandparent);
	} else {
		insert_type4(new_node);
	}
}

template <class T>
void RB_Tree<T>::insert_type4(RB_TreeNode<T>* new_node) {
	RB_TreeNode<T>* parent = new_node->getParent();
	RB_TreeNode<T>* grandparent = parent->getParent();

	if( (new_node == parent->getRightChild()) && (parent == grandparent->getLeftChild()) ) {
	        RB_TreeNode<T>* new_child = new_node->getLeftChild();
		grandparent->setLeftChild(new_node);
		new_node->setLeftChild(parent);
		parent->setRightChild(new_child);
		new_node = new_node->getRightChild();
	} 

	else if( (new_node == parent->getLeftChild()) && (parent == grandparent->getRightChild()) ) {
	        RB_TreeNode<T>* new_child = new_node->getLeftChild();
		grandparent->setRightChild(new_node);
		new_node->setRightChild(parent);
		parent->setLeftChild(new_child);
		new_node = new_node->getLeftChild();
	}
	
	insert_type5(new_node);
}

template <class T>
void RB_Tree<T>::insert_type5(RB_TreeNode<T>* new_node) {
        RB_TreeNode<T>* parent = new_node->getParent();
        RB_TreeNode<T>* grandparent = parent->getParent();

	parent->setBlack();
	grandparent->setRed();
	if(new_node == parent->getLeftChild()) {
                RB_TreeNode<T>* new_child = new_node->getLeftChild();
                grandparent->setRightChild(new_node);
                new_node->setRightChild(parent);
                parent->setLeftChild(new_child);
                new_node = new_node->getLeftChild();
	} else {
                RB_TreeNode<T>* new_child = new_node->getLeftChild();
                grandparent->setLeftChild(new_node);
                new_node->setLeftChild(parent);
                parent->setRightChild(new_child);
                new_node = new_node->getRightChild();
	}
}

////////// DELETION METHODS //////////

template <class T>
bool RB_Tree<T>::remove_type1(T& value) {
	
}

template <class T>
bool RB_Tree<T>::remove_type2(T& value) {
	return false;
}

template <class T>
bool RB_Tree<T>::remove_type3(T& value) {
	return false;
}

template <class T>
bool RB_Tree<T>::remove_type4(T& value) {
	return false;
}

template <class T>
bool RB_Tree<T>::remove_type5(T& value) {
	return false;
}

template <class T>
bool RB_Tree<T>::remove_type6(T& value) {
	return false;
}

////////// GENERAL METHODS //////////

template <class T>
RB_TreeNode<T>* RB_Tree<T>::bst_emplace(RB_TreeNode<T>* rootNode, RB_TreeNode<T>* parent, T value) {

	RB_TreeNode<T>* new_node;	

	if(rootNode == NULL) {
		
		new_node = new RB_TreeNode<T>(value, parent);
	
		if(parent != NULL) {	
			if(new_node < parent) {
				parent->setLeftChild(new_node);
			} else {
				parent->setRightChild(new_node);
			}
		}
	
		return new_node;

	}
	else if(value < rootNode->getData()) {
		return bst_emplace(rootNode->getLeftChild(), rootNode, value);
	}
	else {
		return bst_emplace(rootNode->getRightChild(), rootNode, value);
	}

}

template <class T>
RB_TreeNode<T>* RB_Tree<T>::get_sibling(RB_TreeNode<T>* node) {

	RB_TreeNode<T>* parent = node->getParent();
	if(parent == NULL) {
		return NULL;
	}
	else if(node == parent->getRightChild()) {
		return parent->getLeftChild();
	}
	else {
		return parent->getRightChild();
	}

}

#endif







