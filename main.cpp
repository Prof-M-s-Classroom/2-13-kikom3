#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    ~LinkedList() {
        Node<T> *current = this->head;
        while (head != NULL) {
            head = head->next;
            delete current;
            current = head;
        }
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }
    Node<T>* get(int index) {
        if (index<0||index>length) {
            return nullptr;
        }
        Node<T> *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }


    void insert(int index, T* value) {
        if (index<0||index>length) {
            cout << "Index is invalid" << endl;
            return;
        }
        if (index==0) {
            addHead(value);
        }
        if (index==length) {
            add(value);
        }
        else {
            Node<T> *newNode = new Node<T>(value);
            Node<T> *temp = get(index-1);
            newNode-next = temp->next;
            temp->next = newNode;
            length++;
        }
        return;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
    }

    void deleteNode(int i) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (i<0 || i>=length) {
            return; // edge case
        }
        else if (i==0) {
            return delfirst(); // since the index you chose to delete is 0, you just delete the first node which you can use delete first for
        }
        else if (i==length-1) {
            return dellast(); // if the index you chose is exactly the last node, you can just use delete last
        }
        Node<T> *prev = get(i-1); // gets previous through subtracting one from chosen index and using get method to take it
        Node<T> *temp = prev->next; // sets temp to where your index is so you can move your prev
        prev->next = temp->next; // move next of prev
        delete temp; // deleteing temp
        length--; // takes out from length the node that was deleted
    }

   void reverselist(){
        Node<T> *prev, *current, *next;
        prev = NULL;
        current = head;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->delfirst();
    ll->print();


    ll->reverselist();
    ll->print();

    ll->deleteNode(0);
    ll->print();
}