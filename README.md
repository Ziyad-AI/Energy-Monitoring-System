# Energy-Monitoring-System
Arduino-based smart energy monitoring system that measures voltage, current, and power with overload alert.
## 🔌 Hardware Connections

### Voltage Input (Potentiometer)
| Pin | Arduino |
|-----|---------|
| Middle | A0 |
| Side | 5V |
| Side | GND |

### Current Sensor (ACS712)
| Pin | Arduino |
|-----|---------|
| VCC | 5V |
| GND | GND |
| OUT | A1 |

### I2C LCD
| Pin | Arduino |
|-----|---------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### Buzzer
| Pin | Arduino |
|-----|---------|
| + | D8 |
| - | GND |
