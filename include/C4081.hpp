/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4081
*/

#ifndef __C4081_HPP__
# define __C4081_HPP__

# include "IComponent.hpp"

namespace nts
{
class C4081 : public IComponent
{
public:
    C4081(const std::string &value);
    ~C4081();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "4081";}
    void simulate(int output);

    //Simulation for C4081
    void ANDPin(int, int, int);


protected:
private:
    IComponent *_component[13];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !C4081_HPP_ */
