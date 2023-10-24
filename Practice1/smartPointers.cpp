#include <iostream>
#include <memory>

int main() {
    // Using std::shared_ptr for dynamic memory allocation
    std::shared_ptr<int> myInt1 = std::make_shared<int>(42);
    std::shared_ptr<int> myInt2 = myInt1;  // Both myInt1 and myInt2 share ownership

    // Memory is automatically released when the last shared_ptr (myInt1 and myInt2) is destroyed

    return 0;
}