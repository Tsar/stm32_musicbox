#ifndef _MUSICBOX_H_
#define _MUSICBOX_H_

#include <main.h>

void startMusic(
    TIM_HandleTypeDef* timer1,
    int timer1Channel,
    TIM_HandleTypeDef* timer2,
    int timer2Channel
);

#endif /* _MUSICBOX_H_ */
