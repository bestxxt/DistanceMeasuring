#include <DistanceMeasure.h>

uint8_t BT_distance_output = false;
uint8_t Serial_distance_output = false; 
uint8_t Oled_distance_output = true; 

void Data_Printf(double data)
{
    if(BT_distance_output)SerialBT.println(data);
    if(Serial_distance_output)Serial.println(data);
    
}

void BT_output_no(void)
{
    BT_distance_output = true;
    BtOutput=true;
}

void BT_output_off(void)
{
    BT_distance_output = false;
    BtOutput=false;
}

void serial_output_on(void)
{
    AlarmOut = true;
}

void serial_output_off(void)
{
    AlarmOut = false;
}

void work_on(void)
{
    SetSound(Beep3);
    Work = true;
}

void work_off(void)
{
    SetSound(Beep4);
    Work = false;
}

int command_test(int argc, char** argv)
{
    int i;

    shell_println("-----------------------------------------------");
    shell_println("SHELL DEBUG / TEST UTILITY");
    shell_println("-----------------------------------------------");
    shell_println("");
    shell_printf("Received %d arguments for test command\r\n", argc);

    // Print each argument with string lenghts
    for (i = 0; i < argc; i++)
    {
        // Print formatted text to terminal
        shell_printf("%d - \"%s\" [len:%d]\r\n", i, argv[i], strlen(argv[i]));
    }

    return SHELL_RET_SUCCESS;
}

void shellInit(void)
{
    shell_init(shell_reader, shell_writer, 0);
    shell_register((shell_program_t) command_test, PSTR("test"));
    shell_register((shell_program_t) BT_output_no, PSTR("bt-on"));
    shell_register((shell_program_t) BT_output_off, PSTR("bt-off"));
    shell_register((shell_program_t) serial_output_on, PSTR("alarm-on"));
    shell_register((shell_program_t) serial_output_off, PSTR("alarm-off"));
    shell_register((shell_program_t) work_on, PSTR("sys-on"));
    shell_register((shell_program_t) work_off, PSTR("sys-off"));
    
}


void ICACHE_RAM_ATTR ShellLoop(void)
{
    //命令解析器
    //  while (Serial.available()) shell_task();
    while (Serial.available() || SerialBT.available()) shell_task();
}



/**
 * Function to read data from serial port
 * Functions to read from physical media should use this prototype:
 * int my_reader_function(char * data)
 */
int shell_reader(char* data)
{
    if (Serial.available())
    {
        *data = Serial.read();
        return 1;
    }
    if (SerialBT.available()) //蓝牙串口定义
    {
        *data = SerialBT.read();
        return 1;
    }
    return 0;
}



/**
 * Function to write data to serial port
 * Functions to write to physical media should use this prototype:
 * void my_writer_function(char data)
 */
void shell_writer(char data)
{
    //return; //阻止不干净的输出
    Serial.write(data);
    SerialBT.write(data);//蓝牙串口定义
}
