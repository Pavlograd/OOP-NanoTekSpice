/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#include "Input.hpp"

namespace nts
{
Input::Input(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin)
{
    (void) pin;
    return getValue();
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)otherPin;
    (void)other;
}

void Input::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate Input::getValue() const
{
    return _value;
}

void Input::simulate(int output)
{
    (void) output;
}

void Input::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;   
}

} // namespace nts