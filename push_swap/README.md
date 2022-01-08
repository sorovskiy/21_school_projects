## push_swap

Проект по сортировке стека при помощи ограниченного набора инструкций при минимальном количестве операции.

Для сортировки в задаче разрешается использовать только 2 стека и только сдедующий набор команд:

| Команда       | Описание  |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

Программа принимает на вход целочисленные аргументы и выводит последовательность команд наименьшей длины, которой можно отсортировать входные данные
[подробное описание задачи ](push_swap/en.subject.pdf)