#include <iostream>
#include <cassert>

// IntLinkList from Lab#7
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

/* Stack using Arrays
class IntLinkStack {
private:
    class IntNode {
    public:
        int value;
        IntNode* next;
        IntNode() {
            value = 0;
            next = nullptr;
        }
        IntNode(int value) {
            this->value = value;
            this->next = nullptr;
        }
    };

    IntNode* head;
    int size;

public:
    IntLinkStack() : head(nullptr), size(0) {}

    int Size() const {
        return size;
    }

    void Push(int element) {
        // Create a node to hold the element
        IntNode* new_node = new IntNode(element);

        if (head == nullptr) {
            // Start of a new stack
            head = new_node;
        } else {
            // Push element onto the stack
            new_node->next = head;
            head = new_node;
        }

        size++;
    }

    int Pop() {
        assert(size > 0 && "Cannot pop from an empty stack!");

        int return_value = head->value;

        IntNode* temp_node = head->next;

        delete head;

        head = temp_node;

        size--;

        return return_value;
    }
};
*/

class IntLinkStack {
private:
    IntLinkList list;

public:
    IntLinkStack() {}

    int Size() const {
        return list.Size();
    }

    void Push(int element) {
        list.Add(list.Size(), element);
    }

    int Pop() {
        assert(list.Size() > 0 && "Cannot pop from an empty stack!");

        int return_value = list.Get(list.Size() - 1);
        list.Remove(list.Size() - 1);
        return return_value;
    }
};

int main() {
    IntLinkStack myStack;

    // Pushing elements onto the stack
    myStack.Push(10);
    myStack.Push(20);
    myStack.Push(30);
    myStack.Push(40);
    myStack.Push(50);

    std::cout << "Stack size after pushing elements: " << myStack.Size() << std::endl;

    // Popping elements from the stack
    std::cout << "Popped element: " << myStack.Pop() << std::endl;
    std::cout << "Popped element: " << myStack.Pop() << std::endl;

    std::cout << "Stack size after popping elements: " << myStack.Size() << std::endl;

    return 0;
}