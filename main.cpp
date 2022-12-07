#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
public:
    
    Node* head;
    
    int addAtTop(int val){
        Node* NewNode = new Node();
        NewNode->data = val;
        
        if(this->head == NULL){
            head = NewNode;
            return val;
        }else{
            NewNode->next = this->head;
            head = NewNode;
            return val;
        }
    }
    
    int addAtEnd(int val){
        Node* NewNode = new Node;
        NewNode->data = val;
        Node* currentNode = head;
        
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
        }
        currentNode->next = NewNode;
        return val;
    }
    
    int addAt(int val , int index){
        Node* NewNode = new Node;
        NewNode->data = val;
        
        Node* currentNode = head;
        int nodeNum = 0;
        while (nodeNum != index-1 ) {
            nodeNum++;
            currentNode = currentNode->next;
        }
        
        NewNode->next =currentNode->next;
        currentNode->next = NewNode;
        return val;
    }
    
    int removeTop(){
        if(size()==0){
            return 0;
        }else{
            head = head->next;
            return 0;
        }
    }
    
    int removeBottom(){
        cout << "removing" <<endl;
        if(size()==0){
            return 0;
        }
        Node* currentNode = head;
        while(currentNode->next->next!=NULL){
            currentNode = currentNode->next;
        }
        currentNode->next = NULL;
        return 0;
    }
    
    void removeAt(int index){
        // add conditions for removing the 1st element and last element
        Node* currentNode = head;
        int nodeCount = 0;
        while(nodeCount != index-1){
            nodeCount++;
            currentNode = currentNode->next;
        }
        currentNode->next = currentNode->next->next;
        currentNode->next->next = NULL;
    }
    
    void printAll(){
        Node* currentNode = head;
        cout << "print data starts" << endl;
        while(currentNode->next!= NULL){
            cout << currentNode->data << endl;;
            currentNode = currentNode->next;
        }
        cout << currentNode->data << endl;
        cout << "print data ends" << endl;
    }
    
    int headNodeVal(){
        return head->data;
    }
    
    int endNodeVal(){
        Node* currrentNode = head;
        while(currrentNode->next != NULL){
            currrentNode = currrentNode->next;
        }
        return currrentNode->data;
    }
    
    int size(){
        if(head==NULL){
            return 0;
        }
        
        Node* currentNode = head;
        int size = 0;
        while (currentNode->next != NULL) {
            size++;
            currentNode = currentNode->next;
        }
        return size+1;
    }
    
};

int main(int argc, const char * argv[]) {
    
    LinkedList* LinkList1 = new LinkedList;
    LinkList1->addAtTop(12);  // adds node at top
    LinkList1->addAtTop(22);  // adds node at top
    LinkList1->addAtEnd(55); // adds node at tail
    LinkList1->addAtTop(99);  // adds node at top
    LinkList1->addAt(77,2); // adds value aat the given index
//    LinkList1->removeTop(); // removes value from top
    LinkList1->removeBottom(); //removess value from tail
    int topNodeVal = LinkList1->headNodeVal(); // returns node value at head
    int lastNode = LinkList1->endNodeVal();  // returns node value at tail
    LinkList1->removeAt(2); // removes node from th egiven index; (0 based index)
    LinkList1->printAll(); // prints all node values
    
    cout << "lastNode val : " << lastNode << endl;
    cout << "head val : " << topNodeVal <<endl;
    cout << "size : " << LinkList1->size() << endl;
}
