# Mercado_Pago_ESP

Biblioteca para Arduino ESP8266/ESP32

## Objetivo

A biblioteca **Mercado_Pago_ESP** tem como objetivo facilitar a integração com o Mercado Pago em dispositivos Arduino ESP8266 e ESP32, servindo como SDK para desenvolvedores que buscam integrar soluções de pagamento de forma simples e eficiente.

## Funcionalidades

- Suporte a ESP8266 e ESP32.
- Integração com a API do Mercado Pago.
- Funcionalidades básicas de pagamento, como criação de transações, consultas e cancelamentos.
- Facilita a autenticação e envio de requisições HTTP para o Mercado Pago.
  
## Instalação

1. Clone este repositório:
   ```bash
   git clone https://github.com/shopmaior/Mercado_Pago_ESP.git
   ```
2. Adicione a biblioteca ao Arduino IDE:
- Abra o Arduino IDE.
- Vá em Sketch > Incluir Biblioteca > Adicionar Biblioteca ZIP.
- Selecione a pasta clonada do repositório.

## Exemplo de Uso
  ```cpp
#include <Mercado_Pago_ESP.h>

void setup() {
    // Inicialize a conexão Wi-Fi e a biblioteca Mercado Pago
    WiFi.begin("SSID", "SENHA");
    MercadoPago.begin("ACESS_TOKEN");
}

void loop() {
    // Crie uma transação simples
    auto response = MercadoPago.createPayment(1000, "Descrição do produto");
    
    if (response.success) {
        Serial.println("Pagamento criado com sucesso!");
    } else {
        Serial.println("Erro ao criar o pagamento.");
    }
}
  ```

## Dependências
- ESP8266WiFi ou WiFi (dependendo do dispositivo).
- Bibliotecas HTTPClient para realizar requisições HTTP.

## Contribuindo
Sinta-se à vontade para contribuir com este projeto. Por favor, envie pull requests ou abra issues para sugerir melhorias. Leia o arquivo [CONTRIBUTING](./CONTRIBUTING.md).

## Licença
Este projeto está licenciado sob a licença XXX. Consulte o arquivo LICENSE para mais detalhes.

