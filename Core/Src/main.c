/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void checkCode(char *passCode, char **inputCode)
{

	if(strlen(*inputCode) == 2)
	{
		if(strcmp(passCode,*inputCode) == 0)
		{
			HAL_GPIO_WritePin(GPIOA, PASS_Pin, 0);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOA, FAIL_Pin, 0);
		}
	}
	else if (strlen(*inputCode) > 2)
	{
		strcpy(*inputCode,"");
		GPIOB->ODR = 0xFE;
		HAL_GPIO_WritePin(GPIOA, PASS_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, FAIL_Pin, 1);
		return;
	}
	else
	{
		return;
	}





}



void read_keypad (char *passCode, char **inputCode)
{
	HAL_GPIO_WritePin (GPIOA, ROW1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (GPIOA, ROW2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, ROW3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, ROW4_Pin, GPIO_PIN_RESET);


	if ((HAL_GPIO_ReadPin (GPIOA, COL1_Pin)))
	{
		//1
		GPIOB->ODR = ~0x0C;
		while(HAL_GPIO_ReadPin (GPIOA, COL1_Pin));
		strcat(*inputCode,"1");
		checkCode(passCode, inputCode);
		//return;
	}

	if ((HAL_GPIO_ReadPin (GPIOA, COL2_Pin)))
	{
		//2
		GPIOB->ODR = ~0xB6;
		while(HAL_GPIO_ReadPin (GPIOA, COL2_Pin));
		strcat(*inputCode,"2");
		checkCode(passCode, inputCode);
		//return;
	}

	if ((HAL_GPIO_ReadPin (GPIOB, COL3_Pin)))
	{
		//3
		GPIOB->ODR = ~0x9E;
		while(HAL_GPIO_ReadPin (GPIOB, COL3_Pin));
		strcat(*inputCode,"3");
		checkCode(passCode, inputCode);
		//return;
	}




	HAL_GPIO_WritePin (GPIOA, ROW1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, ROW2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (GPIOA, ROW3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, ROW4_Pin, GPIO_PIN_RESET);



	if ((HAL_GPIO_ReadPin (GPIOA, COL1_Pin)))
	{
		//4
		GPIOB->ODR = ~0xCC;
		while(HAL_GPIO_ReadPin (GPIOA, COL1_Pin));
		strcat(*inputCode,"4");
		checkCode(passCode, inputCode);
		//return;

	}

	if ((HAL_GPIO_ReadPin (GPIOA, COL2_Pin)))
	{
		//5
		GPIOB->ODR = ~0xDA;
		while(HAL_GPIO_ReadPin (GPIOA, COL2_Pin));
		strcat(*inputCode,"5");
		checkCode(passCode, inputCode);
		//return;
	}

	if ((HAL_GPIO_ReadPin (GPIOB, COL3_Pin)))
	{
		//6
		GPIOB->ODR = ~0xFA;
		while(HAL_GPIO_ReadPin (GPIOB, COL3_Pin));
		strcat(*inputCode,"6");
		checkCode(passCode, inputCode);
		//return;
	}



	HAL_GPIO_WritePin (GPIOA, ROW1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, ROW2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, ROW3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin (GPIOA, ROW4_Pin, GPIO_PIN_RESET);

	if ((HAL_GPIO_ReadPin (GPIOA, COL1_Pin)))
	{
		//7
		GPIOB->ODR = ~0x0E;
		while(HAL_GPIO_ReadPin (GPIOA, COL1_Pin));
		strcat(*inputCode,"7");
		checkCode(passCode, inputCode);
		//return;
	}

	if ((HAL_GPIO_ReadPin (GPIOA, COL2_Pin)))
	{
		//8
		GPIOB->ODR = ~0xFD;
		while(HAL_GPIO_ReadPin (GPIOA, COL2_Pin));
		strcat(*inputCode,"8");
		checkCode(passCode, inputCode);
		//return;
	}

	if ((HAL_GPIO_ReadPin (GPIOB, COL3_Pin)))
	{
		//9
		GPIOB->ODR = ~0xDE;
		while(HAL_GPIO_ReadPin (GPIOB, COL3_Pin));
		strcat(*inputCode,"9");
		checkCode(passCode, inputCode);
		//return;
	}





	HAL_GPIO_WritePin (GPIOA, ROW1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, ROW2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, ROW3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (GPIOA, ROW4_Pin, GPIO_PIN_SET);

	if ((HAL_GPIO_ReadPin (GPIOA, COL1_Pin)))
	{
		while(HAL_GPIO_ReadPin (GPIOA, COL1_Pin));
		//return;
	}

	if ((HAL_GPIO_ReadPin (GPIOA, COL2_Pin)))
	{
		while(HAL_GPIO_ReadPin (GPIOA, COL2_Pin));
		//return;
	}

	if ((HAL_GPIO_ReadPin (GPIOB, COL3_Pin)))
	{

		while(HAL_GPIO_ReadPin (GPIOB, COL3_Pin));
		//return;
	}

}





/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  char passCode[2] = "97";
  char *inputCode;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


	  read_keypad(passCode, &inputCode);
	  HAL_Delay(50);





  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOA, PASS_Pin|FAIL_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DISP1_Pin|DISP2_Pin|DISP3_Pin|DISP4_Pin
                          |DISP5_Pin|DISP6_Pin|DISP7_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : COL1_Pin COL2_Pin */
  GPIO_InitStruct.Pin = COL1_Pin|COL2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : ROW1_Pin ROW2_Pin ROW3_Pin ROW4_Pin
                           PASS_Pin FAIL_Pin */
  GPIO_InitStruct.Pin = ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin
                          |PASS_Pin|FAIL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : COL3_Pin */
  GPIO_InitStruct.Pin = COL3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(COL3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : DISP1_Pin DISP2_Pin DISP3_Pin DISP4_Pin
                           DISP5_Pin DISP6_Pin DISP7_Pin */
  GPIO_InitStruct.Pin = DISP1_Pin|DISP2_Pin|DISP3_Pin|DISP4_Pin
                          |DISP5_Pin|DISP6_Pin|DISP7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
