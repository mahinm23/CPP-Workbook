#include <iostream>

/*
Concept: The rule of three/five

If a class manages a resource manually (raw pointer, file handle, etc.), the
compiler's DEFAULT copy constructor and copy assignment operator just copy each
member byte-for-byte ("shallow copy"). For a raw pointer member, that means two
objects end up pointing at the SAME allocated memory. When one is destroyed and
its destructor frees that memory, the other object is left holding a dangling
pointer - using it is undefined behavior, and if both destructors run, you free
the same memory twice (a crash).

Rule of three: if you write a custom destructor, you almost certainly also need
a custom copy constructor and copy assignment operator, to make copies allocate
their OWN memory instead of sharing the original's.

Rule of five: C++11 added move semantics - a move constructor and move assignment
operator, which STEAL another object's resource instead of copying it (leaving
the source in an empty/safe state). If you're managing a resource, you generally
want all five: destructor, copy constructor, copy assignment, move constructor,
move assignment.

class Buffer {
public:
    Buffer(size_t size) : size_(size), data_(new int[size]) {}

    ~Buffer() { delete[] data_; }                       // 1. destructor

    Buffer(const Buffer& other) : size_(other.size_), data_(new int[other.size_]) {
        for (size_t i = 0; i < size_; i++) data_[i] = other.data_[i];
    }                                                      // 2. copy constructor - own allocation

    Buffer& operator=(const Buffer& other) {              // 3. copy assignment
        if (this == &other) return *this;
        delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        for (size_t i = 0; i < size_; i++) data_[i] = other.data_[i];
        return *this;
    }

private:
    size_t size_;
    int* data_;
};

(Move constructor/assignment are the other two of the "five" - we'll touch those
briefly here, but they lean on std::move which you'll cover properly with smart
pointers/references in your upcoming videos. Don't worry about perfecting them yet.)
*/

/*
Exercise 3:

Write a class IntArray that wraps a raw dynamically-allocated array:

1. Constructor IntArray(int size) that allocates `new int[size]` and stores size.
2. Destructor that deletes the array.
3. A method set(int index, int value) and get(int index) to read/write elements.
4. Write the COPY CONSTRUCTOR and COPY ASSIGNMENT OPERATOR by hand, so copying an
   IntArray allocates a fresh array and copies the values across (not the pointer).
5. In main(): create an IntArray a(5), set a few values, copy it into a second
   IntArray b = a (triggers your copy constructor), change a value in b, and
   print both a and b to confirm they're independent (changing b did NOT change a).
6. (Optional, if you want to peek ahead) try deleting your copy constructor/assignment
   by writing them as "= delete;" instead, and see what compiler error you get when
   you try to copy - this is how you'd forbid copying entirely for a resource that
   should only ever be moved.
*/

int main() {
    return 0;
}
