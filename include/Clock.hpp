/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#ifndef __Clock_HPP__
# define __Clock_HPP__

# include "IComponent.hpp"

namespace nts
{
class Clock : public IComponent
{
public:
    Clock(const std::string &value);
    ~Clock();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "Clock";}
    void simulate(int output);

protected:
private:
    nts::Tristate _value;
};
} // namespace nts

#endif /* !Clock_HPP_ */
