/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#ifndef __False_HPP__
# define __False_HPP__

# include "IComponent.hpp"

namespace nts
{
class False : public IComponent
{
public:
    False(const std::string &value);
    ~False();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "False";}
    void simulate(int output);

protected:
private:
    IComponent *_component[1];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !False_HPP_ */
