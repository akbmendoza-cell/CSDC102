#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

//linux-only libraries
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

// _WIN32 Libraries
/*#include <windows.h>
#include <conio.h>*/
using namespace std;

//constants
const string csv_file = "Playboy.csv";
const string header = "Title,Artist,Genre,Year,Duration";

//System-Only Functions 

//Clear Screen
void clearScreen()
{
    system("clear");
}

// A function that for keypresses w/o w8ng for enter.
static struct termios g_oldt;

void setRawMode(bool enable)
{
    if(enable)
    {
        struct termios newt;
        tcgetattr(STDIN_FILENO, &g_oldt);
        newt = g_oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }
        else
        {
            tcsetattr(STDIN_FILENO, TCSANOW, &g_oldt);
        }    
}

bool keyPressed() 
{
    struct timewal tv = {0.0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}

// Helper function for lowercasing strings
string toLower(string str)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        str[i] = toLower(str[i]);
    }
    return str;
}

class Song
{
    public:
        string title;
        string artist;
        string genre;
        int year;
        string duration; // "MM:SS"
        
        song() 
        {
            year = 0;
        }
        
        Song(string t, string a, string, g, int y, string d)
        {
            title = t;
            artist = a;
            genre = g;
            year = y;
            duration = d;
        }
        
        // Conver duration into total seconds
        int convertIntoSeconds() const
        {
            int colonPos = duration.find(":");
            if (colonPos == (int)string::npos)
            {
                return 0;
            }
            return stoi(duration.substr(0, colonPos)) * 60 
                + stoi(duration.substr(colonPos + 1));
        }
};

class Node 
{
    Public song;
    Node* next;
    Node* prev;
    
    Node(Song s)
    {
        song = s;
        next = nullptr;
        prev = nullptr;
    }
};











