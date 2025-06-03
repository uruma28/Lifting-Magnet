/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENCODER_A_Pin GPIO_PIN_2
#define ENCODER_A_GPIO_Port GPIOE
#define ENCODER_B_Pin GPIO_PIN_3
#define ENCODER_B_GPIO_Port GPIOE
#define ENCODER_SW_Pin GPIO_PIN_4
#define ENCODER_SW_GPIO_Port GPIOE
#define LSE_IN_Pin GPIO_PIN_14
#define LSE_IN_GPIO_Port GPIOC
#define LSE_OUT_Pin GPIO_PIN_15
#define LSE_OUT_GPIO_Port GPIOC
#define ADC_SCiB_V_Pin GPIO_PIN_0
#define ADC_SCiB_V_GPIO_Port GPIOC
#define ADC_SCIB_I_CHARGE_Pin GPIO_PIN_1
#define ADC_SCIB_I_CHARGE_GPIO_Port GPIOC
#define ADC_SCIB_I_REGEN_Pin GPIO_PIN_2
#define ADC_SCIB_I_REGEN_GPIO_Port GPIOC
#define ADC_SCIB_I_DISCHARGE_Pin GPIO_PIN_3
#define ADC_SCIB_I_DISCHARGE_GPIO_Port GPIOC
#define PWR_GOOD_RST_Pin GPIO_PIN_2
#define PWR_GOOD_RST_GPIO_Port GPIOF
#define ADC_VIN_Pin GPIO_PIN_0
#define ADC_VIN_GPIO_Port GPIOA
#define ADC_IIN_Pin GPIO_PIN_1
#define ADC_IIN_GPIO_Port GPIOA
#define ADC_TEMP_Pin GPIO_PIN_2
#define ADC_TEMP_GPIO_Port GPIOA
#define MAG_SWITCH_IN_Pin GPIO_PIN_4
#define MAG_SWITCH_IN_GPIO_Port GPIOA
#define MAG_U_LOW_Pin GPIO_PIN_8
#define MAG_U_LOW_GPIO_Port GPIOE
#define MAG_U_HiIGH_Pin GPIO_PIN_9
#define MAG_U_HiIGH_GPIO_Port GPIOE
#define MAG_V_LOW_Pin GPIO_PIN_10
#define MAG_V_LOW_GPIO_Port GPIOE
#define MAG_V_HiIGH_Pin GPIO_PIN_11
#define MAG_V_HiIGH_GPIO_Port GPIOE
#define DCDC_HIGH_Pin GPIO_PIN_14
#define DCDC_HIGH_GPIO_Port GPIOB
#define DCDC_LOW_Pin GPIO_PIN_15
#define DCDC_LOW_GPIO_Port GPIOB
#define LCD_BACKLIGHT_Pin GPIO_PIN_12
#define LCD_BACKLIGHT_GPIO_Port GPIOD
#define I2C_LCD_SCL_Pin GPIO_PIN_6
#define I2C_LCD_SCL_GPIO_Port GPIOC
#define I2C_LCD_SDA_Pin GPIO_PIN_7
#define I2C_LCD_SDA_GPIO_Port GPIOC
#define LCD_VOLUME_Pin GPIO_PIN_8
#define LCD_VOLUME_GPIO_Port GPIOC
#define I2C_ESP32_SDA_Pin GPIO_PIN_8
#define I2C_ESP32_SDA_GPIO_Port GPIOA
#define I2C_ESP32_SCL_Pin GPIO_PIN_9
#define I2C_ESP32_SCL_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
