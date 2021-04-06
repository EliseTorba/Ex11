// Copyright 2021 Elise
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_
#include <iostream>
#include <ctime>
class Cage {
 private:
  bool light;

 public:
  Cage* next;
  Cage* prev;
  Cage() : light(false), next(nullptr), prev(nullptr) {}
  void on();
  void off();
  bool get() const;
};
class Train {
 private:
  Cage* first;
  Cage* last;
  int number_cars;

 public:
  Train();
  void new_cage(bool light);
  void print();
  int calculate_nc();
  void set_nc(int number_cars);
  int get_nc();
};
#endif  // INCLUDE_TRAIN_H_
