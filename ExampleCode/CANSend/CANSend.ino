#include "CANSAME5x.h"

#define CAN_DLC 8
uint8_t can_tx_buffer[8]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};

void setup() {
  Serial1.begin(115200);
  while (!Serial1);

  Serial1.println("CAN Send Frame");
  // start the CAN bus at 500 kbps
  if (!CAN.begin(500000)) {
    Serial1.println("Starting CAN failed!");
    while (1);
  }
}

void loop() {
  Serial1.print("Sending packet ... ");
  CAN.beginPacket(0x100);
  CAN.write(can_tx_buffer,CAN_DLC);
  CAN.endPacket();
  Serial1.println("done");
  delay(1000);
}
