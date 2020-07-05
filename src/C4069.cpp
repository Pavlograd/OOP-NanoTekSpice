/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4069
*/

#include "C4069.hpp"
#include "Input.hpp"

namespace nts
{
C4069::C4069(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

C4069::~C4069()
{
}

nts::Tristate C4069::compute(std::size_t pin)
{
    return _component[pin]->getValue();
}

void C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (&other == this)
    {
        if (!_component[otherPin - 1])
            _component[otherPin - 1] = new Input("U");
        _component[pin - 1] = &other;
        return;
    }
    if (_component[pin - 1])
    {
        std::cerr << "This pin was already attributed." << std::endl;
        exit(84);
    }
    if (pin <= 0 || pin > (size_t)(std::end(_component) - std::begin(_component)))
    {
        std::cerr << "This pin doesn't exist on this component." << std::endl;
        exit(84);
    }
    _component[pin - 1] = &other;
}

void C4069::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate C4069::getValue() const
{
    return _value;
}

void C4069::InvertPin(int pin1, int pin2)
{
    pin1--;
    pin2--;

    if (!_component[pin1])
        return;
    if (_component[pin1]->getValue() == nts::Tristate::FALSE) {
        _component[pin2]->setValue("1");
    } else {
        _component[pin2]->setValue("0");
    }
}

void C4069::simulate(int output)
{
    if (output != 0)
        return;
    InvertPin(1, 2);
    InvertPin(3, 4);
    InvertPin(5, 6);
    InvertPin(9, 8);
    InvertPin(11, 10);
    InvertPin(13, 12);
}

void C4069::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

} // namespace nts