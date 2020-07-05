/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4030
*/

#ifndef __C4030_HPP__
# define __C4030_HPP__

# include "IComponent.hpp"

namespace nts
{
class C4030 : public IComponent
{
public:
    C4030(const std::string &value);
    ~C4030();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "4030";}
    void simulate(int output);

    //Simulation for C4030
    void XORPin(int, int, int);


protected:
private:
    IComponent *_component[14];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !C4030_HPP_ */
