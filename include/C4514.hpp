/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4514
*/

#ifndef __C4514_HPP__
# define __C4514_HPP__

# include "IComponent.hpp"

namespace nts
{
class C4514 : public IComponent
{
public:
    C4514(const std::string &value);
    ~C4514();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "4514";}
    void simulate(int output);

    //NO SIMULATION FOR C4514 BECAUSE EVERYTHING DEPEND OF EVERYTHING

protected:
private:
    IComponent *_component[24];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !C4514_HPP_ */
