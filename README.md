Данный проект предназначен для упрощения контроля за уровнем освещённости в доме. Данная задача является актуальной, потому что, во-первых, степень освещения важна для здоровья глаз. Во-вторых, правильно подобранный уровень освещения позволяет существенно сэкономить бюджет. Также система позволяет осуществлять контроль удалённо. В зависимости от уровня яркости освещения, при его недостатке будет загораться одна из трёх лампочек (при уровне до 500 – левая, от 500 до 600 – средняя, от 600 — правая).
Состав репозитория:
1. description.txt - содержит описание проекта
2. Scheme.png - схема устройства, базирующегося на Arduino Uno, устройство содержит фоторезистор, Wi-Fi модуль ESP8266, 
3. lightlevel.ino - скетч-файл для Arduino IDE, содержит часть прошивки Wi-Fi
4. results.py - содержит код веб-страницы, позволяющей пройти аутентификацию и показывающей график уровня освещённости со значением на шкале
