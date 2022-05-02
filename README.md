# SAMDAT
<img src="https://user-images.githubusercontent.com/103535565/165619637-e3b8099c-63ee-4036-9353-330022a70ceb.jpg" width="300">



The goal of this project is to create a semi-autonomous magnetics data acquisition tool (SAMDAT). The use of a semi-autonomous vehicle for geophysical data acquisition yields the possibility for quick and efficient surveying. We see rovers being used on other planets, however in the geophysics industry on Earth this is not seen often. This project will aim to create a semi- autonomous tool to collect magnetic data. The goal is for the final product to be relatively low cost and to hopefully have the ability to be used for other geophysical applications with a selection of sensors. 

# Equipment
- Magnetic Fluxgate (https://www.mouser.com/ProductDetail/Texas-Instruments/DRV425EVM?qs=yajEpaT76uTkcWWoySodDw%3D%3D&mgh=1&gclid=Cj0KCQjwxtSSBhDYARIsAEn0thRVnLII2vq4DKnGoKh8iU-lrGUxeFzoDiNuYIRZ3_PHS2sOGBCqnD4aAnOFEALw_wcB) 
- GPS (https://www.openimpulse.com/blog/products-page/product-category/gy-neo6mv2-gps-module/) 
- Robotics Kits Robot Car Kit-6WD Off-Road Chassis (https://www.electromaker.io/shop/product/robot-car-kit-6wd-off-road-chassis) 
- Arduino Mega 2560 (2) (https://store-usa.arduino.cc/products/arduino-mega-2560-rev3?selectedStore=us)
- Ethernet Shield (https://www.amazon.com/SunFounder-Ethernet-Shield-W5100-Arduino/dp/B00HG82V1A/ref=asc_df_B00HG82V1A/?tag=hyprod-20&linkCode=df0&hvadid=309776868400&hvpos=&hvnetw=g&hvrand=204336615774606264&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9028824&hvtargid=pla-404289809670&psc=1)
- Micro SD
- Motor Driver (2-3) (https://create.arduino.cc/projecthub/ryanchan/how-to-use-the-l298n-motor-driver-b124c5)
- Battery to power car (https://hobbyking.com/en_us/turnigy-5000mah-3s-20c-lipo-pack-xt-90.html?wrh_pdp=2&utm_source=google&utm_medium=cpc&utm_campaign=google_us_shopping&countrycode=US&gclid=CjwKCAjwu_mSBhAYEiwA5BBmf9hNaCIyZdIzoVELx6cEg9BdRALHj29-YBhEXm_Waaq41nGKFEynphoCsN4QAvD_BwE)
- 9V batteries for arduinos 
- Connectors for batteries, arduinos, sensors
- 3D printed magnetometer extender 

# Estimated Cost Analysis:
Below lists the approximated cost of equipment, this parts list assumes buying one sensor as opposed to discounted builk deliveries and does not include tax and shipping. Note that we bought the sensors and arduinos in bulk and therefore our project was a bit less than this cost analysis.
- Robotics Kit: $99.90
- Magnetic Fluxgate: $24
- Arduino Mega: $35.93 (2)
- Ethernet Shield: $20.99
- Micro SD: $9
- Motor Driver: $6.99 (3)
- Battery: $20.89
- 9V batteries: $2 (2)
- GPS: 


Total: $271.61

# Design
### Robotic Car Kit
Youtube video linked below with a walk through assembly for the 6 WD High Speed Crawler Robot Chassis with Suspension:
https://www.youtube.com/watch?v=SU6XHG54L_c 


Building guide linked below with equipment and build pictures:
https://raw.githubusercontent.com/SeeedDocument/Outsourcing/master/6WD/Robot%20Car%20Kit-6WD%20Off-Road%20Chassis%20Kit%20Guide%20EN%20V1.0.pdf 


### Motor Driver
Note that we are not using a 9V battery, the battery to power the car is being used here.
![driver](https://user-images.githubusercontent.com/103535565/164105223-9fe2444b-2959-419b-9bd1-f1e9fb3f1ce8.png)
Figure: Schematic of motor driver

![Drive System Diagram](https://user-images.githubusercontent.com/104653490/166325154-eeae1fd4-4503-4b32-a7d5-58df1bd26b33.png)


### Magnetic Fluxgate 
Connections: 
- top connection goes to REFOUT
- second connection goes to VOUT
- third connection goes to ground
- fourth connection not used
![mag_img](https://user-images.githubusercontent.com/103535565/164091672-be7d88c6-635e-4af5-af32-a8f0ed0f74d8.png)
Figure: Magnetic Fluxgate Top View
![diagram_mag](https://user-images.githubusercontent.com/103535565/164091989-8241e264-c293-4d68-9656-0c15013473b7.png)
Figure: Schematic of Magnetic Fluxgate


### Attaching the magnetometer at a safe distance
Because the robotic car and the arduinos are magnetic, the magnetic fluxgate needs to be suspended a safe distance from this equipment so that it does not pick up these magnetic anomalies and thus recording false anomalies. This was accounted for by 3D-printing a small rod that can be attached to the robotic car platform and extends roughly 5 inches out. We completed some testing with the magnetic fluxgate and the platform and found that magnetic fluxgate reports steady values once it is 5 inches away from the platform. We tested this while running the motor since this does produce a slightly larger anomaly. We decided to give 10 inches for extra measure. 

https://user-images.githubusercontent.com/103535565/163262615-a055875f-b65d-4c38-8e55-ccc3797bc589.MOV

### GPS
Still need to find schematic for gps...

### 3D Printed Magnetometer Extender
Attached is the solid works file for the 10 inch 3D printed rod that extends from the car. 


# Test Survey
show video and data? 

# Video
Below shows a video of SAMDAT in action on the Colorado School of Mines campus. 

https://user-images.githubusercontent.com/103535565/165623426-cf573f2c-155d-4962-ba4c-ab2bb2be90a3.mov

# Improvements and Potentials
There is large potential with this project to be applied to other geophysical problems using various sensors. By making interchangeable attachments, there is the potential to use other geophysical equipment. The 3D printed rod we attached for the magnetometer is removable and could be replaced with an attached cart that can hold various equipment. 

Specific Recommended improvements:

- Include Bluetooth activation so you can control from your phone as apposed to presetting code to drive the survey lines.
  - Recommended bluetooth device for apple products: HM-10 Bluetooth
- Add a surveyor's wheel for better distance precision/accuracy
- Improve weight distribution: the rover currently drives slightly crooked because the weight is not distributed evenly (mainly the heavy battery causing these issues).


