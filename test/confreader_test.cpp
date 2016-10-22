#include "../lib/confreader/confreader.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(Confreader, ConfreaderGet) {
  confreader conf("../../test/test_data/confreader_test");
  EXPECT_EQ(std::string("value"), conf.get("key"));
}

TEST(Confreader, ConfreaderGetInt) {
  confreader conf("../../test/test_data/confreader_test");
  EXPECT_EQ(int(8), conf.get_int("bits"));
}
