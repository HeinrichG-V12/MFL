## Interface für das BMW Multifuktionslenkrad
Kompatibel mit allen BMW MFL, die einen 8-bit Bus verwenden und folgende Belegung haben:
- +12v
- IBus
- Tempomatausgang
- Masse

###Die 16-bit Modelle haben dagegen diese Belegung:
- +12v
- Tastenbeleuchtung
- Datenausgang
- Masse

#####Zu erkennen ist die 16-bit Version auch daran, dass das Fahrzeug zusätzlich ein MFL-Modul verbaut hat.

###Verwendete Bauteile:
- MCU: Microchip Atmega2561
- Spannungsregler: Infineon TLE42754
- IBus-Transceiver: Elmos E910.15
- ADC-Beschaltung: hochohmiger Eingang mit Microchip MCP601 Puffer
- Digital Poti: Microchip MCP42050
- RS-232 Interface: TI MAX232

###Es können folgende Radios gesteuert werden:
- Pioneer/Sony/JVC mit eine RW Eingang
- Becker mit einem RS232 Eingang