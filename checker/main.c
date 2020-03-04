/* ************************************************************************** */
/*		It's me, 42 header!										42.fr		  */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>

/*
** Это тестер для проекта Get_Next_Line для 42.fr
** По умолчанию с этим тестером идут в комплекте 8 файлов:
** 1_small_file.txt			Базовый тест гнл. Содержит три строки с числами и '\n' в конце.
** 2_lines.txt				Базовый тест гнл. Содержит 4 строки со словами и '\n' в конце.
** 3_1_no_n					Базовый тест гнл. Содержит 1 строку без '\n'
** 4_10lines_no_n.txt		Базовай тест гнл. Содержит 10 строк без '\n'
** 5_empty_lines.txt		Базовый тест. Содержит 10 строк, некоторые из них пусты.
** 6_empty_file.txt			Нестандартный тест с пустым файлом. Убедитесь, что ваша программа не крашится
** bevis_est_long.txt		Хард-тест. Отрывок из книги, удалено форматирование текста. Содержит 3 строки по 94-95 тыс. символов
** bevis_est_original.txt	Хард-тест. Тот же отрывок, но с оригиальным форматированием.
**
** Эти файлы используются для тестов, но вы также можете добавить свои.
** Чтобы запустить тест, разместите Makefile и main.c в одной папке с вашим get_next_line.h и libft (или укажите путь до него выше и в Makefile)
** Так же, для удобства, можно поместить все тестовые файлы туда же.
** Программа использует библиотечную функцию ft_memdel(), убедитесь, что вы подключаете libft.h в своей функции и библиотека имеет ft_memdel()
**
** Скомпилируйте программу командой "make" или "make re"
** Запустите программу командой ./get_next_line [FILENAME_1] [FILENAME_2],
** где FILENAME_1 и FILENAME_2 - имена файлов для теста.
** Программа проверяет сразу 2 файла, но, если вы не хотите этого, либо ваша функция не поддерживает чтение из разных fd, просто отредактируйте программу,
** комментарии ниже помогут это сделать.
** 
** В программе имеется лимит на прогон гнл, по умолчанию - 15 раз. При достижении лимита программа заканчивает тест.
** Для тестирования больших файлов, просто измените это значение, комментарий подскажет, где это сделать. Установите значение 0, если хотите убрать лимит.
** Программа очищает выделенную под *line память, поэтому вы можете тестировать ваш gnl на утечки с помощью этого тестера.
**
** Удачных тестов!
*/

int		get_next_line(const int fd, char **line);

void		print_err(char *file)
{
	ft_putstr("ERROR: ");
	ft_putstr(file);
	if (errno == ENOENT)
		ft_putstr(": No such file or directory\n");
	else if (errno == EISDIR)
		ft_putstr(": Is a directory\n");
	else if (errno == EACCES)
		ft_putstr(": Permission denied\n");
	else
		ft_putstr(": Unknown Error\n");
}

int main(int argc, char **argv) {
	char *line = NULL;
	int returned_value = 99;
	int fd;
	int i = 0;
	int limit = 15; // <----- Лимит прогонов gnl. Установите 0 для отключения лимита.

	if (argc < 3 || argc > 3) // <<---- Удалите это условие или замените 3 на 2, если ваша функция не поддерживает чтение разных fd.
	{
		printf("Тест #1 гнл для 2х файлов. Укажите 2 файла.\n");
		return (0);
	}
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		print_err(argv[1]);
		return -1;
	}
	printf("\033[1;33mDEBUG_MAIN: Начинаю тест get_next_line...\033[0m\n");
	printf("\033[1;33mDEBUG_MAIN: Открыт файл. Текущий FD = %d\033[0m\n", fd);
	line = (char *)malloc(sizeof(*line));
	while((limit == 0 || i < limit) && returned_value > 0)
	{
		returned_value = get_next_line(fd, &line);
		i++;
		printf("\033[1;31mDEBUG_MAIN: прогон gnl #%d. Вернуло:\033[0m\n", i);
		printf("\033[1;37m%s\n", line);
		printf("\033[1;37m%i\n", returned_value);
		ft_memdel((void **)&line);
	}
	if (i == limit)
		printf("\033[1;31mDEBUG_MAIN: Достигнут лимит прогонов (%d) заканчиваю работу.\033[0m\n", limit);
	printf("\033[1;35mЗАКОНЧИЛ РАБОТУ С КОДОМ %i\n", returned_value);
	
	// Удалите весь код ниже до return (0), если ваша функция не поддерживает чтение разных fd.
	
	printf("\033[1;33mDEBUG_MAIN: Открываю новый файл...\033[0m\n");
	fd = open(argv[2], O_RDWR);
	if (fd == -1)
	{
		print_err(argv[2]);
		return -1;
	}
	printf("\033[1;33mDEBUG_MAIN: Открыт файл. Текущий FD = %d\033[0m\n", fd);
	returned_value = 99;
	i = 0;
	while((limit == 0 || i < limit) && returned_value > 0)
	{
		returned_value = get_next_line(fd, &line);
		i++;
		printf("\033[1;31mDEBUG_MAIN: прогон gnl #%d. Вернуло:\033[0m\n", i);
		printf("\033[1;37m%s\033[0m\n", line);
		printf("\033[1;37m%i\033[0m\n", returned_value);
		ft_memdel((void **)&line);
	}
	if (i == limit)
		printf("\033[1;31mDEBUG_MAIN: Достигнут лимит прогонов (%d) заканчиваю работу.\033[0m\n", limit);
	printf("\033[1;35mЗАКОНЧИЛ РАБОТУ С КОДОМ %i\n", returned_value);
	//free(line);
	return (0);
}
