/*
** EPITECH PROJECT, 2020
** IComponent
** File description:
** IComponent
*/

#ifndef __IComponent__
# define __IComponent__

# include <iostream>
# include <iterator>
# include <algorithm>
# include <memory>
# include <vector>
# include <sstream>
# include <map>

namespace nts
{
enum Tristate
{
    UNDEFINED = (-true),
    TRUE = true,
    FALSE = false
};
class IComponent
{
public:
    virtual ~IComponent() = default;

public:
    virtual nts::Tristate compute(std::size_t pin = 1) = 0;
    virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    virtual void dump() const = 0;
    virtual nts::Tristate getValue() const = 0;
    virtual std::string getType() const = 0;
    virtual void simulate(int output) = 0;
    virtual void setValue(const std::string &value) = 0;
};

class Component : public IComponent
{
public:
    Component() {}
    ~Component() {}
    nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    nts::Tristate getValue() const { return TRUE; }
    const std::string getName() const { return "noName"; }
    virtual std::string getType() const { return "noType"; }
    void setValue(const std::string &value) { (void)value; }
    void addComponent(const std::string &type, const std::string &value, const std::string &name);
    std::unique_ptr<IComponent> createComponent(const std::string &type, const std::string &value);
    void simulate(int output);
    void display();
    void dump() const;
    void dumpAll();
    void createLink(const std::string &component1, const std::string &component2, int pin1, int pin2);
    void changeValue(const std::string &input, const std::string &value);
    bool componentExist(const std::string &name);

private:
    std::map<std::string, std::unique_ptr<IComponent>> _components;
    std::unique_ptr<IComponent> create4001(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4008(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4011(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4013(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4017(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4030(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4040(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4069(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4071(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4081(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4094(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4514(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> create4801(const std::string &value) const noexcept;

    std::unique_ptr<IComponent> createClock(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> createInput(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> createOutput(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> createTrue(const std::string &value) const noexcept;
    std::unique_ptr<IComponent> createFalse(const std::string &value) const noexcept;
};

} // namespace nts

#endif /* !IComponent_ */
