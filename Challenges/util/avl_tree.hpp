
//*****************************************************************************
// Generic AVL Tree implementation.
// Reference: geeksforgeeks.org/avl-tree-set-1-insertion
//*****************************************************************************

#pragma once

#include <cstddef>

using namespace std;

template <class T>
class AVL_Tree{

private:

    class AVL_Node{

    private:
        T * item;
        AVL_Node * parent;
        AVL_Node * left_child;
        AVL_Node * right_child;
        size_t height;

    public:
        // constructor and destructor
        AVL_Node(T * p_item);
        ~AVL_Node();
        // getters and setters
        T * get_item();
        AVL_Node * get_parent();
        void set_parent(AVL_Node * p_parent);
        AVL_Node * get_left_child();
        void set_left_child(AVL_Node * p_left);
        AVL_Node get_right_child();
        void set_right_child(AVL_Node * p_right);
        size_t get_height();
        void set_height(size_t p_height);
        int get_balance_factor();
    };

    AVL_Node * root;

    void rotate_right(AVL_Node * z);
    void rotate_left(AVL_Node * z);
    void rotate_left_right(AVL_Node * z);
    void rotate_right_left(AVL_Node * z);

public:

    AVL_Tree();
    ~AVL_Tree();

    void insert(T * p_item);
    void delete(T * p_item);
    void print();
    void delete_all();
};

template <class T>
AVL_Tree<T>::AVL_Node::AVL_Node(T * p_item){
    item = p_item;
    parent = NULL;
    left_child = NULL;
    right_child = NULL;
    height = 0;
}

template <class T>
AVL_Tree<T>::AVL_Node::~AVL_Node(){
    if(item != NULL){
        delete item;
    }
    parent = NULL;
    left_child = NULL;
    right_child = NULL;
}

template <class T>
T * AVL_Tree<T>::AVL_Node::get_item(){
    return item;
}

template <class T>
AVL_Node * AVL_Tree<T>::AVL_Node::get_parent(){
    return parent;
}

template <class T>
void AVL_Tree<T>::AVL_Node::set_parent(AVL_Node * p_parent){
    parent = p_parent;
}

template <class T>
AVL_Node * AVL_Tree<T>::AVL_Node::get_left_child(){
    return left_child;
}

template <class T>
void AVL_Tree<T>::AVL_Node::set_left_child(AVL_Node * p_left)(){
    left_child = p_left;
}

template <class T>
AVL_Node * AVL_Tree<T>::AVL_Node::get_right_child(){
    return right_child;
}

template <class T>
void AVL_Tree<T>::AVL_Node::set_right_child(AVL_Node * p_right)(){
    right_child = p_right;
}

template <class T>
size_t AVL_Tree<T>::AVL_Node::get_height(){
    return height;
}

template <class T>
void AVL_Tree<T>::AVL_Node::set_height(size_t p_height)(){
    height = p_height;
}

template <class T>
int AVL_Tree<T>::AVL_Node::get_balance_factor(){

    if(this->left_child == NULL){
      return -(this->right_child->height);
    }else if(this->right_child == NULL){
      return this->left_child->height;
    }
    return this->left_child->height - this->right_child->height;
}

template <class T>
AVL_Tree<T>::AVL_Tree(){
    root = NULL;
}

template <class T>
AVL_Tree<T>::~AVL_Tree(){
    if(root != NULL){
        delete root;
    }
}

template <class T>
void AVL_Tree<T>::rotate_right(AVL_Node * z){

    AVL_Node * y = z->get_left_child();
    AVL_Node * x = y->get_left_child();

    z->set_left_child(y->get_right_child());
    y->get_right_child()->set_parent(z);
    y->set_left_child(x);
    y->set_right_child(z);

    if(z->get_parent() != NULL){
        y->set_parent(z->get_parent());
        if(z->get_parent()->get_left_child() == z){
            z->get_parent->set_left_child(y);
        }else if(z->get_parent()->get_right_child() == z){
            z->get_parent()->set_right_child(y);
        }
    }else{
        this.root = y;
    }

    x->set_parent(y);
    z->set_parent(y);

    x->set_height(1 + max(x->get_left_child()->get_height(), x->get_right_child()->get_height()));
    z->set_height(1 + max(z->get_left_child()->get_height(), z->get_right_child()->get_height()));
    y->set_height(1 + max(y->get_left_child()->get_height(), y->get_right_child()->get_height()));
}

template <class T>
void AVL_Tree<T>::rotate_left(AVL_Node * z){

    AVL_Node * y = z->get_right_child();
    AVL_Node * x = y->get_right_child();

    z->set_right_child(y->get_left_child());
    y->get_left_child()->set_parent(z);
    y->set_left_child(z);
    y->set_right_child(x);

    if(z->get_parent() != NULL){
        y->set_parent(z->get_parent());
        if(z->get_parent()->get_left_child() == z){
            z->get_parent()->set_left_child(y);
        }else if(z->get_parent()->get_right_child() == z){
            z->get_parent()->set_right_child(y);
        }
    }else{
        this.root = y;
    }

    x->set_parent(y);
    z->set_parent(y);

    x->set_height(1 + max(x->get_left_child()->get_height(), x->get_right_child()->get_height()));
    z->set_height(1 + max(z->get_left_child()->get_height(), z->get_right_child()->get_height()));
    y->set_height(1 + max(y->get_left_child()->get_height(), y->get_right_child()->get_height()));
}

template <class T>
void AVL_Tree<T>::rotate_left_right(AVL_Node * z){
    this.rotate_left(z->get_left_child());
    this.rotate_right(z);
}

template <class T>
void AVL_Tree<T>::rotate_right_left(AVL_Node * z){
    this.rotate_right(z->get_right_child());
    this.rotate_left(z);
}

template <class T>
void AVLTree<T>::insert(T * p_item){
    // starting with the cur_node_parent, up until the root,
    // adjust heights and make rotations if necessary
    // fixing the unbalanced node will fix the complete AVL Tree here.
    cur_node = cur_node_parent;
    bool balance_fixed = false;
    while(cur_node != NULL){
        cur_node->set_height(1 + max(cur_node->get_left_child->get_height(), cur_node->get_right_child->get_height()));
        if(balance_fixed == false){
            size_t balance_factor = cur_node->get_balance_factor();
            if(balance_factor > 1 && p_item < cur_node->get_left_child()->get_item()){
                // left left case
                rotate_right(cur_node);
                balance_fixed = true;
            }else if(balance_factor > 1 && p_item > cur_node->get_left_child()->get_item()){
                // left right case
                rotate_left(cur_node->get_left_child());
                rotate_right(cur_node);
                balance_fixed = true;
            }else if(balance_factor < -1 && p_item > cur_node->get_right_child()->get_item()){
                // right right case
                rotate_left(cur_node);
                balance_fixed = true;
            }else if(balance_factor < -1 && p_item < cur_node->get_right_child()->get_item()){
                // right left case
                rotate_right(cur_node->get_right_child());
                rotate_left(cur_node);
                balance_fixed = true;
            }
        }
        cur_node = cur_node->get_parent();
    }
}

template <class T>
void AVL_Tree<T>::delete(T * p_item){

}
