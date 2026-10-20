# stm32f407_bare_metal_poc
(Multi producer, single consumer bare metal project)

Board used: STM32F407 Black Board
OS: None (bare metal-ish...used HAL rather than bit banging registers)

This application has two producers (a potentiometer-controlled voltage to be converted by a peripheral ADC and am onboard button) and one consumer (the main loop). Values from the producers (both interrupt-driven) are added to an event queue and the main loop dequeues events & passes them to a dispatcher. The dispatcher forwards the event to the appropriate handler. The ADC voltage is used to control the duty cycle of a PWM signal. The button presses display two LEDs according to the current state.



https://github.com/user-attachments/assets/a7469d52-3ede-48bd-ac71-3242aea4c4c2

<img width="3024" height="4032" alt="IMG_5869" src="https://github.com/user-attachments/assets/0321a507-20e2-4cfb-a150-d205a0823fdc" />
<img width="3024" height="4032" alt="IMG_5870" src="https://github.com/user-attachments/assets/4f071056-7c21-4aea-980a-afd5d0a10a7d" />


