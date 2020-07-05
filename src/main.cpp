/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "IComponent.hpp"
#include "Parsing.hpp"
#include "Command.hpp"
#include "C4001.hpp"

int main(int argc, char **argv)
{
    nts::Component component;
    std::string command = "";

    parsingFile(argc, argv, &component);
    /*component.addComponent("4001", "1", "and0");

    component.addComponent("Input", "1", "I0");
    component.addComponent("Input", "1", "I1");
    component.addComponent("Input", "0", "I2");
    //component.addComponent("Output", "0", "S0");

    component.addComponent("4001", "1", "and1");
    component.addComponent("Input", "0", "I3");
    component.addComponent("Output", "0", "S1");

    //component.addComponent("Clock", "1", "ClockUp");
    //component.createLink("I0", "S0", 1, 1); //Set on link betwteen one input and one output
    //component.createLink("and0", "ClockUp", 10, 1);

    component.createLink("and0", "I0", 1, 1);
    component.createLink("and0", "I1", 2, 1);
    component.createLink("and0", "I2", 6, 1);
    component.createLink("and0", "and0", 3, 5);
    component.createLink("and0", "and1", 4, 2);

    component.createLink("and1", "I3", 1, 1);
    component.createLink("and1", "S1", 3, 1);*/
    component.simulate(0);
    component.display();
    while (readData(std::cin, &command))
    {
        if (check_command(command, &component))
            break;
    }
    return 0;
}