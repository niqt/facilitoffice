

#include "speak.h"
#include "types.h"

#include <iostream>

#include <sys/types.h>

#include <sys/ipc.h>

#include <sys/msg.h>

#include <fcntl.h>
#include <mqueue.h>

#include <stdio.h>


using namespace std;

int main(int argc, char *argv[])
{
  	
  struct mq_attr wanted_attrs, actual_attrs;
   
  Msg msg;
  int msgqid, msgqidSender;
  int result;
  unsigned int sender;
  Speak speak;
          
  /* filling the attribute structure */
  wanted_attrs.mq_flags = 0;                    /* no exceptional behavior (just O_NONBLOCK currently available)  */
  wanted_attrs.mq_maxmsg = 100;                 /* room for at most 100 messages in the queue */
  wanted_attrs.mq_msgsize = sizeof(Msg);      /* maximum size of a message */
  wanted_attrs.mq_curmsgs = 123;                /* this (current number of messages) will be ignored */


  // Init audio sinthesis

  speak.init();
  

  // remove queues if exist

  mq_unlink("/speakqu");
  mq_unlink("/sender");


  // Create queue
	
  if((msgqid = mq_open("/speakqu", O_RDWR | O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, wanted_attrs)) != -1 && 
  (msgqidSender = mq_open("/sender", O_RDWR | O_CREAT | O_EXCL, S_IRWXU | S_IRWXG, wanted_attrs)) != -1 )
  {
    int err;
    mq_attr attr;
    mq_getattr(msgqid,&attr);

    while(1)
    {
      if((err = mq_receive(msgqid, (char *)&msg, attr.mq_msgsize, &sender)) == -1)
	perror("Receive: ") ;
      else
      {
	cout << "msg = " << msg.msgId << " testo " << msg.text << "\n";

  	string t(msg.text);    
	speak.sayText(t);
	cout << "HO PARLATO\n";
	
	if(msg.msgId != -1)
	{
	  // send msg code have read

	  mq_send(msgqidSender, (char *) &msg, sizeof(Msg), NULL);
	}
      
      }
    }
  }
  else
    perror("Creation: ") ;
  
  mq_close(msgqid);
  mq_close(msgqidSender);

  return 0;
}

