# ASOLED
Библиотека для i2c 128х64 OLED дисплея на базе SSD1306.
Ветка на форуме, где была выложена автором: http://arduino.ru/forum/programmirovanie/kirillitsa-na-displee-ili-chto-ya-delayu-ne-tak
Новая версия от автора: http://arduino.ru/forum/proekty/asoled-kompaktnaya-biblioteka-dlya-oled-displeya-128kh64-s-kirillitsei-utf-8
Datasheet на контроллер дисплея: https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf

Создание библиотеки преследовало две цели:
1. Добиться, чтобы без всекого шаманства что мы видим на экране в Arduino IDE, то же было на дисплее.
2. Уменьшить расход оперативной памяти при использовании библиотеки.

Вторая цель достигнута за счет отказа от экранного буфера в оперативной памяти. И, соответственно, вынужденного отказа от пиксельной графики: библиотека может выводить только текст или битмап. При этом высота как текста, так и битмапа должна нацело делиться на 8, а Y-координата также должна быть кратна 8. Это - плата за экономию памяти. Исправить это нельзя, если указанные ограничения критичны, пользуйтесь другой библиотекой - с экранным буфером объемом 1 киб.

В последней версии (0.4) добавлено
1. переключение ориентации (нормальный и кверху тормашками)
2. поддержка строк из PROGMEM
3. установка скорости для Arduino Due
4. добавлена поддержка 1.3" OLED SH1106
 
Комментарии:
1. В Arduino почему-то считается, что экран должен располагаться так, чтобы пины были сверху дисплея. А производитель дисплея, наоборот, сделал режимом по умолчанию тот, где пины снизу. И последнее логично: при раз0мещении экрана на лицевой панели совместно с другими органами управления более благоприятное расположение дисплея именно такое. Поэтому кроме "прямного" режима сделан "кверху тормашками" - какждый сам выбирает, как сориентировать дисплей в своей конструкции.
2. Собственно, теперь можно располагать строковые константы в PROGMEM: F("Моя новая строка")
3. Библиотека для увеличения скорости работы переключает шину I2C со стандлартных 100 кГц на 400 кГц. Теперь и для Arduino Due - тоже. Скажу по секрету: я добился устойчивой работы этой библиотеки на Arduino Due с имеющимся у меня дисплеем на 2 МГц.
4. Для подключения такого дисплея нужно раскомментировать одну строку в ASOLED.h. Если этого не сделать, то, в принципе, работать все равно будет - но со сдвижкой на 2 пиксела вправо.
