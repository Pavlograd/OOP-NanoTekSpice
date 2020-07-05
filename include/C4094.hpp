/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4094
*/

#ifndef __C4094_HPP__
# define __C4094_HPP__

# include "IComponent.hpp"

namespace nts
{
class C4094 : public IComponent
{
public:
    C4094(const std::string &value);
    ~C4094();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "4094";}
    void simulate(int output);

    //Simulation for C4094
    void NORPin(int, int, int);


protected:
private:
    IComponent *_component[14];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !C4094_HPP_ */
