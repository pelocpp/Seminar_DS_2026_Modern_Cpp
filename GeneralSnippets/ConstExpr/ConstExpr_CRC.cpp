// =====================================================================================
// ConstExpr_CRC.cpp // Example from Fraunhofer-Institute for Integrated Circuits IIS
// =====================================================================================

/*
 * Fraunhofer-Institute for Integrated Circuits IIS
 * Am Wolfsmantel 33, 91058 Erlangen, Germany
 * www.iis.fraunhofer.de
 *
 * Application Center Wireless Sensor Systems
 * Sonntagsanger 1, 96450 Coburg, Germany
 *
 * Copyright Fraunhofer IIS, All rights reserved.
 */

module;

#include <cstdint>   // for uint8_t

module modern_cpp:const_expr;



static void test()
{
    [] {};
    []() {};

    []() {}();

    [](int a, int b) { return a + b; };

    int;

    auto sum = [](int a, int b) { return a + b; };

    auto result = sum(10, 11);

    auto sum2 = [](int a, int b) constexpr { return a + b; };

    constexpr auto result2 = sum2(20, 30);

    constexpr auto result3 =
        [](int a, int b) constexpr { return a * b; } (10.9, 20.9);
}


constexpr uint8_t MY_POLYNOM = 0x07;
constexpr int TABLE_SIZE = 256;

template<uint8_t POLYNOM>
constexpr auto crcTable{
    [] () {
        std::array<uint8_t, TABLE_SIZE> A {};
        for (int i = 0; i < TABLE_SIZE; i++) {
            A[i] = i;
            for (int j = 0; j < 8; j++) {
                if ((A[i] & 0x80) != 0) {
                    A[i] = (uint8_t)((A[i] << 1) ^ POLYNOM);
                }
                else {
                    A[i] <<= 1;
                }
            }
        }
        return A;
    }()
};

constexpr auto tableBy10 = crcTable<10>;

constexpr auto tableBy20 = crcTable<20>;

static constexpr auto calcCRC(std::string_view data) {
    uint8_t checksum{};
    auto len{ data.size() };
    for (std::size_t i{}; i != len; ++i) {
        checksum = crcTable<MY_POLYNOM>[data[i] ^ checksum];
    }
    return checksum;
}

void main_constexpr_crc()
{
    constexpr uint8_t checksum{ calcCRC("Hello World") };
    std::println("Checksum is: {}", checksum);

    // print table
    for (std::size_t i{}; i != TABLE_SIZE; ++i) {
        std::println("{:03}: {}", i, crcTable<MY_POLYNOM>[i]);
    }
}

// =====================================================================================
// End-of-File
// =====================================================================================
