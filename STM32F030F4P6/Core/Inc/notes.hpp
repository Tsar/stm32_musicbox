#ifndef _NOTES_HPP_
#define _NOTES_HPP_

#include <note_frequency.hpp>

#pragma pack(push, 1)

struct Note {
  uint16_t frequency;  // Hz
  uint16_t duration;   // ms
};

#pragma pack(pop)

const Note voice1[] = {
    {MI_2, 250},
    {RE_D_2, 250},
    {MI_2, 250},
    {RE_D_2, 250},
    {MI_2, 250},
    {SI_1, 250},
    {RE_2, 250},
    {DO_2, 250},
    {LA_1, 500},
    {0, 250},
    {DO_1, 250},
    {MI_1, 250},
    {LA_1, 250},
    {SI_1, 500},
    {0, 250},
    {MI_1, 250},
    {SOL_D_1, 250},
    {SI_1, 250},
    {DO_2, 500},
    {0, 250},

    {MI_1, 250},
    {MI_2, 250},
    {RE_D_2, 250},
    {MI_2, 250},
    {RE_D_2, 250},
    {MI_2, 250},
    {SI_1, 250},
    {RE_2, 250},
    {DO_2, 250},
    {LA_1, 500},
    {0, 250},
    {DO_1, 250},
    {MI_1, 250},
    {LA_1, 250},
    {SI_1, 500},
    {0, 250},
    {MI_1, 250},
    {DO_2, 250},
    {SI_1, 250},
    {LA_1, 1000},
};

const Note voice2[] = {
    {0, 2000},
    {LA_0, 250},
    {MI_1, 250},
    {LA_1, 250},
    {0, 750},
    {MI_0, 250},
    {MI_1, 250},
    {SOL_D_1, 250},
    {0, 750},
    {LA_0, 250},
    {MI_1, 250},
    {LA_1, 250},

    {0, 2250},
    {LA_0, 250},
    {MI_1, 250},
    {LA_1, 250},
    {0, 750},
    {MI_0, 250},
    {MI_1, 250},
    {SOL_D_1, 250},
    {0, 750},
    {LA_0, 250},
    {MI_1, 250},
    {LA_1, 250},
};

#define VOICE1_NOTES_COUNT static_cast<int>(sizeof(voice1) / sizeof(Note))
#define VOICE2_NOTES_COUNT static_cast<int>(sizeof(voice2) / sizeof(Note))

#endif /* _NOTES_HPP_ */
