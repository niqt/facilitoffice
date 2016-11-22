#include "speak.h"
#include <iostream>

int main()
{
    Speak speak;
	speak.init();
    cout << "Test Speak: Ciao Nicola\n";
    speak.sayText("Ciao Nicola");
    cout << "Test Speak: set voice result " << speak.setVoice("voice_lp_diphone") << "\n";
    speak.sayText("Ciao Nicola");
    return 0;
}
