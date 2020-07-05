/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#include "True.hpp"

namespace nts
{
True::True(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

True::~True()
{
}

nts::Tristate True::compute(std::size_t pin)
{
    (void) pin;
    return getValue();
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)otherPin;
    (void)other;
}

void True::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate True::getValue() const
{
    return _value;
}

void True::simulate(int output)
{
    (void) output;
}

void True::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;   
}

} // namespace nts