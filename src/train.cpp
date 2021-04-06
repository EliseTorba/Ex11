// Copyright 2021 Elise
#include "train.h"

#include <cstdlib>
#include <iostream>

void Cage::on() { light = true; }
void Cage::off() { light = false; }
bool Cage::get() const { return light; }
Train::Train() {
  this->first = nullptr;
  this->last = nullptr;
}
void Train::new_cage(bool light) {
  int count = 0;
  while (count < number_cars) {
    Cage* cage_new = new Cage;
    if (light == false) {
      cage_new->off();
    } else {
      cage_new->on();
    }
    if ((this->first == nullptr) && (this->last == nullptr)) {
      this->first = cage_new;
      this->last = cage_new;
    }
    if (this->first == this->last) {
      this->last = cage_new;
      this->first->next = cage_new;
      this->first->prev = cage_new;
      this->last->next = this->first;
      this->last->prev = this->first;
    } else {
      cage_new->prev = this->last;
      this->last->next = cage_new;
      this->last = cage_new;
      this->first->prev = this->last;
      this->last->next = this->first;
    }
    count++;
  }
}
void Train::print() {
  Cage* ptr = this->first;
  int i = 1;
  while (ptr != this->last) {
    std::cout << "Cage " << i << " - " << ptr->get() << std::endl;
    i++;
    ptr = ptr->next;
  }
  std::cout << "Cage " << i << " - " << ptr->get() << std::endl;
}
int Train::calculate_nc() {
  Cage* ptr_cage = this->first;
  ptr_cage->on();
  int nc = 1;
  while (true) {
    for (int i = 0; i < nc; i++) {
      ptr_cage = ptr_cage->next;
      ptr_cage->off();
    }
    for (int i = 0; i < nc; i++) {
      ptr_cage = ptr_cage->prev;
    }
    if (ptr_cage->get() == false) break;
    nc++;
  }
  return nc;
}
void Train::set_nc(int number_cars) {
    this->number_cars = number_cars;
}
int Train::get_nc() {
    return number_cars;
}
