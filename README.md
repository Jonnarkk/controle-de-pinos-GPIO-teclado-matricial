# Projeto: Controle de LEDs e Buzzer com Teclado Matricial no Raspberry Pi Pico W

## Descrição Geral
Este projeto utiliza um Raspberry Pi Pico W para controlar LEDs RGB e um buzzer através de um teclado matricial 4x4. O código foi implementado em C e integra diversas funcionalidades que são acionadas por meio das teclas do teclado. Além disso, o programa inclui a opção de reinicializar o microcontrolador no modo BOOTSEL.

## Funcionalidades Principais

### 1. Controle de LEDs RGB
O sistema utiliza três LEDs RGB conectados aos seguintes pinos GPIO do Raspberry Pi Pico W:
- **LED Vermelho:** GPIO 13
- **LED Verde:** GPIO 11
- **LED Azul:** GPIO 12

#### Comandos Disponíveis:
- **Tecla A:** Pisca o LED vermelho por 1 segundo.
- **Tecla B:** Pisca o LED azul por 1 segundo.
- **Tecla C:** Pisca o LED verde por 1 segundo.
- **Tecla D:** Acende todos os LEDs simultaneamente por 1 segundo.

### 2. Controle do Buzzer
O buzzer está conectado ao GPIO 16 e é controlado utilizando o módulo PWM do Raspberry Pi Pico W.

#### Comando Disponível:
- **Tecla #:** Ativa o buzzer por 2 segundos emitindo um som de 2000 Hz.

### 3. Leitura do Teclado Matricial
Um teclado matricial 4x4 é utilizado para receber comandos. As linhas e colunas estão conectadas aos seguintes pinos GPIO:
- **Linhas:** GPIO 9, 8, 7, 6
- **Colunas:** GPIO 5, 4, 3, 2

O mapeamento de teclas é o seguinte:

| 1 | 2 | 3 | A |
|---|---|---|---|
| 4 | 5 | 6 | B |
| 7 | 8 | 9 | C |
| * | 0 | # | D |

### 4. Modo BOOTSEL
- **Tecla *:** Reinicia o microcontrolador e o coloca no modo BOOTSEL para facilitar o upload de um novo firmware.

## Como Utilizar
1. Conecte os LEDs RGB, buzzer e teclado matricial ao Raspberry Pi Pico W de acordo com os pinos especificados no código.
2. Compile e carregue o código no Raspberry Pi Pico W utilizando uma ferramenta compatível (como o SDK do Raspberry Pi).
3. Abra o monitor serial para visualizar as mensagens de depuração e interagir com o sistema.
4. Pressione as teclas no teclado matricial para acionar as funcionalidades correspondentes:
   - `A`, `B`, `C`, `D` para controlar os LEDs.
   - `#` para ativar o buzzer.
   - `*` para reiniciar o dispositivo no modo BOOTSEL.

## Dependências
- Biblioteca `pico/stdlib.h` para funções básicas de controle de hardware.
- Biblioteca `hardware/pwm.h` para controle de sinais PWM (usado pelo buzzer).
- Biblioteca `pico/bootrom.h` para acesso ao modo BOOTSEL.

## Observações
- Certifique-se de que o hardware está conectado corretamente antes de ligar o microcontrolador.
- O tempo de debounce para o teclado foi configurado em 200 ms para evitar leituras repetidas.

## Exemplo de Saída no Monitor Serial
Quando uma tecla é pressionada, as seguintes mensagens serão exibidas no console:
- `Piscando LED vermelho` (Tecla A)
- `Piscando LED azul` (Tecla B)
- `Piscando LED verde` (Tecla C)
- `Acendendo todos os LEDs` (Tecla D)
- `Buzzer ligado por 2 segundos` (Tecla #)
- `Tecla pressionada: <tecla>`


# Plano de Trabalho

### Divisão de Tarefas entre 9 Pessoas

## **Tarefas e Responsabilidades**

### 1. **Organização do Circuito e Diagrama no Wokwi**
**Responsável:** Adson 
- Criar e montar o diagrama do circuito no simulador Wokwi.
- Conectar o teclado matricial 4x4 ao Raspberry Pi Pico W.
- Conectar 3 LEDs RGB (utilizando pinos PWM) ao Raspberry Pi Pico W.
- Conectar o buzzer ao Raspberry Pi Pico W.
- Verificar se todas as conexões estão corretas no Wokwi.

### 2. **Programação e Configuração do Teclado Matricial**
**Responsável:** Adson
- Escrever o código para configurar e ler as teclas do teclado matricial 4x4.
- Criar uma função que detecta as teclas pressionadas.
- Testar se o teclado está sendo lido corretamente no código.
- Integrar a leitura das teclas ao fluxo principal do programa.

### 3. **Programação da Função de Controle do LED 1 (RGB)**
**Responsável:** Guilherme Miller 
- Escrever as funções para controlar o LED 1 (RGB), acendendo as cores individualmente.
- Integrar as funções de controle do LED 1 com a detecção de teclas do teclado matricial.
- Testar as cores do LED 1 para garantir o funcionamento correto.
- Documentar o mapeamento das teclas para o controle do LED 1.

### 4. **Programação da Função de Controle do LED 2 (RGB)**
**Responsável:** Dorivaldo 
- Escrever as funções para controlar o LED 2 (RGB), acendendo as cores individualmente.
- Integrar as funções de controle do LED 2 com a detecção de teclas do teclado matricial.
- Testar as cores do LED 2 para garantir o funcionamento correto.
- Documentar o mapeamento das teclas para o controle do LED 2.

### 5. **Programação da Função de Controle do LED 3 (RGB)**
**Responsável:** Isabella  
- Escrever as funções para controlar o LED 3 (RGB), acendendo as cores individualmente.
- Integrar as funções de controle do LED 3 com a detecção de teclas do teclado matricial.
- Testar as cores do LED 3 para garantir o funcionamento correto.
- Documentar o mapeamento das teclas para o controle do LED 3.

### 6. **Programação e Controle do Buzzer**
**Responsável:** Arthur  
- Escrever as funções para acionar e desligar o buzzer, dependendo da tecla pressionada.
- Testar a funcionalidade do buzzer para garantir que ele emite som ao pressionar as teclas configuradas.
- Integrar o controle do buzzer com a leitura do teclado matricial.

### 7. **Integração do Código: Função Principal**
**Responsável:** Ricardo  
- Integrar todas as funções (controle de LEDs, buzzer e teclado) em um único código de execução.
- Escrever a função principal que verifica continuamente o estado das teclas pressionadas e executa as ações correspondentes.
- Garantir que todas as funções de controle dos LEDs e buzzer sejam acionadas corretamente com base nas teclas do teclado matricial.

### 8. **Testes e Validação do Funcionamento do Circuito**
**Responsável:** Ricardo
- Organizar e reestruturar todo o código tornando-o funcional com todas as funções.
- Realizar testes de integração entre o hardware (simulação no Wokwi) e o código.
- Verificar se todas as funções estão respondendo corretamente às teclas pressionadas.
- Testar as cores dos LEDs e o controle do buzzer com a entrada do teclado.
- Identificar e corrigir qualquer erro que surja durante os testes.

### 9. **Documentação e Relatório Final**
**Responsável:** Canila e Jabson 
- Criar a documentação explicando a montagem do circuito no Wokwi, as funções programadas e o mapeamento das teclas.
- Documentar o fluxo do código, destacando as responsabilidades de cada função.
- Elaborar o relatório final com a explicação do processo de desenvolvimento, problemas encontrados e soluções implementadas.
- Organizar o código-fonte de maneira limpa e comentada, para que outras pessoas possam entender facilmente.

---

## **Divisão das tarefas:**

| **Tarefa**                                     | **Responsável**
|------------------------------------------------|------------|
| Organização do Circuito e Diagrama no Wokwi     |Adson            |
| Programação e Configuração do Teclado Matricial |Adson            | 
| Programação do Controle do LED 1                |Guilherme Miller | 
| Programação do Controle do LED 2                |Dorivaldo        | 
| Programação do Controle do LED 3                |Isabella         | 
| Programação e Controle do Buzzer                |Arthur           | 
| Integração do Código: Função Principal          |Ricardo          | 
| Testes e Validação do Funcionamento             |Ricardo          | 
| Documentação e Relatório Final                  |Canila e Jabson  | 

---
## **Link com a produção do vídeo:**
https://youtu.be/fn3x_e9NXnQ

![Projeto](https://github.com/user-attachments/assets/73b4b073-a170-4230-b83e-6b1ae70795ed)

