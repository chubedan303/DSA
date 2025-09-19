#include <iostream>

const int MAX = 1000;

struct List {
    
    int data[MAX];
    int size;

    // khởi tạo list
    List() {
        size = 0;
    }

    // truy cập vào vị trí i
    int get(int i) {
        if (i < 0 || i >= size) {
            std::cout << "Vị trị truy cập ngoài phạm vi\n";
            return -1;
        }
        return data[i];
    }

    // chèn vào đầu
    void insertHead(int value) {
        if (size == MAX) {
            std::cout << "Danh sách đã đầy\n";
            return;
        }
        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
    }

    //chèn vào cuối
    void insertTail(int value) {
        if (size == MAX) {
            std::cout << "Danh sách đã đầy\n";
            return;
        }
        data[size++] = value;
    }

    //chèn vào vị trí i
    void insertAt(int i, int value) {
        if (size == MAX) {
            std::cout << "Danh sách đã đầy\n";
            return;
        }
        if (i < 0 || i > size) {
            std::cout << "Vị trí chèn không hợp lệ\n";
            return;
        }

        for (int j = size; j > i; i--) {
            data[j] = data[j - 1];
        }
        data[i] = value;
        size++;
    }

    // xóa phần tử đầu
    void deleteHead() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    // xóa phần tử cuối
    void deleteTail() {
        if (size == 0) return;
        size--;
    }

    // xóa phần tử ở vị trí i;
    void deleteAt(int i) {
        if (i < 0 || i >= size) {
            std::cout << "Vị trí xóa không hợp lệ\n";
            return;
        }
        for (int j = i; i < size - 1; i++) {
            data[j] = data[j + 1];
        }
        size--;
    }

    // duyệt xuôi
    void dxuoi() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }

    void dnguoc() {
        for (int i = size - 1; i >= 0; i--) {
            std::cout << data[i] <<  " ";
        }
        std::cout << "\n";
    }
};


int main() {
    List lst;

    return 0;
}