#pragma once
#include "List.h"
#include <iostream>
#include <stdexcept>
using std::cout;
using std::endl;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    List() : head(nullptr), size(0) {}

    ~List() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        size = 0;
    }

    void insert(const T& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        size++;
    }

    bool remove(const T& value) {
        if (head == nullptr) {
            return false;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        if (current->next == nullptr) {
            return false;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
        return true;
    }

    int getSize() const {
        return size;
    }

    Node* getHead() const {
        return head;
    }

    void checkEmptyList() const {
        if (size == 0) {
            throw std::out_of_range("List is empty.");
        }
    }

    T getElementAt(int index) const {
        checkEmptyList();
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index.");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
};
