/**************************************************************

    "iSpindel"
    changes by S.Lang <universam@web.de>

 **************************************************************/

#ifndef _SENDER_H_
#define _SENDER_H_

#include "Globals.h"

#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <MD5Builder.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

class SenderClass
{
public:
  SenderClass();
  String sendTCP(String server, uint16_t port = 80);
  bool sendThingSpeak(String token, long Channel);
  bool sendGenericPost(String server, String uri, uint16_t port = 80);
  bool sendHTTPSPost(String server, String uri);
  bool sendInfluxDB(String server, uint16_t port, String db, String name, String username, String password);
  bool sendPrometheus(String server, uint16_t port, String job, String instance);
  bool sendUbidots(String token, String name);
  bool sendMQTT(String server, uint16_t port, String username, String password, String name);
  bool sendFHEM(String server, uint16_t port, String name);
  bool sendTCONTROL(String server, uint16_t port);
  bool sendBlynk(char* token);
  bool sendBrewblox(String server, uint16_t port, String topic, String username, String password, String name);
#if API_MQTT_HASSIO
  bool enableHassioDiscovery(String server, uint16_t port, String username, String password, String name, String unit);
  bool disableHassioDiscovery(String server, uint16_t port, String username, String password, String name);
#endif
  bool sendSecureMQTT(char CACert[], char deviceCert[], char deviceKey[], String server, uint16_t port, String name, String topic);    //AWS
  uint32_t sendBricks();
  void add(String id, float value);
  void add(String id, String value);
  void add(String id, int32_t value);
  void add(String id, uint32_t value);
  String createMd5Hash(String input);
  void stopclient();
  bool RTCSyncToNTP();
  void mqttCallback(char *topic, byte *payload, unsigned int length);
  bool mqttConnect(const String &server, uint16_t port, const String &name, const String &username, const String &password, const bool secure = false, const char CACert[] = "", const char deviceCert[] = "", const char deviceKey[] = "");
  // ~SenderClass();

private:
  WiFiClient _client;
  PubSubClient _mqttClient;
  StaticJsonDocument<512> _doc;
  WiFiClientSecure _secureClient;
  MD5Builder _md5;
};

#endif
