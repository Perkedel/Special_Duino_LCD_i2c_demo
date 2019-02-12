#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //original, multiple: original, New, SR.
//#include <LiquidCrystal_PCF8574.h> //alternative mathertel

/*  http://bit.ly/DuinoLCDi2cPerkedel
 *   GNU GPL v3
 *   various libraries and copy from examples from library applied
 *   Video Demo: https://www.youtube.com/watch?v=f47Uz1C97Uw
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

    other refferencing:
    https://github.com/mathertel/LiquidCrystal_PCF8574
 */

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
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
  //Serial.begin(300);
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

unsigned int choicer = 0;
const int chamber = 21;

//String Liner[10][2] = {{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""}}
String Liner[chamber][2] = {
  {"Cool and Good","\x01 Perkedel Tech"},
  {"Hello World","Halo Dunia"},
  {"Hatsune \xd0\xb9","Leekspinner"},
  {"I SQUARED C PC","C++ Arduino"},
  {"\xa2\xb1\xd9\xc4\xde\xb3\xa8\xb0\xc9\xa3","SPECIAL \xb5\xc7\xb9\xa1"},
  
  {"\x7e DUPER_AWESOME\x7f","\xff{DIV BY ZERO} \xff"},
  {"1234567890ABCDEF","!@#$%^&*()abcdef"},
  {"SELF ESTEEM vINF","Rp100rb /\x5c 100rb"},
  {"OpenCX","VanElektronische"},
  {"",""}, //empty is intended for templating. leave it for future project!
  
  {"ASCII Table data","with NIHONGO"}, 
  {"Only support:","\xb6\xc7\xb6\xc5 & LATIN ..."},
  {"Also has:","GREEK,SIGN,ETC."},
  {"SUPER SIMPLE","4 PIN ONLY!!!"},
  {"GND          SDA","VCC          SCL"},
  
  {"GND \x7f--- - POWER","VCC \x7f--- + 5VOLT"},
  {"DATA    ---\x7e SDA","CLOCK   ---\x7e SCL"},/*
  {"MOCKUP TIME","FAKE SCREEN"},
  {"TravolP - Inochi","Song Select"},
  {"TravolP - Inochi","1:00 --------- 4:45"},
  
  {"TravolP - Inochi","Cm | Perkedel Edits"},
  {"Lyric Lyric Lyric","  @           "},
  {"USB: TUPAI SQ (2TB)","26GB ---------- 2TB"},
  {"",""},
  {"",""},
  
  {"TravolP - Inochi",""},
  {"MOCKUP END","FUTURE DREAM"},*/
  {"by JOELwindows7","\x01 Perkedel Tech"},
  {"GNU GPL v3","FREE-OPEN-FULL"},
  {"linktr.ee/","joelwindows7"},
  
  {"\x03  Last Found  \x03","\x02  Game  Over  \x02"},
  
  };

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0); lcd.print(String(Liner[choicer][0]));
  lcd.setCursor(0,1); lcd.print(String(Liner[choicer][1]));

  //Serial.print(String("O================O\n|") + String(Liner[choicer][0]) + String("|\n|") + String(Liner[choicer][1]) + String("O================O\n\n"));

  choicer++;
  if(choicer>chamber-1)choicer=0;

  //code from example lcd i2c pcf library
  //choicer = (choicer + 1) % chamber;
  
  delay(3000);
}

//Arduino Uno has small memory of sketch!
/* Trouble:
 * - Serialing, more than about 23 chamber = hang! display writing gone! crash!
 * /
 */
