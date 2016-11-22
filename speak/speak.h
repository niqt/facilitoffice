#ifndef _SPEAK_HEADER
#define _SPEAK_HEADER

#include<string>

using namespace std;

class Speak
{
  public:
    Speak();
    int setVoice(string voiceCommand);
    void sayText(string text);
    void setSpeed(float speed);
    void init();
    ~Speak() {;}
};



#endif
