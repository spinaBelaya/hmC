#include "int_list_t.h"

int_list_t::int_list_t() {
    head = new node_t(0, nullptr, nullptr);
    tail = new node_t(0, head, nullptr);
    head->next = tail;
    _size = 0;
}

int_list_t::~int_list_t() {
    clear();
    delete head;
    delete tail;
}

size_t int_list_t::size() const {
    return _size;
}

bool int_list_t::empty() const {
    return _size == 0;
}

void int_list_t::swap(int_list_t &other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(_size, other._size);
}

int &int_list_t::back() {
    return tail->prev->value;
}


const int int_list_t::front() const {
    return head->next->value;
}

int_list_t::node_t *int_list_t::get(int pos) const {
    if (pos <= size() / 2) {
        node_t *pointer = head;
        do {
            pointer = pointer->next;
        } while (pos--);

        return pointer;
    } else {
        pos = pos - size() + 1;
        pos = abs(pos);
        node_t *pointer = tail;
        do {
            pointer = pointer->prev;
        } while (pos--);

        return pointer;
    }

}

void int_list_t::insert(size_t pos, int new_val) {

    if (pos == _size) {
        node_t *pointer = tail;
        node_t *new_node = new node_t(new_val, pointer->prev, pointer);
        pointer->prev->set_next(new_node);
        pointer->set_prev(new_node);
        _size++;
        return;
        }
    node_t *pointer = get(pos);
    node_t *new_node = new node_t(new_val, pointer->prev, pointer);
    pointer->prev->set_next(new_node);
    pointer->set_prev(new_node);

    _size++;
}

int &int_list_t::operator[](size_t pos) {
    node_t *pointer = get(pos);
    return pointer->value;
}

const int &int_list_t::operator[](size_t pos) const {
    node_t *pointer = get(pos);
    return pointer->value;
}

void int_list_t::push_front(int new_val) {
    insert(0, new_val);
}

void int_list_t::push_back(int new_val) {
    insert(_size, new_val);
}

void int_list_t::erase(size_t pos) {
    node_t *pointer = get(pos);
    pointer->prev->set_next(pointer->next);
    pointer->next->set_prev(pointer->prev);
    delete pointer;
    _size--;
}

void int_list_t::pop_front() {
    erase(0);
}

void int_list_t::pop_back() {
    erase(_size - 1);
}

int_list_t::int_list_t(const int_list_t &other) : int_list_t() {

    auto pointer = other.head;
    pointer = pointer->next;
    while (pointer != other.tail) {
        push_back(pointer->value);
        pointer = pointer->next;
    }
}

int_list_t::int_list_t(size_t count, int value) : int_list_t() {
    for (int i = 0; i < count; ++i) {
        push_front(value);
    }
}

int_list_t &int_list_t::operator=(const int_list_t &other) {
    if (this != &other) {
        int_list_t tmp(other);
        swap(tmp);
    }
    return *this;
}

void int_list_t::clear() {
    node_t *pointer = head->next;
    node_t *next = pointer->next;
    for (int i = 0; i < size(); ++i) {
        delete pointer;
        pointer = next;
        next = pointer->next;
    }
    head->next = tail;
    tail->prev = head;
    _size = 0;
}

std::ostream &operator<<(std::ostream &stream, const int_list_t &list) {
    auto pointer = list.head;
    pointer = pointer->next;
    while (pointer != list.tail) {
        stream << pointer->value << ' ';
        pointer = pointer->next;
    }
    return stream;
}

int_list_t int_list_t::splice(size_t start_pos, size_t count) {
    int_list_t new_list;

    node_t *pointer = head;

    for (int i = 0; i < start_pos + 1; ++i) {
        pointer = pointer->next;
    }

    node_t *prev_p = pointer->prev;
    new_list.head->set_next(pointer);
    pointer->set_prev(new_list.head);

    for (int i = 0; i < count - 1; ++i) {
        pointer = pointer->next;
    }

    new_list.tail->set_prev(pointer);
    node_t *next_p = pointer->next;
    pointer->set_next(new_list.tail);
    prev_p->set_next(next_p);
    next_p->set_prev(prev_p);
    _size -= count;
    new_list._size = count;
    return new_list;
}

std::istream &operator>>(std::istream &stream, int_list_t &list) {
    list.clear();
    int i = 0;
    std::string str_list;
    stream >> str_list;
    while (i < str_list.length()) {
        list.push_back(str_list[i]-'0');
        i++;
    }
    return stream;
}

int_list_t &int_list_t::merge(int_list_t &other) {
    if (this != &other) {
        
        tail->prev->set_next(other.head->next);
        other.head->next->set_prev(tail->prev);
        tail->set_prev(other.tail->prev);
        other.tail->prev->set_next(tail);
        other.head->set_next(other.tail);
        other.tail->set_prev(other.head);
        _size += other.size();
        other._size = 0;
    }
    return *this;
}

void int_list_t::reverse() {
    node_t *tmp = head->next;
    node_t *pointer = head->next;
    node_t *new_tmp;

    while (pointer != tail) {
        new_tmp = pointer->next;
        std::swap(pointer->prev, pointer->next);
        pointer = new_tmp;
    }
    head->next = tail->prev;
    head->next->prev = head;
    tail->prev = tmp;
    tail->prev->next = tail;
}
