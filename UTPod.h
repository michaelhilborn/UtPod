//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"
#include <ctime>

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

    int getUsedMemory(); //done

    /* FUNCTION - int numberOfSongs
     *  returns the number of Songs currently on the UTPod

     input parms - none

     output parms - number of songs on UTPod
     */

    int numberOfSongs(); //done

    void swapSongs(int num_node1, int num_node2); //done

public:
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;
    //Default constructor
    //set the memory size to MAX_MEMORY

    UtPod(); //done

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.

    UtPod(int size);//done

    /* FUNCTION - int addSong
     * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

     precondition: s is a valid Song

     input parms - song that is wanted to be added to the UTPod

     output parms - an error code based on whether the song was successfully added or not
     */

    int addSong(Song const &s);//done


    /* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -1 if nothing is removed


     input parms - A song that is to be removed from the UTPod

     output parms - An error code based on whether it was succesfully removed
        or if it was not found on the UTPod
     */

    int removeSong(Song const &s);//done


    /* FUNCTION - void shuffle
     *  shuffles the songs into random order
     o will do nothing if there are less than two songs in the current list

     input parms - none

     output parms - none
     */

    void shuffle();//done


    /* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

     input parms - none

     output parms - none
     */

    void showSongList();


    /* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
     o will do nothing if there are less than two songs in the current list

     input parms - none

     output parms - none
     */

    void sortSongList(); //done


    /* FUNCTION - void clearMemory
     * clears all the songs from memory

     input parms - none

     output parms - none
     */
    void clearMemory();


    /* FUNCTION - int getTotalMemory
     *  returns the total amount of memory in the UtPod
     o will do nothing if there are less than two songs in the current list

     input parms - none

     output parms - Total memory on the UTPod
     */

    int getTotalMemory() { //done
        return memSize;
    }



    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

     input parms - none

     output parms - remaining memory space on the UTPod
     */

    int getRemainingMemory(); //done


    ~UtPod();

};



#endif
