/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#ifndef __Output_HPP__
# define __Output_HPP__

# include "IComponent.hpp"

namespace nts
{
class Output : public IComponent
{
public:
    Output(const std::string &value);
    ~Output();
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    void dump() const;
    nts::Tristate getValue() const;
    void setValue(const std::string &value);
    virtual std::string getType() const {return "Output";}
    void simulate(int output);

protected:
private:
    IComponent *_component[1];
    nts::Tristate _value;
};
} // namespace nts

#endif /* !Output_HPP_ */
