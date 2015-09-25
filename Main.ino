#include <IRremote.h>

const int IR_Receiver_Pin = 2;
const int Light_A_Pin = 3;
const int Light_B_Pin = 4;

IRrecv irrecv(IR_Receiver_Pin);
decode_results results;

const unsigned long Remote_Button_Number_1 = 3268051581; // SAMSUNG remote controller - button number 1
const unsigned long Remote_Button_Number_2 = 3268035261; // SAMSUNG remote controller - button number 2

int Remote_Button_Number_1_State = HIGH;
int Remote_Button_Number_2_State = HIGH;

void controlLights(decode_results results);

void setup(){
    pinMode(Light_A_Pin, OUTPUT);
    pinMode(Light_B_Pin, OUTPUT);

    digitalWrite(Light_A_Pin, Remote_Button_Number_1_State);
    digitalWrite(Light_B_Pin, Remote_Button_Number_2_State);

    irrecv.enableIRIn();
}

void loop(){
    if(irrecv.decode(&results)){
        controlLights(results);
        irrecv.resume();
    }

    delay(200);
}

void controlLights(decode_results results){
    switch(results.value){
        case Remote_Button_Number_1:
            Remote_Button_Number_1_State = !Remote_Button_Number_1_State;
            digitalWrite(Light_A_Pin, Remote_Button_Number_1_State);
        break;

        case Remote_Button_Number_2:
            Remote_Button_Number_2_State = !Remote_Button_Number_2_State;
            digitalWrite(Light_B_Pin, Remote_Button_Number_2_State);
        break;
    }
}
