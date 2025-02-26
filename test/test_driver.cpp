#include <gtest/gtest.h>

// ReSharper disable CppUnusedIncludeDirective
#include <suites/bogus_suite.hpp>
// ReSharper enable CppUnusedIncludeDirective

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
