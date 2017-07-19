#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "tb6612.hpp"

static void motor_task(void *pvParameters) {
    MOTOR m1(GPIO_NUM_32, GPIO_NUM_26, GPIO_NUM_27, MOTOR0);
    MOTOR m2(GPIO_NUM_23, GPIO_NUM_19, GPIO_NUM_22, MOTOR1);
    ESP_LOGI("motor", "set speed to 50%%");
    m1.setspeed(50);
    m1.start(true);
    m2.setspeed(100);
    m2.start(true);
    vTaskDelay(5000/portTICK_RATE_MS);
    ESP_LOGI("motor", "stop");
    m1.stop();
    m2.stop();
    vTaskDelay(5000/portTICK_RATE_MS);
    ESP_LOGI("motor", "reverse direction");
    m1.start(false);
    m2.setspeed(70);
    m2.start(false);
    vTaskDelay(5000/portTICK_RATE_MS);
    ESP_LOGI("motor", "brake");
    m1.brake();
    m2.brake();
    vTaskDelete(0);
}

extern "C" void app_main()
{
    xTaskCreatePinnedToCore(&motor_task,"motor_task",2048,NULL,5,NULL,0);
}