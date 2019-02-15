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
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Cool and good");
  lcd.setCursor(0,1);
  lcd.print("Perkedel Tech");
}

uint8_t choicer = 0;
const uint8_t chamber = 21;

//String Liner[10][2] = {{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""}}; //Empty Templater already exist
//char Liner[10][2][] PROGMEM = {{"",""}}; //we must branch this old version to move the different way where initializer is shorter, not too long!
//const String Liner[chamber][2] PROGMEM = {}; initalizer cannot be too long!
  const char subLiner_01[2][16] PROGMEM = {"Cool and Good","\x01 Perkedel Tech"};
  const char subLiner_02[2][16] PROGMEM = {"Hello World","Halo Dunia"};
  const char subLiner_03[2][16] PROGMEM = {"Hatsune \xd0\xb9","Leekspinner"};
  const char subLiner_04[2][16] PROGMEM = {"I SQUARED C PC","C++ Arduino"};
  const char subLiner_05[2][16] PROGMEM = {"\xa2\xb1\xd9\xc4\xde\xb3\xa8\xb0\xc9\xa3","SPECIAL \xb5\xc7\xb9\xa1"};
  
  const char subLiner_06[2][16] PROGMEM = {"\x7e DUPER_AWESOME\x7f","\xff{DIV BY ZERO} \xff"};
  const char subLiner_07[2][16] PROGMEM = {"1234567890ABCDEF","!@#$%^&*()abcdef"};
  const char subLiner_08[2][16] PROGMEM = {"SELF ESTEEM vINF","Rp100rb /\x5c 100rb"};
  const char subLiner_09[2][16] PROGMEM = {"OpenCX","VanElektronische"};
  const char subLiner_10[2][16] PROGMEM = {"\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff",""}; //empty is intended for templating. leave it for future project! wait, he's already exist above!
  
  const char subLiner_11[2][16] PROGMEM = {"ASCII Table data","with NIHONGO"};
  const char subLiner_12[2][16] PROGMEM = {"Only support:","\xb6\xc7\xb6\xc5 & LATIN ..."};
  const char subLiner_13[2][16] PROGMEM = {"Also has:","GREEK,SIGN,ETC."};
  const char subLiner_14[2][16] PROGMEM = {"SUPER SIMPLE","4 PIN ONLY!!!"};
  const char subLiner_15[2][16] PROGMEM = {"GND          SDA","VCC          SCL"};
  
  const char subLiner_16[2][16] PROGMEM = {"GND \x7f--- - POWER","VCC \x7f--- + 5VOLT"};
  const char subLiner_17[2][16] PROGMEM = {"DATA    ---\x7e SDA","CLOCK   ---\x7e SCL"};/*
  const char subLiner_18[2][16] PROGMEM = {"MOCKUP TIME","FAKE SCREEN"};
  const char subLiner_19[2][16] PROGMEM = {"TravolP - Inochi","Song Select"};
  const char subLiner_20[2][16] PROGMEM = {"TravolP - Inochi","1:00 --------- 4:45"};
  
  const char subLiner_21[2][16] PROGMEM = {"TravolP - Inochi","Cm | Perkedel Edits"};
  const char subLiner_22[2][16] PROGMEM = {"Lyric Lyric Lyric","  @           "};
  const char subLiner_23[2][16] PROGMEM = {"USB: TUPAI SQ (2TB)","26GB ---------- 2TB"};
  const char subLiner_24[2][16] PROGMEM = {"",""};
  const char subLiner_25[2][16] PROGMEM = {"",""};
  
  const char subLiner_26[2][16] PROGMEM = {"TravolP - Inochi",""};
  const char subLiner_27[2][16] PROGMEM = {"MOCKUP END","FUTURE DREAM"};*/
  const char subLiner_28[2][16] PROGMEM = {"by JOELwindows7","\x01 Perkedel Tech"};
  const char subLiner_29[2][16] PROGMEM = {"GNU GPL v3","FREE-OPEN-FULL"};
  const char subLiner_30[2][16] PROGMEM = {"linktr.ee/","joelwindows7"};
  
  const char subLiner_LAST[2][16] PROGMEM = {"\x03  Last Found  \x03","\x02  Game  Over  \x02"};

const char* const Liner[chamber][2] PROGMEM ={
  {subLiner_01[0],subLiner_01[1]},
  {subLiner_02[0],subLiner_02[1]},
  {subLiner_03[0],subLiner_03[1]},
  {subLiner_04[0],subLiner_04[1]},
  {subLiner_05[0],subLiner_05[1]},

  {subLiner_06[0],subLiner_06[1]},
  {subLiner_07[0],subLiner_07[1]},
  {subLiner_08[0],subLiner_08[1]},
  {subLiner_09[0],subLiner_09[1]},
  {subLiner_10[0],subLiner_10[1]},

  {subLiner_11[0],subLiner_11[1]},
  {subLiner_12[0],subLiner_12[1]},
  {subLiner_13[0],subLiner_13[1]},
  {subLiner_14[0],subLiner_14[1]},
  {subLiner_15[0],subLiner_15[1]},

  {subLiner_16[0],subLiner_16[1]},
  {subLiner_17[0],subLiner_17[1]},
  /*{subLiner_18[0],subLiner_18[1]},
  {subLiner_19[0],subLiner_19[1]},
  {subLiner_20[0],subLiner_20[1]},

  {subLiner_21[0],subLiner_21[1]},
  {subLiner_22[0],subLiner_22[1]},
  {subLiner_23[0],subLiner_23[1]},
  {subLiner_24[0],subLiner_24[1]},
  {subLiner_25[0],subLiner_25[1]},

  {subLiner_26[0],subLiner_26[1]},
  {subLiner_27[0],subLiner_27[1]},*/
  {subLiner_28[0],subLiner_28[1]},
  {subLiner_29[0],subLiner_29[1]},
  {subLiner_30[0],subLiner_30[1]},

  {subLiner_LAST[0],subLiner_LAST[1]},
};

//char buffer[2][16];
char buffer;

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  //strcpy_P(buffer[0], (char*)pgm_read_word(&(Liner[choicer][0])));
  //strcpy_P(buffer[1], (char*)pgm_read_word(&(Liner[choicer][1])));
  lcd.setCursor(0,0); 
  for(uint8_t i = 0; i < strlen_P(Liner[choicer][0]);i++){
    //buffer= Liner[choicer][0][i];
    //strcpy_P(buffer, (char*)pgm_read_word(&(Liner[choicer][0][i])));
    lcd.print(buffer); Serial.println(buffer);
  }
  lcd.setCursor(0,1);
  for(uint8_t i = 0; i < strlen_P(Liner[choicer][1]);i++){
    //buffer= Liner[choicer][1][i];
    //strcpy_P(buffer, (char*)pgm_read_word(&(Liner[choicer][1][i])));
    lcd.print(buffer); Serial.println(buffer);
  }
  /*for(uint8_t i = 0; i > 16;i++){
    buffer= pgm_read_word_near(Liner[choicer][0]+i);
    lcd.setCursor(0,0); lcd.print(buffer);
  }
  for(uint8_t i = 0; i > 16;i++){
    buffer= pgm_read_word_near(Liner[choicer][1]+i);
    lcd.setCursor(0,1); lcd.print(buffer);
  }*/
  //lcd.setCursor(0,0); lcd.print(buffer[0]);
  //lcd.setCursor(0,1); lcd.print(buffer[1]);
  
  
  lcd.setCursor(0,0); lcd.print(Liner[choicer][0]);
  lcd.setCursor(0,1); lcd.print(Liner[choicer][1]);

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
 * - Serialing, more than about 23 chamber = hang! display writing gone! crash!
 * /
 */
