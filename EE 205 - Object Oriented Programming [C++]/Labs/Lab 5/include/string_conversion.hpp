#ifndef EE205_STRING_CONVERSION_HPP
#define EE205_STRING_CONVERSION_HPP

#include <string>
#include <vector>
#include <sstream>

template <typename T>
std::string lexical_cast(T obj) {
    // Create a std::stringstream
    // Using operator<<, output the object to it
    // Take the std::string from the stringstream

    std::stringstream stream;
    std::string str;

    stream << obj;
    str = stream.str();

    return str;
}

template <typename T>
std::string vector_to_string(std::vector<T>& items) {
    // For each item in the vector
    // Get the string representation of it
    // Put a comma after it if it's not the last element
    // Accumuate that string into a final result
    
    std::vector<std::stringstream> stream(items.size());
    
    for(int i = 0; i < items.size(); i++) {
        std::cout << stream.size() << std::endl;
        stream[i] << items[i];
    }

    std::string str;

    str = stream[0].str();
    for(int i = 1; i < stream.size(); i++) {
        str.append(",");
        str.append(stream[i].str());
    }

    return str;
}

#endif // EE205_STRING_CONVERSION_HPP 
