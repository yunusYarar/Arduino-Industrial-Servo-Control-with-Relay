#include <avr/interrupt.h>
#include <avr/sleep.h>
 #include <EEPROM.h>

const int SleepButton = 2;     // the number of the pushbutton pin
const int NamazButton =  3;      // the number of the LED pin
const short int input1=A2;
const short int input2=A3;
const short int input3=A4;
const short int input4=A5;
const short int input5=A1;
const short int input6=A0;

const short int Output1=4;
const short int Output2=5;
const short int Output3=6;
const short int Output4=7;
const short int Output5=8;
const short int Output6=9;

int Buton_Tarama=0,Buton_Sayac=10,i=0,Sleep=0,Namaz = 0,Position_1=0,Position_2=0,Position_3=0,POZISYON_OK=0,Run=0;
int Sleep_Tarama=0,Sleep_Sayac=50,Sleep_On_Timer=500,Sleep_Mode_On=0,posisyon_Tamam=0,A=0;
int Value=0,LOCK=0,addr = 0; //başlangıç adresi
int Buton_Tarama1=0,Buton_Sayac1=10;
int Buton_Tarama2=0,Buton_Sayac2=10;
int Buton_Tarama3=0,Buton_Sayac3=10;
int Buton_Tarama4=0,Buton_Sayac4=10;
int Buton_Tarama5=0,Buton_Sayac5=10;
char Blink=0xFF,Blink_time=50,Blink_On=0;

//void wakeUpNow()        // here the interrupt is handled after wakeup
//{
//  //execute code here after wake-up before returning to the loop() function
//  // timers and code using timers (serial.print and more...) will not work here.
//  //digitalWrite(interruptPin, HIGH);
//     digitalWrite(8,LOW); 
//     digitalWrite(9,LOW); 
//     digitalWrite(10,LOW); 
//     digitalWrite(11,LOW); 
//     digitalWrite(12,LOW);
//     sleepNow();
//}


//
//void sleepNow()         // here we put the arduino to sleep
//{
//    delay(100); 
//    digitalWrite (13, HIGH);
//    /*
//     * The 5 different modes are:
//     *     SLEEP_MODE_IDLE         -the least power savings 
//     *     SLEEP_MODE_ADC
//     *     SLEEP_MODE_PWR_SAVE
//     *     SLEEP_MODE_STANDBY
//     *     SLEEP_MODE_PWR_DOWN     -the most power savings
//     *
//     * For now, we want as much power savings as possible, 
//     * so we choose the according sleep modus: SLEEP_MODE_PWR_DOWN
//     * 
//     */ 
//    attachInterrupt(0,wakeUpNow, LOW);
//    sei();
//    set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here
//
//    sleep_enable();              // enables the sleep bit in the mcucr register
//                                 // so sleep is possible. just a safety pin 
//                                 // use interrupt 0 (pin 2) and run function
////                               // wakeUpNow when pin 2 gets LOW 
////
//   
//    sleep_mode();                // here the device is actually put to sleep!!
////                               // 
//
//    sleep_disable();             // first thing after waking from sleep:
//                                 // disable sleep...
//    //detachInterrupt(0);        // disables interrupt 0 on pin 2 so the 
//                                 // wakeUpNow code will not be executed 
//                                 // during normal running time.
//    delay(100);                  // wat 2 sec. so humans can notice the
//                                 // interrupt. 
//                                 // LED to show the interrupt is handled
//    digitalWrite (13, LOW);      // turn off the interrupt LED
//}
//
//


// the setup function runs once when you press reset or power the board
void setup() {
    //kaynak adresten veriyi oku
  Value = EEPROM.read(addr);
  if(Value==0xFF)  Value=0;
  //val değerini addr değerinden itibaren yazar.
  EEPROM.write(addr, Value);
   
      pinMode(SleepButton, INPUT);
        pinMode(NamazButton, INPUT);
          pinMode(input1, INPUT);
            pinMode(input2, INPUT);
              pinMode(input3, INPUT);
                pinMode(input4, INPUT);
                  pinMode(input5, INPUT);
                    pinMode(input6, INPUT);
  // initialize digital pin 13 as an output.
  pinMode(Output1, OUTPUT);
    pinMode(Output2, OUTPUT);
      pinMode(Output3, OUTPUT);
        pinMode(Output4, OUTPUT);
          pinMode(Output5, OUTPUT);
            pinMode(Output6, OUTPUT);
  /* Now is time to enable a interrupt. In the function call 
   * attachInterrupt(A, B, C)
   * A   can be either 0 or 1 for interrupts on pin 2 or 3.   
   * 
   * B   Name of a function you want to execute while in interrupt A.
   *
   * C   Trigger mode of the interrupt pin. can be:
   *             LOW        a low level trigger
   *             CHANGE     a change in level trigger
   *             RISING     a rising edge of a level trigger
   *             FALLING    a falling edge of a level trigger
   *
   * In all but the IDLE sleep modes only LOW can be used.
   */

//  attachInterrupt(0, wakeUpNow, LOW); // use interrupt 0 (pin 2) and run function
                                      // wakeUpNow when pin 2 gets LOW           
}


// the loop function runs over and over again forever
void loop() {
  
  delay(10);  i++;
  if(Blink_On)
  {
      if(i%Blink_time) Blink=~Blink;
  }
  
  Run = !digitalRead(input1);
  Position_1 = !digitalRead(input2);
  Position_2 = !digitalRead(input3);
  Position_3 = !digitalRead(input1); 
  POZISYON_OK = !digitalRead(input6);

  
//  if (Run == HIGH)
//  {
//       // if(Buton_Tarama>=1)  i=0;    /////// Work Cathing ///////
//        if(++Buton_Tarama1>=Buton_Sayac1) 
//        {  
//           if(LOCK==0) Value=1;
//        }
//  }  
//  else Buton_Tarama1=0;
//  
  if (Position_1 == HIGH)
  {
       // if(Buton_Tarama>=1)  i=0;    /////// Work Cathing ///////
        if(++Buton_Tarama2>=Buton_Sayac2) 
        {  
           if(LOCK==0) Value=1;
        }
  }  
  else Buton_Tarama2=0;
  
  if (Position_2 == HIGH)
  {
       // if(Buton_Tarama>=1)  i=0;    /////// Work Cathing ///////
        if(++Buton_Tarama3>=Buton_Sayac3) 
        {  
          if(LOCK==0) Value=2;
        }
  }  
  else Buton_Tarama3=0;
  
  if (Position_3 == HIGH)
  {
       // if(Buton_Tarama>=1)  i=0;    /////// Work Cathing ///////
       //  Buton_Tarama3=0;  Buton_Tarama2=0; // 1 ve 2 butonunu okumasını engellemek icin
         
        if(++Buton_Tarama4>=Buton_Sayac4) 
        {  
          if(LOCK==0) Value=3;
        }
  }  
  else Buton_Tarama4=0;
  
  if (POZISYON_OK == HIGH)
  {
       // if(Buton_Tarama>=1)  i=0;    /////// Work Cathing ///////
        if(++Buton_Tarama5>=Buton_Sayac5) 
        {  
          posisyon_Tamam=1;
        }
  }  
  else Buton_Tarama5=0;
  
//  if(Buton_Tarama>=50) Value=0;
   
//  if (i >= Sleep_On_Timer)
//  {            // start to put the device in sleep
//       i=0;
//       digitalWrite(8,LOW); 
//       digitalWrite(9,LOW); 
//       digitalWrite(10,LOW); 
//       digitalWrite(11,LOW); 
//       digitalWrite(12,LOW); 
//      // sleepNow();                      // sleep function called here
//}
     switch(Value){
     
     case 1: 
             if(LOCK==0)
             {
                 LOCK=1;
                 Buton_Tarama5=0;
                 posisyon_Tamam=0;
                 digitalWrite(Output3,HIGH); // Servo pozisyon1 output
                 digitalWrite(Output1,HIGH); // Servo run output
                 delay(100);
             }
             if((posisyon_Tamam==1) && (A==0)) // pos tamam komutu al
             {
                 Buton_Tarama5=0;
                 posisyon_Tamam=0;
                 digitalWrite(13,HIGH);
                 delay(50);
                 digitalWrite(Output3,LOW); // Servo pozisyon1 output
                 digitalWrite(Output1,LOW); // Servo run output
                 delay(50);                 
                // LOCK=0;
                 //Value=0;
                 delay(100);
                 digitalWrite(Output1,HIGH); // Servo run output
                 delay(10);
                 A=1;
             }
             if((posisyon_Tamam==1) && (A==1)) // pos tamam komutu al
             {
                 Buton_Tarama5=0;
                 digitalWrite(13,LOW);
                 posisyon_Tamam=0;
                 LOCK=0;
                 Value=0;
                 A=0;
             } 
     break;
 
     case 2: 
             if(LOCK==0)
             {
                 LOCK=1;
                 Buton_Tarama5=0;
                 posisyon_Tamam=0;
                 digitalWrite(Output4,HIGH); // Servo pozisyon1 output
                 digitalWrite(Output1,HIGH); // Servo run output
                 delay(100);
             }
             if((posisyon_Tamam==1) && (A==0)) // pos tamam komutu al
             {
                 Buton_Tarama5=0;
                 posisyon_Tamam=0;
                 digitalWrite(13,HIGH);
                 delay(50);
                 digitalWrite(Output4,LOW); // Servo pozisyon1 output
                 digitalWrite(Output1,LOW); // Servo run output
                 delay(50);                 
                // LOCK=0;
                 //Value=0;
                 delay(100);
                 digitalWrite(Output1,HIGH); // Servo run output
                 delay(10);
                 A=1;
             }
             if((posisyon_Tamam==1) && (A==1)) // pos tamam komutu al
             {
                 Buton_Tarama5=0;
                 digitalWrite(13,LOW);
                 posisyon_Tamam=0;
                 LOCK=0;
                 Value=0;
                 A=0;
             } 
     break;
     
     case 3:
             if(LOCK==0)
             {
                 LOCK=1;
                 Buton_Tarama5=0;
                 posisyon_Tamam=0;
                 digitalWrite(Output3,HIGH); // Servo pozisyon1 output
                 digitalWrite(Output4,HIGH); // Servo pozisyon1 output
                 digitalWrite(Output1,HIGH); // Servo run output
                 delay(100);
             }
             if((posisyon_Tamam==1) && (A==0)) // pos tamam komutu al
             {
                 Buton_Tarama5=0;
                 posisyon_Tamam=0;
                 digitalWrite(13,HIGH);
                 delay(50);
                 digitalWrite(Output3,LOW); // Servo pozisyon1 output
                 digitalWrite(Output4,LOW); // Servo pozisyon1 output                 
                 digitalWrite(Output1,LOW); // Servo run output
                 delay(50);                 
                // LOCK=0;
                 //Value=0;
                 delay(100);
                 digitalWrite(Output1,HIGH); // Servo run output
                 delay(10);
                 A=1;
             }
             if((posisyon_Tamam==1) && (A==1)) // pos tamam komutu al
             {
                 Buton_Tarama5=0;
                 digitalWrite(13,LOW);
                 posisyon_Tamam=0;
                 LOCK=0;
                 Value=0;
                 A=0;
             } 
     break;
     
     default:
     digitalWrite(Output1,LOW);
     digitalWrite(Output2,LOW);
     digitalWrite(Output3,LOW);
     digitalWrite(Output4,LOW);
     digitalWrite(Output5,LOW);
     digitalWrite(Output6,LOW);                    
       Value=0;
     break;
     }
     
}
  

