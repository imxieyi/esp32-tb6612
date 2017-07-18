#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "tb6612.hpp"

static void motor_task(void *pvParameters) {
    MOTOR m(GPIO_NUM_33, GPIO_NUM_26, GPIO_NUM_27, MOTOR0);
    ESP_LOGI("motor", "set speed to 50%%");
    m.setspeed(50);
    m.start(true);
    vTaskDelay(5000/portTICK_RATE_MS);
    ESP_LOGI("motor", "stop");
    m.stop();
    vTaskDelay(5000/portTICK_RATE_MS);
    ESP_LOGI("motor", "reverse direction");
    m.start(false);
    vTaskDelay(5000/portTICK_RATE_MS);
    ESP_LOGI("motor", "brake");
    m.brake();
    vTaskDelete(0);
}

extern "C" void app_main()
{
    xTaskCreatePinnedToCore(&motor_task,"motor_task",2048,NULL,5,NULL,0);
}