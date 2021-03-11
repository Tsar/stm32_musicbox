#ifndef _MUSICBOX_HPP_
#define _MUSICBOX_HPP_

#include <main.h>

#ifdef __cplusplus
extern "C" {
#endif

void startMusic(
    TIM_HandleTypeDef* timer1,
    int timer1Channel,
    TIM_HandleTypeDef* timer2,
    int timer2Channel
);

#ifdef __cplusplus
}
#endif

#endif /* _MUSICBOX_HPP_ */
