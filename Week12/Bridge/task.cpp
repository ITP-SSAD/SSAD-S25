#include <iostream>
#include <string>

using namespace std;

// Interface (Abstract Base Class)
class MusicPlayer {
public:
    virtual void start(const string& fileName) = 0;
    virtual void decode(const string& fileName) = 0;
    virtual ~MusicPlayer() {} // Virtual destructor for proper cleanup
};

// Jazz Music Players
class JazzMusicPlayerMP3Codec : public MusicPlayer {
public:
    void start(const string& fileName) override {
        cout << "Started Jazz Player..." << endl;
        decode(fileName);
    }

    void decode(const string& fileName) override {
        cout << "Playing " << fileName << " using MP3 codec." << endl;
    }
};

class JazzMusicPlayerWAVCodec : public MusicPlayer {
public:
    void start(const string& fileName) override {
        cout << "Started Jazz Player..." << endl;
        decode(fileName);
    }

    void decode(const string& fileName) override {
        cout << "Playing " << fileName << " using WAV codec." << endl;
    }
};

// Pop Music Players
class PopMusicPlayerMP3Codec : public MusicPlayer {
public:
    void start(const string& fileName) override {
        cout << "Started Pop Player..." << endl;
        decode(fileName);
    }

    void decode(const string& fileName) override {
        cout << "Playing " << fileName << " using MP3 codec." << endl;
    }
};

class PopMusicPlayerWAVCodec : public MusicPlayer {
public:
    void start(const string& fileName) override {
        cout << "Started Pop Player..." << endl;
        decode(fileName);
    }

    void decode(const string& fileName) override {
        cout << "Playing " << fileName << " using WAV codec." << endl;
    }
};

int main() {
    // Using pointers for polymorphism
    MusicPlayer* popMusicPlayer1 = new PopMusicPlayerMP3Codec();
    MusicPlayer* jazzMusicPlayer = new JazzMusicPlayerMP3Codec();
    MusicPlayer* popMusicPlayer2 = new PopMusicPlayerWAVCodec();

    popMusicPlayer1->start("pop_song_1.mp3");
    jazzMusicPlayer->start("jazz_song.mp3");
    popMusicPlayer2->start("pop_song_2.wav");

    // Clean up
    delete popMusicPlayer1;
    delete jazzMusicPlayer;
    delete popMusicPlayer2;

    return 0;
}