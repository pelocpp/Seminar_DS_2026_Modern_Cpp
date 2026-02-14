// =====================================================================================
// Ergänzende Betrachungen: Rule of Three
// =====================================================================================

#include <iostream>

namespace RuleofThree {

    class BigData
    {
    private:
        // private member data
        std::size_t m_size;  // current number of elements
        int*        m_data;    // array of elements

    public:
        // c'tors and d'tor
        BigData();
        BigData(std::size_t, int);

    public:
        // getter
        std::size_t size() const;
        bool isEmpty() const;
    };

    // c'tors and d'tor
    BigData::BigData() {
        // empty buffer
        m_size = 0;
        m_data = nullptr;
    }

    BigData::BigData(std::size_t size, int preset) {
        // create buffer
        m_size = size;
        m_data = new int[m_size];

        // initialize buffer
        for (std::size_t n{}; n != m_size; ++n) {
            m_data[n] = preset;
        }
    }

    // getter
    std::size_t BigData::size() const {
        return m_size;
    }

    bool BigData::isEmpty() const {
        return m_size == 0;
    }

    // test methods
    static void test_01_big_data()
    {
        BigData data(10, 1);

        std::cout << "BigData Size:    " << data.size() << std::endl;
        std::cout << "BigData isEmpty: " << std::boolalpha << data.isEmpty() << std::endl;
    }

    static void test_02_big_data()
    {
        BigData data1(10, 1);

        BigData data2(20, 2);

        data1 = data2;
    }
}

void seminar_topic_02_big_three()
{
    using namespace RuleofThree;

    test_01_big_data();
    // test_02_big_data();
}

// =====================================================================================
// End-of-File
// =====================================================================================
