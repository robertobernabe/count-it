#include <gtest/gtest.h>
#include <countit/countit.hpp>
#include <countit/system.hpp>

using namespace robertobernabe::countit;

TEST (countit, add_default_counter)
{
    auto dir = System::create_and_get_tmp_dir_path();
    auto m = CountIt(dir);

    m.add_counter();
    auto c = m.get_counter();
    EXPECT_EQ(c.get_count(), 1);
}

TEST (countit, reset_counter)
{
    auto dir = System::create_and_get_tmp_dir_path();
    auto m = CountIt(dir);

    m.add_counter();
    auto c = m.get_counter();
    EXPECT_EQ(c.get_count(), 1);
    m.reset_counter();
    c = m.get_counter();
    EXPECT_EQ(c.get_count(), 0);
}

TEST (countit, remove_counter)
{
    auto dir = System::create_and_get_tmp_dir_path();
    auto m = CountIt(dir);

    m.add_counter("test");
    auto c = m.get_counter("test");
    EXPECT_EQ(c.get_count(), 1);
    m.remove_counter("test");
    c = m.get_counter("test");
    EXPECT_TRUE(c.get_is_empty());
}

TEST (system, create_and_get_tmp_dir)
{
    auto dir = System::create_and_get_tmp_dir_path();
    EXPECT_TRUE(true);
}
