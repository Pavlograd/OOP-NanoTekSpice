/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4514
*/

#include "C4514.hpp"
#include "Input.hpp"

namespace nts
{
C4514::C4514(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

C4514::~C4514()
{
}

nts::Tristate C4514::compute(std::size_t pin)
{
    return _component[pin]->getValue();
}

void C4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C4514::dump() const
{
    if (getValue() == -1)
        std::cout << "=U" << std::endl;
    else
        std::cout << "=" << getValue() << std::endl;
}

nts::Tristate C4514::getValue() const
{
    return _value;
}

void C4514::simulate(int output)
{
    if (output != 0)
        return;
    if (!_component[22]) {
        std::cerr << "Error no Inhibit." << std::endl;
        exit(84);
    }
    if (!_component[0]) {
        std::cerr << "Error no Strobe." << std::endl;
        exit(84);
    }
    if (_component[22]->getValue() == nts::Tristate::TRUE) {
        for (int i = 3; i < 20; i++)
            _component[i]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::FALSE && _component[20]->getValue() == nts::Tristate::FALSE && _component[2]->getValue() == nts::Tristate::FALSE && _component[1]->getValue() == nts::Tristate::FALSE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[10]->setValue("1");
        else
            _component[10]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::FALSE && _component[20]->getValue() == nts::Tristate::FALSE && _component[2]->getValue() == nts::Tristate::FALSE && _component[1]->getValue() == nts::Tristate::TRUE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[8]->setValue("1");
        else
            _component[8]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::FALSE && _component[20]->getValue() == nts::Tristate::FALSE && _component[2]->getValue() == nts::Tristate::TRUE && _component[1]->getValue() == nts::Tristate::FALSE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[9]->setValue("1");
        else
            _component[9]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::FALSE && _component[20]->getValue() == nts::Tristate::FALSE && _component[2]->getValue() == nts::Tristate::TRUE && _component[1]->getValue() == nts::Tristate::TRUE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[7]->setValue("1");
        else
            _component[7]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::FALSE && _component[20]->getValue() == nts::Tristate::TRUE && _component[2]->getValue() == nts::Tristate::FALSE && _component[1]->getValue() == nts::Tristate::FALSE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[6]->setValue("1");
        else
            _component[6]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::FALSE && _component[20]->getValue() == nts::Tristate::TRUE && _component[2]->getValue() == nts::Tristate::FALSE && _component[1]->getValue() == nts::Tristate::TRUE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[5]->setValue("1");
        else
            _component[5]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::FALSE && _component[20]->getValue() == nts::Tristate::TRUE && _component[2]->getValue() == nts::Tristate::TRUE && _component[1]->getValue() == nts::Tristate::FALSE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[4]->setValue("1");
        else
            _component[4]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::FALSE && _component[20]->getValue() == nts::Tristate::TRUE && _component[2]->getValue() == nts::Tristate::TRUE && _component[1]->getValue() == nts::Tristate::TRUE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[3]->setValue("1");
        else
            _component[3]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::TRUE && _component[20]->getValue() == nts::Tristate::FALSE && _component[2]->getValue() == nts::Tristate::FALSE && _component[1]->getValue() == nts::Tristate::FALSE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[17]->setValue("1");
        else
            _component[17]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::TRUE && _component[20]->getValue() == nts::Tristate::FALSE && _component[2]->getValue() == nts::Tristate::FALSE && _component[1]->getValue() == nts::Tristate::TRUE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[16]->setValue("1");
        else
            _component[16]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::TRUE && _component[20]->getValue() == nts::Tristate::FALSE && _component[2]->getValue() == nts::Tristate::TRUE && _component[1]->getValue() == nts::Tristate::FALSE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[19]->setValue("1");
        else
            _component[19]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::TRUE && _component[20]->getValue() == nts::Tristate::FALSE && _component[2]->getValue() == nts::Tristate::TRUE && _component[1]->getValue() == nts::Tristate::TRUE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[18]->setValue("1");
        else
            _component[18]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::TRUE && _component[20]->getValue() == nts::Tristate::TRUE && _component[2]->getValue() == nts::Tristate::FALSE && _component[1]->getValue() == nts::Tristate::FALSE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[13]->setValue("1");
        else
            _component[13]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::TRUE && _component[20]->getValue() == nts::Tristate::TRUE && _component[2]->getValue() == nts::Tristate::FALSE && _component[1]->getValue() == nts::Tristate::TRUE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[12]->setValue("1");
        else
            _component[12]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::TRUE && _component[20]->getValue() == nts::Tristate::TRUE && _component[2]->getValue() == nts::Tristate::TRUE && _component[1]->getValue() == nts::Tristate::FALSE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[15]->setValue("1");
        else
            _component[15]->setValue("0");
        return;
    }
    if (_component[21]->getValue() == nts::Tristate::TRUE && _component[20]->getValue() == nts::Tristate::TRUE && _component[2]->getValue() == nts::Tristate::TRUE && _component[1]->getValue() == nts::Tristate::TRUE) {
        if (_component[0]->getValue() == nts::Tristate::FALSE)
            _component[14]->setValue("1");
        else
            _component[14]->setValue("0");
        return;
    }
    std::cerr << "One or more Data Inputs is missing." << std::endl;
    exit(84);
}

void C4514::setValue(const std::string &value)
{
    if (value == "0")
        _value = Tristate::FALSE;
    else if (value == "1")
        _value = Tristate::TRUE;
    else
        _value = Tristate::UNDEFINED;
}

} // namespace nts