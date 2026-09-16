# Smart HVAC Firmware

This is a rebuild of the firmware for my B.Eng final-year project at Afe Babalola University (2024), "Development of a Smart HVAC System". The original code was lost, so I am rewriting it from the design in my project report.

# What the project does

The prototype is a model office split into four zones, each with its own fan. An ESP32-CAM above the model runs a machine learning model (trained in Edge Impulse) that counts the people in each zone. It sends the counts to an Arduino Nano, which sets each fan's speed based on how many people are in that zone. Empty zones get no airflow, which saves energy.

# Fan speed logic

Each zone's fan speed depends on how many people are in that zone. More people produce more heat, so the fan runs faster.

The Arduino controls fan speed using PWM (pulse width modulation). It switches the power to the fan on and off very quickly, and the value from 0 to 255 sets how much of the time the power is on:

- 0 means the fan is always off.
- 255 means the fan is always on (full speed).
- Values in between give partial speeds.

| Occupants in zone | PWM value | Approximate speed |
|---|---|---|
| 0 | 0 | Off |
| 1 | 64 | 25% |
| 2 | 128 | 50% |
| 3 | 192 | 75% |
| 4 or more | 255 | 100% |

Each extra person adds about 25% to the fan speed, up to full speed at four people. Each zone is controlled separately, so a busy zone can run at full speed while an empty

## Hardware

- Arduino Nano (ATmega328P)
- ESP32-CAM
- 2 × L298N motor drivers
- 4 × 5 V DC fans
- 0.96" OLED display
- Push button
