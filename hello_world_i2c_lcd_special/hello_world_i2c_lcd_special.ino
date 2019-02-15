#include <Wire.h> 
//#include <SoftWire.h>  
//#include <AsyncDelay.h>
//#include <SoftwareWire.h> //This case, this works
//SoftwareWire Wire(A4,A5); //no need declare

#include <LiquidCrystal_I2C.h> //original, multiple: original, New, SR.
//#include <LiquidCrystal_PCF8574.h> //alternative mathertel
//#include <LiquidCrystal_I2C_SoftWire.h> //JOELwindows7 edit for SoftWire
//#include <LiquidCrystal_I2C_SoftwareWire.h> //JOELwindows7 edit for SoftwareWire //This case, this works

/*  http://bit.ly/DuinoLCDi2cPerkedel
 *   GNU GPL v3
 *   various libraries and copy from examples from library applied
 *   Video Demo: https://www.youtube.com/watch?v=f47Uz1C97Uw ; https://www.cocoscope.com/watch?v=12095
 *   Google Photo https://photos.app.goo.gl/UyCcSdYZttxR5bMNA
 *   
 *   https://www.arduino.cc/en/Reference/Wire
 *   Unit = Arduino Pin (Connect to)
 *  Uno, Ethernet = A4 (SDA), A5 (SCL)
    Mega2560 = 20 (SDA), 21 (SCL)
    Leonardo = 2 (SDA), 3 (SCL)
    Due = 20 (SDA), 21 (SCL), SDA1, SCL1

    All = 5V (VCC), GND (GND)

    http://forum.arduino.cc/index.php?topic=19002.0

    https://synapse.kyoto/lib/KanaLiquidCrystal/page001.html
    https://synapse.kyoto/lib/MGLCD/CharacterCode/page001.html

    https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

    buy i2c pack for LCD : https://shopee.co.id/simpleh.id/651372108

    LCD Character Creator:
    https://maxpromer.github.io/LCD-Character-Creator/
    https://omerk.github.io/lcdchargen/

    google translate! https://translate.google.com

    other refferencing:
    https://github.com/mathertel/LiquidCrystal_PCF8574
    https://forum.arduino.cc/index.php?topic=407904.0

    https://forum.arduino.cc/index.php?topic=448155.0 The Software Wire I2C discussion; BitBang includes

    https://www.arduino.cc/en/tutorial/memory RAM is running out cause trouble!
    https://www.arduino.cc/reference/en/language/variables/utilities/progmem/ PROGMEM things
    https://learn.adafruit.com/memories-of-an-arduino/optimizing-sram adafruit tips of memory
 */

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_I2C_SoftWire lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display 
//LiquidCrystal_I2C_SoftwareWire lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display //This case, this works
//LiquidCrystal_I2C lcd(0x27);
//LiquidCrystal_PCF8574 lcd(0x27);

byte PerkedelLogo[] = {
  B00000,
  B01110,
  B10001,
  B10101,
  B11111,
  B10101,
  B10001,
  B01110
};

byte SpeakerIcon[] = {
  B00001,
  B00011,
  B00101,
  B11001,
  B11001,
  B00101,
  B00011,
  B00001
};

byte SpeakerDeflate[] = {
  B00000,
  B00010,
  B00110,
  B11010,
  B11010,
  B00110,
  B00010,
  B00000
};

byte SpeakerPress[] = {
  B00000,
  B00000,
  B00100,
  B11100,
  B11100,
  B00100,
  B00000,
  B00000
};

byte TurnDown[] = {
  B00000,
  B11100,
  B00100,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100
};

byte Empty[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte Sadd[8] = {
  0b01110,
  0b10001,
  0b11011,
  0b10001,
  0b10101,
  0b11011,
  0b10001,
  0b01110
};

byte Happ[8] = {
  0b01110,
  0b10001,
  0b11011,
  0b10001,
  0b11011,
  0b10101,
  0b10001,
  0b01110
};

byte Osurprise[8] = {
  0b01110,
  0b10001,
  0b11011,
  0b11011,
  0b10001,
  0b10101,
  0b10001,
  0b01110
};

byte LineMouthFace[8] = {
  0b01110,
  0b10001,
  0b11011,
  0b11011,
  0b10001,
  0b11111,
  0b10001,
  0b01110
};

byte ExclamBox[8] = {
  0b11111,
  0b10001,
  0b10101,
  0b10101,
  0b10001,
  0b10101,
  0b10001,
  0b11111
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(56700); //No matter what, the Arduino crashes always.
  Serial.println(F("OK"));
  lcd.init();
  lcd.begin(16,2);
  lcd.createChar(1,PerkedelLogo);
  lcd.createChar(2,Sadd);
  lcd.createChar(3,ExclamBox);
  lcd.createChar(4,Happ);
  lcd.createChar(5,Osurprise);
  lcd.createChar(6,LineMouthFace);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Cool and good");
  lcd.setCursor(0,1);
  lcd.print("Perkedel Tech");
}

uint8_t choicer = 0;
const uint8_t chamber = 31;

//String Liner[10][2] = {{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""}}; //Empty Templater already exist
//char Liner[10][2][] PROGMEM = {{"",""}}; //we must branch this old version to move the different way where initializer is shorter, not too long!
//const String Liner[chamber][2] PROGMEM = {}; initalizer cannot be too long!
const char Liner[chamber][2][50] PROGMEM = {
  {"Cool and Good","\x01 Perkedel Tech"},
  {"Hello World","Halo Dunia"},
  {"Hatsune \xd0\xb9","Leekspinner"},
  {"I SQUARED C PC","C++ Arduino"},
  {"\xa2\xb1\xd9\xc4\xde\xb3\xa8\xb0\xc9\xa3","SPECIAL \xb5\xc7\xb9\xa1"},
  
  {"\x7e DUPER_AWESOME\x7f","\xff{DIV BY ZERO} \xff"},
  {"1234567890ABCDEF","!@#$%^&*()abcdef"},
  {"SELF ESTEEM vINF","Rp100rb /\x5c 100rb"},
  {"OpenCX","VanElektronische"},
  {"\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff",""}, //empty is intended for templating. leave it for future project! wait, he's already exist above!
  
  {"ASCII Table data","with NIHONGO"}, 
  {"Only support:","\xb6\xc7\xb6\xc5 & LATIN ..."},
  {"Also has:","GREEK,SIGN,ETC."},
  {"SUPER SIMPLE","4 PIN ONLY!!!"},
  {"GND          SDA","VCC          SCL"},
  
  {"GND \x7f--- - POWER","VCC \x7f--- + 5VOLT"},
  {"DATA    ---\x7e SDA","CLOCK   ---\x7e SCL"},
  {"\x04 MOCKUP  TIME \x02","\x05 FAKE  SCREEN \x06"},
  {"TravolP - Inochi","MIDI|120MB|XG++"},
  {"\x7ePlay          \x7f"," Options        "},
  
  {"TravolP - Inochi","Cm| PerkedelEdit"},
  {"TravolP - Inochi","1:00 ------ 4:45"},
  {"USB: TUPAI(2TB)","26GB ------ 20TB"},
  {"Do Re Mi Fa","1 2 3 4"},
  {"C      A   Cm","LyricLyric Lyrrx"},
  
  {"TravolP - Inochi","567 S.Art! H. \xd0\xb9"},
  {"\x04 MOCKUP  END! \x02","\x05 FUTURE DREAM \x06"},
  {"by JOELwindows7","\x01 Perkedel Tech"},
  {"GNU GPL v3","FREE-OPEN-FULL"},
  {"linktr.ee/","joelwindows7"},
  
  {"\x03  Last Found  \x03","\x02  Game  Over  \x02"},
  
  };

//char buffering[2][16];
char buffer;
String buffString;

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  //strcpy_P(buffer[0], (char*)pgm_read_word(&(Liner[choicer][0])));
  //strcpy_P(buffer[1], (char*)pgm_read_word(&(Liner[choicer][1])));
  
  lcd.setCursor(0,0); 
  Serial.print(F("O================O\n|"));
  for(uint8_t i = 0; i < strlen_P(Liner[choicer][0]);i++){
    //buffer= Liner[choicer][0][i];
    buffer= (char)pgm_read_word(&(Liner[choicer][0][i]));
    //strcpy_P(buffer, (char*)pgm_read_word(&(Liner[choicer][0][i])));
    Serial.print(buffer);
    buffString+=buffer;
  } lcd.print(buffString); buffString = "";
  lcd.setCursor(0,1);
  Serial.print(F("|\n|"));
  for(uint8_t i = 0; i < strlen_P(Liner[choicer][1]);i++){ //strlen_P(Liner[choicer][1]
    //buffer= Liner[choicer][1][i];
    buffer= (char)pgm_read_word(&(Liner[choicer][1][i]));
    //strcpy_P(buffer, (char*)pgm_read_word(&(Liner[choicer][1][i])));
    Serial.print(buffer);
    buffString+=buffer;
  } lcd.print(buffString); buffString = "";
  Serial.print(F("|\nO================O\n\n"));  //winner
  
  /*for(uint8_t i = 0; i > 16;i++){
    buffer= pgm_read_word_near(Liner[choicer][0]+i);
    lcd.setCursor(0,0); lcd.print(buffer);
  }
  for(uint8_t i = 0; i > 16;i++){
    buffer= pgm_read_word_near(Liner[choicer][1]+i);
    lcd.setCursor(0,1); lcd.print(buffer);
  }*/
  
  /*for(uint8_t i = 0; i < 2;i++){ //strlen_P(Liner[choicer][1]
    strcpy_P(buffer[2], (char*)pgm_read_word(&(Liner[choicer][i]])));
    lcd.print(buffer);Serial.print(buffer);
    buffString+=buffer;
  }*/ //trouble, you cannot set cursor lcd
  
  //lcd.setCursor(0,0); lcd.print(buffer[0]);
  //lcd.setCursor(0,1); lcd.print(buffer[1]);
  
  
  //lcd.setCursor(0,0); lcd.print(Liner[choicer][0]);
  //lcd.setCursor(0,1); lcd.print(Liner[choicer][1]);

  //Serial.print(String("O================O\n|") + String(Liner[choicer][0]) + String("|\n|") + String(Liner[choicer][1]) + String("O================O\n\n")); //Like I said, Arduino crash with serial on due to RAM low.
  //Serial.println(F(Liner[choicer][0]));
  //Serial.println(F(Liner[choicer][1]));
  //Serial.println(Liner[choicer][0]);
  //Serial.println(Liner[choicer][1]);

  //choicer++;
  //if(choicer>chamber-1)choicer=0;

  //code from example lcd i2c pcf library
  choicer = (choicer + 1) % chamber;
  
  delay(3000);
}

//Arduino Uno has small memory of sketch!
/* Trouble:
 * - Serialing, more than about 23 chamber = hang! display writing gone! crash! //Solved! new function is above
 * /
 */
