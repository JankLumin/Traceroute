# Утилита Traceroute (для Linux)
## Данная утилита предназначена для получения пути до заданного адреса на операционной системе Linux, для своей работы она использует ICMP Echo Request.
...
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
## Пример использования
```sh
sudo ./traceroute example.com
```