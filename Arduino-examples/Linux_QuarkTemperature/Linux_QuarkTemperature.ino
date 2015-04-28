/*
This example shows how to read the temperature of the Quark SoC

Example code by Erik Nyquist 2013;
erik.nyquist@intel.com

I do not hold any rights over these 
code examples, and you may do with 
them what you wish
*/

char temp_raw[6];
int temp;

void setup() {
  
  Serial.begin(115200);

}

void loop() {
  
  temp = getQuarkTemp();
  Serial.print("The temperature of the Quark SoC is ");
  Serial.print(temp);
  Serial.println(" degrees celcius.");
  
  delay(1000);
  
}

int getQuarkTemp(){
 
  FILE *fp;
 
  fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r"); 
  fgets(temp_raw, 5, fp);
  fclose(fp);
  
  int temp = atoi(temp_raw);
  temp /= 100;
  return temp;  
  
}
