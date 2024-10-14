#include "Mercado_Pago_ESP.h"
// #include <ESP8266HTTPClient.h>
// #include <HTTPClient.h>

#if defined(ESP8266)
    #include <ESP8266HTTPClient.h>
#elif defined(ESP32)
    #include <HTTPClient.h>
#else
    #error "This ain't a ESP8266 or ESP32"
#endif

Mercado_Pago_ESP::Mercado_Pago_ESP(const String& accessToken)
    : _accessToken(accessToken) {}

bool Mercado_Pago_ESP::createPayment(const String& paymentData) {
    String url = "https://api.mercadopago.com/v1/payments?access_token=" + _accessToken;
    String response = sendRequest(url, paymentData);
    return !response.isEmpty();
}

String Mercado_Pago_ESP::getPaymentStatus(const String& paymentID) {
    String url = "https://api.mercadopago.com/v1/payments/" + paymentID + "?access_token=" + _accessToken;
    return sendRequest(url, "");
}

String Mercado_Pago_ESP::createPaymentQRCode(const String& userID, const String& externalID, const String& paymentData) {
    String url = "https://api.mercadopago.com/mpmobile/instore/qr/" + userID + "/" + externalID + "?access_token=" + _accessToken;
    String response = sendRequest(url, paymentData);
    return response; // Retorna a resposta da API para ser manipulada
}

String Mercado_Pago_ESP::createDynamicQRCode(const String& collectorID, const String& posID, const String& jsonPayload) {
    String url = "https://api.mercadopago.com/instore/orders/qr/seller/collectors/" + collectorID + "/pos/" + posID + "/qrs?access_token=" + _accessToken;
    return sendRequest(url, jsonPayload);
}

String Mercado_Pago_ESP::sendRequest(const String& url, const String& payload) {
    HTTPClient http;
    http.begin(url);
    String response = "";

    if (!payload.isEmpty()) {
        http.addHeader("Content-Type", "application/json");
        int httpCode = http.POST(payload);
        if (httpCode > 0) {
            response = http.getString();
            Serial.printf("HTTP POST Status Code: %d\n", httpCode);
        } else {
            Serial.printf("Erro ao enviar requisição POST: %s\n", http.errorToString(httpCode).c_str());
        }
    } else {
        int httpCode = http.GET();
        if (httpCode > 0) {
            response = http.getString();
            Serial.printf("HTTP GET Status Code: %d\n", httpCode);
        } else {
            Serial.printf("Erro ao enviar requisição GET: %s\n", http.errorToString(httpCode).c_str());
        }
    }

    http.end();
    return response;
}