/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4008
*/

#include "C4008.hpp"
#include "Input.hpp"

namespace nts
{
C4008::C4008(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

C4008::~C4008()
{
}

nts::Tristate C4008::compute(std::size_t pin)
{
    return _component[pin]->getValue();
}

void C4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C4008::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate C4008::getValue() const
{
    return _value;
}

void C4008::ADDERPin(int pin1, int pin2, int pin3, int pin4)
{
    pin1--;
    pin2--;
    pin3--;
    pin4--;

    if (!_component[pin1] && !_component[pin2] && _component[pin3] && !_component[pin4])
    {
        return;
    }
    if (!_component[pin1] || !_component[pin2] || _component[pin3] || !_component[pin4])
    {
        std::cerr << "One component is missing." << std::endl;
        exit(84);
    }
    if (_component[pin1]->getValue() == nts::Tristate::FALSE && _component[pin2]->getValue() == nts::Tristate::FALSE)
    {
        if (_component[pin3]->getValue() == nts::Tristate::FALSE)
        {
            _component[pin4]->setValue("0");
            return;
        }
        else
        {
            _component[pin4]->setValue("1");
            return;
        }
    }
    if (_component[pin3]->getValue() == nts::Tristate::TRUE)
    {
        if (_component[pin1]->getValue() == nts::Tristate::TRUE && _component[pin2]->getValue() == nts::Tristate::TRUE)
        {
            _component[pin4]->setValue("1");
            return;
        }
        if (_component[pin1]->getValue() == nts::Tristate::TRUE || _component[pin2]->getValue() == nts::Tristate::TRUE)
        {
            _component[pin4]->setValue("0");
            return;
        }
    }
    if (_component[pin1]->getValue() == nts::Tristate::TRUE && _component[pin2]->getValue() == nts::Tristate::TRUE)
    {
        _component[pin4]->setValue("0");
        return;
    }
    if (_component[pin1]->getValue() == nts::Tristate::TRUE || _component[pin2]->getValue() == nts::Tristate::TRUE)
    {
        _component[pin4]->setValue("1");
        return;
    }
    _component[pin4]->setValue("0");
    return;
}

void C4008::simulate(int output)
{
    if (output != 0)
        return;
    ADDERPin(7, 6, 9, 10);
    ADDERPin(5, 4, 10, 11);
    ADDERPin(3, 2, 11, 12);
    ADDERPin(1, 15, 12, 13);
}

void C4008::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

} // namespace nts