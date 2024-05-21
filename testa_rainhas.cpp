#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "./romanos.hpp"

TEST_CASE("Algarismos unicos", "[romanos]") {
    REQUIRE(romanos_para_decimal("I") == 1);
    REQUIRE(romanos_para_decimal("V") == 5);
    REQUIRE(romanos_para_decimal("X") == 10);
    REQUIRE(romanos_para_decimal("L") == 50);
    REQUIRE(romanos_para_decimal("C") == 100);
    REQUIRE(romanos_para_decimal("D") == 500);
    REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Algarismos invalidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("G") == -1);
    REQUIRE(romanos_para_decimal("A") == -1);
    REQUIRE(romanos_para_decimal("B") == -1);
    REQUIRE(romanos_para_decimal("E") == -1);
    REQUIRE(romanos_para_decimal("F") == -1);
    REQUIRE(romanos_para_decimal("H") == -1);
    REQUIRE(romanos_para_decimal("J") == -1);
    REQUIRE(romanos_para_decimal("K") == -1);
    REQUIRE(romanos_para_decimal("N") == -1);
    REQUIRE(romanos_para_decimal("O") == -1);
    REQUIRE(romanos_para_decimal("P") == -1);
    REQUIRE(romanos_para_decimal("Q") == -1);
    REQUIRE(romanos_para_decimal("R") == -1);
    REQUIRE(romanos_para_decimal("S") == -1);
    REQUIRE(romanos_para_decimal("T") == -1);
    REQUIRE(romanos_para_decimal("U") == -1);
    REQUIRE(romanos_para_decimal("W") == -1);
    REQUIRE(romanos_para_decimal("Y") == -1);
    REQUIRE(romanos_para_decimal("Z") == -1);
    REQUIRE(romanos_para_decimal("a") == -1);
    REQUIRE(romanos_para_decimal("b") == -1);
    REQUIRE(romanos_para_decimal("c") == -1);
    REQUIRE(romanos_para_decimal("e") == -1);
    REQUIRE(romanos_para_decimal("f") == -1);
    REQUIRE(romanos_para_decimal("g") == -1);
    REQUIRE(romanos_para_decimal("h") == -1);
    REQUIRE(romanos_para_decimal("j") == -1);
    REQUIRE(romanos_para_decimal("k") == -1);
    REQUIRE(romanos_para_decimal("n") == -1);
    REQUIRE(romanos_para_decimal("o") == -1);
    REQUIRE(romanos_para_decimal("p") == -1);
    REQUIRE(romanos_para_decimal("q") == -1);
    REQUIRE(romanos_para_decimal("r") == -1);
    REQUIRE(romanos_para_decimal("s") == -1);
    REQUIRE(romanos_para_decimal("t") == -1);
    REQUIRE(romanos_para_decimal("u") == -1);
    REQUIRE(romanos_para_decimal("w") == -1);
    REQUIRE(romanos_para_decimal("y") == -1);
    REQUIRE(romanos_para_decimal("z") == -1);
    REQUIRE(romanos_para_decimal("i") == -1);
    REQUIRE(romanos_para_decimal("v") == -1);
    REQUIRE(romanos_para_decimal("x") == -1);
    REQUIRE(romanos_para_decimal("l") == -1);
    REQUIRE(romanos_para_decimal("c") == -1);
    REQUIRE(romanos_para_decimal("d") == -1);
}

TEST_CASE("Numeros romanos invalidos", "[romanos]" ) {
    REQUIRE(romanos_para_decimal("XXXX") == -1);
    REQUIRE(romanos_para_decimal("CCCC") == -1);
    REQUIRE(romanos_para_decimal("IIII") == -1);
    REQUIRE(romanos_para_decimal("MMMM") == -1);
    REQUIRE(romanos_para_decimal("VVV") == -1);
    REQUIRE(romanos_para_decimal("VV") == -1);
    REQUIRE(romanos_para_decimal("VX") == -1);
    REQUIRE(romanos_para_decimal("IL") == -1);
    REQUIRE(romanos_para_decimal("IC") == -1);
    REQUIRE(romanos_para_decimal("XD") == -1);
    REQUIRE(romanos_para_decimal("XM") == -1);
    REQUIRE(romanos_para_decimal("LL") == -1);
    REQUIRE(romanos_para_decimal("DD") == -1);
}

TEST_CASE("Numeros romanos - algarismos compostos", "[romanos]") {
    REQUIRE(romanos_para_decimal("II") == 2);
    REQUIRE(romanos_para_decimal("IV") == 4);
    REQUIRE(romanos_para_decimal("VI") == 6);
    REQUIRE(romanos_para_decimal("IX") == 9);
    REQUIRE(romanos_para_decimal("XI") == 11);
    REQUIRE(romanos_para_decimal("XX") == 20);
    REQUIRE(romanos_para_decimal("XL") == 40);
    REQUIRE(romanos_para_decimal("XC") == 90);
    REQUIRE(romanos_para_decimal("CL") == 150);
    REQUIRE(romanos_para_decimal("CD") == 400);
    REQUIRE(romanos_para_decimal("CM") == 900);
    REQUIRE(romanos_para_decimal("MC") == 1100);
    REQUIRE(romanos_para_decimal("MMM") == 3000);
}
