#include<Arduino_FreeRTOS.h>
void setup(){
  Serial.begin(115200);
  xTaskCreate(TaskWriteAnalog, "Analog", 128, NULL, 1, NULL);
  xTaskCreate(TaskWriteDigital, "Digital", 128, NULL, 2, NULL);
  vTaskStartScheduler();
}
void TaskWriteAnalog(void *pvParameters){
  (void) pvParameters;
  int i;
  for(;;){
    vTaskDelay(pdMS_TO_TICKS(900));
    Serial.print("Analog  : ");
    for(i=0;i<=5;i++){
      Serial.print(analogRead(i));
      Serial.print(" , ");
    }
    Serial.println(analogRead(i));
  }
}
void TaskWriteDigital(void *pvParameters){
  (void) pvParameters;
  int i;
  for(;;){
    vTaskDelay(pdMS_TO_TICKS(300));
    Serial.print("Digital  : ");
    for(i=1;i<=13;i++){
      Serial.print(digitalRead(i)); 
      Serial.print(" , ");
    }
    Serial.println(digitalRead(i));
  }
}
void loop(){}
