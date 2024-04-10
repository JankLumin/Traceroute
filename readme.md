# Утилита Traceroute (для Linux)
 Данная утилита предназначена для получения пути до заданного адреса на операционной системе Linux, для своей работы она использует ICMP Echo Request.
## Сборка и запуск
### Требования
- Компилятор g++
- Библиотеки Google Test (для сборки и запуска тестов)
## Сборка утилиты Traceroute
```sh
g++ -c main.cpp -o main.o
g++ -c functions.cpp -o functions.o
g++ functions.o main.o -o traceroute 
```
## Запуск утилиты Traceroute
Для корректной работы программы запускайте ее от имени суперпользователя:
```sh
sudo ./traceroute
```
## Флаги компиляции
При сборке утилиты Traceroute вы можете использовать несколько флагов для регулирования работы программы:

- `-f`: Позволяет выбрать начальное значение TTL.
  ```sh
  traceroute -f 5 example.com
  ```
- `-m`: Позволяет поставить максимальное значение TTL.
-   ```sh
    traceroute -m 15 example.com
    ```
- `--help`: Выводит диалоговое окно для помощи и получения информации.
- ```sh
  traceroute --help
  ```
## Пример использования
  ```sh
  sudo ./traceroute example.com
  ```
## Пример вывода программы
```sh
Tracing route to 93.184.216.34
1 10.96.0.1  (_gateway) Time: 114.955 ms 10.96.0.1  (_gateway) Time: 115.219 ms 10.96.0.1  (_gateway) Time: 127.799 ms
2 185.183.33.2  Time: 115.293 ms 185.183.33.2  Time: 115.489 ms 185.183.33.2  Time: 115.436 ms
3 109.236.95.142  Time: 117.184 ms 109.236.95.142  Time: 118.919 ms 109.236.95.142  Time: 115.806 ms
4 109.236.95.173  Time: 118.142 ms *  Time: 1001.05 ms 109.236.95.173  Time: 119.492 ms
5 5.56.21.173  (ae12-403.ams10.core-backbone.com) Time: 86.965 ms 5.56.21.173  (ae12-403.ams10.core-backbone.com) Time: 40.281 ms 5.56.21.173  (ae12-403.ams10.core-backbone.com) Time: 40.851 ms
6 5.56.18.94  (ae5-2092.nyk10.core-backbone.com) Time: 233.51 ms 5.56.18.94  (ae5-2092.nyk10.core-backbone.com) Time: 115.688 ms 5.56.18.94  (ae5-2092.nyk10.core-backbone.com) Time: 112.534 ms
7 198.32.160.115  (edgecastcdn.net) Time: 349.537 ms 198.32.160.115  (edgecastcdn.net) Time: 116.107 ms 198.32.160.115  (edgecastcdn.net) Time: 115.874 ms
8 152.195.68.133  (ae-65.core1.nyd.edgecastcdn.net) Time: 174.254 ms 152.195.68.133  (ae-65.core1.nyd.edgecastcdn.net) Time: 116.769 ms 152.195.68.133  (ae-65.core1.nyd.edgecastcdn.net) Time: 115.568 ms
9 *  Time: 1000.93 ms 93.184.216.34  Time: 447.133 ms 93.184.216.34  Time: 190.726 ms 
```
## Сборка и запуск тестов
Сборка тестов
```sh
g++ -c tests.cpp -o tests.o
g++ -c functions.cpp -o functions.o
g++ functions.o tests.o -o tests -lgtest -lgtest_main -pthread
```
## Запуск тестов
Для корректной работы тестов запускайте их от имени суперпользователя:
```sh
sudo ./tests
```