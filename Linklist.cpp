#include <iostream>

struct Node {
    int data;
    Node* next;
};
struct LinkedList {
    Node* head;
    // khởi tạo
    LinkedList () {
        head = nullptr;
    }
    // Tạo node mới
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    // truy cập đến vị trí tại phần tử i
    int get(int i) {
        Node* temp = head;
        int index = 0;
        while(temp != nullptr && index < i) {
            temp = temp->next;
            index++;
        }
        if (temp == nullptr) {
            std::cout << "Vị trí truy cập không hợp lệ\n";
            return -1;
        }
        return temp->data;
    }

    // chèn vào đầu
    void insertHead(int value) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
    }

    // chèn vào cuối
    void insertTail(int value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // chèn vào vị trí i
    void insertAT(int i, int value) {
        if (i == 0) {
            insertHead(value);
            return;
        }

        Node* temp = head;
        int index = 0;
        while (temp != nullptr && index < i - 1) {
            temp = temp->next;
            index++;
        }
        if (temp == nullptr) {
            std::cout << "Vị trí chèn không hợp lệ";
            return;
        }
        Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // xóa phần tử đầu
    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    // xóa ở vị trí cuối
    void deleteTail() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // xóa phần tự tại vị trí i
    void deleteAt(int i) {
        if (head == nullptr) return;
        if (i == 0) {
            deleteHead();
            return;
        }
        Node* temp = head;
        int index = 0;
        while (temp->next != nullptr && index < i - 1) {
            temp = temp->next;
            index++;
        }
        if (temp->next == nullptr) {
            std::cout << "Vị trí xóa không hợp lệ\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // duyệt xuôi 
    void dxuoi() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
    // duyệt ngược
    void dequy(Node* node) {
        if (node == nullptr) return;
        dequy(node->next);
        std::cout << node->data << " ";
    }
    void dnguoc() {
        dequy(head);
        std::cout << "\n";
    }
};
int main() {
    LinkedList list;
    
    return 0;
}