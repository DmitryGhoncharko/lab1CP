#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& item) {
        elements.push_back(item);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            std::cerr << "Error: Stack is empty. Cannot pop.\n";
            exit(EXIT_FAILURE);
        }
    }

    T& top() {
        if (!elements.empty()) {
            return elements.back();
        } else {
            std::cerr << "Error: Stack is empty. Returning reference to invalid memory.\n";
            exit(EXIT_FAILURE);
        }
    }

    const T& top() const {
        if (!elements.empty()) {
            return elements.back();
        } else {
            std::cerr << "Error: Stack is empty. Returning reference to invalid memory.\n";
            exit(EXIT_FAILURE);
        }
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};
