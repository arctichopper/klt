#define CATCH_CONFIG_MAIN

#include "catch.hpp"

using std::string;

TEST_CASE( "This test does nothing!", "[Test]")
{
    string ret = "Returning String";

    CAPTURE( ret );

    CHECK( ret == "Returning String" );
    REQUIRE( ret != "Returning String!" );
}
