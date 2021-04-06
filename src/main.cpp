// Copyright 2021 Elise
#include "train.h"

int main() {
  unsigned int seed = time(nullptr);
  int state = rand_r(&seed) % 100;

  Train train;
  train.set_nc(7);
  train.new_cage(state / 2);
  train.print();
  std::cout <<  train.calculate_nc() << std::endl;
  return 0;
}
