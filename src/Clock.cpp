/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#include "Clock.hpp"

namespace nts
{
Clock::Clock(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

Clock::~Clock()
{
}

nts::Tristate Clock::compute(std::size_t pin)
{
    (void) pin;
    return getValue();
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)otherPin;
    (void)other;
}

void Clock::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate Clock::getValue() const
{
    return _value;
}

void Clock::simulate(int output)
{
    if (output == 2) {
        if (_value == Tristate::TRUE) {
            _value = Tristate::FALSE;
        } else if (_value == Tristate::FALSE) {
            _value = Tristate::TRUE;
        }
    }
}

void Clock::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;   
}

} // namespace nts