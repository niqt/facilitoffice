#include "speak.h"
#include <festival.h>
#include <sstream>

Speak::Speak()
{
  int heap_size = 210000;  // default scheme heap size
  int load_init_files = 1; // we want the festival init files loaded
  festival_initialize(load_init_files, heap_size);
  festival_eval_command("(voice_pc_diphone)");
  
}

int Speak::setVoice(string voiceCommand)
{
  voiceCommand = "(" + voiceCommand + ")";
  EST_String *est_command = new EST_String(voiceCommand.c_str());
  int rc = festival_eval_command(reinterpret_cast<EST_String&>(*est_command));
  delete est_command;
  return rc;
}

void Speak::sayText(string text)
{
  EST_String *est_text = new EST_String(text.c_str());
  int rc = festival_say_text(reinterpret_cast<EST_String&>(*est_text));
  festival_wait_for_spooler();
  
  delete est_text;
  
}

void Speak::setSpeed(float speed)
{
  ostringstream s;
  s << speed;
  string command = "(Parameter.set 'Duration_Stretch " + s.str() + ")";
  

  EST_String *est_command = new EST_String(command.c_str());
  int rc = festival_eval_command(reinterpret_cast<EST_String&>(*est_command));
  delete est_command;
}

void Speak::init()
{
 /* int heap_size = 20000000;  // default scheme heap size
  int load_init_files = 1; // we want the festival init files loaded
  festival_initialize(load_init_files, heap_size);
  festival_eval_command("(voice_pc_diphone)");*/
}

