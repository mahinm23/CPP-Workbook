// Reference solution for ../03_rule_of_three_five.cpp

#include <iostream>

class IntArray {
public:
    IntArray(int size) : size_(size), data_(new int[size]) {
        for (int i = 0; i < size_; i++) data_[i] = 0;
    }

    ~IntArray() {
        delete[] data_;
    }

    void set(int index, int value) {
        data_[index] = value;
    }

    int get(int index) const {
        return data_[index];
    }

    // Copy constructor - allocates its own array, copies values across
    IntArray(const IntArray& other) : size_(other.size_), data_(new int[other.size_]) {
        for (int i = 0; i < size_; i++) data_[i] = other.data_[i];
    }

    // Copy assignment - frees the old array first, then does the same deep copy
    IntArray& operator=(const IntArray& other) {
        if (this == &other) return *this;
        delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; i++) data_[i] = other.data_[i];
        return *this;
    }

private:
    int size_;
    int* data_;
};

int main() {
    IntArray a(5);
    for (int i = 0; i < 5; i++) a.set(i, i * 10);

    IntArray b = a;   // copy constructor
    b.set(0, 999);    // only b should change

    std::cout << "a[0] = " << a.get(0) << "\n";  // 0
    std::cout << "b[0] = " << b.get(0) << "\n";  // 999

    return 0;
}
