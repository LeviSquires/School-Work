#include <iostream>
#include <exception>

using std::cout;
using std::endl;    


int const SOUND_CONFIG_ERROR = 0;
int const VIDEO_CONFIG_ERROR = 1;
int const NETWORK_CONFIG_ERROR = 2;
int const DATA_CONFIG_ERROR = 3;
int const LOGON_ERROR = 4;

void checkSoundConfiguration(); 
void checkVideoConfiguration();
void checkNetworkConfiguration();
void checkDataConfiguration();
void logon();  

int main()
{
    try
    {
        checkSoundConfiguration(); 
        checkVideoConfiguration();
        checkNetworkConfiguration();
        checkDataConfiguration();
        logon();  
    }
    catch(int errorCode)
    {
        switch(errorCode)
        {
            case SOUND_CONFIG_ERROR:
                cout << "Sound config error." << endl;
                break;
            case VIDEO_CONFIG_ERROR:
                cout << "Video config error." << endl;
                break;
            case NETWORK_CONFIG_ERROR:
                cout << "Network config error." << endl;
                break;
            case DATA_CONFIG_ERROR:
                cout << "Data config error." << endl;
                break;
            case LOGON_ERROR:
                cout << "Logon error." << endl;
                break;
        }
    }
    return 0;
} 


void checkSoundConfiguration()
{
    if(/*Sound check*/ true)
    {
        throw SOUND_CONFIG_ERROR;
    }
}

void checkVideoConfiguration()
{
    if(/*Video check*/ true)
    {
        throw VIDEO_CONFIG_ERROR;
    }
}

void checkNetworkConfiguration()
{
    if(/*Network check*/ true)
    {
        throw NETWORK_CONFIG_ERROR;
    }
}

void checkDataConfiguration()
{
    if(/*Data check*/ true)
    {
        throw DATA_CONFIG_ERROR;
    }
}

void logon()
{
    if(/*Logon rejected*/ true)
    {
        throw LOGON_ERROR;
    }
}

