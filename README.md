# Smart-Health-IoT

##  Contexte

Projet IoT de surveillance du rythme cardiaque en temps réel avec ESP32 et Blynk.

##  Objectifs

- Surveillance BPM
- Affichage temps réel
- Détection anomalies
- Alertes automatiques


##  Architecture

Potentiomètre → ESP32 → WiFi → Blynk Cloud→Alerte


##  Composants utilisés

- ESP32
- Potentiomètre
- Wokwi
- Blynk IoT
- Led

##  Simulation BPM

Le capteur MAX30100 n’étant pas disponible dans Wokwi, nous avons utilisé un potentiomètre pour simuler les BPM.


##  Instructions d’exécution

1. Ouvrir le projet sur Wokwi.

2. Lancer la simulation ESP32.

3. Vérifier la connexion WiFi Wokwi-GUEST.

4. Ouvrir le dashboard Blynk.

5. Observer les valeurs BPM en temps réel.

6. Tourner le potentiomètre pour simuler les variations du rythme cardiaque.

7. Tester les alertes lorsque :
   - BPM < 60
   - BPM > 100
