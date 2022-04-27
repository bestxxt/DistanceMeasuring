#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdint.h>
#include <Shell.h>

extern uint8_t EasyCursor[10][2];
extern uint8_t OLED_ScreenshotFlag;

void shellInit(void);
void ShellLoop(void);
int shell_reader(char* data);
void shell_writer(char data);
void shell_SendDatas(uint8_t buf[], uint32_t size); 
int command_test(int argc, char** argv);
void Data_Printf(double data);

#endif