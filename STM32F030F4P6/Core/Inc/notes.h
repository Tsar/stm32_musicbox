#ifndef _NOTES_H_
#define _NOTES_H_

#include <note_frequency.h>

typedef struct {
  uint16_t frequency;  // Hz
  uint16_t duration;   // ms
} Note;

#define VOICE1_NOTES_COUNT 19

const Note voice1[] = {
    {MI_2, 100},
    {RE_D_2, 100},
    {MI_2, 100},
    {RE_D_2, 100},
    {MI_2, 100},
    {SI_1, 100},
    {RE_2, 100},
    {DO_2, 100},
    {LA_1, 200},
    {0, 100},
    {DO_1, 100},
    {MI_1, 100},
    {LA_1, 100},
    {SI_1, 200},
    {0, 100},
    {MI_1, 100},
    {SOL_D_1, 100},
    {SI_1, 100},
    {DO_2, 200},
};

#define VOICE2_NOTES_COUNT 12

const Note voice2[] = {
    {0, 800},
    {LA_0, 100},
    {MI_1, 100},
    {LA_1, 100},
    {0, 300},
    {MI_0, 100},
    {MI_1, 100},
    {SOL_D_1, 100},
    {0, 300},
    {LA_0, 100},
    {MI_1, 100},
    {LA_1, 100},
};

#endif /* _NOTES_H_ */
