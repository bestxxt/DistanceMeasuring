#include <DistanceMeasure.h>

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
}


void ICACHE_RAM_ATTR ShellLoop(void)
{
    //命令解析器
     while (Serial.available()) shell_task();
    // while (Serial.available() || SerialBT.available()) shell_task();
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
    // if (SerialBT.available()) //蓝牙串口定义
    // {
    //     *data = SerialBT.read();
    //     return 1;
    // }
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
    // SerialBT.write(data);//蓝牙串口定义
}
