#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct douLinkedList {
    Node* head;

    douLinkedList() {
        head = nullptr;
    }

    // tạo node mới
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

    // truy cập vào vị trí i
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

    // thêm vào đầu 
    void insertHead(int value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            newNode = head;
        }
    }

    // thêm vào cuối
    void insertTail(int value) {
        Node* newNode = createNode(value);
        if (head == nullptr){
            head = newNode;
        }
        else {
            Node* temp = head;
            while(temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // thêm vào vị trí i
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
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // xóa đầu
    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
    }

    // xóa cuối
    void deleteTail() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    // xóa vị trí i
    void deleteAt(int i) {
        if (head == nullptr) return;
        if (i == 0) {
            deleteHead();
            return;
        }
        Node* temp = head;
        int index = 0;
        while (temp->next != nullptr && index < i) {
            temp = temp->next;
            index++;
        }
        if (temp == nullptr) {
            std::cout << "Vị trí xóa không hợp lệ\n";
            return;
        }
        
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;

        delete temp;
    }

    // duyệt xuôi
    void dxuoi() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // duyệt ngược
    void printBackward(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}

};


int main() {
    douLinkedList lst;

    return 0;
}