#define BLYNK_TEMPLATE_ID "TMPL2508bY02T"
#define BLYNK_TEMPLATE_NAME "Smart Health"
#define BLYNK_AUTH_TOKEN "Tt7ivzyCy713nL9mu_Zw6r72Vt6u0M-7"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Potentiomètre
const int potPin = 34;

// LEDs
const int ledVerte = 18;
const int ledRouge = 19;

BlynkTimer timer;

bool alerteActive = false;

void sendSensorData() {

  int potValue = analogRead(potPin);

  // BPM entre 40 et 180
  int bpm = map(potValue, 0, 4095, 40, 180);

  // Envoi vers Blynk
  Blynk.virtualWrite(V0, bpm);

  Serial.print("Rythme cardiaque simulé : ");
  Serial.print(bpm);
  Serial.println(" BPM");

  // BPM NORMAL
  if (bpm >= 60 && bpm <= 100) {

    digitalWrite(ledVerte, HIGH);
    digitalWrite(ledRouge, LOW);

    // Réinitialisation système
    if (alerteActive == true) {

      Serial.println("Rythme revenu à la normale.");
      alerteActive = false;
    }
  }

  // BPM DANGEREUX
  else {

    digitalWrite(ledVerte, LOW);
    digitalWrite(ledRouge, HIGH);

    // Éviter spam notifications
    if (alerteActive == false) {

      Blynk.logEvent(
        "alerte_cardiaque",
        "⚠️ Anomalie ! Rythme : " + String(bpm) + " BPM"
      );

      Serial.println(" ALERTE CRITIQUE ENVOYÉE ");

      alerteActive = true;
    }
  }
}

void setup() {

  Serial.begin(115200);

  // LEDs OUTPUT
  pinMode(ledVerte, OUTPUT);
  pinMode(ledRouge, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(500L, sendSensorData);
}

void loop() {

  Blynk.run();
  timer.run();
}