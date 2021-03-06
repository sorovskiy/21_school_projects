<center><h1>Libft</h1></center>
<center><h2>Собственная библиотека</h2></center>
</br>
<center><i>Цель этого проекта - написать собственную реализацию некоторых функций из стандартной библиотеки Си.</i></center>
</br>
</br>

### Для компиляции библиотеки нужно запустить команду <br>
### ```make all```  <br>


## Часть 1 - Функции `libc`

В этой первой части вы должны перекодировать набор функций `libc`, как определено в их `man`. Ваши функции должны будут представлять тот же прототип и поведение, что и исходные. Имена ваших функций должны иметь префикс `ft_`. Например, `strlen` становится `ft_strlen`.

Для компиляции библиотеки нужно запустить команду <br>
```make all```  <br>

Вы должны перекодировать следующие функции. Этим функциям не нужны внешние функции:
- memset
- strrchr
- bzero
- strnstr
- memcpy
- strncmp
- memccpy
- atoi
- memmove
- isalpha
- memchr
- isdigit
- memcmp
- isalnum
- strlen
- isascii
- strlcpy
- isprint
- strlcat
- toupper
- strchr
- tolower

Вы также должны перекодировать следующие функции, используя функцию `malloc`:
- calloc
- strdup

</br>
</br>
</br>

## Часть 2 - Дополнительные функции

Во второй части вы должны закодировать набор функций, которые либо не включены в `libc`, либо включены в другую форму. Некоторые из этих функций могут быть полезны для написания функций Части 1.



---------------------------------------------------------------------------------------------
> | Имя функции           | ft_substr                                                       |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | char *ft_substr(char const *s, unsigned int start, size_t len); |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Строка, из которой создается подстрока. #2. Начальный индекс подстроки в строке ’s’. #3. Максимальная длина подстроки. |
> | Возвращаемое значение | Подстрока. `NULL`, если выделение не удалось.                   |
> | Внешние функции.      | malloc
> | Описание              | Выделяет(с помощью `malloc`) и возвращает подстроку из строки `s`. Подстрока начинается с индекса `start` и имеет максимальный размер `len`. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_strjoin                                                      |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | char *ft_strjoin(char const *s1, char const *s2);               |
> | Файлы для сдачи       | -                                                               |
> | Параметры             |  #1.Строка префикса. #2. Строка суффикса.                       |
> | Возвращаемое значение | Новая строка. `NULL`, если выделение не удалось.                |
> | Внешние функции.      | malloc                                                          |
> | Описание              | Выделяет (с помощью `malloc`) и возвращает новую строку, которая является результатом объединения `s1` и `s2`. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_strtrim                                                      |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | char *ft_strtrim(char const *s1, char const *set);              |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1.Обрезаемая строка. #2.Контрольный набор символов для обрезки.|
> | Возвращаемое значение | Новая строка. `NULL`, если выделение не удалось.                |
> | Внешние функции.      | malloc                                                          |
> | Описание              | Выделяет (с помощью `malloc`) и возвращает копию `s1` с символами, указанными в `set`, удаленными из начала и конца строки. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_split                                                        |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | char **ft_split(char const *s, char c);                         |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Строка, которую нужно разделить. #2. Символ-разделитель.    |
> | Возвращаемое значение | Массив новых строк, полученных в результате разделения. NULL, если выделение не удалось. |
> | Внешние функции.      | malloc, free                                                    |
> | Описание              | Выделяет (с помощью `malloc`) и возвращает массив строк, полученных путем разделения `s` с использованием символа `c` в качестве разделителя. Массив должен заканчиваться указателем NULL. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_itoa                                                         |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | char *ft_itoa(int n);                                           |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Целое число для преобразования.                             |
> | Возвращаемое значение | Строка, представляющая целое число. NULL, если размещение не удается. |
> | Внешние функции.      | malloc                                                          |
> | Описание              | Выделяет (с помощью `malloc`) и возвращает строку, представляющую целое число, полученное в качестве аргумента. Отрицательные числа нужно обрабатывать. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_strmapi                                                      |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | char *ft_strmapi(char const *s, char (*f)(unsigned int, char)); |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Строка, по которой выполняется итерация. #2. Функция, применяемая к каждому |персонажу.
> | Возвращаемое значение | Строка, созданная последовательным применением 'f'. Возвращает NULL, если выделение не удалось. |
> | Внешние функции.      | malloc                                                          |
> | Описание              | Применяет функцию `f` к каждому символу строки `s` для создания новой строки (с помощью `malloc`) в результате последовательных применений `f`. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_putchar_fd                                                   |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | void ft_putchar_fd(char c, int fd);                             |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Символ для вывода. #2. Дескриптор файла для записи в поток. |
> | Возвращаемое значение | -                                                               |
> | Внешние функции.      | write                                                           |
> | Описание              | Выводит символ `c` в указанный файловым дескриптором поток.     |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_putstr_fd                                                    |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | void ft_putstr_fd(char *s, int fd);                             |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Строка для вывода. #2. Дескриптор файла для записи в поток. |
> | Возвращаемое значение | -                                                               |
> | Внешние функции.      | write                                                           |
> | Описание              | Выводит строку `s` в указанный файловым дескриптором поток.     |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_putendl_fd                                                   |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | void ft_putendl_fd(char *s, int fd);                            |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Строка для вывода. #2. Дескриптор файла для записи в поток. |
> | Возвращаемое значение | -                                                               |
> | Внешние функции.      | write                                                           |
> | Описание              | Выводит строку `s` в указанный файловым дескриптором поток, за которой следует новая строка. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_putnbr_fd                                                    |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | void ft_putnbr_fd(int n, int fd);                               |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Число для вывода. #2. Дескриптор файла для записи в поток.  |
> | Возвращаемое значение | -                                                               |
> | Внешние функции.      | write                                                           |
> | Описание              | Выводит целое число `n` в указанный файловым дескриптором поток.|
---------------------------------------------------------------------------------------------


</br>
</br>
</br>

# Глава IV.

## Бонусная часть

### Функции для работы с односвязным спискам

Вы будете использовать следующую структуру для представления элементов вашего списка.

```
typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}               t_list;
```

Вот описание полей структуры `t_list`:

- `content`: содержит адрес данных. `void *` позволяет хранить адреса любых данных.
- `next`: содержит адрес следующего элемента списка связаных между собой структур или `NULL`, если это последний элемент.</br>
  </br>

Реализованы следующие функции:

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_lstnew                                                       |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | t_list *ft_lstnew(void *content);                               |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Контент для создания нового элемента.                       |
> | Возвращаемое значение | Новый элемент.                                                  |
> | Внешние функции.      | malloc                                                          |
> | Описание              | Выделяет (с помощью malloc) и возвращает новый элемент. Переменная `content` инициализируется значением параметра `content`. Переменная `next` инициализируется значением `NULL`. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_lstadd_front                                                 |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | void ft_lstadd_front(t_list **lst, t_list *new);
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Адрес указателя на первую ссылку списка. #2. Адрес указателя на элемент, который нужно добавить в список. |
> | Возвращаемое значение | -                                                               |
> | Внешние функции.      | -                                                               |
> | Описание              | Добавляет элемент `new` в начало списка.                        |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_lstsize                                                      |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | int ft_lstsize(t_list *lst);                                    |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Начало списка.                                              |
> | Возвращаемое значение | Длина списка.                                                   |
> | Внешние функции.      | -                                                               |
> | Описание              | Подсчитывает количество элементов в списке.                     |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_lstlast                                                      |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | t_list *ft_lstlast(t_list *lst);                                |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Начало списка.                                              |
> | Возвращаемое значение | Последний элемент списка.                                       |
> | Внешние функции.      | -                                                               |
> | Описание              | Возвращает последний элемент списка.                            |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_lstadd_back                                                  |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | void ft_lstadd_back(t_list **lst, t_list *new);                 |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Адрес указателя на первую ссылку списка. #2. Адрес указателя на элемент, который нужно добавить в список. |
> | Возвращаемое значение | -                                                               |
> | Внешние функции.      | -                                                               |
> | Описание              | Добавляет элемент `new` в конец списка.                         |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_lstdelone                                                    |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | void ft_lstdelone(t_list *lst, void (*del)(void *));            |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Элемент, который нужно освободить. #2. Адрес функции, используемой для удаления содержимого. |
> | Возвращаемое значение | -                                                               |
> | Внешние функции.      | free                                                            |
> | Описание              | Принимает в качестве параметра элемент и освобождает память содержимого элемента с помощью функции `del`, заданной в качестве параметра, и освобождает элемент. Память следующего элемента списка не должна освобождаться. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_lstclear
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | void ft_lstclear(t_list **lst, void (*del)(void *));            |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Адрес указателя на элемент. #2. Адрес функции, используемой для удаления содержимого элемента.
> | Возвращаемое значение | -                                                               |
> | Внешние функции.      | free                                                            |
> | Описание              | Удаляет и освобождает память данного элемента и всех его последователей, используя функцию `del` и `free`. Наконец, указатель на список должен быть установлен в `NULL`. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_lstiter                                                      |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | void ft_lstiter(t_list *lst, void (*f)(void *));                |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Адрес указателя на элемент. #2. Адрес функции, используемой для перебора списка. |
> | Возвращаемое значение | -                                                               |
> | Внешние функции.      | -                                                               |
> | Описание              | Итерирует список `lst` и применяет функцию `f` к содержимому каждого элемента. |
---------------------------------------------------------------------------------------------

</br>

---------------------------------------------------------------------------------------------
> | Имя функции           | ft_lstmap                                                       |
> |-----------------------|-----------------------------------------------------------------|
> | Прототип              | t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)); |
> | Файлы для сдачи       | -                                                               |
> | Параметры             | #1. Адрес указателя на элемент. #2. Адрес функции, используемой для перебора списка. #3. Адрес функции, используемой для удаления содержимого элемента при необходимости.|
> | Возвращаемое значение | Новый список. `NULL`, если выделение не удалось, .              |
> | Внешние функции.      | malloc, free                                                    |
> | Описание              | Итерирует список `lst` и применяет функцию `f` к содержимому каждого элемента. Создает новый список в результате последовательных применений функции `f`. Функция `del` используется для удаления содержимого элемента, если это необходимо. |
---------------------------------------------------------------------------------------------
</br>
