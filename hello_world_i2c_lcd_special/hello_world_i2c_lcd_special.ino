#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

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
 */

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

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

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.createChar(1,PerkedelLogo);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Cool and good");
  lcd.setCursor(0,1);
  lcd.print("Perkedel Tech");
}

int choicer = 0;
//String Liner[10][2] = {{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""},{"",""}}
String Liner[10][2] = {
  {"Cool and Good","\01 Perkedel Tech"},
  {"Hello World","Halo Dunia"},
  {"Hatsune \xd0\xb9","Leekspinner"},
  {"I SQUARED C PC","C++ Arduino"},
  {"\xa2\xb1\xd9\xc4\xde\xb3\xa8\xb0\xc9\xa3","SPECIAL \xb5\xc7\xb9\xa1"},
  {"\x7e DUPER_AWESOME\x7f","\xff{DIV BY ZERO} \xff"},
  {"1234567890ABCDEF","!@#$%^&*()abcdef"},
  {"SELF ESTEEM vINF","Rp100rb /\x5c 100rb"},
  {"OpenCX","VanElektronische"},
  {"Last Found","Game Over"},
  };

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0); lcd.print(String(Liner[choicer][0]));
  lcd.setCursor(0,1); lcd.print(String(Liner[choicer][1]));

  choicer++;
  if(choicer>9)choicer=0;
  delay(3000);
}
