// Ergänzende Betrachungen
// -----------------------

#include <iostream>


//class Calculator
//{
//public:
//    static int add(int a, int b) { return a + b; }
//    static int sub(int a, int b) { return a - b; }
//    static int mul(int a, int b) { return a * b; }
//    static int div(int a, int b) { return a / b; }
//};




class DoubleCalculator
{
public:
    static double add(double a, double b) { return a + b; }
    static double sub(double a, double b) { return a - b; }
    static double mul(double a, double b) { return a * b; }
    static double div(double a, double b) { return a / b; }
};


template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

// Schablone
template <typename T>
   requires Number <T>
class Calculator
{
public:
    /*static*/ T add(T a, T b) { 
        return a + b; 
    }
    /*static*/ T sub(T a, T b) { return a - b; }
    /*static*/ T mul(T a, T b) { return a * b; }
    /*static*/ T div(T a, T b) { return a / b; }
};


// Eine Schablone mit einem konkreten Type ausstatten:
// Für T = int ... oder : T = double 
// eine Schablone instanziieren ==> um eine
       // konkrete Klasse zu bekommen.

void seminar_topic_03_templates()
{
    

    //int result1 = Calculator <int>  ::add(1, 2);

    //double result2 = Calculator <double>::add(1.5, 2.5);

    // std::string result3 = Calculator <std::string>::add("1.5", "2.5");



    Calculator<double> doubleCalc;
    double result = doubleCalc.add(1.5, 2.5);


   // Calculator<std::string> cString;
   // std::string result3 = cString.add("1.5", "2.5");


    std::cout << "Hello Topic" << std::endl;
}
