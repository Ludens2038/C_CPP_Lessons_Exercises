#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory>

namespace MC {
    template<typename T>
    class List {
    public:
        List() {
            std::cout << "Constructor called!" << std::endl;
        }

        ~List() {
            std::cout << "Destructor called!" << std::endl;
            clear();
        }

        List(const List &rhs) {
            std::cout << "Copy constructor called!" << std::endl;
            std::shared_ptr<Node> current = rhs.head;
            while (current != nullptr) {
                push_back(current->value);
                current = current->next;
            }
        }

        List &operator=(const List &rhs) {
            std::cout << "Copy assignment operator called!" << std::endl;
            clear();

            std::shared_ptr<Node> current = rhs.head;
            while (current != nullptr) {
                push_back(current->value);
                current = current->next;
            }
            return *this;
        }

        int size() const {
            int count = 0;
            std::shared_ptr<Node> current = head;
            while (current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
        }

        int empty() const {
            if (head == nullptr) {
                return 1;
            }
            return 0;
        }

        void clear() {
            if (head == nullptr) {
                return;
            }
            head = nullptr;
            tail = nullptr;
        }

        void push_back(const T &value) {
            std::shared_ptr<Node> n = std::make_shared<Node>();
            n->value = value;

            if (head == nullptr) {
                head = n;
                tail = n;
            }
            else {
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
        }

        void pop_back() {
            if (head == nullptr) {
                throw std::logic_error("empty list");
            }

            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            }
            else {
                tail = tail->prev.lock();
                tail->next = nullptr;
            }
        }

        void push_front(const T &value) {
            std::shared_ptr<Node> n = std::make_shared<Node>();
            n->value = value;

            if (head == nullptr) {
                head = n;
                tail = n;
            }
            else {
                n->next = head;
                head->prev = n;
                head = n;
            }
        }

        void pop_front() {
            if (head == nullptr) {
                throw std::logic_error("empty list");
            }
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->next;
                head->prev = nullptr;
            }
        }

        void sort() {
            if (head == nullptr || head->next == nullptr) {
                return;
            }

            std::shared_ptr<Node> sorted = nullptr;
            std::shared_ptr<Node> current = head;

            while (current != nullptr) {
                std::shared_ptr<Node> next = current->next;
                current->prev = current->next = nullptr;

                if (sorted == nullptr || current->value < sorted->value) {
                    current->next = sorted;
                    if (sorted != nullptr) {
                        sorted->prev = current;
                    }
                    sorted = current;
                }
                else {
                    std::shared_ptr<Node> temp = sorted;
                    while (temp->next != nullptr && temp->next->value < current->value) {
                        temp = temp->next;
                    }
                    current->next = temp->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = current;
                    }
                    temp->next = current;
                    current->prev = temp;
                }

                current = next;
            }

            head = sorted;
            tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
        }

        T &front() const {
            if (head == nullptr) {
                throw std::logic_error("empty list");
            }
            return head->value;
        }

        T &back() const {
            if (head == nullptr) {
                throw std::logic_error("empty list");
            }
            return tail->value;
        }

        void print() {
            std::shared_ptr<Node> current = head;
            int count = 1;

            while (current != nullptr) {
                std::cout << "Entry " << count << ": " << current->value << std::endl;
                current = current->next;
                count++;
            }
        }

    private:
        struct Node {
            T value;
            std::shared_ptr<Node> next;
            std::weak_ptr<Node> prev;
        };

        std::shared_ptr<Node> head = nullptr;
        std::shared_ptr<Node> tail = nullptr;
    };
}
#endif
