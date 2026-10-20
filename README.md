# stm32f407_bare_metal_poc
(Multi producer, single consumer bare metal project)

Board used: STM32F407 Black Board
OS: None (bare metal-ish...used HAL rather than bit banging registers)

This application has two producers (a potentiometer-controlled voltage to be converted by a peripheral ADC and am onboard button) and one consumer (the main loop). Values from the producers (both interrupt-driven) are added to an event queue and the main loop dequeues events & passes them to a dispatcher. The dispatcher forwards the event to the appropriate handler. The ADC voltage is used to control the duty cycle of a PWM signal. The button presses display two LEDs according to the current state.




