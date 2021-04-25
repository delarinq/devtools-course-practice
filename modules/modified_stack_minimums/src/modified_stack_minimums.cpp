// Copyright 2021 Novozhilova Ekaterina

#include "include/modified_stack_minimums.h"
#include <vector>
#include <utility>

ModifiedStack::ModifiedStack(int _size) {
        st_size = _size;
        last = -1;
        mem.resize(st_size);
}

ModifiedStack::ModifiedStack(const ModifiedStack &tmp) {
    st_size = tmp.st_size;
    last = tmp.last;
    mem.resize(st_size);
    for (int i = 0; i < st_size; i++) {
        mem[i] = tmp.mem[i];
    }
}

ModifiedStack& ModifiedStack::operator=(const ModifiedStack &tmp) {
    if (st_size != tmp.st_size) {
        if (st_size != 0) {
            mem.resize(0);
        }
        st_size = tmp.st_size;
        mem.resize(st_size);
    }
    last = tmp.last;
    for (int i = 0; i < st_size; i++) {
        mem[i] = tmp.mem[i];
    }
    return *this;
}

void ModifiedStack::push(double el) {
    if (last == -1) {
        std::pair<double, double> elem(el, el);
        mem[0] = elem;
        last++;
    } else if (last < st_size) {
        double last_min = mem[last].second;
        if (last_min > el) {
            std::pair<double, double> elem(el, el);
            last++;
            mem[last] = elem;
        } else if (last_min < el) {
            std::pair<double, double> elem(el, last_min);
            last++;
            mem[last] = elem;
        }
    } else {
        throw - 1;
    }
}

bool ModifiedStack::isFull() {
    if (last == st_size - 1) {
        return true;
    } else {
        return false;
    }
}

bool ModifiedStack::isEmpty() {
    if (last == -1) {
        return true;
    } else {
        return false;
    }
}

void ModifiedStack::pop() {
    mem[last] = std::pair<double, double>(0.0, 0.0);
    last--;
}

double ModifiedStack::getTop() {
    return mem[last].first;
}

double ModifiedStack::getMin() {
    return mem[last].second;
}

bool ModifiedStack::operator==(const ModifiedStack& tmp) {
    if (st_size != tmp.st_size) {
        return false;
    } else {
        for (int i = 0; i < st_size; i++) {
            if (mem[i] != tmp.mem[i]) {
                return false;
            }
        }
    }
    return true;
}

bool ModifiedStack::operator!=(const ModifiedStack& tmp) {
    if (st_size != tmp.st_size) {
        return true;
    } else {
        for (int i = 0; i < st_size; i++) {
            if (mem[i] != tmp.mem[i]) {
                return true;
            }
        }
    }
    return false;
}

int ModifiedStack::getSize() {
    return st_size;
}

int ModifiedStack::getLast() {
    return last;
}
