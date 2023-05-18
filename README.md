# Навигация

В корне репозитория находятся папки с названиями проектов.

Внутри каждого проекта есть файл README.txt или README.md с кратким описанием проекта.

Исходный код находится в папке src каждого проекта.

Чтобы запустить проект, необходимо перейти в каталог "название_проекта"/src и в терминале запустить в терминале команду "make".

Makefile есть в папке src для каждого проекта.

Проекты decimal, math, matrix, simple_bash и stringplus_library представляют собой реализованные на языке C библиотеки. Каждая реализованная библиотека протестирована unit-тестами. Чтобы посмотреть проходит ли проект тесты, необходимо в терминале, находясь в каталоге src, запустить команду "make test" или "make gcov_report" (покажет отчет о покрытии проекта тестами).

Проекты smart_calc и 3d_viewer - полноценные приложения с отрисованным функционалом. Для открытия документации по работе с этими приложениями необходимо перейти в каталог "название_проекта"/src и запустить в терминале команду "make dvi".

Также в проекте в папке SQL_bootcamp находятся задачи и решения для SQL. В каталоге SQL_bootcamp находится папка materials с базой данных для работы с проектами SQL_Day00-SQL_Day09. В проектах SQL_Team00 и SQL_Team01 реализованы свои базы данных. Файлы лежат в каталоге соответствующих проектов. В каждом проекте SQL_bootcamp находится свой README.md с описанием задачи.