#ifndef MERCADO_PAGO_ESP_H
#define MERCADO_PAGO_ESP_H

#include <Arduino.h>

class Mercado_Pago_ESP {
public:
    Mercado_Pago_ESP(const String& accessToken);
    bool createPayment(const String& paymentData);
    String getPaymentStatus(const String& paymentID);
    String createPaymentQRCode(const String& userID, const String& externalID, const String& paymentData);
    String createDynamicQRCode(const String& collectorID, const String& posID, const String& jsonPayload);

private:
    String _accessToken;
    String sendRequest(const String& url, const String& payload);
};

#endif
