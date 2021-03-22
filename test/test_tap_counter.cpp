#include <gtest/gtest.h>
#include <countit/tap_counter.hpp>

using namespace robertobernabe::countit;

TEST (tap_counter, tap_counter_operator_eq)
{
    auto tp1 = TapCounter();
    auto tp2 = TapCounter();
    EXPECT_TRUE(tp1 == tp2);
    tp1++;
    tp2++;
    EXPECT_TRUE(tp1 == tp2);
}

TEST (tap_counter, tap_counter_operator_not_eq)
{
    auto tp1 = TapCounter();
    auto tp2 = TapCounter();
    tp2++;
    EXPECT_TRUE(tp1 != tp2);
}