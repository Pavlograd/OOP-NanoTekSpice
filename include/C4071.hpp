/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4071
*/

#ifndef __C4071_HPP__
# define __C4071_HPP__

# include "IComponent.hpp"

namespace nts
{
class C4071 : public IComponent
{
public:
    C4071(const std::string &value);
    ~C4071();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "4071";}
    void simulate(int output);

    //Simulation for C4071
    void ORPin(int, int, int);


protected:
private:
    IComponent *_component[13];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !C4071_HPP_ */
