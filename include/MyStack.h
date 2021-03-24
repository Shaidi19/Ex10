// Copyright 2021 Sharibzhanova Diana
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <class T>
class MyStack {
 private:
  int size_max;
  unsigned int size;
  T* data;

 public:
  explicit MyStack(unsigned int size) {
    size = 0;
    size_max = size;
    data = new T[size_max];
  }

  MyStack(const MyStack& new_one) {
    size = new_one.size;
    size_max = new_one.size_max;
    data = new T[size_max];
    for (unsigned i = 0; i < size; i++) data[i] = new_one.data[i];
  }

  ~MyStack() {
    delete[] data;
  }

  bool isFull() const {
    if (size_max == size) {
      return 1;
    } else
      return 0;
  }

  bool isEmpty() const {
    if (size_max == 0) {
      return 1;
    } else
      return 0;
  }

  T get() const {
    if (!isEmpty())
      return data[size - 1];
  }

  T pop() {
    if (!isEmpty()) {
      size = size-1;
      return data[size];
    }
  }

  void push(T value) {
    if (!isFull()) {
      data[size++] = value;
    }
  }
};




#endif  // INCLUDE_MYSTACK_H_