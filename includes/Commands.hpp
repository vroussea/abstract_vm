
#ifndef ABSTRACT_VM_COMMANDS_HPP
#define ABSTRACT_VM_COMMANDS_HPP


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Commands {
public:
    Commands();

    Commands(Commands const &src);

    virtual ~Commands();

    Commands &operator=(Commands const &);

    const std::vector<std::string> getList() const;

    void setCommands();

    void setCommands(const char *filename);

private:
    std::vector<std::string> list;
};

std::ostream &operator<<(std::ostream &o, Commands const &i);

#endif
