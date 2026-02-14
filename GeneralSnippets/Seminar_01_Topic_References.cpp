// =====================================================================================
// Ergänzende Betrachungen: Referenzen 
// =====================================================================================

#include <iostream>

namespace References {

    // lvalue reference
    static void sayHello(std::string& message) {
        std::cout << "sayHello [std::string&]: " << message << std::endl;
    }

    static void test01() {

        std::string a = "Hello";

        std::string b = " World";

        sayHello(a);

        // sayHello(a + b);
    }
}

void seminar_topic_01_references()
{
    using namespace References;

    test01();
}

// =====================================================================================
// End-of-File
// =====================================================================================
