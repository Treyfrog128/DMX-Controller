/*
  DMX_Master.ino - Example code for using the Conceptinetics DMX library
 Copyright (c) 2013 W.A. van der Meeren <danny@illogic.nl>.  All right reserved.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 3 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <Conceptinetics.h>


//
// CTC-DRA-13-1 ISOLATED DMX-RDM SHIELD JUMPER INSTRUCTIONS
//
// If you are using the above mentioned shield you should 
// place the RXEN jumper towards pin number 2, this allows the
// master controller to put to iso shield into transmit 
// (DMX Master) mode 
//
//
// The !EN Jumper should be either placed in the G (GROUND) 
// position to enable the shield circuitry 
//   OR
// if one of the pins is selected the selected pin should be
// set to OUTPUT mode and set to LOGIC LOW in order for the 
// shield to work
//


//
// The master will control 100 Channels (1-100)
// 
// depending on the ammount of memory you have free you can choose
// to enlarge or schrink the ammount of channels (minimum is 1)
//
#define DMX_MASTER_CHANNELS   100 

//
// Pin number to change read or write mode on the shield
//
#define RXEN_PIN                2


// Configure a DMX master controller, the master controller
// will use the RXEN_PIN to control its write operation 
// on the bus
DMX_Master        dmx_master ( DMX_MASTER_CHANNELS, RXEN_PIN );
const int buttonPinRed = 3;
const int buttonPinWhite = 5;
const int buttonPinBlue = 6;
const int buttonPinAmber = 9;
const int buttonPinGreen = 10;
const int buttonPinStrobe = 8;
const int buttonPinLazer = 7;
int buttonStateRed = 0;
int buttonStateWhite = 0;  
int buttonStateBlue = 0;  
int buttonStateAmber = 0;  
int buttonStateGreen = 0;  
int buttonStateStrobe = 0; 
int buttonStateLazer = 0; 
const int potPinStrobe = 0;
const int potPinMotor = 1;
int valStrobe = 0;
int valMotor = 0;
// the setup routine runs once when you press reset:
void setup() {             
  
  // Enable DMX master interface and start transmitting
  dmx_master.enable ();  
  pinMode(buttonPinRed, INPUT); 
  pinMode(buttonPinWhite, INPUT); 
  pinMode(buttonPinBlue, INPUT); 
  pinMode(buttonPinAmber, INPUT); 
  pinMode(buttonPinGreen, INPUT); 
  pinMode(buttonPinStrobe, INPUT); 
  pinMode(buttonPinLazer, INPUT);
  dmx_master.setChannelRange ( 1, 10, 0 );
  dmx_master.setChannelValue ( 1, 225);  
  dmx_master.setChannelValue ( 7, 255);
  dmx_master.setChannelValue ( 9, 200);
}

// the loop routine runs over and over again forever:
void loop() 
{
  if (digitalRead(buttonPinStrobe) == HIGH) {
     buttonStateStrobe = 1;
  }
  else {
    buttonStateStrobe = 0;
  }
  if (digitalRead(buttonPinLazer) == HIGH) {
     buttonStateLazer = 1;
  }
  else {
    buttonStateLazer = 0;
  }
  if (digitalRead(buttonPinRed) == HIGH) {
     buttonStateRed = 1;
  }
  else {
    buttonStateRed = 0;
  }
  if (digitalRead(buttonPinWhite) == HIGH) {
     buttonStateWhite = 1;
  }
  else {
    buttonStateWhite = 0;
  }
  if (digitalRead(buttonPinBlue) == HIGH) {
     buttonStateBlue = 1;
  }
  else {
    buttonStateBlue = 0;
  }
  if (digitalRead(buttonPinAmber) == HIGH) {
     buttonStateAmber = 1;
  }
  else {
    buttonStateAmber = 0;
  }
  if (digitalRead(buttonPinGreen) == HIGH) {
     buttonStateGreen = 1;
  }
  else {
    buttonStateGreen = 0;
  }
  if (buttonStateRed == 1 && buttonStateGreen == 1 && buttonStateBlue == 1 && buttonStateAmber == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 164);
  }
  else if(buttonStateRed == 1 && buttonStateBlue == 1 && buttonStateAmber == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 159);
  }
  else if(buttonStateRed == 1 && buttonStateGreen == 1 && buttonStateAmber == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 154);
  }
  else if(buttonStateGreen == 1 && buttonStateBlue == 1 && buttonStateAmber == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 149);
  }
  else if(buttonStateRed == 1 && buttonStateGreen == 1 && buttonStateBlue == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 144);
  }
  else if(buttonStateRed == 1 && buttonStateGreen == 1 && buttonStateBlue == 1 && buttonStateAmber == 1) {
    dmx_master.setChannelValue (2, 139);
  }
  else if(buttonStateAmber == 1 && buttonStateWhite == 1 && buttonStateBlue == 1) {
    dmx_master.setChannelValue (2, 134);
  }
  else if(buttonStateAmber == 1 && buttonStateGreen == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 129);
  }
  else if(buttonStateBlue == 1 && buttonStateGreen == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 124);
  }
  else if(buttonStateAmber == 1 && buttonStateGreen == 1 && buttonStateBlue == 1) {
    dmx_master.setChannelValue (2, 119);
  }
  else if(buttonStateRed == 1 && buttonStateAmber == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 114);
  }
  else if(buttonStateRed == 1 && buttonStateBlue == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 109);
  }
  else if(buttonStateRed == 1 && buttonStateBlue == 1 && buttonStateAmber == 1) {
    dmx_master.setChannelValue (2, 104);
  }
  else if(buttonStateRed == 1 && buttonStateGreen == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 99);
  }
  else if(buttonStateRed == 1 && buttonStateGreen == 1 && buttonStateAmber == 1) {
    dmx_master.setChannelValue (2, 94);
  }
  else if(buttonStateRed == 1 && buttonStateGreen == 1 && buttonStateBlue == 1) {
    dmx_master.setChannelValue (2, 89);
  }
  else if(buttonStateWhite == 1 && buttonStateBlue == 1) {
    dmx_master.setChannelValue (2, 84);
  }
  else if(buttonStateRed == 1 && buttonStateBlue == 1) {
    dmx_master.setChannelValue (2, 79);
  }
  else if(buttonStateRed == 1 && buttonStateAmber == 1) {
    dmx_master.setChannelValue (2, 74);
  }
  else if(buttonStateGreen == 1 && buttonStateAmber == 1) {
    dmx_master.setChannelValue (2, 69);
  }
  else if(buttonStateGreen == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 64);
  }
  else if(buttonStateAmber == 1 && buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 59);
  }
  else if(buttonStateAmber == 1 && buttonStateBlue == 1) {
    dmx_master.setChannelValue (2, 54);
  }
  else if(buttonStateGreen == 1 && buttonStateBlue == 1) {
    dmx_master.setChannelValue (2, 49);
  }
  else if(buttonStateGreen == 1 && buttonStateRed == 1) {
    dmx_master.setChannelValue (2, 44);
  }
  else if(buttonStateWhite == 1 && buttonStateRed == 1) {
    dmx_master.setChannelValue (2, 39);
  }
  else if(buttonStateWhite == 1) {
    dmx_master.setChannelValue (2, 34);
  }
  else if(buttonStateAmber == 1) {
    dmx_master.setChannelValue (2, 29);
  }
  else if(buttonStateBlue == 1) {
    dmx_master.setChannelValue (2, 24);
  }
  else if(buttonStateGreen == 1) {
    dmx_master.setChannelValue (2, 19);
  }
  else if(buttonStateRed == 1) {
    dmx_master.setChannelValue (2, 14);
  }
  else {
    dmx_master.setChannelValue (2, 9);
  }
  valStrobe = analogRead(potPinStrobe);
  if (valStrobe == 1023) {
    dmx_master.setChannelValue (4, 4);
  }
  else {
    valStrobe = map(valStrobe, 0, 1023, 5, 254);
    dmx_master.setChannelValue (4, valStrobe);
  }
  valMotor = analogRead(A1);
  if (0 <= valMotor && valMotor < 250) {
    valMotor = 255;
  }
  else if (250 <= valMotor && valMotor <= 512) {
    valMotor = map(valMotor, 512, 250, 252, 255);
  }
  else if (512 <= valMotor && valMotor <=800) {
    valMotor = map(valMotor, 513, 800, 124, 127);
  }
  else {
    valMotor = 127;
  }
  dmx_master.setChannelValue (8, valMotor);
  if (buttonStateStrobe == 1) {
    dmx_master.setChannelValue (5, 255);
  }
  else {
    dmx_master.setChannelValue (5, 0);
  }
  if (buttonStateLazer == 1) {
    dmx_master.setChannelValue (6, 130);
  }
  else {
    dmx_master.setChannelValue (6, 0);
  }
  // Keep dmfading channel 1 in from 0 to 100%

}

