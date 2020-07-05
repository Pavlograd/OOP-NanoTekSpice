/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4071
*/

#include "C4071.hpp"
#include "Input.hpp"

namespace nts
{
C4071::C4071(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

C4071::~C4071()
{
}

nts::Tristate C4071::compute(std::size_t pin)
{
    return _component[pin]->getValue();
}

void C4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C4071::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate C4071::getValue() const
{
    return _value;
}

void C4071::ORPin(int pin1, int pin2, int pin3)
{
    pin1--;
    pin2--;
    pin3--;

    if (!_component[pin1] || !_component[pin2])
    {
        if (_component[pin3])
            _component[pin3]->setValue("U");
        return;
    }
    if (!_component[pin3])
        return;
    if (_component[pin1]->getValue() == nts::Tristate::TRUE || _component[pin2]->getValue() == nts::Tristate::TRUE)
    {
        _component[pin3]->setValue("1");
    }
    else
    {
        _component[pin3]->setValue("0");
    }
}

void C4071::simulate(int output)
{
    if (output != 0)
        return;
    ORPin(1, 2, 3);
    ORPin(5, 6, 4);
    ORPin(8, 9, 10);
    ORPin(12, 13, 11);
}

void C4071::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

} // namespace nts