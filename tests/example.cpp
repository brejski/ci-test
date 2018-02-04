// Distributed under the MIT software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.
#include "gtest/gtest.h"
#include "lib/BoolExample.h"

namespace
{
    TEST(ExampleTest, myTest1)
    {
        BoolExample tmp;

        EXPECT_TRUE(tmp.AlwaysTrue());
    }
    
    TEST(ExampleTest, myTest2)
    {
        BoolExample tmp;

        EXPECT_TRUE(tmp.AlwaysFalse());
    }
}
