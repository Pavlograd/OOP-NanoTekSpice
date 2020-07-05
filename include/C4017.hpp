/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4017
*/

#ifndef __C4017_HPP__
# define __C4017_HPP__

# include "IComponent.hpp"

namespace nts
{
class C4017 : public IComponent
{
public:
    C4017(const std::string &value);
    ~C4017();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "4017";}
    void simulate(int output);

    //Simulation for C4017

protected:
private:
    IComponent *_component[14];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !C4017_HPP_ */
