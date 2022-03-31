# Вступительное испытание по алгоритмам на кафедру 1С

**Задача  № 211:**
---
Необходимо реализовать эффективный алгоритм поиска по строке в очень большом текстовом файле.
Файл загружается один раз, потом происходит большое количество запросов на поиск.
___
**Формат входных данных:**
    
На вход подается путь до файла (можно абсолютный). Затем вводится натуральное число K - количество запросов.
После этого в каждой из K строк вводится подстрока, поиск которой будет выполняться.

Важное уточнение: Алгоритм чувствителен к регистру, поэтому по запросу Harry в книге "Гарри Поттер" будет меньше результатов, чем выдаст поиск Ctrl+F по файлу, который не чувствителен к регистру.


Пример ввода: 
/home/sonches/1C_admission/tests/HarryPotter.txt

2

Harry

Potter
___

**Формат выходных данных:**

На вывод подается сперва контекст первого включения (если оно есть) подстроки в текст. Затем выводится общий подсчет количества вхождений данной подстроки в текст.

___
**Алгоритм решения:**
---

1) Будем использовать Префикс-функцию и ее модификацию, обе из которых работают за линию.

2) С помощью обычной префикс функции сначала насчитаем значения функции для искомой подстроки и сохраним эти значения.

3) Затем будем посимвольно проходиться по файлу (важное уточнение: файл подгружается только 1 раз, затем просто происходит сброс итерации), и применять модифицированную префикс-функцию, которая будет принимать только саму подстроку, массив ее префикс-функции, предыдущее значение префикс функции для ТЕКСТА и новый символ текста. Заметим, что нам не надо хранить массив префикс-функции для текста, ибо из-за того, что мы ограничиваем значения функции от 0 до длины подстроки, опираться мы все равно будем на значения префикс-функции от самой подстроки (смотрим пред. значение префикс-функции для текста и работаем как в обычной префикс функции).
4) После этого, если вхождение было найдено и оно первое - выводим контекст, если просто нашли значение - увеличиваем счетчик.


Итоговая асимптотика времени - O(K * len(text))


___
**Тесты:**
---

В ветке master находятся файлы main.cpp и testing.cpp
Через запуск файла main.cpp можно тестировать свои примеры.
В файле testing.cpp находятся тесты по найденным мною 4 файлам. Все правильные ответы находятся в файле constants.h, а подтверждения этим файлам - в папке tests/img, где лежат скриншоты с поиском по файлам с помощью Cntl+F.
