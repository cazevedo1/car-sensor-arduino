# \# Arduino Car Sensor Project

Projeto usando Arduino para simular um sensor de ré de uma automóvel.

### \## Componentes

* Sensor Ultrassônico - HCSR04
* Leds
* Tela LCD 16x2 I2C
* Buzzer

### \## Funcionamento



Ao sensor ultrassônico captar a distância mais próxima a sua frente ele seguirá o padrão de:

- Distância maior que 30cm:
    * Imprime a distância na tela LCD
    * Todos os leds apagados

- Distância entre 21 e 30cm:
    * Imprime a distância na tela LCD
    * Led verde acesso
    * Mensagem personalizada

- Distância entre 11 e 30cm:
    * Imprime a distância na tela LCD
    * Led amarelo acesso
    * Mensagem personalizada
    * Buzzer emite som

- Distância menor que 11cm:
    * Imprime a distância na tela LCD
    * Led vermelho acesso
    * Mensagem personalizada
    * Buzzer emite som


### \## Autor

Carlos Caetano
LinkedIn: www.linkedin.com/in/carlosazecaetano

