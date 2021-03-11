#include <musicbox.hpp>

#include <algorithm>

#include <notes.hpp>

void processSpeaker(TIM_HandleTypeDef* timer, int timerChannel, const Note* notes, int notesCount, int& noteNum, uint16_t& noteTimeLeft, uint8_t& speakerState) {
  if (noteNum < notesCount && noteTimeLeft == 0) {
    ++noteNum;
    if (noteNum == notesCount) {
      HAL_TIM_PWM_Stop(timer, timerChannel);
      speakerState = 0;
    } else {
      if (notes[noteNum].frequency > 0) {
        timer->Init.Period = 1000000 / notes[noteNum].frequency;
        timer->Instance->CCR2 = timer->Init.Period >> 1;
        HAL_TIM_PWM_Init(timer);
        if (!speakerState) {
          HAL_TIM_PWM_Start(timer, timerChannel);
          speakerState = 1;
        }
      } else {
        if (speakerState) {
          HAL_TIM_PWM_Stop(timer, timerChannel);
          speakerState = 0;
        }
      }
      noteTimeLeft = notes[noteNum].duration;
    }
  }
}

void startMusic(
    TIM_HandleTypeDef* timer1,
    int timer1Channel,
    TIM_HandleTypeDef* timer2,
    int timer2Channel
) {
  uint8_t speaker1State = 0;
  uint8_t speaker2State = 0;
  int speaker1NoteNum = -1;
  int speaker2NoteNum = -1;
  uint16_t speaker1NoteTimeLeft = 0;
  uint16_t speaker2NoteTimeLeft = 0;

  while (speaker1NoteNum < VOICE1_NOTES_COUNT || speaker2NoteNum < VOICE2_NOTES_COUNT) {
    processSpeaker(timer1, timer1Channel, voice1, VOICE1_NOTES_COUNT, speaker1NoteNum, speaker1NoteTimeLeft, speaker1State);
    processSpeaker(timer2, timer2Channel, voice2, VOICE2_NOTES_COUNT, speaker2NoteNum, speaker2NoteTimeLeft, speaker2State);

    uint16_t delay;
    if (speaker1NoteNum < VOICE1_NOTES_COUNT && speaker2NoteNum < VOICE2_NOTES_COUNT) {
      delay = std::min(speaker1NoteTimeLeft, speaker2NoteTimeLeft);
    } else {
      delay = (speaker1NoteNum < VOICE1_NOTES_COUNT) ? speaker1NoteTimeLeft : speaker2NoteTimeLeft;
    }

    HAL_Delay(delay);
    speaker1NoteTimeLeft -= delay;
    speaker2NoteTimeLeft -= delay;
  }
}
