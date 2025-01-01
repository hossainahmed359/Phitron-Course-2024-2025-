// https://leetcode.com/problems/design-linked-list/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyLinkedList
{
public:
    int val = NULL;
    MyLinkedList *next = NULL;

    MyLinkedList() {}

    int get(int index)
    {
        MyLinkedList *tmp = this;
        for (int i = 0; i < index; i++)
        {
            if (tmp == NULL || tmp->next == NULL)
            {
                return -1;
            }
            tmp = tmp->next;
        }
        return tmp->val;
    }

    void addAtHead(int val)
    {

        if (this->val == NULL)
        {
            this->val = val;
            return;
        }

        MyLinkedList *tmp = new MyLinkedList();

        tmp->val = this->val;
        tmp->next = this->next;
        this->val = val;
        this->next = tmp;
    }

    void addAtTail(int val)
    {
        MyLinkedList *tmp = new MyLinkedList();
        tmp->val = val;

        MyLinkedList *curr = this;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = tmp;
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        MyLinkedList *tmp = new MyLinkedList();
        tmp->val = val;

        MyLinkedList *curr = this;
        for (int i = 0; i < index - 1; i++)
        {
            if (curr == NULL || curr->next == NULL)
            {
                return;
            }
            curr = curr->next;
        }

        tmp->next = curr->next;
        curr->next = tmp;
    }

    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            if (this->next != NULL)
            {
                this->val = this->next->val;
                MyLinkedList *tmp = this->next;
                this->next = this->next->next;
                delete tmp;
            }
            return;
        }

        MyLinkedList *curr = this;
        for (int i = 0; i < index - 1; i++)
        {
            if (curr == NULL || curr->next == NULL)
            {
                return;
            }
            curr = curr->next;
        }

        if (curr->next != NULL)
        {
            MyLinkedList *tmp = curr->next;
            curr->next = tmp->next;
            delete tmp;
        }
    }
};

// TEST SECTION

void print_linked_list(MyLinkedList *head)
{
    MyLinkedList *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

int main()
{
    vector<string> operations = {"MyLinkedList", "addAtHead", "addAtHead", "addAtHead", "addAtIndex", "deleteAtIndex", "addAtHead", "addAtTail", "get", "addAtHead", "addAtIndex", "addAtHead"};
    vector<vector<int>> values = {{}, {7}, {2}, {1}, {3, 0}, {2}, {6}, {4}, {4}, {4}, {5, 0}, {6}};

    MyLinkedList *obj = NULL;

    for (int i = 0; i < operations.size(); i++)
    {
        string op = operations[i];
        vector<int> val = values[i];

        if (op == "MyLinkedList")
        {
            obj = new MyLinkedList();
            cout << "Initialized LinkedList" << endl;
            print_linked_list(obj);
        }
        else if (op == "addAtHead" && obj)
        {
            obj->addAtHead(val[0]);
            cout << "Added " << val[0] << " at head" << endl;
            print_linked_list(obj);
        }
        else if (op == "addAtTail" && obj)
        {
            obj->addAtTail(val[0]);
            cout << "Added " << val[0] << " at tail" << endl;
            print_linked_list(obj);
        }
        else if (op == "addAtIndex" && obj)
        {
            obj->addAtIndex(val[0], val[1]);
            cout << "Added " << val[1] << " at index " << val[0] << endl;
            print_linked_list(obj);
        }
        else if (op == "get" && obj)
        {
            int result = obj->get(val[0]);
            cout << "Value at index " << val[0] << ": " << result << endl;
            print_linked_list(obj);
        }
        else if (op == "deleteAtIndex" && obj)
        {
            obj->deleteAtIndex(val[0]);
            cout << "Deleted at index " << val[0] << endl;
            print_linked_list(obj);
        }
    }

    print_linked_list(obj);

    return 0;
}
