#include<Arduino_FreeRTOS.h>
int analog[6];
int digital[13];
char req;
void setup(){
  Serial.begin(115200);
  xTaskCreate(TaskSerialRead, "TaskSerialRead", 128, NULL, 1, NULL);
  xTaskCreate(TaskSerialWrite, "TaskSerialWrite", 128, NULL, 2, NULL);
  vTaskStartScheduler();
}
void TaskSerialRead(void *pvParameters){
  (void) pvParameters;
  int i;
  for(;;){
    vTaskDelay(pdMS_TO_TICKS(150));
    for (i = 0; i <= 5; i++) analog[i] = analogRead(i);
      for (i = 1; i <= 13; i++)  digital[i] = digitalRead(i);
  }
}
void TaskSerialWrite(void *pvParameters){
  (void) pvParameters;
  int i;
  for(;;){
    vTaskDelay(pdMS_TO_TICKS(150));
    if(Serial.available() > 0){
      req = Serial.read();
      if(req == 'a'){
        Serial.print("Analog  : ");
        for(i=0;i<5;i++){
          Serial.print(analog[i]);
          Serial.print(" , ");
        }
        Serial.println(analog[i]);
        req = 0;
      }else if(req == 'd'){
        Serial.print("Digital  : ");
        for(i=0;i<12;i++){
          Serial.print(digital[i]); 
          Serial.print(" , ");
        }
        Serial.println(digital[i]);
        req = 0;
      }
    }
  }
}
void loop(){}
