#include <set>
#include <iostream>

int main() {
    std::set<std::string> s;
    s.insert("123");
    std::set<std::string >::iterator it = s.begin();
    // std::cout << it->  << "\n"; 
    return 0;
}