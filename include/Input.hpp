/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#ifndef __Input_HPP__
# define __Input_HPP__

# include "IComponent.hpp"

namespace nts
{
class Input : public IComponent
{
public:
    Input(const std::string &value);
    ~Input();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "Input";}
    void simulate(int output);

protected:
private:
    IComponent *_component[1];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !Input_HPP_ */
