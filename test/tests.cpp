// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <string>
#include <ctime>
#include "train.h"

TEST(Train_Test, test1) {
  Train train1;
  train1.set_nc(8);
  EXPECT_EQ(8, train1.get_nc());
}

TEST(Train_Test, test2) {
  unsigned int seed = time(nullptr);
  int state = rand_r(&seed) % 100;
  Train train1;
  train1.set_nc(67);
  train1.new_cage(state / 2);
  EXPECT_EQ(67, train1.calculate_nc());
}

TEST(Train_Test, test3) {
  unsigned int seed = time(nullptr);
  int state = rand_r(&seed) % 100;
  Train train1;
  unsigned int seed = time(nullptr);
  int nc = rand_r(&seed) % 100;
  train1.set_nc(nc);
  train1.new_cage(state / 2);
  EXPECT_EQ(nc, train1.calculate_nc());
}

