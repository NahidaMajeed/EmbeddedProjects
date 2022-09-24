#include <Wire.h>
#include <SPI.h>
#include <mcp2515.h>
#include <rgb_lcd.h>

struct can_frame canMsg;
rgb_lcd lcd;

MCP2515 mcp2515(10);  

void setup() {
  Serial.begin(9600);
  SPI.begin();
  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.print("CANBUS TRAIL");
  Serial.println("CanBus Trail");
  delay(1500);
  lcd.clear();

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();                 
}
void loop() {
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data (Poll Read)
  {
    int x = canMsg.data[0];
    int y = canMsg.data[1];
    lcd.setCursor(0,0);
    lcd.print("Humi : ");
    lcd.print(x);
    Serial.println(x);
    lcd.setCursor(0,1);
    lcd.print("Temp : ");
    Serial.println( y);
    lcd.print(y);
    delay(500);
    lcd.clear();
  }
  else
  {
    Serial.println(mcp2515.readMessage(&canMsg));
  }
}
