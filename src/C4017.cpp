/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4017
*/

#include "C4017.hpp"
#include "Input.hpp"

namespace nts
{
C4017::C4017(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

C4017::~C4017()
{
}

nts::Tristate C4017::compute(std::size_t pin)
{
    return _component[pin]->getValue();
}

void C4017::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C4017::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate C4017::getValue() const
{
    return _value;
}

void C4017::simulate(int output)
{
    int good = 0;

    if (output != 0)
        return;
    for (int i = 0; i < 14; i++)
    {
        if (!_component[i])
        {
            std::cerr << "One component is missing for this circuit." << std::endl;
            exit(84);
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if (_component[i]->getValue() == nts::Tristate::TRUE)
            good = 1;
    }
    if (good == 1)
    {
        _component[2]->setValue("1");
        return;
    }
    if (_component[10]->getValue() == nts::Tristate::TRUE)
    {
        _component[10]->setValue("0");
        _component[11]->setValue("1");
    }
    if (_component[8]->getValue() == nts::Tristate::TRUE)
    {
        _component[8]->setValue("0");
        _component[10]->setValue("1");
    }
    if (_component[5]->getValue() == nts::Tristate::TRUE)
    {
        _component[5]->setValue("0");
        _component[8]->setValue("1");
    }
    if (_component[4]->getValue() == nts::Tristate::TRUE)
    {
        _component[4]->setValue("0");
        _component[5]->setValue("1");
    }
    if (_component[0]->getValue() == nts::Tristate::TRUE)
    {
        _component[0]->setValue("0");
        _component[4]->setValue("1");
    }

    if (_component[9]->getValue() == nts::Tristate::TRUE)
    {
        _component[9]->setValue("0");
        _component[0]->setValue("1");
    }

    if (_component[6]->getValue() == nts::Tristate::TRUE)
    {
        _component[6]->setValue("0");
        _component[9]->setValue("1");
    }

    if (_component[3]->getValue() == nts::Tristate::TRUE)
    {
        _component[3]->setValue("0");
        _component[6]->setValue("1");
    }

    if (_component[1]->getValue() == nts::Tristate::TRUE)
    {
        _component[1]->setValue("0");
        _component[3]->setValue("1");
    }

    if (_component[2]->getValue() == nts::Tristate::TRUE)
    {
        _component[2]->setValue("0");
        _component[1]->setValue("1");
    }

    if (_component[0]->getValue() == nts::Tristate::TRUE)
    {
        _component[11]->setValue("0");
    }
}

void C4017::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

} // namespace nts