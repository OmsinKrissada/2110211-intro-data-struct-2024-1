#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "priority_queue.h"

using namespace std;

class Song {
   public:
    std::string artist, title;
    int count;

    Song() {}
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) {}
    Song(std::string artist, std::string title, int count) : artist(artist), title(title), count(count) {}

    friend std::ostream &operator<<(std::ostream &out, const Song &s) {
        return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }
};

//  you have to write something below this line
#include <tuple>
class Compare1 {
   public:
    bool operator()(Song left, Song right) {
        typedef std::tuple<std::string, std::string> tup;
        tup l = {left.artist, left.title};
        tup r = {right.artist, right.title};
        return l > r;
    }
};

class Compare2 {
   public:
    bool operator()(Song left, Song right) {
        typedef std::tuple<int, std::string, std::string> tup;
        tup l = {-left.count, left.artist, left.title};
        tup r = {-right.count, right.artist, right.title};
        return l > r;
    }
};
//  you *MIGHT* have to change the declaration of pq1 and pq2
CP::priority_queue<Song, Compare1> pq1;
CP::priority_queue<Song, Compare2> pq2;

#endif
