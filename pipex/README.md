# `pipex`

Целью этого проекта является реализация механизма UNIX - `pipe`.<br>


### Discription of mandatory part
Программа "pipex` должна повторять поведение следующей shell-команды
```bash
$> < file1 cmd1 | cmd2 > file2
```
и вызываться таким образом:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```

Программе необходимо обрабатывать несколько пайпов:
```bash
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Для компиляции приложения нужно запустить команду \
```make all```  <br>

[подробное описание задачи](en.subject.pdf)