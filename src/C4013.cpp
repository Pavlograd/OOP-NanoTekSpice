/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4013
*/

#include "C4013.hpp"
#include "Input.hpp"

namespace nts
{
C4013::C4013(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

C4013::~C4013()
{
}

nts::Tristate C4013::compute(std::size_t pin)
{
    return _component[pin]->getValue();
}

void C4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C4013::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate C4013::getValue() const
{
    return _value;
}

void C4013::FlipFlopPin(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6)
{
    pin1--;
    pin2--;
    pin3--;
    pin4--;
    pin5--;
    pin6--;

    if (!_component[pin1] && !_component[pin2] && !_component[pin3] && !_component[pin4] && !_component[pin5] && !_component[pin6]) {
        return;
    }
    if (!_component[pin3] || !_component[pin1]) {
        std::cerr << "One pin is not set." << std::endl;
        exit(84);
    }
    if (_component[pin4]->getType().compare("Clock") != 0) {
        std::cerr << "This pin need to have a Clock." << std::endl;
        exit(84);
    }
    if (_component[pin1]->getValue() == nts::Tristate::TRUE && _component[pin3]->getValue() == nts::Tristate::TRUE)
    {
        _component[pin6]->setValue("1");
        _component[pin5]->setValue("1");
        return;
    }
    if (_component[pin1]->getValue() == nts::Tristate::TRUE && _component[pin3]->getValue() == nts::Tristate::FALSE)
    {
        _component[pin6]->setValue("1");
        _component[pin5]->setValue("0");
        return;
    }
    if (_component[pin1]->getValue() == nts::Tristate::FALSE && _component[pin3]->getValue() == nts::Tristate::TRUE)
    {
        _component[pin6]->setValue("0");
        _component[pin5]->setValue("1");
        return;
    }
    if (_component[pin4]->getValue() == nts::Tristate::TRUE && _component[pin2]->getValue() == nts::Tristate::FALSE)
    {
        _component[pin6]->setValue("0");
        _component[pin5]->setValue("1");
        return;
    }
    if (_component[pin4]->getValue() == nts::Tristate::TRUE && _component[pin2]->getValue() == nts::Tristate::TRUE)
    {
        _component[pin6]->setValue("1");
        _component[pin5]->setValue("0");
        return;
    }
}

void C4013::simulate(int output)
{
    if (output != 0)
        return;
    FlipFlopPin(6, 5, 4, 3, 2, 1);
    FlipFlopPin(8, 9, 10, 11, 12, 13);
}

void C4013::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

} // namespace nts