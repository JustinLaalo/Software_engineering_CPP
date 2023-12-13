#include "Queue.h"
//constuctor for queue
Queue::Queue(){
    this->head = NULL;
    this->tail = NULL;
    this->totalSize = 0;
}
//destructor for queue, to loop through linked list we need to set a head and temp node (so we can delete)
Queue::~Queue(){
   Node* curr = head;
   Node* prev;

   while(curr!= nullptr){
      prev = curr;
      curr= curr->next;
      //also need to delete the data within the node
      delete prev->data;
      delete prev;
   }
}
//checks if the queue is empty or not
bool Queue::empty() const {
    if(this->totalSize == 0){
        return true;
    }
    return false;
}
//returns the size of the queue
int Queue::size() const {
    return this->totalSize;
}
//returns the head of the queue
Order* Queue::peekFirst()const{
    if(this->head == NULL){
        return nullptr;
    }
    return this->head->data;
}
//returns the head of the queue and removes it from the queue
Order* Queue::popFirst(){
    if(this->head == NULL){
        return nullptr;
    }
    //statically allocates memory for the head node data (deletes itself)
    Order* temp = this->head->data;
    //makes a pointer to the head node before we set head to the next node
    Node* tempNode = this->head;
    this->head = this->head->next;
    //deletes the old head node
    delete tempNode;
    this->totalSize--;

    return temp;
}
//adds to the linked list
void Queue::addLast(Order* order){

    Node* newNode = new Node();
    newNode->data = order;
    newNode->next = nullptr;
    //checks if there is one thing in the queue
    if(head != NULL && tail == NULL){
        this->tail = newNode;
        this->head->next = this->tail;
        this->tail->next = NULL;
        this->totalSize++;
    //checks if nothing is in the queue
    }else if(this->head == NULL){
        this->head = newNode;
        this->head->next = NULL;
        this->totalSize++;
    //every other case
    }else{
        this->tail->next = newNode;
        this->tail = this->tail->next;
        this->totalSize++;
    }
}