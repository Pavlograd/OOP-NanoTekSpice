/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4069
*/

#ifndef __C4069_HPP__
# define __C4069_HPP__

# include "IComponent.hpp"

namespace nts
{
class C4069 : public IComponent
{
public:
    C4069(const std::string &value);
    ~C4069();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "4069";}
    void simulate(int output);

    //Simulation for C4069
    void InvertPin(int, int);


protected:
private:
    IComponent *_component[14];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !C4069_HPP_ */
