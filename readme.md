# Утилита Traceroute, которая работает через ICMP протокол.
## Сборка и запуск утилиты Traceroute
### Для сборки утилиты Traceroute через объектные файлы выполните следующие шаги:
```sh
g++ -c main.cpp -o main.o
g++ -c functions.cpp -o functions.o
g++ functions.o main.o -o traceroute 
```
### Для корректной работы программы запускайте ее от имени суперпользователя:
```sh
sudo ./traceroute
```
## Сборка и запуск тестов
### Для сборки тестов выполните аналогичные шаги сборки основной программы:
```sh
g++ -c tests.cpp -o tests.o
g++ -c functions.cpp -o functions.o
g++ functions.o tests.o -o tests -lgtest -lgtest_main -pthread
```
### Для корректной работы тестов запускайте их от имени суперпользователя:
```sh
sudo ./tests
```