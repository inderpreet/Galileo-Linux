/*
This example takes advantage of the fact that the SoC temperature 
drops by a few degrees when you touch it- use the Quark SoC as a 
touch sensor!

Example code by Erik Nyquist 2013;
erik.nyquist@intel.com

I do not hold any rights over these 
code examples, and you may do with 
them what you wish
*/

char temp_raw[6];
int temp;
int check = 1;
int initialTemp;


void setup() {
  
  Serial.begin(115200);
  Serial.println("Touch Quark to start.");
  initialTemp = getQuarkTemp();

}

void loop() {
  temp = getQuarkTemp();
  if (temp < initialTemp - 2 && check == 1){
    
    Serial.println("Touch!");
    check = 0;
    delay(500);
    
  }
  
  if (temp > initialTemp - 1 && check == 0){
    check = 1;
  }
    
  
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
