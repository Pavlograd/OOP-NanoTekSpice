/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#include "Output.hpp"

namespace nts
{
Output::Output(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin)
{
    (void)pin;
    return getValue();
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)otherPin;

    if (_component[pin - 1]) {
        std::cerr << "This pin was already attributed." << std::endl;
        exit(84);
    }
    if (pin <= 0 || pin > (size_t)(std::end(_component) - std::begin(_component))) {
        std::cerr << "This pin doesn't exist on this component." << std::endl;
        exit(84);
    }
    _component[pin - 1] = &other;
}

void Output::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate Output::getValue() const
{
    return _value;
}

void Output::simulate(int output)
{
    if (output != 1)
        return;
    if (!_component[0])
    {
        std::cerr << "The output has no link." << std::endl;
        exit(84);
    }
    if (_component[0]->getType().compare("Input") != 0 && _component[0]->getType().compare("Clock") != 0 &&
    _component[0]->getType().compare("True") != 0 &&
    _component[0]->getType().compare("False") != 0) {
        return;
    }
    if (_component[0]->getType().compare("Output") == 0) {
        std::cerr << "I have no clue of what's supposed to happend but I'm sure that's an error." << std::endl;
        exit(84);
    }
    if (_component[0]->getValue() == nts::Tristate::TRUE)
    {
        _value = Tristate::TRUE;
    }
    else
    {
        _value = Tristate::FALSE;
    }
}

void Output::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

} // namespace nts