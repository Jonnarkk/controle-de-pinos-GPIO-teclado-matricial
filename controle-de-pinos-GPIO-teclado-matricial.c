#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/pwm.h"

// Define o LEDs de saída
#define GPIO_RED_LED 13
#define GPIO_GREEN_LED 11
#define GPIO_BLUE_LED 12
#define GPIO_Buzzer 16

// Define linhas e colulas
#define ROWS 4
#define COLS 4

// Conexão dos pinos GPIO
const uint8_t row_pins[ROWS] = {9, 8, 7, 6};
const uint8_t col_pins[ROWS] = {5, 4, 3, 2};

// Mapa de teclas
char key_map[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

void pwm_init_buzzer(uint pin)
{
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_config config = pwm_get_default_config();
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(pin, 0); // Desativa o buzzer
}

// Função para gerar uma frequência no buzzer
void beep(uint note, uint duration)
{
    uint slice_num = pwm_gpio_to_slice_num(GPIO_Buzzer);
    uint32_t clock = clock_get_hz(clk_sys);

    // Calcula divisor de clock para a frequência desejada
    uint32_t divisor = clock / (note * 4096);
    pwm_set_clkdiv(slice_num, divisor);

    // Define duty cycle para 50%
    pwm_set_gpio_level(GPIO_Buzzer, 2048);

    sleep_ms(duration); // Dura o tempo necessário

    // Desativa o buzzer
    pwm_set_gpio_level(GPIO_Buzzer, 0);
    sleep_ms(20); // Pequena pausa entre notas
}

// Função para inicializar saídas
void inicializar_led()
{
  gpio_init(GPIO_RED_LED);
  gpio_set_dir(GPIO_RED_LED, GPIO_OUT);
  gpio_init(GPIO_GREEN_LED);
  gpio_set_dir(GPIO_GREEN_LED, GPIO_OUT);
  gpio_init(GPIO_BLUE_LED);
  gpio_set_dir(GPIO_BLUE_LED, GPIO_OUT);
}

void piscar_led(uint gpio, uint duracao)
{
  gpio_put(gpio, 1);
  sleep_ms(duracao);
  gpio_put(gpio, 0);
}

void acender_todos_leds(uint duracao) {
    gpio_put(GPIO_RED_LED, 1);
    gpio_put(GPIO_GREEN_LED, 1);
    gpio_put(GPIO_BLUE_LED, 1);
    sleep_ms(duracao);
    gpio_put(GPIO_RED_LED, 0);
    gpio_put(GPIO_GREEN_LED, 0);
    gpio_put(GPIO_BLUE_LED, 0);
}

// Função para inicializar os pinos do teclado
void keypad_init()
{
  for (int i = 0; i < ROWS; i++)
  {
    gpio_init(row_pins[i]);
    gpio_set_dir(row_pins[i], GPIO_OUT);
    gpio_put(row_pins[i], 0); // Saída em nível baixo
  }
  for (int i = 0; i < COLS; i++)
  {
    gpio_init(col_pins[i]);
    gpio_set_dir(col_pins[i], GPIO_IN);
    gpio_pull_down(col_pins[i]); // Entrada com pull-dow
  }
}

// Função de leitura do teclado
char read_keypad()
{
  for (int row = 0; row < ROWS; row++)
  {
    gpio_put(row_pins[row], 1); // Ativa linha atual
    for (int col = 0; col < COLS; col++)
    {
      if (gpio_get(col_pins[col]))
      {                             // Verifica se a coluna atual está em nível alto
        gpio_put(row_pins[row], 0); // Desativa a linha atual
        return key_map[row][col];   // Retorna a tecla pressionada
      }
    }
    gpio_put(row_pins[row], 0); // Desativa linha atual
  }
  return '\0';
}

// Função principal
int main()
{
  stdio_init_all();
  inicializar_led();
  keypad_init();
  pwm_init_buzzer(GPIO_Buzzer);

  while (true)
  {
    char key = read_keypad(); // Ler teclado

    if (key != '\0')
    {
      switch (key)
      {
      case 'A':
        // Pisca LED vermelho
        printf("Piscando LED vermelho \n");
        piscar_led(GPIO_RED_LED, 1000);
        break;
      case 'B': // Liga o led azul por 1s

        printf("Piscando LED azul \n");
        piscar_led(GPIO_BLUE_LED, 1000);
        break;
      case 'C':
        // Pisca LED verde
        printf("Piscando LED verde \n");
        piscar_led(GPIO_GREEN_LED, 1000);
        break;
      case 'D':
        printf("Acendendo todos os LEDs\n");
        acender_todos_leds(1000);
        break;
      case '#':
        // Ativa o buzzer por 2 seg
        beep(2000, 2000);
          printf("Buzzer ligado por 2 segundos.\n");
          break;
      case '*':
        // Entra no modo BOOTSEL
        reset_usb_boot(0, 0);
        break;
      }
      printf("Tecla pressionada: %c\n", key); // Imprime a tecla no console
    }
    sleep_ms(200); // Evita leituras repetidas
  }
  return 0;
}