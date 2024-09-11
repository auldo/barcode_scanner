#include <gtest/gtest.h>

#include "auldo_barcode_scanner.h"

TEST(container, get_version) {
    EXPECT_NO_THROW(auldo::bs::get_version());
}