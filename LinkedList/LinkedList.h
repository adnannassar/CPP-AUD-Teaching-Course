#include <iostream>
#include <stdbool.h>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        const char *data;
        Node *next;
        Node *before;
        Node(const char *data, Node *next, Node *before) : data(data), next(next), before(before) {}
    };

    typedef struct Node *node;

    node first;
    node last;
    int counter;

public:
    LinkedList();
    LinkedList(const LinkedList &orig);

    // ~LinkedList();
    void append(const char *data);
    bool isEmpty();
    void insert(const char *data, int p);
    void remove(int p);
    const char *get(int p);
    int index_of(const char *data);
    const char *getFirst();
    const char *getLast();
    void printList();
    int countElements();
};

LinkedList::LinkedList() : first(nullptr), last(nullptr), counter(0) {}
bool LinkedList::isEmpty()
{
    return first == nullptr || counter == 0;
}
void LinkedList::append(const char *data)
{
    node toBeAdded = new Node(data, nullptr, nullptr);
    // add first
    if (isEmpty())
    {
        first = last = toBeAdded;
        counter++;
    }
    // add last
    else
    {
        last->next = toBeAdded;
        toBeAdded->before = last;
        last = toBeAdded;
        counter++;
    }
}
void LinkedList::printList()
{
    node ptr = first;
    while (ptr->next != nullptr)
    {

        cout << ptr->data << " <--> ";
        ptr = ptr->next;
    }
    cout << ptr->data << endl;
}
int LinkedList::countElements()
{
    return counter;
}
const char *LinkedList::get(int p)
{
    if (isEmpty())
    {
        return "List ist leer!";
    }
    else if (p < 0 || p > counter)
    {
        return "Ungültige Position!";
    }
    else
    {
        node ptr = first;
        int i = 0;
        while (i != p)
        {
            i++;
            ptr = ptr->next;
        }
        return ptr->data;
    }
}
int LinkedList::index_of(const char *data)
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        node ptr = first;
        int i = 0;
        while (ptr != nullptr)
        {
            if (data == ptr->data)
            {
                return i;
            }
            ptr = ptr->next;
            i++;
        }
        return -1;
    }
}
const char *LinkedList::getFirst()
{
    return isEmpty() ? nullptr : first->data;
    /*

      if(isEmpty()){
          return nullptr;
      }else{
         return first->data;
      }

  */
}
const char *LinkedList::getLast()
{
    return isEmpty() ? nullptr : last->data;
}
void LinkedList::insert(const char *data, int p)
{
    node toBeAdded = new Node(data, nullptr, nullptr);
    if (p < 0)
    {
        cout << "Ungültige Position!" << endl;
    }

    else if (p == 0)
    {
        toBeAdded->next = first;
        first->before = toBeAdded;
        first = toBeAdded;
        counter++;
    }
    else if (p >= counter)
    {
        toBeAdded->before = last;
        last->next = toBeAdded;
        last = toBeAdded;
        counter++;
    }
    else
    {
        node ptr = first;
        int i = 0;
        while (i != p)
        {
            i++;
            ptr = ptr->next;
        }
        ptr->before->next = toBeAdded;
        toBeAdded->before = ptr->before;
        ptr->before = toBeAdded;
        toBeAdded->next = ptr;
        counter++;
    }
}
void LinkedList::remove(int p)
{
    node toBeDeleted;
    if (isEmpty())
    {
        cout << "List ist leer!" << endl;
    }
    else if (counter == 1)
    {
        toBeDeleted = first;
        first = last = nullptr;
        delete toBeDeleted;
        counter--;
    }
    else if (p == 0)
    {
        toBeDeleted = first;
        first->next->before = nullptr;
        first = first->next;
        delete toBeDeleted;
        counter--;
    }
    else if (p >= counter)
    {
        toBeDeleted = last;
        last->before->next = nullptr;
        last = last->before;
        delete toBeDeleted;
        counter--;
    }
    else
    {
        node ptr = first;
        int i = 0;
        while (i != p)
        {
            i++;
            ptr = ptr->next;
        }
        toBeDeleted = ptr;
        ptr->before->next = ptr->next;
        ptr->next->before = ptr->before;
        delete toBeDeleted;
        counter--;
    }
}