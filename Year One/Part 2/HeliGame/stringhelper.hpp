#ifndef BOOK_STRINGHELPERS_HPP
#define BOOK_STRINGHELPERS_HPP

#include <sstream>

// Converts any type to std::string
// Note: Custom implementation for cross-platform compatibility
// (std::to_string has issues on MinGW)
/**
 * @brief Converts a value of any type to its string representation.
 * 
 * This template function provides a generic way to convert various data types
 * to their string equivalents. The actual conversion depends on the type T
 * and typically relies on stream insertion operators or specializations.
 * 
 * @tparam T The type of the value to be converted to a string
 * @param value The value to convert to a string representation
 * @return std::string The string representation of the input value
 * 
 * @note This function may require that type T has an appropriate stream
 *       insertion operator (operator<<) defined, or a specialized version
 *       of this template for the specific type.
 */
template <typename T>
std::string toString(const T& value);

// Template implementation
#include "stringhelper.inl"

#endif // BOOK_STRINGHELPERS_HPP