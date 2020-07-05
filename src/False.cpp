/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#include "False.hpp"

namespace nts
{
False::False(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

False::~False()
{
}

nts::Tristate False::compute(std::size_t pin)
{
    (void) pin;
    return getValue();
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)otherPin;
    (void)other;
}

void False::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate False::getValue() const
{
    return _value;
}

void False::simulate(int output)
{
    (void) output;
}

void False::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;   
}

} // namespace nts