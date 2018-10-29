//
//  Song.hpp
//  UTPod
//
//  Created by Michael Hilborn on 10/19/18.
//  Copyright © 2018 Michael Hilborn. All rights reserved.
//

#ifndef Song_h
#define Song_h

#include <stdio.h>
#include <string>

class Song{

private:

    std::string title;
    std::string artist;
    int size;
    static const int MAX_SIZE;

public:

    Song();
    Song(std::string _title, std::string _artist, int _size);

    std::string getTitle() const;
    std::string getArtist() const;
    int getSize() const;

    void setTitle(std::string newTitle);
    void setArtist(std::string newArtist);
    void setSize(int Size);

    bool operator >(Song const &rhs);
    bool operator ==(Song const &rhs);
    bool operator <(Song const &rhs);


    ~Song();


};

#endif /* Song_hpp */
