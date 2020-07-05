/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Command
*/

#include "IComponent.hpp"
#include <csignal>
#include <unistd.h>
#include <sstream>

volatile int sigint;

void signalHandler(int signum)
{
    sigint = signum;
}

void defaultHandler(int signum)
{
    exit(signum);
}

void loop(nts::Component *component)
{
    sigint = 0;

    std::signal(SIGINT, signalHandler);

    while (1)
    {
        component->simulate(0);
        if (sigint)
            break;
        sleep(1);
    }

    std::signal(SIGINT, defaultHandler);
}

int readData(std::istream &in, std::string *command)
{
    std::string line;
    std::stringstream ss;
    std::string error;

    if (!in)
        exit(0);
    std::cout << "> ";
    getline(in, line);
    ss << line;
    ss >> *command;
    ss >> error;
    if (!error.empty())
    {
        std::cerr << "Invalid command." << std::endl;
        exit(84);
    }
    return 1;
}

void changeValue(std::string command, nts::Component *component)
{
    std::string input = "";
    std::string value = "";
    size_t n = std::count(command.begin(), command.end(), '=');
    std::replace(command.begin(), command.end(), '=', ' ');

    if (n != 1)
    {
        std::cerr << "Invalid command." << std::endl;
        return;
    }
    std::istringstream ss(command);
    ss >> input;
    ss >> value;
    if (input.empty() || value.empty()) {
        std::cerr << "Value or Input name is missing." << std::endl;
        return;
    }
    component->changeValue(input, value);
}

int check_command(std::string command, nts::Component *component)
{
    if (command == "exit")
        return 1;
    else if (command == "display")
        component->display();
    else if (command == "simulate")
        component->simulate(0);
    else if (command == "dump")
        component->dumpAll();
    else if (command == "loop")
        loop(component);
    else
    {
        changeValue(command, component);
    }
    return 0;
}