#include <iostream>
#include <string>
#include "SugarSupplier.hpp"
#include "ChocolateSupplier.hpp"
#include "CandyMaker.hpp"
#include "CandyBox.hpp"

// --- 1. Define a Custom Struct to test Object Storage ---
struct Candy {
    std::string name;
    int calories;

    // Default Constructor (Required for 'new T[]' inside DynamicArray)
    Candy() : name("Unknown"), calories(0) {}

    // Custom Constructor
    Candy(std::string n, int c) : name(n), calories(c) {}

    // Overload '<<' so CandyBox::displayItems() can print it!
    friend std::ostream& operator<<(std::ostream& os, const Candy& c) {
        os << "[Candy: " << c.name << " (" << c.calories << " kcal)]";
        return os;
    }
};

void typeSafetyTest()
{
    std::cout << "\n--- STARTING TYPE SAFETY TEST ---" << std::endl;

    // TEST 1: Primitives (Integers)
    std::cout << "\n[Test 1] Testing with INTEGERS..." << std::endl;
    CandyBox<int> numberBox(2);
    numberBox.addItem(100);
    numberBox.addItem(200);
    numberBox.addItem(300); // Triggers resize
    numberBox.displayItems();
    numberBox.removeItem(1); // Remove 200
    std::cout << "After removing index 1:" << std::endl;
    numberBox.displayItems();


    // TEST 2: Raw Pointers (const char*)
    // Note: These work because string literals exist in static memory. 
    // If you used 'new char[]', you would need to delete them manually before the box dies.
    std::cout << "\n[Test 2] Testing with CHAR POINTERS..." << std::endl;
    CandyBox<const char*> charBox(2);
    charBox.addItem("HardCandy");
    charBox.addItem("Marshmallow");
    charBox.displayItems();


    // TEST 3: Custom Objects (The 'Candy' struct)
    std::cout << "\n[Test 3] Testing with CUSTOM CANDY OBJECTS..." << std::endl;
    CandyBox<Candy> customBox(2);
    customBox.addItem(Candy("MegaBar", 500));
    customBox.addItem(Candy("DietDrop", 5));
    customBox.addItem(Candy("FudgeBlock", 900)); // Resize triggers copy constructors
    customBox.displayItems();

    std::cout << "--- TYPE SAFETY TEST PASSED ---" << std::endl;
}

int main()
{
    // Run the new test
    typeSafetyTest();

    return 0;
}