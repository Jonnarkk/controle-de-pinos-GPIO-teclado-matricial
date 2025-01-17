# Plano de Trabalho: Controle de Pinos GPIO com Teclado Matricial, LEDs e Buzzer

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
**Responsável:** Pessoa 3  
- Escrever as funções para controlar o LED 1 (RGB), acendendo as cores individualmente.
- Integrar as funções de controle do LED 1 com a detecção de teclas do teclado matricial.
- Testar as cores do LED 1 para garantir o funcionamento correto.
- Documentar o mapeamento das teclas para o controle do LED 1.

### 4. **Programação da Função de Controle do LED 2 (RGB)**
**Responsável:** Pessoa 4  
- Escrever as funções para controlar o LED 2 (RGB), acendendo as cores individualmente.
- Integrar as funções de controle do LED 2 com a detecção de teclas do teclado matricial.
- Testar as cores do LED 2 para garantir o funcionamento correto.
- Documentar o mapeamento das teclas para o controle do LED 2.

### 5. **Programação da Função de Controle do LED 3 (RGB)**
**Responsável:** Pessoa 5  
- Escrever as funções para controlar o LED 3 (RGB), acendendo as cores individualmente.
- Integrar as funções de controle do LED 3 com a detecção de teclas do teclado matricial.
- Testar as cores do LED 3 para garantir o funcionamento correto.
- Documentar o mapeamento das teclas para o controle do LED 3.

### 6. **Programação e Controle do Buzzer**
**Responsável:** Pessoa 6  
- Escrever as funções para acionar e desligar o buzzer, dependendo da tecla pressionada.
- Testar a funcionalidade do buzzer para garantir que ele emite som ao pressionar as teclas configuradas.
- Integrar o controle do buzzer com a leitura do teclado matricial.

### 7. **Integração do Código: Função Principal**
**Responsável:** Pessoa 7  
- Integrar todas as funções (controle de LEDs, buzzer e teclado) em um único código de execução.
- Escrever a função principal que verifica continuamente o estado das teclas pressionadas e executa as ações correspondentes.
- Garantir que todas as funções de controle dos LEDs e buzzer sejam acionadas corretamente com base nas teclas do teclado matricial.

### 8. **Testes e Validação do Funcionamento do Circuito**
**Responsável:** Pessoa 8  
- Organizar e reestruturar todo o código tornando-o funcional com todas as funções.
- Realizar testes de integração entre o hardware (simulação no Wokwi) e o código.
- Verificar se todas as funções estão respondendo corretamente às teclas pressionadas.
- Testar as cores dos LEDs e o controle do buzzer com a entrada do teclado.
- Identificar e corrigir qualquer erro que surja durante os testes.

### 9. **Documentação e Relatório Final**
**Responsável:** Pessoa 9  
- Criar a documentação explicando a montagem do circuito no Wokwi, as funções programadas e o mapeamento das teclas.
- Documentar o fluxo do código, destacando as responsabilidades de cada função.
- Elaborar o relatório final com a explicação do processo de desenvolvimento, problemas encontrados e soluções implementadas.
- Organizar o código-fonte de maneira limpa e comentada, para que outras pessoas possam entender facilmente.

---

## **Divisão das tarefas:**

| **Tarefa**                                     | **Responsável**
|------------------------------------------------|------------|
| Organização do Circuito e Diagrama no Wokwi     |Adson      |
| Programação e Configuração do Teclado Matricial |Adson      | 
| Programação do Controle do LED 1                |           | 
| Programação do Controle do LED 2                |           | 
| Programação do Controle do LED 3                |           | 
| Programação e Controle do Buzzer                |           | 
| Integração do Código: Função Principal          |           | 
| Testes e Validação do Funcionamento             |           | 
| Documentação e Relatório Final                  |           | 

---


