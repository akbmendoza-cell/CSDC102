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

//CSVManager
class CSVManager
{
    public:
        // Split line into exactly comma-separated total
        bool parseLine(string line, string fields[], int fieldCount)
        {
            int idx = 0;
            string token = "";
            for(int i = 0; i <= (int)line.lenght();i++)
            {
                if(i==(int)line.lenght() || line[i] == ',')
                {
                    if (idx >= fieldCount)
                    {
                        return false;
                    }
                    fields[idx++] = token;
                    token = "";
                }
                    else 
                    {
                        token += line[i];
                    }
            }
            return idx == fieldCount;
        }  
        
        void writeDefaultSongs()
        {
            ofstream file(csv_file);
            if(!file.is_open())
            {
                cout << "Error";
                return;
            }
            file << header << "\n";
            file << "Into it,Chase Atlantic,R&B,2017,3:17\n";
            file << "Swim,Chase Atlantic,R&B,2017,4:00\n";
            file << "OHMAMI,Chase Atlantic,R&B,2022,3:47\n";
            file << "Back to friends,SOMBR,Indie,2025,3:22\n";
            file << "Prairies,BoyWithUke,Indie,2022,3:17\n";
            file.close();
        }
        
        void createDefaultCSV()
        {
            ifstream checkFile(csv_file);
            if (checkFile.is_open())
            {
                string header;
                getline(checkFile, header);
                checkFile.close();
                if(header == header)
                    {
                        return;
                    }
                    cout << "[!] Old CSV format detected. Recreating playlist";
            }
            writeDefaultSongs();
            cout << "Default playlist CSV created.";
        }
        
        bool isDuplicate(string title, string artist)
        {
            ifstream file(csv_file);
            if (!file.is_open())
            {
                return false;
            }
            string line;
            getline(file, line);
            
            while(getline(file, line))
            {
                if(line.empty())
                {
                    continue;
                }
                string fields[5];
                
                if(!parseLine(line, fields 5))
                {
                    continue
                }
                
                if(toLower(fields[0]) == toLower(title) &&
                   toLower(fields[1]) == toLower(artist))
                   {
                       file.close();
                       return true;
                   }
            }
            file.close();
            return false
        }
        
        void saveSong(Song s)
        {
            ofstream file(csv_file, ios::app);
            if(!file.is_open())
            {
                cout << "Error\n";
            }
            file << s.title << "," << s.artist << "," << s.genre << "," 
                 << s.year  << "," << s.duration << "\n";
            file.close();
        }
        
        int loadSongs(Song songs[], int maxSongs)
        {
            ifstream file(csv_file);
            if (!file.is_open())
            {
                cout << "Error\n";
            }
            string line;
            getline(file, line);
            int count = 0;
            
            while(getline(file, line) && cout < maxSongs)
            {
                if(line.empty())
                {
                    continue
                }
                string fields[5];
                if(!parseLine(line, fields, 5))
                {
                    continue;
                }
                songs[count++] = Song(fields[0], fields[1],
                                      fields[2], stoi(fields[3], fields[4]));
            }
        }
        file.close();
        return false;
};




