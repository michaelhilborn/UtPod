//
//  UTPod.cpp
//  UTPod
//
//  Created by Michael Hilborn on 10/19/18.
//  Copyright © 2018 Michael Hilborn. All rights reserved.
//

#include "UtPod.h"
#include <iostream>
#include <cstdlib>
using namespace std;

UtPod::UtPod(){
    songs = NULL;
    memSize = MAX_MEMORY;
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
}

UtPod::UtPod(int size){
    songs = NULL;
    if(size > MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
}

int UtPod::addSong(const Song &s){
    //check if there is memory left if not return falure else do this
    int returncode;
    if(this->getRemainingMemory() < s.getSize()){
        returncode = NO_MEMORY;
    }
    else{
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = UtPod::songs;
        songs = temp;
        returncode = SUCCESS;
    }
    return returncode;
}

int UtPod::getRemainingMemory(){
    int total_mem = getTotalMemory();
    int used_mem = getUsedMemory();
    int remaining_mem = total_mem - used_mem;
    return remaining_mem;
}

int UtPod::getUsedMemory(){

    SongNode *temp_songnode = songs;
    Song *temp_song = new Song;
    int used_mem = 0;
    while(temp_songnode != NULL){
        *temp_song = temp_songnode->s;
        used_mem = used_mem + temp_song->getSize();
        temp_songnode = temp_songnode->next;
    }
    delete temp_song;
    return used_mem;
}

int UtPod::removeSong(const Song &song){
    int test = 42;
    int errorCode = NOT_FOUND;
    SongNode *temp = songs;
    SongNode *trail = songs;
    SongNode *found;
    if(temp != NULL){
        if(temp->s == song){
            test = 0;
            temp = trail->next;
            songs = temp;
            delete trail;
        }
        else{
            temp = trail->next;
            while(temp != NULL){
                if(temp->s == song){
                    test = 0;
                    trail->next = temp->next;
                    delete temp;
                }
                trail = trail->next;
                if(trail != NULL){
                  temp = trail->next;
                }
                else{
                  temp = NULL;
                }
            }
        }
    }
    if(test == 0){
        errorCode = SUCCESS;
    }
    return errorCode;
}

int UtPod::numberOfSongs(){

    int num = 0;
    SongNode *temp = songs;

    while(temp != NULL){
        temp = temp->next;
        num++;
    }

    return num;
}

void UtPod::shuffle(){
    int num_songs = UtPod::numberOfSongs();
    int num_loops = num_songs*3;
    for(int i = 0; i<num_loops; i++){

        //get random number mod it with num_songs
        int randNum1 = rand() % num_songs;

        //get random number 2 and mod it with num_songs
        int randNum2 = rand() % num_songs;

        //call swapSongs with input random number 1 and random number 2
        swapSongs(randNum1, randNum2);
    }
}

void UtPod::sortSongList(){

    SongNode *song_pointer1 = songs;
    SongNode *song_pointer2 = songs;
    int index_song1 = 0;
    int index_song2 = 0;

    while(song_pointer2 != NULL){

        while(song_pointer1 != NULL){

            if(song_pointer2->s <  song_pointer1->s){
                swapSongs(index_song1, index_song2);
            }

            index_song1++;
            song_pointer1 = song_pointer1->next;
        }
        song_pointer1 = songs;
        index_song1 = 0;

        index_song2++;
        song_pointer2 = song_pointer2->next;
    }
}

void UtPod::showSongList(){

    SongNode *temp = songs;
    int num = 0;
    if(temp == NULL){
        cout << "Your UtPod is empty" << endl;
    }
    while(temp != 0){

        cout << "song " << num << "-" << temp->s.getArtist() << ": " << temp->s.getTitle() << endl;
        temp = temp->next;
        num++;

    }

}

void UtPod::swapSongs(int num_node1, int num_node2){

    SongNode *temp = songs;
    SongNode *temp2 = songs;

    for(int i=0; i<num_node1; i++){
        temp = temp->next;
    }
    for(int i=0; i<num_node2;i++){
        temp2=temp2->next;
    }

    Song *temp_song = new Song;
    *temp_song = temp->s;
    temp->s = temp2->s;
    temp2->s = *temp_song;
    delete temp_song;

}

void UtPod::clearMemory(){
    int numSongs = numberOfSongs();
    SongNode *temp = songs;
    SongNode *trail = songs;
    SongNode *trailtrail = songs;

    for(int i = 0; i<numSongs; i++){

        temp = temp->next;

        if(temp != NULL){
            temp = temp->next;
            trail = trail->next;
        }

        while(temp != NULL){
            temp = temp->next;
            trail = trail->next;
            trailtrail = trailtrail->next;
        }
        trailtrail->next = temp;
        delete trail;
        trail = songs;
        temp = songs;
        trailtrail = songs;
    }
}

UtPod::~UtPod(){
    clearMemory();
}
