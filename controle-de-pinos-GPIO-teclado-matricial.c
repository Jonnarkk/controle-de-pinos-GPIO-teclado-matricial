#include <stdio.h>
#include "pico/stdlib.h"

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
    {'1', '2' , '3', 'A'},
    {'4', '5' , '6', 'B'},
    {'7', '8' , '9', 'C'},
    {'*', '0' , '#', 'D'}
};

// Função para inicializar saídas
void inicializar_saidas(){
  gpio_init(GPIO_RED_LED);
  gpio_set_dir(GPIO_RED_LED, GPIO_OUT);
  gpio_init(GPIO_GREEN_LED);
  gpio_set_dir(GPIO_GREEN_LED, GPIO_OUT);
  gpio_init(GPIO_BLUE_LED);
  gpio_set_dir(GPIO_BLUE_LED, GPIO_OUT);
  gpio_init(GPIO_Buzzer);
  gpio_set_dir(GPIO_Buzzer, GPIO_OUT);
}

// Função para inicializar os pinos do teclado
void keypad_init(){
	for(int i = 0; i < ROWS; i++){
		gpio_init(row_pins[i]);
		gpio_set_dir(row_pins[i],GPIO_OUT);
		gpio_put(row_pins[i],0);// Saída em nível baixo
	}
	for(int i = 0; i < COLS; i++){
		gpio_init(col_pins[i]);
		gpio_set_dir(col_pins[i],GPIO_IN);
		gpio_pull_down(col_pins[i]);// Entrada com pull-dow
	}
}

// Função de leitura do teclado
char read_keypad(){
	for (int row = 0; row < ROWS; row++){
		gpio_put(row_pins[row],1); // Ativa linha atual
		for(int col = 0; col < COLS; col++){
			if(gpio_get(col_pins[col])){ // Verifica se a coluna atual está em nível alto
				gpio_put(row_pins[row],0); // Desativa a linha atual
				return key_map[row][col]; // Retorna a tecla pressionada
			}
		}
		gpio_put(row_pins[row],0); // Desativa linha atual
	}
  return '\0';
}

// Função principal
int main() {

  inicializar_saidas();
  stdio_init_all();
  keypad_init();

  while(true){
	  char key = read_keypad();// Ler teclado

    if (key != '\0') {
        switch(key) {
            case 'A':
                 // Pisca LED vermelho
                 printf("Piscando LED vermelho \n");
                 gpio_put(GPIO_RED_LED, 1); // liga o led
                 sleep_ms(1000); // seta duracao de 1s
                 gpio_put(GPIO_RED_LED, 0); // desliga o led
            break;
            case 'B': // Liga o led azul por 1s
                 
                 printf("Piscando LED azul \n");
                 gpio_put(GPIO_BLUE_LED, 1); // liga o led
                 sleep_ms(1000); // seta duracao de 1s
                 gpio_put(GPIO_BLUE_LED, 0); // desliga o led
            break;
            case 'C':
                // Pisca LED verde
                printf("Piscando LED verde \n");
                gpio_put(GPIO_GREEN_LED, 1);
                sleep_ms(1000);
                gpio_put(GPIO_GREEN_LED, 0);
            break;
            case 'D':
                // Liga todos os LED
            break;
            case '#':
                // Ativa o buzzer
            break;
        }
        printf("Tecla pressionada: %c\n", key);  // Imprime a tecla no console
    }
    sleep_ms(200);  // Evita leituras repetidas
  }
  return 0;
}