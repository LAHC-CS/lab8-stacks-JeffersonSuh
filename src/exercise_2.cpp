#include <iostream>
#include <cassert>

class IntLinkList {
public:
    class IntNode {
    public:
        int value;
        IntNode* next;
        IntNode(int val) {
            value = val;
            next = nullptr;
        }
    };

    IntNode* head;
    IntNode* tail;
    int size;

    IntLinkList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~IntLinkList() {
        while (head) {
            IntNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int Size() const {
        return size;
    }

    int Get(int index) const {
        assert(index >= 0 && index < size);
        IntNode* iterator = head;
        for (int i = 0; i < index; i++) {
            iterator = iterator->next;
        }
        return iterator->value;
    }

    void Set(int index, int value) {
        assert(index >= 0 && index < size);
        IntNode* iterator = head;
        for (int i = 0; i < index; i++) {
            iterator = iterator->next;
        }
        iterator->value = value;
    }

    void Add(unsigned int index, int value) {
        assert(index >= 0 && index <= size);
        IntNode* element = new IntNode(value);
        if (head == nullptr) {
            // New List
            head = element;
            tail = head;
        } else if (index == size) {
            // Add to the end of the list
            tail->next = element;
            tail = element;
        } else if (index == 0) {
            // Add at the beginning of the list
            element->next = head;
            head = element;
        } else {
            // Add in the middle
            IntNode* iterator = head;
            for (int i = 0; i < index - 1; i++) {
                iterator = iterator->next;
            }
            element->next = iterator->next;
            iterator->next = element;
        }
        size++;
    }

    void Remove(unsigned int index) {
        assert(index >= 0 && index < size);
        if (index == 0) {
            IntNode* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            IntNode* iterator = head;
            for (unsigned int i = 0; i < index - 1; i++) {
                iterator = iterator->next;
            }
            IntNode* temp = iterator->next;
            iterator->next = temp->next;
            delete temp;
            if (temp == tail) {
                tail = iterator;
            }
        }
        size--;
    }
};

class Stack {
public:
    IntLinkList list;

    Stack() {}

    ~Stack() {}

    int Size() const {
        return list.Size();
    }

    void Push(int value) {
        list.Add(list.Size(), value);
    }

    void Pop() {
        assert(list.Size() > 0);
        list.Remove(list.Size() - 1);
    }
};

int main() {
    Stack myStack;

    myStack.Push(100);
    std::cout << "Size after push: " << myStack.Size() << std::endl;

    myStack.Push(200);
    std::cout << "Size after push: " << myStack.Size() << std::endl;

    myStack.Pop();
    std::cout << "Size after pop: " << myStack.Size() << std::endl;

    return 0;
}
