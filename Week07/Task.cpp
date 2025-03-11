#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class CircularBuffer {
private:
    vector<T> buffer;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t count;

public:
    // Constructor
    CircularBuffer(size_t size) : capacity(size), head(0), tail(0), count(0) {
        buffer.resize(capacity);
    }

    // Push an element into the buffer
    void push(const T& value) {
        if (count == capacity) {
            throw overflow_error("CircularBuffer is full");
        }
        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        ++count;
    }

    // Pop an element from the buffer
    T pop() {
        if (empty()) {
            throw underflow_error("CircularBuffer is empty");
        }
        T value = buffer[head];
        head = (head + 1) % capacity;
        --count;
        return value;
    }

    // Check if the buffer is empty
    bool empty() const {
        return count == 0;
    }

    // Get the number of elements in the buffer
    size_t size() const {
        return count;
    }

    // Custom forward iterator
    class Iterator {
    private:
        CircularBuffer<T>& cb;
        size_t index;
        size_t steps;

    public:
        Iterator(CircularBuffer<T>& buffer, size_t idx, size_t s = 0)
            : cb(buffer), index(idx), steps(s) {}

        // Dereference operator
        T& operator*() {
            return cb.buffer[index];
        }

        // Pre-increment operator
        Iterator& operator++() {
            index = (index + 1) % cb.capacity;
            ++steps;
            return *this;
        }

        // Post-increment operator
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Equality operator
        bool operator==(const Iterator& other) const {
            return &cb == &other.cb && index == other.index && steps == other.steps;
        }

        // Inequality operator
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    // Begin iterator
    Iterator begin() {
        return Iterator(*this, head);
    }

    // End iterator (circular, so it wraps around)
    Iterator end() {
        return Iterator(*this, tail, count);
    }
};

int main() {
    CircularBuffer<int> c(5);

    // Assign values
    for (int i = 0; i < 5; ++i) {
        c.push(i);
    }

    // Update values
    for (CircularBuffer<int>::Iterator i = c.begin(); i != c.end(); ++i) {
        *i = *i + 1;
    }

    // Get values (uses iterators)
    for (int i : c) {
        cout << i << " ";
    }
    cout << endl;

    // Testing circular iteration
    auto i = c.begin();
    i++;
    ++i;
    int count = 0;
    while (count < c.size()) {
        cout << *i << " ";
        ++i;
        count++;
    }
    cout << endl;

    // Empty container and get values
    while (!c.empty()) {
        cout << c.pop() << " ";
    }
    cout << endl;

    return 0;
}
