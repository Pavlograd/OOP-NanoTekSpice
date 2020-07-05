/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4040
*/

#ifndef __C4040_HPP__
# define __C4040_HPP__

# include "IComponent.hpp"

namespace nts
{
class C4040 : public IComponent
{
public:
    C4040(const std::string &value);
    ~C4040();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "4040";}
    void simulate(int output);

    //Simulation for C4040 not required because everything depend of everything


protected:
private:
    IComponent *_component[16];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !C4040_HPP_ */
