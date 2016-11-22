#ifndef TYPES_H
#define TYPES_H

#include <QRgb>



enum {STOP};

//! Configuration parameter

typedef struct configuration
{
    QString voice;
    int volume;
    int speed;
    int wait;
    bool evidence;
    bool showEvidence;
    int evidenceType; // c for Color; b for background; u forn underline;
    bool readText;
    bool evidenceRow;
    bool shortcuts;
    bool copybooks;
    QRgb color;

}Configurations;


typedef struct messagge_s
{
    int msgId;
    char text[1024];
} Msg;

typedef struct message_s_q
{
    long type;
    Msg msg;
} MsgQueue;

#endif // TYPES_H
