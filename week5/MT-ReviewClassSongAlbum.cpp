#include <iostream>
using namespace std;

class Album {
public:
    Album();
    Album(const Album& o);
    ~Album();
    Album& operator=(const Album& o);
    void addSong(string n, double d); // Appends a song into the end of the list
    void print(); // Prints all songs in the album
    void removeSong(int index); // Remove a song from the list by its index
    double totalDuration(); // Return the total duration of all songs in the list
private:
    struct Song {
        string name;
        double duration;
    };
    string singer;
    Song* list;
    int numSongs;
};

Album::Album() {
  singer = "";
  list = new Song[10];
  numSongs = 0;
}

Album::Album(const Album& o) {
  singer = o.singer;
  numSongs = o.numSongs;
  list = new Song[10];
  for (int i = 0; i < numSongs; i++) {
      list[i] = o.list[i];
  }
}

Album::~Album() { delete[] list; }

Album& Album::operator=(const Album& o) {
  if (this == &o) {
      return *this;
  }
  delete[] list;
  singer = o.singer;
  numSongs = o.numSongs;
  list = new Song[10];
  for (int i = 0; i < numSongs; i++) {
      list[i] = o.list[i];
  }
  return *this;
}

void Album::addSong(string n, double d) {
  if (numSongs == 10) {
      cerr << "list full" << endl;
      return;
  }
  Song s;
  s.name = n;
  s.duration = d;
  list[numSongs++] = s;
}

void Album::print() {
  for (int i = 0; i < numSongs; i++) {
      std::cout << list[i].name << "(" << list[i].duration << ")" << std::endl;
  }
}

void Album::removeSong(int index) {

  if (index > numSongs) {
      std::cerr << "invalid index" << std::endl;
      return;
  }
  Song* newList = new Song[10];
  for (int i = 0; i < index; i++) {
      newList[i] = list[i];
  }
  for (int i = index + 1; i < numSongs; i++) {
      newList[i - 1] = list[i];
  }
  delete[] list;
  list = newList;
  numSongs--;
}

double Album::totalDuration() {
  double total = 0;
  for (int i = 0; i < numSongs; i++) {
      total += list[i].duration;
  }
  return total;
}

int main() {
    Album album;
    album.addSong("Song1", 3.5);
    album.addSong("Song2", 4.0);
    album.addSong("Song3", 2.75);

    cout << "Album contents:" << endl;
    album.print();

    cout << "Total duration: " << album.totalDuration() << " minutes" << endl;

    album.removeSong(1);
    cout << "Album contents after removing Song2:" << endl;
    album.print();

    cout << "Total duration: " << album.totalDuration() << " minutes" << endl;

    Album album2 = album; // Test copy constructor
    album2.addSong("Song4", 3.0);

    cout << "Album2 contents after adding Song4:" << endl;
    album2.print();

    album = album2; // Test assignment operator

    cout << "Album contents after assignment from album2:" << endl;
    album.print();

    return 0;
}