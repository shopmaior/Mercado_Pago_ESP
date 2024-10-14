#include <Mercado_Pago_ESP.h>
#include <WiFi.h>

const String accessToken = "SEU_ACCESS_TOKEN";
Mercado_Pago_ESP mercadoPago(accessToken);

void setup() {
    Serial.begin(115200);
    if (WiFi.status() != WL_CONNECTED) {
        WiFi.begin("SSID", "PASSWORD");
        while (WiFi.status() != WL_CONNECTED) {
            delay(1000);
            Serial.println("Conectando ao WiFi...");
        }
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Conectado ao WiFi.");
    }

    String userID = "SEU_USER_ID";
    String posID = "default";
    String jsonPayload = R"(
    {
        "external_reference": "coffee_001",
        "title": "Coffee Credit",
        "description": "Coffee Credit.",
        "notification_url": "https://yourdomain.com/notifications",
        "total_amount": 1.99,
        "items": [
            {
                "sku_number": "5116392062",
                "category": "drink",
                "title": "Coffee P",
                "description": "This is the Coffee P",
                "unit_price": 1.99,
                "quantity": 1,
                "unit_measure": "unit",
                "total_amount": 1.99
            }
        ]
    })";

    // Chama a função para criar o QR Code dinâmico
    String qrCodeResponse = mercadoPago.createDynamicQRCode(userID, posID, jsonPayload);
    if (!qrCodeResponse.isEmpty()) {
        Serial.println("QR Code dinâmico criado com sucesso.");
        Serial.println("Resposta da API:");
        Serial.println(qrCodeResponse);
    } else {
        Serial.println("Falha ao criar QR Code dinâmico.");
    }
}

void loop() {
    // put your main code here, to run repeatedly
}
