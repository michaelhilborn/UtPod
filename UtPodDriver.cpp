/* utPod_driver.cpp
 Demo Driver for the UtPod.

 Roger Priebe
 EE 312 10/16/18

 This is a basic driver for the UtPod.

 You will want to do more complete testing.

 */
#include <cstdlib>
#include <iostream>
#include "Song.hpp"
#include "UTPod.hpp"

using namespace std;

int main(int argc, char *argv[])
{

    static const int CUSTOM_MEMORY = 255;
    UtPod t;
    UtPod t2(CUSTOM_MEMORY);
    //static const int SUCCESS = 0;
    //static const int NO_MEMORY = -1;
    //static const int NOT_FOUND = -2;

    int errorcode = 0;
    int totmemory = 0;
    int remainingmemory = 0;
    int correct = 0;
    int total = 50;

    Song redbone("Childish Gambino", "Redbone", 15);
    Song bonfire("Childish Gambino", "Bonfire", 10);
    Song heartbeat("Childish Gambino", "Heartbeat", 12);
    Song outside("Childish Gambino", "Outside", 12);
    Song three00five("Childish Gambino", "3005", 11);
    Song sober("Childish Gambino", "Sober", 13);
    Song telegraphave("Childish Gambino", "Telegraph Ave.", 16);
    Song summertimemagic("Childish Gambino", "Summertime Magic", 19);
    Song freaksandgeeks("Childish Gambino", "Freaks and Geeks", 11);
    Song brokenwhiskeyglass("Post Malone", "Broken Whiskey Glass", 13);
    Song feelingwhitney("Post Malone", "Feeling Whitney", 18);
    Song zackandcodeine("Post Malone", "Zack & Codeine", 10);
    Song betternow("Post Malone", "Better Now", 11);
    Song stay("Post Malone", "Stay", 19);
    Song takinshots("Post Malone", "Takin Shots", 12);
    Song psycho("Post Malone", "Psycho", 10);
    Song ifallapart("Post Malone", "I Fall Apart", 15);
    Song congratulations("Post Malone ft. Quavo", "Congratulations", 14);
    Song sickomode("Travis Scott", "SICKO MODE", 13);
    Song yosemite("Travis Scott", "YOSEMITE", 11);
    Song nobystanders("Travis Scott", "NO BYSTANDERS", 13);
    Song antidote("Travis Scott", "Antidote", 14);
    Song onenight("Lil Yachty", "One Night", 17);
    Song foreveryoung("Lil Yachty ft. Diplo", "Forever Young", 13);
    Song doreme("Blackbear", "do re mi", 18);
    Song prblms("Blackbear", "PRBLMS", 11);
    Song excalling("Blackbear", "Ex Calling", 12);
    Song newpatek("Lil Uzi Vert", "New Patek", 13);
    Song xotourlife("Lil Uzi Vert", "XO TOUR Llif3", 11);
    Song moneylonger("Lil Uzi Vert", "Money Longer", 12);
    Song devastated("Joey Bada$$", "DEVASTATED", 13);
    Song promnight("Chance The Rapper", "Prom Night", 15);
    Song daynnight("Kid Cudi", "Day 'n' Night", 13);
    Song mobamba("Sheck Wes", "Mo Bamba", 19);
    Song iloveit("Lil Pump ft. Kanye", "I Love It", 17);
    Song luciddreams("Juice WRLD", "Lucid Dreams", 12);
    Song partyonfifth("Mac Miller", "Party On Fifth Ave.", 12);
    Song weekend("Mac Miller ft. Miguel", "Weekend", 13);
    Song seniorskipday("Mac Miller", "Senior Skip Day", 11);
    Song selfcare("Mac Miller", "Self Care", 13);
    Song memyselfandi("G-Eazy", "Me, Myself, & I", 19);
    Song almostfamous("G-Eazy", "Almost Famous", 15);
    Song himandi("G-Eazy ft. Halsey", "Him and I", 11);
    Song geazysober("G-Eazy ft. Charlie Puth", "Sober", 11);
    Song letsgetlost("G-Eazy ft Devon Baldwin", "Let's Get Lost", 12);
    Song rebel("G-Eazy", "Rebel", 15);
    Song nointerruption("Hoodie Allen", "No Interruption", 17);
    Song surpriseparty("Hoodie Allen ft. Blackbear", "Surprise Party", 20);
    Song movie("Hoodie Allen", "Movie", 18);
    Song actmyage("Hoodie Allen", "Act My Age", 19);
    Song highagain("Hoodie Allen", "High Again", 20);
    Song eighteencool("Hoodie Allen", "Eighteen Cool", 21);
    Song dumbforyou("Hoodie Allen", "Dumb For You", 23);
    Song floatsmyboat("Aer", "Floats My Boat", 21);
    Song saysshelovesme("Aer", "Says She Loves Me", 25);
    Song twentyonetwelve("Rush", "2112", 256);

    //Test 1: Default Constructor Memory Size test
    totmemory = t.getTotalMemory();
    if(totmemory == 512){
        correct ++;
        cout<<"Test 1: Default Constructor Memory Test Passed"<<endl;
        cout<< "Score:"<<correct<<"/"<<total<<endl<<endl;
    }

    //Test 2: Custom size Constructor test
    totmemory = t2.getTotalMemory();
    if(totmemory == CUSTOM_MEMORY){
        correct ++;
        cout<<"Test 2: Custom Memory Constructor Test Passed"<<endl;
        cout<< "Score:"<<correct<<"/"<<total<<endl<<endl;
    }

    //Test 3: remaining memory test
    totmemory = t.getTotalMemory();
    remainingmemory = t.getRemainingMemory();
    if(totmemory == remainingmemory){
        correct ++;
        cout<< "Test 3: Remaining Memory Test 1 passed"<<endl;
        cout<< "Score:"<<correct<<"/"<<total<<endl<<endl;
    }

    //Test 4: remaining memory test 2
    t.addSong(redbone);
    t.addSong(betternow);
    t.addSong(devastated);
    t.addSong(mobamba);
    t.addSong(himandi);
    t.addSong(movie);
    t.addSong(rebel);
    t.addSong(doreme);
    t.addSong(iloveit);
    t.addSong(yosemite);
    remainingmemory = t.getRemainingMemory();
    if(remainingmemory == 364){
        correct ++;
        cout<<"Test 4: Remaining Memory Test 2 passed"<< endl;
        cout<< "Score:"<<correct<<"/"<<total<<endl<<endl;

    }

    //Test 5: Remove Song Test 1:
    errorcode = t.removeSong(stay);
    if(errorcode == t.NOT_FOUND){
        correct ++;
        cout<<"Test 5: Remove Song Test 1 passed"<<endl;
        cout<< "Score:"<<correct<<"/"<<total<<endl<<endl;
    }

    t.showSongList();
    cout<<endl<<endl;

    //shuffle test
    t.shuffle();
    t.showSongList();
    cout<<endl<<endl;

    //Sort Test
    t.sortSongList();
    t.showSongList();
    cout<<endl<<endl;

    //Test 6: Remove Song Test 2:
    errorcode = t.removeSong(betternow);
    if(errorcode == t.SUCCESS){
        correct ++;
        cout<<"Test6: Remove Song Test 2 passed"<<endl;
        cout<< "Score:"<<correct<<"/"<<total<<endl<<endl;
    }

    //Test 7: Fill up memory test
    t.addSong(nointerruption);
    t.addSong(surpriseparty);
    t.addSong(actmyage);
    t.addSong(highagain);
    t.addSong(eighteencool);
    t.addSong(dumbforyou);
    errorcode = t.addSong(twentyonetwelve);

    if(errorcode == t.NO_MEMORY){
        correct++;
        cout<<"Test 7 Add Song Test No Memory Passed"<<endl;
        cout<< "Score:"<<correct<<"/"<<total<<endl<<endl;
    }
}
