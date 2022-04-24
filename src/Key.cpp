#include <DistanceMeasure.h>


// KeyUP按下一次回调函数
static void KeyUP_Click() 
{
    SetSound(Beep1);
    AlarmOut=true;
}

//KeyUP按下两次回调函数
static void KeyUP_DoubleClick() 
{
    SetSound(Beep2);
    AlarmOut=false;
}

//KeyUP长按回调函数
static void KeyUP_LongPress() 
{   
    if(Work)
    {
        SetSound(Beep4);
        Work=false;
    }
    else
    {
        SetSound(Beep3);
        Work=true;
    }
    

}

// KeyDown按下一次回调函数
static void KeyDown_Click() 
{  
    
}

//KeyDown按下两次回调函数
static void KeyDown_DoubleClick() 
{
    
}

//KeyDown长按回调函数
static void KeyDown_LongPress() 
{

}

void Key_Init(void)
{
    KeyUP.setDebounceTicks(10);	//设置10ms内变化的信号忽略
    KeyUP.setClickTicks(300);//设置两次按下在400ms以内算双击
    KeyUP.setPressTicks(800);//设置按住1000ms算长按
    KeyUP.attachClick(KeyUP_Click);
    KeyUP.attachDoubleClick(KeyUP_DoubleClick);
    KeyUP.attachLongPressStart(KeyUP_LongPress);
    
    KeyDown.setDebounceTicks(10);	//设置10ms内变化的信号忽略
    KeyDown.setClickTicks(300);//设置两次按下在400ms以内算双击
    KeyDown.setPressTicks(800);//设置按住1000ms算长按
    KeyDown.attachClick(KeyDown_Click);
    KeyDown.attachDoubleClick(KeyDown_DoubleClick);
    KeyDown.attachLongPressStart(KeyDown_LongPress);
}


void KeyLoop(void)
{
    KeyUP.tick();
    KeyDown.tick();
}