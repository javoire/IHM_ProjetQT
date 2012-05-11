#ifndef FILMDUMMY_H
#define FILMDUMMY_H

#include <iostream>

class filmDummy
{
public:
    filmDummy();
    std::string name() const { return name_; }
    unsigned short genre() const { return genre_; }
    unsigned short rating() const { return rating_; }
    unsigned short length() const { return length_; }

private:
    std::string name_;
    unsigned short genre_;
    unsigned short rating_;
    unsigned short length_;

};

#endif // FILMDUMMY_H
