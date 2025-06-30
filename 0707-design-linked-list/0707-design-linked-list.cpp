class MyLinkedList {
    private:
    class Node{
        public:
        int val;
        Node* next;
        Node(int val){
            this->val=val;
            this->next=NULL;
        }
    };
    Node* head;
    int size;
public:
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size) return -1;
        Node* curr=head;
        for(int i=0; i<index; i++){
            curr=curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            size++;
            return;
        }
        newNode->next=head;
        head=newNode;
        size++;
        return;
    }
    
    void addAtTail(int val) {
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
        }else{
            Node* curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* newNode=new Node(val);
        Node* curr=head;
        for(int i=0; i<index-1; i++){
            curr=curr->next;
        }
        newNode->next=curr->next;
        curr->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        if(index==0){
            Node* delNode=head;
            head=head->next;
            delete delNode;
        }else{
            Node* curr=head;
            for(int i=0;i<index-1; i++){
                curr=curr->next;
            }
            Node* delNode=curr->next;
            curr->next=curr->next->next;
            delete delNode;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */