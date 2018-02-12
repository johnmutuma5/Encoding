#pragma once

#include <iostream>
#include <string>

// using namespace std; // avoid this in .h files. Consider scope specification in the code or use specific 'using clauses' like 'using std::cout;'

template <class T>
struct NodeItem {

    T data;
    long priority;
    NodeItem<T>* next = NULL;

    NodeItem (T, long);
    ~NodeItem ();
};


template <class T>
class PriorityQueue {
  private:
    int size;
    NodeItem<T>* root = NULL;

    void updatePriorityHelper (T data, long newPriority, NodeItem<T>*& current, int currentIndex = 0);
  public:
    PriorityQueue (T, long);
    PriorityQueue ();
    ~PriorityQueue ();

    // friend method is an external method, hence we give it a template of its own and define it in this file
    template <class T_out>
    friend std::ostream& operator<<(std::ostream& out, PriorityQueue<T_out>&);

    int get_size () const;
    void insert(T, long);
    T pop ();
    void updatePriority (T, long);
    void erase (int);
    void clear();
  protected:
};






// the methods have to be defined in this file as they are all template methods by being methods of template classes
// Let's go!




template <class T>
NodeItem<T>::NodeItem (T data, long priority) {
    // std::cout<< "NodeItem constructor"<< std::endl;
    this->data = data;
    this->priority = priority;
}

template <class T>
NodeItem<T>::~NodeItem () {
    // std::cout<< "NodeItem destructor"<< std::endl;
}



template <class T>
PriorityQueue<T>::PriorityQueue (T data, long priority):
size(0)
{
    this->root = new NodeItem<T> (data, priority);
    (this->size)++;
}

template <class T>
PriorityQueue<T>::~PriorityQueue () {
    clear();
}
template <class T>
PriorityQueue<T>::PriorityQueue ():
size(0)
{
  // non-parameterised constructor
}

template <class T>
int PriorityQueue<T>::get_size () const {
    return this->size;
}


template <class T>
void outHelper (std::ostream& out, NodeItem<T>*& current) {
    if (current == NULL)
        return;
    out << current->data << " ";
    outHelper(out, current->next);
}

template <class T_out>
std::ostream& operator<< (std::ostream& out, PriorityQueue<T_out>& q) { // std::ostream& implies return the original out by referencing it and not by creating a copy of out to return
    if (q.root == NULL) {
      std::cout << "[priorityQueue::operator<<] Done" << std::endl;
      return out;
    }

    outHelper (out, q.root);
    out << std::endl << "Size: " << q.size;
    return out;
}

template <class T>
T PriorityQueue<T>::pop () {
    T popped_item = this->root->data;
    // delink the popped item
    this->erase(0);
    return popped_item;
}



template <class T>
void insertHelper (T& data, long priority, NodeItem<T>*& current, int index = 0) {
    if (current == NULL || current-> priority > priority) {
        NodeItem<T>* newItem = new NodeItem<T> (data, priority);
        newItem -> next = current;
        current = newItem;
        return;
    }
    insertHelper (data, priority, current->next, ++index);
}

template <class T>
void PriorityQueue<T>::insert (T data, long priority) {
    insertHelper (data, priority, this->root);
    (this->size)++;
}







template <class T>
void PriorityQueue<T>::updatePriorityHelper (T data, long newPriority, NodeItem<T>*& current, int currentIndex) {
    if (current == NULL) {
        return;
    }
    if (current->data == data) {
        this->erase(currentIndex);
        this->insert(data, newPriority);
        return;
    }
    updatePriorityHelper (data, newPriority, current->next, currentIndex + 1);
}

template <class T>
void PriorityQueue<T>::updatePriority(T data, long newPriority) {
    updatePriorityHelper (data, newPriority, this->root);
}






template <class T>
bool eraseHelper (int index, NodeItem<T>*& current, int currentIndex = 0) {
    if (current == NULL)
        return false;

    if (currentIndex == index){
        NodeItem<T>* trash = current;
        current = current->next;
        delete trash;
        return true;
    }

    return eraseHelper (index, current->next, currentIndex + 1);
}

template <class T>
void PriorityQueue<T>::erase(int index) {
    bool erased;
    if (index >= 0 && index < size)
        erased = eraseHelper (index, this->root);

    if (erased) {
        (this->size)--;
        return;
    }

    std::cout<< "Could not find item at: [" << index << "]" << std::endl;
}







template <class T>
void clearHelper (NodeItem<T>* current) {
    if (current == NULL)
        return;

    clearHelper(current->next);
    delete current;
}

template <class T>
void PriorityQueue<T>::clear () {
    clearHelper (this->root);
}
