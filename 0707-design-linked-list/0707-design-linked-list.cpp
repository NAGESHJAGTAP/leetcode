class MyLinkedList {
public:
    class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value=value;
            this->next=nullptr;
        }
    };
    Node* head;
    MyLinkedList() {
        head=nullptr;
    }
    int get(int index) {
        Node*temp=head;
        int i=0;
        while(temp !=nullptr) {
            if (i==index)
                return temp->value;
            temp=temp->next;
            i++;
        }
        return -1;
    }
    void addAtHead(int val) {
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
    }
    void addAtTail(int val) {
        Node* newNode=new Node(val);
        if (head==nullptr) {
            head=newNode;
            return;
        }
        Node* temp=head;
        while (temp->next !=nullptr)
            temp=temp->next;
        temp->next=newNode;
    }
    void addAtIndex(int index, int val) {
        if (index<0)
            return;
        if (index==0) {
            addAtHead(val);
            return;
        }
        Node*temp=head;
        for (int i=0; temp && i < index - 1; i++)
            temp=temp->next;
        if (!temp)
            return;
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void deleteAtIndex(int index) {
        if (index < 0 || !head)
            return;
        if (index==0) {
            Node* del=head;
            head=head->next;
            delete del;
            return;
        }
        Node* temp=head;
        for (int i=0; temp->next && i<index-1; i++)
            temp=temp->next;
        if (!temp->next)
            return;
        Node* del=temp->next;
        temp->next=del->next;
        delete del;
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