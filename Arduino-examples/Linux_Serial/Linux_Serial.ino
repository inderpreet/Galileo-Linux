/*
This example shows how to print text to the 
Galileo's serial ports using Linux system calls.

Example code by Erik Nyquist 2013;
erik.nyquist@intel.com

I do not hold any rights over these 
code examples, and you may do with 
them what you wish
*/
void setup() {
  
  Serial.begin(115200);

}

void loop() {
  
  system("echo \"hello, world!\" > /dev/ttyGS0"); //Serial (IDE Serial Monitor)
  system("echo \"hello, world!\" > /dev/ttyS0");  //Serial1 (Arduino header UART)
  delay(500);
}
