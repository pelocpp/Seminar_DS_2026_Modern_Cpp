// =====================================================================================
// LValue / RValue
// =====================================================================================

module modern_cpp:rvalue_lvalue;

namespace LValueRValue {

    // lvalue reference
    static void sayHello(const std::string& message) {
        std::println("sayHello [std::string&]:  {}", message);
    
       // message[0] = '?';
    }

    // rvalue reference
    static void sayHello(std::string&& message) {
        std::println("sayHello [std::string&&]: {}", message);
    
        message.clear();
    }

    static void test01() {

        std::string a = "Hello";
        std::string b = " World";

        sayHello(a);   // Mit Name

        sayHello(a + b);  // anon. Objekt
    }

    // -------------------------------------------------------------------

    static void helper(std::string&& message)
    {
        sayHello( std::move ( message )  ); // && RValue: Typen sind identisch   
    
                           // & LValue: message ist eine Name eines Objekts 
    }

    static void test02()
    {
        helper(std::string("Where are we going ..."));
    }

    // -------------------------------------------------------------------

    static void test03() {

        std::string s = "Hello";

        sayHello(s);
        // versus
        sayHello(std::move(s));  // casts an lvalue to an rvalue
    }

    // -------------------------------------------------------------------

    static void test04() {

        int a = 2;
        int b = 3;

        int& ri = a;          // works: (lvalue) reference to a (named) variable
        int&& ri2 = 123;

        // int& i = 123;      // invalid: (lvalue) reference to a constant

        int&& i = 123;        // works: (rvalue) reference to a constant

        const int& j = 123;   // works: const references binds to everything

        // int& k = a + b;    // invalid: (lvalue) reference to a temporary object

        int&& k = a + b;      // works: (rvalue) reference to a temporary object
    }
}

void main_rvalue_lvalue()
{
    using namespace LValueRValue;
    test01();
    test02(); 
    test03();
    test04();
}

// =====================================================================================
// End-of-File
// =====================================================================================
