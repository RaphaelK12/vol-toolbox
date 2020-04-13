#include <gtest/gtest.h>
#include <voltlbx/utils.h>

using namespace voltlbx;

void check_locate_index(const std::vector<double>& xs)
{
    for (long i = 0; i < xs.size(); ++i)
    {
        double x = xs[i];
        if (std::abs(x) > 0.0)
        {
            const double x_l = x * (1.0 - std::numeric_limits<double>::epsilon());
            ASSERT_EQ(locate_left_index(xs, x_l), i - 1);

            const double x_p = x * (1.0 + std::numeric_limits<double>::epsilon());
            ASSERT_EQ(locate_left_index(xs, x_p), i);
        }
        else
        {
            const double x_l = -std::numeric_limits<double>::min();
            ASSERT_EQ(locate_left_index(xs, x_l), i - 1);

            const double x_p = std::numeric_limits<double>::min();
            ASSERT_EQ(locate_left_index(xs, x_p), i);
        }
    }
}

TEST(Utils, CheckLocate)
{
    check_locate_index({ 0.0 });
    check_locate_index({ 3.14 });
    check_locate_index({ 0.0, 1.0, 2.0 });
}

void check_longest_inc_seq(const std::vector<double>& a, 
                           const std::vector<std::size_t>& ref_seq)
{
    auto seq = longest_increasing_subsequence(a);   
    ASSERT_EQ(seq.size(), ref_seq.size());
    for (std::size_t i = 0; i < seq.size(); ++i)
    {
        ASSERT_EQ(seq[i], ref_seq[i]);
    }
}

TEST(Utils, LongestIncreasingSeq)
{
    check_longest_inc_seq({ }, { });
    check_longest_inc_seq({ 1.0 }, { 0 });
    check_longest_inc_seq({ 10, 22, 9, 33, 21, 50, 41, 60 },
                          { 0, 1, 3, 6, 7 });
    check_longest_inc_seq({ 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 },
                          { 0, 4, 6, 9, 13, 15 });
}