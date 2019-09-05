
//*****************************************************************************
// Generic Doubly Linked List implementation.
// head and tail nodes don't store any item
//*****************************************************************************

#pragma once

#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

template <class T>
class List_Node{
private:
    T * item;
    List_Node * prev;
    List_Node * next;

public:
    List_Node(T * p_item){
        item = p_item;
        prev = 0;
        next = 0;
    }

    ~List_Node(){
        if(item != 0){
            delete item;
        }
        prev = 0;
        next = 0;
    }

    T * get_item(){return item;}
    List_Node * get_next(){return next;}
    void set_next(List_Node * p_next){next = p_next;}
    List_Node * get_prev(){return prev;}
    void set_prev(List_Node * p_prev){prev = p_prev;}
};

template <class T>
class Linked_List{
private:
    List_Node<T> * head;
    List_Node<T> * tail;
    size_t size;

public:
    Linked_List(){
        head = new List_Node<T>(0);
        tail = new List_Node<T>(0);
        head->set_next(tail);
        head->set_prev(0);
        tail->set_prev(head);
        tail->set_next(0);
        size = 0;
    }

    ~Linked_List(){

        List_Node<T> * cur_node = head->get_next();

        while(cur_node != tail){
            List_Node<T> * tmp = cur_node;
            cur_node = cur_node->get_next();
            tmp->set_prev(0);
            tmp->set_next(0);
            delete tmp;
        }

        delete head;
        delete tail;
    }

    void insert_first(T * p_item){
        List_Node<T> * new_node = new List_Node<T>(p_item);
        List_Node<T> * head_next = head->get_next();
        head->set_next(new_node);
        head_next->set_prev(new_node);
        new_node->set_prev(head);
        new_node->set_next(head_next);
        size++;
    }

    void insert_last(T * p_item){
        List_Node<T> * new_node = new List_Node<T>(p_item);
        List_Node<T> * tail_prev = tail->get_prev();
        tail->set_prev(new_node);
        tail_prev->set_next(new_node);
        new_node->set_prev(tail_prev);
        new_node->set_next(tail);
        size++;
    }

    bool remove_item(T * p_item){
        // p_item is an anonymous object, thus it should be freed
        // before return

        // if the list is empty return false
        if(size == 0){
            delete p_item;
            return false;
        }

        // find the node to be deleted
        List_Node<T> * cur_node = head->get_next();
        while(cur_node != tail && *(cur_node->get_item()) != *p_item){
            cur_node = cur_node->get_next();
        }

        if(cur_node == tail){
            delete p_item;
            return false;
        }

        List_Node<T> * cur_node_prev = cur_node->get_prev();
        List_Node<T> * cur_node_next = cur_node->get_next();
        cur_node_prev->set_next(cur_node_next);
        cur_node_next->set_prev(cur_node_prev);
        cur_node->set_next(0);
        cur_node->set_prev(0);
        // deleting the node calls destructor of the Node, which deletes the item
        delete cur_node;

        size--;

        delete p_item;
        return true;
    }

    void print(){
        List_Node<T> * cur_node = head->get_next();
        for(int i = 0; i < size; i++){
            cout << *(cur_node->get_item()) << endl;
            cur_node = cur_node->get_next();
        }
    }

    T get_item(int p_index){
        /*if(p_index >= size){
            return;
        }*/

        int item_counter = 0;
        List_Node<T> * cur_node = head->get_next();
        while(cur_node != tail && item_counter != p_index){
            cur_node = cur_node->get_next();
            item_counter++;
        }

        /*if(cur_node == tail){
            return;
        }*/

        // calling the copy constructor
        T new_item = *(cur_node->get_item());

        // return the copy of the cur_node's item
        return new_item;
    }

    size_t get_size(){
        return size;
    }
};
