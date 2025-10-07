/// Converts any value to its string representation
/// @param value The value to convert
/// @return String representation of the value
/**
 * @brief Converts a value of any type to its string representation.
 * 
 * This template function uses std::stringstream to convert any type that supports
 * stream insertion operator (<<) into a std::string.
 * 
 * @tparam T The type of the value to convert. Must support operator<<.
 * @param value The value to be converted to a string.
 * @return std::string The string representation of the input value.
 * 
 * @note This function requires that type T has an overloaded operator<< for std::ostream.
 * @note The conversion behavior depends on the stream insertion operator implementation for type T.
 * 
 * @example
 * int number = 42;
 * std::string str = toString(number);  // Returns "42"
 * 
 * double pi = 3.14159;
 * std::string piStr = toString(pi);    // Returns "3.14159"
 */
template <typename T>
std::string toString(const T& value)
{
    // Create a string stream to handle the conversion
    std::stringstream stream;
    
    // Insert the value into the stream
    stream << value;
    
    // Extract and return the resulting string
    return stream.str();
}