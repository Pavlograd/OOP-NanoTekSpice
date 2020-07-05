/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4008
*/

#ifndef __C4008_HPP__
# define __C4008_HPP__

# include "IComponent.hpp"

namespace nts
{
class C4008 : public IComponent
{
public:
    C4008(const std::string &value);
    ~C4008();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "4008";}
    void simulate(int output);

    //Simulation for C4008
    void ADDERPin(int, int, int, int);


protected:
private:
    IComponent *_component[16];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !C4008_HPP_ */
