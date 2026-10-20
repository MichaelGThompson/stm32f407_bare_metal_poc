# stm32f407_bare_metal_poc
(Multi producer, single consumer bare metal project)

Board used: STM32F407 Black Board (connected to MacBook Pro via J-Link)
OS: None (bare metal-ish...used HAL rather than bit banging registers)

This application has two producers (a potentiometer-controlled voltage to be converted by a peripheral ADC and am onboard button) and one consumer (the main loop). Values from the producers (both interrupt-driven) are added to an event queue and the main loop dequeues events & passes them to a dispatcher. The dispatcher forwards the event to the appropriate handler. The ADC voltage is used to control the duty cycle of a PWM signal. The button presses display two LEDs according to the current state. 

(view of the cheap oscilloscope and board!)
<img width="3024" height="4032" alt="IMG_5869" src="https://github.com/user-attachments/assets/0321a507-20e2-4cfb-a150-d205a0823fdc" />

(PWM signal responding to adjusting the potentiometer)
https://github.com/user-attachments/assets/457f88d0-b375-4ec4-b481-7d1ae8239560


