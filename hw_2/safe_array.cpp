#include <iostream>

template<class T>
class safe_cust_array {
private:
    T *array_t;
    size_t array_size;

public:
    explicit safe_cust_array(size_t size) {
        array_size = size;
        array_t = new T[size];
    }

    safe_cust_array(const safe_cust_array &current) {
        array_size = current.array_size;
        array_t = new T[array_size];
        for (int i = 0; i < array_size; i++) {
            array_t[i] = current[i];
        };
    }

    void operator=(safe_cust_array &current) {
        if (this != &current) {
            delete[] array_t;
            array_size = current.array_size;
            array_t = new T[array_size];
            for (int i = 0; i < array_size; i++) {
                array_t[i] = current[i];
            };
        };
    }

    const T operator[](int index) const {
        if (index < 0 || index >= array_size) {
            std::cout << "Index out of range";
            exit(-1);
        };

        return array_t[index];
    }

    T &operator[](int index) {
        if (index < 0 || index >= array_size) {
            std::cout << "Index out of range";
            exit(-1);
        };

        return array_t[index];
    }

    ~safe_cust_array() {
        delete[] array_t;
    }
};

int main() {
    safe_cust_array<int> cur(10);
    cur[2] = 7;
    std::cout << cur[2];
    return 0;
} 