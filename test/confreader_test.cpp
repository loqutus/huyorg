#include "../lib/confreader/confreader.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(Confreader, ConfreaderGet) {
    confreader conf("../../test/master.conf");
    EXPECT_EQ(std::string("::1"), conf.get("host"));
}

TEST(Confreader, ConfreaderGetInt) {
    confreader conf("../../test/master.conf");
    EXPECT_EQ(int(9999), conf.get_int("port"));
}
