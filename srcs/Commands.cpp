#include "../includes/Commands.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Commands::Commands() = default;

Commands::Commands(Commands const &src) {
    *this = src;
}

Commands::~Commands() = default;

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Commands &Commands::operator=(Commands const &rhs) {
    if (this != &rhs) {
        this->list = rhs.getList();
    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, Commands const &instance) {
    std::vector<std::string> list = instance.getList();
    for (const std::string &command : list)
        std::cout << command << std::endl;

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

void Commands::setCommands() {
    std::string input;

    while (input != ";;") {
        std::cin >> input;
        this->list.push_back(input);
    }
    this->list.pop_back();
}


void Commands::setCommands(const char *filename) {
    std::string line;

    std::ifstream file;

    file.open(filename, std::ifstream::in);
    if (!file.fail()) {
        while (getline(file, line)) {
            this->list.push_back(line);
        }
    } else {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        throw std::exception();
    }
    file.close();
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */

const std::vector<std::string> Commands::getList() const {
    return this->list;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

