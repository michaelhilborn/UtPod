//
//  Song.cpp
//  UTPod
//
//  Created by Michael Hilborn on 10/19/18.
//  Copyright © 2018 Michael Hilborn. All rights reserved.
//

#include "Song.hpp"
using namespace std;

Song::Song(){

};

Song::Song(string _artist, string _title, int _size){
    title = _title;
    artist = _artist;
    size = _size;
};

string Song::getTitle() const{
    return title;
}

string Song::getArtist() const{
    return artist;
}

int Song::getSize() const{
    return size;
}

void Song::setTitle(string newTitle){
    title = newTitle;
}

void Song::setArtist(string newArtist){
    artist = newArtist;
}

void Song::setSize(int newSize){
    size = newSize;
}

bool Song::operator >(Song const &rhs){
    if(artist > rhs.artist){
        return(artist>rhs.artist);
    }
    if(title > rhs.title){
        return(title>rhs.title);
    }
    if(size > rhs.size){
        return(size>rhs.size);
    }
    return(false);
}

bool Song::operator ==(Song const &rhs){
    return (artist == rhs.artist &&
            title == rhs.title &&
            size == rhs.size);
}

bool Song::operator <(Song const &rhs){

    bool returnvalue;
    if(artist < rhs.artist){
        returnvalue = (artist<rhs.artist);
    }
    else{
        if((title < rhs.title) && (artist == rhs.artist)){
            returnvalue = (title < rhs.title);
        }
        else{
            if((size < rhs.size) && (title == rhs.title)){
                returnvalue = (size<rhs.size);
            }
            else{
                returnvalue = (false);
            }
        }
    }
    return returnvalue;
}

Song::~Song(){

}
