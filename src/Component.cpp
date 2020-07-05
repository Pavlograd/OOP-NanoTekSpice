/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component
*/

#include "IComponent.hpp"
#include "C4001.hpp"
#include "C4008.hpp"
#include "C4071.hpp"
#include "C4011.hpp"
#include "C4013.hpp"
#include "C4017.hpp"
#include "C4030.hpp"
#include "C4040.hpp"
#include "C4069.hpp"
#include "C4081.hpp"
#include "C4514.hpp"
#include "Clock.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"

namespace nts
{
nts::Tristate Component::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::UNDEFINED;
}

void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)otherPin;
    (void)other;
}

void Component::dump() const
{
    return;
}

void Component::display()
{
    std::map<std::string, std::unique_ptr<IComponent>>::iterator it = _components.begin();
    std::vector<std::string> outputs;

    while (it != _components.end())
    {
        if (it->second->getType().compare("Output") == 0)
        {
            //std::cout << it->first;
            outputs.push_back(it->first);
            //it->second->dump();
        }
        it++;
    }

    struct
    {
        bool operator()(std::string a, std::string b) const
        {
            return a.size() < b.size();
        }
    } customLess;

    std::sort(outputs.begin(), outputs.end(), customLess);
    for (const auto &currentName : outputs)
    {
        std::map<std::string, std::unique_ptr<IComponent>>::iterator it_second = _components.begin();
        while (it_second != _components.end())
        {
            if (it_second->first.compare(currentName) == 0)
            {
                std::cout << currentName;
                it_second->second->dump();
                break;
            }
            it_second++;
        }
    }
}

void Component::dumpAll()
{
    std::map<std::string, std::unique_ptr<IComponent>>::iterator it = _components.begin();

    while (it != _components.end())
    {
        std::cout << it->first;
        it->second->dump();
        it++;
    }
}

void Component::addComponent(const std::string &type, const std::string &value, const std::string &name)
{
    _components[name] = createComponent(type, value);
}

void Component::simulate(int output)
{
    (void)output;

    std::map<std::string, std::unique_ptr<IComponent>>::iterator it = _components.begin();

    while (it != _components.end())
    {
        it->second->simulate(0);
        it++;
    }
    it = _components.begin();
    while (it != _components.end())
    {
        it->second->simulate(1);
        it++;
    }
    it = _components.begin();
    while (it != _components.end())
    {
        it->second->simulate(2);
        it++;
    }
}

bool Component::componentExist(const std::string &name)
{
    std::map<std::string, std::unique_ptr<IComponent>>::iterator it = _components.begin();

    while (it != _components.end())
    {
        if (it->first.compare(name) == 0)
            return true;
        it++;
    }
    return false;
}

void Component::changeValue(const std::string &input, const std::string &value)
{
    std::map<std::string, std::unique_ptr<IComponent>>::iterator it = _components.begin();
    int find = 0;

    while (it != _components.end())
    {
        if (it->first.compare(input) == 0)
        {
            find++;
            if (it->second->getType().compare("Input") != 0 && it->second->getType().compare("Clock") != 0)
            {
                std::cerr << "The input type is not an input." << std::endl;
                exit(84);
            }
            if (value.compare("1") != 0 && value.compare("0") != 0)
            {
                std::cerr << "This value is incorrect: " << value << std::endl;
                exit(84);
            }
            it->second->setValue(value);
            break;
        }
        it++;
    }
    if (find == 0)
    {
        std::cerr << "Input's name match no valid inputs." << std::endl;
        exit(84);
    }
}

void Component::createLink(const std::string &component1, const std::string &component2, int pin1, int pin2)
{
    std::map<std::string, std::unique_ptr<IComponent>>::iterator it = _components.begin();
    int find1 = 0;
    int find2 = 0;
    std::map<std::string, std::unique_ptr<IComponent>>::iterator _component1;
    std::map<std::string, std::unique_ptr<IComponent>>::iterator _component2;

    if (component1.compare(component2) == 0 && pin1 == pin2)
    {
        std::cerr << "Same Component and same pin. I don't know if it works." << std::endl;
        return;
    }
    while (it != _components.end())
    {
        if (it->first.compare(component1) == 0)
        {
            find1++;
            _component1 = it;
        }
        if (it->first.compare(component2) == 0)
        {
            find2++;
            _component2 = it;
        }
        it++;
    }
    if (find1 != 1 || find2 != 1)
    {
        std::cerr << "Invalid component name." << std::endl;
        exit(84);
    }
    _component1->second->setLink(pin1, *_component2->second, pin2);
    _component2->second->setLink(pin2, *_component1->second, pin1);
}

std::unique_ptr<IComponent> Component::createComponent(const std::string &type, const std::string &value)
{
    if (type.compare("4001") == 0)
        return create4001(value);
    if (type.compare("4008") == 0)
        return create4008(value);
    else if (type.compare("4071") == 0)
        return create4071(value);
    else if (type.compare("4081") == 0)
        return create4081(value);
    else if (type.compare("4030") == 0)
        return create4030(value);
    else if (type.compare("4011") == 0)
        return create4011(value);
    else if (type.compare("4069") == 0)
        return create4069(value);
    else if (type.compare("4081") == 0)
        return create4081(value);
    else if (type.compare("4514") == 0)
        return create4514(value);
    else if (type.compare("4013") == 0)
        return create4013(value);
    else if (type.compare("4514") == 0)
        return create4514(value);
    else if (type.compare("4017") == 0)
        return create4017(value);
    else if (type.compare("4040") == 0)
        return create4040(value);
    else if (type.compare("Clock") == 0)
        return createClock(value);
    else if (type.compare("Input") == 0)
        return createInput(value);
    else if (type.compare("Output") == 0)
        return createOutput(value);
    else if (type.compare("True") == 0)
        return createTrue(value);
    else if (type.compare("False") == 0)
        return createFalse(value);
    std::cerr << "Invalid Type" << std::endl;
    exit(84);
}
std::unique_ptr<IComponent> Component::create4001(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4001(value));
}

std::unique_ptr<IComponent> Component::create4008(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4008(value));
}

std::unique_ptr<IComponent> Component::create4071(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4071(value));
}

std::unique_ptr<IComponent> Component::create4011(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4011(value));
}

std::unique_ptr<IComponent> Component::create4081(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4081(value));
}

std::unique_ptr<IComponent> Component::create4030(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4030(value));
}

std::unique_ptr<IComponent> Component::create4013(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4013(value));
}

std::unique_ptr<IComponent> Component::create4069(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4069(value));
}

std::unique_ptr<IComponent> Component::create4514(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4514(value));
}

std::unique_ptr<IComponent> Component::create4040(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4040(value));
}

std::unique_ptr<IComponent> Component::create4017(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new C4017(value));
}

/*

    std::unique_ptr<IComponent> Component::create4094(const std::string &value) const noexcept
    {

    }

    std::unique_ptr<IComponent> Component::create4801(const std::string &value) const noexcept
    {

    }


    */
std::unique_ptr<IComponent> Component::createClock(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new Clock(value));
}

std::unique_ptr<IComponent> Component::createInput(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new Input(value));
}

std::unique_ptr<IComponent> Component::createOutput(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new Output(value));
}

std::unique_ptr<IComponent> Component::createTrue(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new True(value));
}

std::unique_ptr<IComponent> Component::createFalse(const std::string &value) const noexcept
{
    return std::unique_ptr<IComponent>(new False(value));
}

} // namespace nts
