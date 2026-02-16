// =====================================================================================
// Ergänzende Betrachungen: Referenzen 
// =====================================================================================

#include <iostream>

static  std::string aString("sdfsdf");

namespace References {

    // lvalue reference

    static void sayIntegerA( int& value) {

        int m = value;
    }

    static void sayIntegerB(int value) {

        int m = value;
    }



    static void sayHello(const std::string& message) {
        std::cout << "sayHello [std::string&]: " << message << std::endl;
    }

    static void sayHelloZWEI(std::string* message) {
        // std::cout << "sayHello [std::string&]: " << message << std::endl;
    
        delete message;
    
    }



    static void test01() {

        std::string a = "Hello";

        std::string* pa = new std::string("ABC");

        std::string& ra = a;

        std::string b = " World";

        sayHello(a);

        sayHelloZWEI(&aString);

        // tmp = a+b "Hello World"

        sayHello(a + b);
    }
}

void seminar_topic_01_references()
{
    using namespace References;

    int x = 123;

    sayIntegerA(x);

    sayIntegerB(x);



    test01();
}

// =====================================================================================
// End-of-File
// =====================================================================================
