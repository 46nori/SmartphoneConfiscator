# Smartphone Confiscator
My son : "The reason of my poorly grade at school is due to smartphone!"

46nori : "OK, I'm gonna make a machine confiscating your phone!!"

## Features
* Lock the box for the specific period of time.
* Emergency unlocking via Internet by IFTTT widget.

## Hardware
* [Particle Photon](https://docs.particle.io/photon/)
  * STM32F205 120Mhz ARM Cortex M3
  * 1MB flash, 128KB RAM
  * Battery backup
  * WiFi 802.11b/g/n
* Servo Motor : [SG-90](http://akizukidenshi.com/download/ds/towerpro/SG90_a.pdf)
* LCD Display (16x2 characters) : [SC1602BSLB-XA-GB-K](http://akizukidenshi.com/download/ds/sunlike/SC1602BSLB-XA-GB-K_20181119.pdf)
* 4 buttons for configuration
* 5V external power supply
* Acrylic Box : [MUJI 無印良品 / 重なるアクリルケース２段フタ付引出・大](https://www.muji.net/store/cmdty/detail/4549738970125?searchno=5&sectionCode=S200280101)

## How to use
1. Open the tray and put the smartphone. (You can put anything actually.)
2. Set countdown timer. (Hour and minutes up to 24hour 59minutes.)
3. Push the start button.
4. Tray will be locked, and remaining time is shown.
5. Tray will be unlocked when the countdown timer is expired.

* Emegency unlock widget (IFTTT) is able to unlock in anytime. (But it is only owned by parents. :-P )

## How to build & run
* You need to create a Particle account in advance.
* Your Photon needs to have been set up and connected to Particle server by WiFi. 

1. Open [Particle IDE](https://build.particle.io/build/new) on Web Browser.
2. Create files in the src/. And copy & paste the each content of files. 
3. Push build button on IDE.
4. Push flash button on IDE so that download the  firmware onto your Photon.

## To Do
* To equip the sensor in order to prevent from locking at incorrect position of tray.
  * Hall effect sensor or photo reflector is candidate.
  * To implement ```bool UISTMBridge::IsCaseClosed()``` as return true if the tray position is correct.

## Screenshots
**Front View**  
Button Layout
- White Button: Up / Down
- Blue Button: Mode
- Red Button: Set  
![Front view](https://github.com/46nori/SmartphoneConfiscator/blob/master/doc/images/front.JPG)

**Rear View**  
5V AC Adopter outlet  
![Rear view](https://github.com/46nori/SmartphoneConfiscator/blob/master/doc/images/rear.JPG)

**Particle Photon and LCD module**  
![Particle Photon](https://github.com/46nori/SmartphoneConfiscator/blob/master/doc/images/photon.JPG)

**IFTTT widget**  
Button WIdget and Particle Service  
![IFTTT Widget for Emergency Unlock](https://github.com/46nori/SmartphoneConfiscator/blob/master/doc/images/widget.PNG)
