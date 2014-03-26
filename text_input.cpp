#include <boost/algorithm/string.hpp>
#include "text_input.h"

const TextInput TextInput::parseInput(const std::string input) {
    TextInput result;

    int firstSpace = input.find_first_of(' ');
    result.verb = input.substr(0, firstSpace);
    if (firstSpace != -1) {
        result.params = input.substr(firstSpace+1);
        boost::trim(result.params);
    } else {
        result.params = "";
    }
    return result;
}
