/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4040
*/

#include "C4040.hpp"
#include "Input.hpp"

namespace nts
{
C4040::C4040(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

C4040::~C4040()
{
}

nts::Tristate C4040::compute(std::size_t pin)
{
    return _component[pin]->getValue();
}

void C4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C4040::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate C4040::getValue() const
{
    return _value;
}

void C4040::simulate(int output)
{
    if (output != 0)
        return;
    if (!_component[10])
    {
        std::cerr << "Error no Reset." << std::endl;
        exit(84);
    }
    if (_component[10]->getValue() == nts::Tristate::TRUE)
    {
        for (int i = 0; i < 8; i++)
        {
            if (_component[i])
                _component[i]->setValue("0");
        }
        if (_component[8])
            _component[8]->setValue("0");
        for (int i = 11; i < 16; i++)
        {
            if (_component[i])
                _component[i]->setValue("0");
        }
        return;
    }
    if (!_component[9])
    {
        std::cerr << "Error no Clock." << std::endl;
        exit(84);
    }
    for (int i = 0; i < 8; i++)
    {
        if (_component[i])
        {
            if (_component[i]->getValue() == nts::Tristate::FALSE)
                _component[i]->setValue("1");
            else
                _component[i]->setValue("0");
        }
    }
    if (_component[8])
    {
        if (_component[8]->getValue() == nts::Tristate::FALSE)
            _component[8]->setValue("1");
        else
            _component[8]->setValue("0");
    }
    for (int i = 11; i < 16; i++)
    {
        if (_component[i])
        {
            if (_component[i]->getValue() == nts::Tristate::FALSE)
                _component[i]->setValue("1");
            else
                _component[i]->setValue("0");
        }
    }
    return;
}

void C4040::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

} // namespace nts