//
//  Song.hpp
//  UTPod
//
//  Created by Michael Hilborn on 10/19/18.
//  Copyright © 2018 Michael Hilborn. All rights reserved.
//

#ifndef Song_hpp
#define Song_hpp

#include <stdio.h>
#include <string>

class Song{

private:

    std::string title;
    std::string artist;
    int size;
    static const int MAX_SIZE;

public:

    //Default constructor
    //set the memory size to 0 and the title and artist to blank strings
    Song();
    //Default constructor
    //set the title to the given title and the artist to the given artist and the
    Song(std::string _artist, std::string _title, int _size);

    /* FUNCTION - int getTitle
     *  returns the title of the current song

     input parms - none

     output parms - the title of the song
     */
    std::string getTitle() const;

    /* FUNCTION - int getArtist
     *  returns the name of the artist of the current song

     input parms - none

     output parms - the name of the artist of the current song
     */
    std::string getArtist() const;

    /* FUNCTION - int getSize
     *  returns the size of the current song

     input parms - none

     output parms - the size of the current song
     */
    int getSize() const;


    /* FUNCTION - int setTitle
     *  sets the title for the current song

     input parms - the wanted name for the song

     output parms - none
     */
    void setTitle(std::string newTitle);

    /* FUNCTION - int setArtist
     *  sets the artist of the current song

     input parms - the wanted artist for the song

     output parms - none
     */
    void setArtist(std::string newArtist);

    /* FUNCTION - int setSize
     *  sets the size of the current song

     input parms - the wanted size for the song

     output parms - none
     */
    void setSize(int Size);

    //Overload the > Operator to be able to compare songs
    bool operator >(Song const &rhs);

    //Overload the == Operator to be able to compare songs
    bool operator ==(Song const &rhs);

    //Overload the < Operator to be able to compare songs
    bool operator <(Song const &rhs);

    //default deconstructor for song
    ~Song();


};

#endif /* Song_hpp */
