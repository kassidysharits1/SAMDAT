# SAMDAT
The goal of this project is to create a semi-autonomous magnetics data acquisition tool (SAMDAT). With the advancement of drones in the geophysics industry, quicker and more efficient geophysical surveys have become a reality, especially in areas with difficult terrain to walk heavy equipment for hours. Of course, there are many restrictions with drone usage, and it may not always be applicable to use drones for your survey. Another possibility for quick and efficient surveying would be to use an autonomous or semi-autonomous vehicle or “rover”. We see these being used on other planets, however in the geophysics industry on Earth this is not seen often. This project will aim to create a semi- autonomous tool to collect magnetic data. The goal is for the final product to be relatively low cost and to hopefully have the ability to be used for other geophysical applications with a selection of sensors. 

# Equipment
- Magnetic Fluxgate (https://www.mouser.com/ProductDetail/Texas-Instruments/DRV425EVM?qs=yajEpaT76uTkcWWoySodDw%3D%3D&mgh=1&gclid=Cj0KCQjwxtSSBhDYARIsAEn0thRVnLII2vq4DKnGoKh8iU-lrGUxeFzoDiNuYIRZ3_PHS2sOGBCqnD4aAnOFEALw_wcB) 
- Robotics Kits Robot Car Kit-6WD Off-Road Chassis (https://www.electromaker.io/shop/product/robot-car-kit-6wd-off-road-chassis) 
- Arduino Mega 2560 (https://store-usa.arduino.cc/products/arduino-mega-2560-rev3?selectedStore=us)
- Motor Driver (https://create.arduino.cc/projecthub/ryanchan/how-to-use-the-l298n-motor-driver-b124c5)
- Battery to power car (https://hobbyking.com/en_us/turnigy-5000mah-3s-20c-lipo-pack-xt-90.html?wrh_pdp=2&utm_source=google&utm_medium=cpc&utm_campaign=google_us_shopping&countrycode=US&gclid=CjwKCAjwu_mSBhAYEiwA5BBmf9hNaCIyZdIzoVELx6cEg9BdRALHj29-YBhEXm_Waaq41nGKFEynphoCsN4QAvD_BwE)
- 9V batteries for arduinos 
- 

# Design
### Magnetometer
Connections: 
![mag_img](https://user-images.githubusercontent.com/103535565/164091672-be7d88c6-635e-4af5-af32-a8f0ed0f74d8.png)
Figure: Magnetic Fluxgate Top View
![diagram_mag](https://user-images.githubusercontent.com/103535565/164091989-8241e264-c293-4d68-9656-0c15013473b7.png)
Figure: Schematic of Magnetic Fluxgate


### Attaching the magnetometer at a safe distance
Because the robotic car and the arduinos are magnetic, the magnetic fluxgate needs to be suspended a safe distance from this equipment so that it does not pick up these magnetic anomalies and thus recording false anomalies. This was accounted for by 3D-printing a small rod that can be attached to the robotic car platform and extends roughly 5 inches out. We completed some testing with the magnetic fluxgate and the platform and found that magnetic fluxgate reports steady values once it is 5 inches away from the platform. We tested this while running the motor since this does produce a slightly larger anomaly.

https://user-images.githubusercontent.com/103535565/163262615-a055875f-b65d-4c38-8e55-ccc3797bc589.MOV


# Video
We can make a video showing it in action here...

# Improvements
There are many improvements that can be made and this project has many future potentials... 
Add a surveyor's wheel for better precision 

There is large potential with this project to be applied to other geophysical problems using various sensors. By making interchangeable attachments, there is the potential to use other geophysical equipment. 
