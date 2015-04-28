/*
This example shows how to use Linux system calls to enable a shell prompt 
via the standard Galileo USB cable. Simply upload the sketch, then use 
your favourite terminal emulator (we used puTTY) to connect to your Galileo's
COM port (it's the same one you use to connect Galileo to the Arduino IDE).
Baud rate is 115200.

WARNING: uploading this sketch will DISABLE the ability to upload further 
sketches through the IDE. If you are booting from non-persistent SPI flash
firmware, then simply reboot the board and your changes will be reverted.
If this doesn't work, you will need to do a firmware update.

Example code by Erik Nyquist 2013;
erik.nyquist@intel.com

I do not hold any rights over these 
code examples, and you may do with 
them what you wish

*/

void setup() {
  
  system("sed -i 's/S:2345/S0:2345/g' /etc/inittab");
  system("sed -i 's/ttyS1/ttyGS0/g' /etc/inittab");
  system("sed -i 's/grst/#grst/g' /etc/inittab");
  system("sed -i 's/clld/#clld/g' /etc/inittab");
  system("kill -SIGHUP 1");

}

void loop() {
  
}
