#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <deque>

// Capacity
// std::for_each
// std::generate
// std::find
// std::fill

// Generische Algorithmen

void seminar_topic_04_stl_01()
{
    std::vector<int> numbers;
   // std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    for (int i = 0; i != numbers.size(); ++i)
    {
        std::cout << numbers[i] << std::endl;
    }
}

void seminar_topic_04_stl_02()
{
    // std::vector<int> numbers;
    std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    //std::list<int>::iterator pos = numbers.begin();
    // or
    std::list<int>::iterator pos = numbers.begin();

    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    int elem = *pos;
    std::cout << elem << std::endl;

    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    elem = *pos;
    std::cout << elem << std::endl;

    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    elem = *pos;
    std::cout << elem << std::endl;

    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    elem = *pos;
    std::cout << elem << std::endl;
}

// C++ Classic !!!
void seminar_topic_04_stl_03()
{
    // std::vector<int> numbers;
    std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::list<int>::iterator pos = numbers.begin();
    std::list<int>::iterator end = numbers.end();

    while (pos != end) {

        int elem = *pos;
        std::cout << elem << std::endl;
        ++pos;
    }
}

// C++ Modern !!!
void seminar_topic_04_stl_04()
{
    std::vector<int> numbers;
    //std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    auto pos = numbers.begin();
    auto end = numbers.end();

    while (pos != end) {

        auto elem = *pos;
        std::cout << elem << std::endl;
        ++pos;
    }
}

template <typename T>
using MyContainer = std::vector<T>;

using ElemType = double; // hier ändern ---

void seminar_topic_04_stl_05()
{
    MyContainer<ElemType> numbers;

    ElemType elem1{};
    MyContainer<ElemType>::value_type elem2{};

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    auto pos = numbers.begin();
    auto end = numbers.end();

    while (pos != end) {

        auto elem = *pos;
        std::cout << elem << std::endl;
        ++pos;
    }
}

void seminar_topic_04_stl_06()
{
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    auto pos = numbers.begin();
    auto end = numbers.end();

    while (pos != end) {

        auto elem = *pos;
        std::cout << elem << std::endl;
        ++pos;
    }
}

void seminar_topic_04_stl_07()
{
    const std::vector<int> numbers{ 1, 2, 3};

    //numbers.push_back(1);
    //numbers.push_back(2);
    //numbers.push_back(3);

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [](const int& elem) {
           // elem = elem + 10;
            std::cout << elem << " ";
        }
    );

    std::cout << "Done." << " ";
}

void seminar_topic_04_stl_08()
{
    std::vector<int> numbers;

    std::map<int, std::string> numbers2;
    std::unordered_map<int, std::string> numbers3;
    std::deque<int> numbers34;


    numbers.reserve(80);  // !!!!!!!!!!!!!!!!!

    for (std::size_t n{}; n != 100; ++n) {

        numbers.push_back(2 * n);
        std::cout << "Size: " << numbers.size() << ", Capacity: " << numbers.capacity() << std::endl;
    }


    int* begin = numbers.data();

    numbers.shrink_to_fit();

    begin = numbers.data();

    std::cout << "Size: " << numbers.size() << ", Capacity: " << numbers.capacity() << std::endl;

    std::cout << "Done." << " ";
}

void seminar_topic_04_stl_09()
{
    std::vector<int> numbers1 (100);
    numbers1.push_back(123);

    std::vector<int> numbers2{ 100 };
    numbers2.push_back(123);
   // numbers.reserve(100);
}

void seminar_topic_04_stl_10()
{
    std::vector<int> numbers(100);

    for (size_t n = 0; n != numbers.size(); ++n ) {
        numbers[n] = 123;
    }

    std::fill(
        numbers.begin(),
        numbers.end(),
        456
    );

   // int n = 2;

    std::generate(
        numbers.begin(),
        numbers.end(),
        [n = 2]() mutable{
            n++;
            return 2 * n;
        }
    );
}
void seminar_topic_04_stl()
{
    //seminar_topic_04_stl_01();
    //seminar_topic_04_stl_02();
    //seminar_topic_04_stl_03();
    //seminar_topic_04_stl_04();
    //seminar_topic_04_stl_05();
    //seminar_topic_04_stl_06();
    //seminar_topic_04_stl_07();
    //seminar_topic_04_stl_08();
    //seminar_topic_04_stl_09();
    seminar_topic_04_stl_10();
}