
#include <vector>
#include <list>
#include <iostream>

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

    ElemType elem1;
    MyContainer<ElemType>::value_type elem2;

    decltype (numbers[0])  elem3;

    // std::vector<int> numbers;
    //std::list<int> numbers;

    numbers.push_back(elem);
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

void seminar_topic_04_stl()
{
   // seminar_topic_04_stl_01();
   // seminar_topic_04_stl_02();
    seminar_topic_04_stl_03();
}