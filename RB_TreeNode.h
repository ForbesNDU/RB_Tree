// To use this class, template types are forced to declare an ordering (<,>,==)
#ifndef RB_TREENODE_H
#define RB_TREENODE_H

////////// INTERFACE //////////

template <class T>
class RB_TreeNode {

	public:
		RB_TreeNode(const T&);
		RB_TreeNode(const T&, RB_TreeNode<T>* parent);
		~RB_TreeNode();

		void setBlack();
		void setRed();
		bool isBlack();
		bool isRed();
		const T& getData();

		RB_TreeNode<T>* getRightChild();
		RB_TreeNode<T>* getLeftChild();
		RB_TreeNode<T>* getParent();

		void setRightChild(RB_TreeNode<T>*);
		void setLeftChild(RB_TreeNode<T>*);
		void setParent(RB_TreeNode<T>*);

		bool operator<(const RB_TreeNode<T>&);
		bool operator>(const RB_TreeNode<T>&);
		bool operator==(const RB_TreeNode<T>&);

	private:
                const T& dataElement;
		bool nodeColor;					// red = 0, black = 1		
		RB_TreeNode<T>* rightChild;
		RB_TreeNode<T>* leftChild;
		RB_TreeNode<T>* parent;

};

////////// PUBLIC IMPLEMENTATION //////////

template <class T>
RB_TreeNode<T>::RB_TreeNode( const T& data ):
	dataElement(data),
	nodeColor(0), 					// nodes pushed to the tree start out red during inserts
	rightChild(NULL),
	leftChild(NULL),
	parent(NULL) {

}

template <class T>
RB_TreeNode<T>::RB_TreeNode( const T& data, RB_TreeNode<T>* nodeParent ):
	dataElement(data),
	nodeColor(0),
	rightChild(NULL),
	leftChild(NULL),
	parent(nodeParent) {

}

template <class T>
RB_TreeNode<T>::~RB_TreeNode() {
	
}

template <class T>
void RB_TreeNode<T>::setBlack() {
	nodeColor = 1;
}

template <class T>
void RB_TreeNode<T>::setRed() {
	nodeColor = 0;
}

template <class T>
bool RB_TreeNode<T>::isBlack() {
	if(nodeColor == 1) {
		return true;
	} else {
		return false;
	}
}

template <class T>
bool RB_TreeNode<T>::isRed() {
	if(nodeColor == 0) {
		return true;
	} else {
		return false;
	}
}

template <class T>
const T& RB_TreeNode<T>::getData() {
	return dataElement;
}

template <class T>
RB_TreeNode<T>* RB_TreeNode<T>::getRightChild() {
	return rightChild;
}

template<class T>
RB_TreeNode<T>* RB_TreeNode<T>::getLeftChild() {
	return leftChild;
}

template <class T>
RB_TreeNode<T>* RB_TreeNode<T>::getParent() {
	return parent;
}

template <class T>
void RB_TreeNode<T>::setRightChild(RB_TreeNode<T>* newChild) {
	rightChild = newChild;
}

template <class T>
void RB_TreeNode<T>::setLeftChild(RB_TreeNode<T>* newChild) {
	leftChild = newChild;
}

template <class T>
void RB_TreeNode<T>::setParent(RB_TreeNode<T>* newParent) {
	parent = newParent;
}

template <class T>
bool RB_TreeNode<T>::operator<( const RB_TreeNode<T>& n ) {
	if(this.dataElement < n.dataElement) {
		return true;
	} else {
		return false;
	}
}

template <class T>
bool RB_TreeNode<T>::operator>( const RB_TreeNode<T>& n ) {
	if(this.dataElement > n.dataElement) {
		return true;
	} else {
		return false;
	}
}

template <class T>
bool RB_TreeNode<T>::operator==( const RB_TreeNode<T>& n ) {
	if(this.dataElement == n.dataElement) {
		return true;
	} else {
		return false;
	}
}


#endif
