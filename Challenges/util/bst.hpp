
//*****************************************************************************
// Generic BST implementation.
// Reference: geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
//*****************************************************************************

#pragma once

#include <cstddef>

using namespace std;

template <class T>
class BS_Node{
protected:
    T * item;
    Tree_Node * left_child;
    Tree_Node * right_child;
    Tree_Node * parent;

public:
    BS_Node(T * p_item){
        item = p_item;
        parent = NULL;
        left_child = NULL;
        right_child = NULL;
    }

    virtual ~BS_Node(){
        if(item != NULL){
            delete item;
        }
        parent = NULL;
        left_child = NULL;
        right_child = NULL;
    }

    virtual T * get_item() {return item};
    virtual BS_Node * get_parent() {return parent};
    virtual void set_parent(BS_Node * p_parent) {parent = p_parent};
    virtual BS_Node * get_left_child() {return left_child};
    virtual void set_left_child(BS_Node * p_left) {left_child = p_left};
    virtual BS_Node get_right_child() {return right_child};
    void set_right_child(BS_Node * p_right) {right_child = p_right};
};

template <class T>
class BS_Tree{
protected:
    BS_Node<T> * root;

public:

    virtual ~BS_Tree(){
        if(root != NULL){
            delete root;
        }
    }

    virtual void insert(T * p_item){

        if(root == NULL){
            root = new BS_Node(p_item);
            return;
        }
        // find the correct position to add the new node
        BS_Node * cur_node = root;
        BS_Node * cur_node_parent = NULL;
        while(cur_node != NULL){
            if(p_item < cur_node->get_item()){
                cur_node_parent = cur_node;
                cur_node = cur_node->get_left_child();
            }else if(p_item > cur_node->get_item()){
                cur_node_parent = cur_node;
                cur_node = cur_node->get_right_child();
            }else{
                // no duplicate is allowed
                return;
            }
        }
        // add the new node
        BS_Node * new_node = new BS_Node(p_item);
        new_node->set_parent(cur_node_parent);
        if(p_item < cur_node_parent->get_item()){
            cur_node_parent->set_left_child(new_node);
        }else{
            cur_node_parent->set_right_child(new_node);
        }
    }

    virtual bool delete(T * p_item){

        // do nothing if the tree is empty
        if(root == NULL){
            return;
        }

        // find the node to be deleted
        BS_Node * cur_node = root;
        T * cur_item = cur_node->get_item();
        while(p_item != cur_item){
            if(p_item < cur_item){
                cur_node = cur_node->get_left_child();
            }else if(p_item > cur_item){
                cur_node = cur_node->get_right_child();
            }
            cur_item = cur_node->get_item();
        }

        // if the item is not found, return
        if(p_item != cur_item){
            return false;
        }

        if(cur_node->get_left_child() == NULL && cur_node->get_right_child() == NULL){
            // if the node is a leaf node
            BS_Node * cur_node_parent = cur_node->get_parent();
            if(cur_node_parent->get_left_child() == cur_node){
                cur_node_parent->set_left_child(NULL);
            }else{
                cur_node_parent->set_right_child(NULL);
            }
            cur_node->set_parent(NULL);
        }else if(cur_node->get_left_child() != NULL && cur_node->get_right_child() != NULL){
            // if the node has two children
            //find the inorder successor of the node
            BS_Node * cur_inorder_node = cur_node->get_right_child();
            BS_Node * cur_inorder_left = NULL;
            while((cur_inorder_left = cur_inorder_node->get_left_child()) != NULL){
                cur_inorder_node = cur_inorder_left;
            }
            if(cur_inorder_node->get_right_child() != NULL){
                cur_inorder_node->get_parent()->set_left_child(cur_inorder_node->get_right_child());
                cur_inorder_node->get_right_child()->set_parent(cur_inorder_node->get_parent());
            }else{
                cur_inorder_node->get_parent()->set_left_child(NULL);
            }

            cur_inorder_node->set_parent(cur_node->get_parent());
            if(cur_node == cur_node->get_parent()->get_left_child()){
                cur_node->get_parent()->set_left_child(cur_inorder_node);
            }else{
                cur_node->get_parent()->set_right_child(cur_inorder_node);
            }
            cur_inorder_node->set_left_child(cur_node->get_left_child());
            cur_node->get_left_child()->set_parent(cur_inorder_node);
            cur_inorder_node->set_right_child(cur_node->get_right_child());
            cur_node->get_right_child()->set_parent(cur_inorder_node);

            cur_node->set_left_child(NULL);
            cur_node->set_right_child(NULL);
            cur_node->set_parent(NULL);
        }else{
            // if the node has only one child
            BS_Node * cur_node_child = cur_node->get_left_child();
            if(cur_node_child == NULL){
                cur_node_child = cur_node->get_right_child();
            }
            BS_Node * cur_node_parent = cur_node->get_parent();
            if(cur_node == cur_node_parent->get_left_child()){
                cur_node_parent->set_left_child(cur_node_child);
            }else{
                cur_node_parent->set_right_child(cur_node_child);
            }
            cur_node_child->set_parent(cur_node_parent);
            cur_node->set_parent(NULL);
            cur_node->set_left_child(NULL);
            cur_node->set_right_child(NULL);
        }

        delete cur_node->get_item();
        delete cur_node;

        return true;

    }

    void print(){

    }

    void delete_all(){

    }
};
