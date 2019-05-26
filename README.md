# Smartphone Confiscator
My son : "The reason of my poorly grade at school is due to smatphone!"

46nori : "OK, I'm gonna make a machine confiscating your phone!!"

## Features
* Lock the box for the specific period of time.
* Emergency unlocking via Internet by IFTTT widget.

## Hardware
* Particle Photon
  * https://docs.particle.io/photon/
  * STM32F205 120Mhz ARM Cortex M3
  * 1MB flash, 128KB RAM
  * Battery backup
  * WiFi 802.11b/g/n
* SC1602BSLB-XA-GB-K
  * LCD Display (16x2 characters)
    http://akizukidenshi.com/download/ds/sunlike/SC1602BSLB-XA-GB-K_20181119.pdf
* 4 buttons for configuration
* 5V external power supply

## How to use
1. Open the tray and put the smartphone. (You can put anything actually.)
2. Set countdown timer. (Hour and minutes up to 24hour 59minutes.)
3. Push the start button.
4. Tray will be locked, and remaining time is shown.
5. Tray will be unlocked when the countdown timer is expired.

Emegency unlock widget (IFTTT) is able to unlock in anytime. (But it is owned only by parents. :-P )

## Screenshots

![Front view](https://github.com/46nori/SmartphoneConfiscator/blob/master/doc/images/front.JPG)

![Rear view](https://github.com/46nori/SmartphoneConfiscator/blob/master/doc/images/rear.JPG)

![Particle Photon](https://github.com/46nori/SmartphoneConfiscator/blob/master/doc/images/photon.JPG)

![IFTTT Widget for Emergency Unlock](https://github.com/46nori/SmartphoneConfiscator/blob/master/doc/images/widget.PNG)
