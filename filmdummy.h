#ifndef FILMDUMMY_H
#define FILMDUMMY_H

#include <string>

class FilmDummy
{
public:
    FilmDummy();
    std::string name() const { return name_; }
    std::string genre() const { return genre_; }
    unsigned short rating() const { return rating_; }
    unsigned short length() const { return length_; }

private:
    std::string name_;
    std::string genre_;
    unsigned short rating_;
    unsigned short length_;

};

#endif // FILMDUMMY_H
