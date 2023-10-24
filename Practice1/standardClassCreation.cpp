#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(const std::string& n, int a) : name(n), age(a) {}

    // Getter methods
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // Setter methods
    void setName(const std::string& n) {
        name = n;
    }

    void setAge(int a) {
        if (a >= 0) {  // Ensure age is non-negative
            age = a;
        } else {
            std::cerr << "Error: Age cannot be negative." << std::endl;
        }
    }

    // Other methods
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Create an instance of the Person class
    Person person("John Doe", 25);

    // Use getter methods
    std::cout << "Name: " << person.getName() << ", Age: " << person.getAge() << std::endl;

    // Use setter methods
    person.setName("Jane Doe");
    person.setAge(30);

    // Display information using another method
    person.displayInfo();

    return 0;
}