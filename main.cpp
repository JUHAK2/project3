#include <iostream>
#include <cstdlib>
#include <fstream>

class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;
    
    LinkedList();
    ~LinkedList();
    Node *  insert(int index, int data);
    Node *  remove(int index);
    Node *  output(int index, int data);
    void output();
};

LinkedList::LinkedList()
{
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList()
{
    cout << "LIST DELETED";
}

Node* LinkedList::insert(int index, int data)
{
    
    
    int currIndex = 1;
    Node* currNode = head;
    while (currNode && index > currIndex)
    {
        currNode = currNode->next;
        currIndex++;
    }
    
    Node* newNode = new Node;
    newNode->data = data;
    if (index == 0)
    {
        newNode->next = head;
        head        =    newNode;
        this->length++;
    }
    else
    {
        newNode->next = currNode->next;
        currNode->next = newNode;
        this->length++;
    }
    return newNode;
}

Node* LinkedList::remove(int index)
{
    
    int currIndex = 0;
    Node* prevNode= NULL;
    Node* currNode = head;
    while(currIndex != index)
    {
        if(index == 0) break;
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode)
    {
        if(prevNode)
        {
            prevNode->next = currNode->next;
            delete currNode;
        }
        else
        {
            head = currNode->next;
            delete currNode;
        }
    }
    return 0;
}


void LinkedList::output()
{
    ofstream file;
    file.open("Juhak.Lee.lList.txt");
    Node* head = this->head;
    while(head)
    {
        file << head->data <<"\t";
        head = head->next;
    }
    cout<<endl;
    file<<"\n";
}

int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();
    
    
    list -> insert(0,11);
    list -> insert(1,10);
    list -> insert(2,9);
    list -> insert(3,8);
    list -> insert(4,7);
    list -> insert(5,6);
    list -> insert(6,5);
    list -> insert(7,4);
    list -> insert(8,3);
    list -> insert(9,2);
    list -> insert(10,1);
    list -> remove(5);
    list -> insert(8,100);
    
    list -> output();
  
    
    
    
    return 0;
}