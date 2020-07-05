/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#ifndef __True_HPP__
# define __True_HPP__

# include "IComponent.hpp"

namespace nts
{
class True : public IComponent
{
public:
    True(const std::string &value);
    ~True();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "True";}
    void simulate(int output);

protected:
private:
    IComponent *_component[1];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !True_HPP_ */
