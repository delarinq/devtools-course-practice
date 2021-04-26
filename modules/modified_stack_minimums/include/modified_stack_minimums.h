// Copyright 2021 Novozhilova Ekaterina

#ifndef MODULES_MODIFIED_STACK_MINIMUMS_INCLUDE_MODIFIED_STACK_MINIMUMS_H_
#define MODULES_MODIFIED_STACK_MINIMUMS_INCLUDE_MODIFIED_STACK_MINIMUMS_H_

#include <utility>
#include <vector>

class ModifiedStack {
 private:
    std::vector<std::pair<double, double>> mem;
    int last;
    int st_size;

 public:
    explicit ModifiedStack(int _size = 0);
    ModifiedStack(const ModifiedStack &tmp);
    ModifiedStack &operator=(const ModifiedStack &tmp);
    ~ModifiedStack() {}
    void push(double el);

    bool isFull() const;

    void pop();

    bool isEmpty() const;

    double getTop() const;

    double getMin() const;
    bool operator==(const ModifiedStack& tmp) const;

    bool operator!=(const ModifiedStack& tmp) const;

    int getSize() const;
    int getLast() const;
};

#endif  // MODULES_MODIFIED_STACK_MINIMUMS_INCLUDE_MODIFIED_STACK_MINIMUMS_H_
