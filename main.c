/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:28:02 by andre             #+#    #+#             */
/*   Updated: 2024/05/06 19:51:11 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>//
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    char *linha;
    int i;

    Abre o arquivo exemplo1.txt diretamente
    fd = open("exemplo1.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    Lê e imprime cada linha do arquivo até o final
    while ((linha = get_next_line(fd)) != NULL)
    {
        printf("line [%02d]: %s", i, linha);
        free(linha);
        i++;
    }

    Fecha o arquivo
    close(fd);
    return 0;
}
int	main(void) 
{
int		descritor_arquivo;
int		i;
char	*line;
//A linha abaixo é usada para abrir um arquivo específico.
    descritor_arquivo = open("exemplo2.txt", O_RDONLY);
        i = 1;
        while ((line = get_next_line(descritor_arquivo))) {
            printf("line [%02d]: %s", i, line);
            free(line); // Libera a memória alocada para a linha.
            i++; // Incrementa o contador de linhas.
        }
close(descritor_arquivo); // Fecha o arquivo.
     return (0);
}
char	*get_next_line(int fd)
{
	char		*current_line;
	static char	*remaining_content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remaining_content = read_and_store(fd, remaining_content);
	if (!remaining_content)
		return (NULL);
	current_line = extract_line(remaining_content);
	remaining_content = update_content(remaining_content);
	
	// Imprimir o ponteiro associado com o novo parágrafo
	printf("Ponteiros associados com o novo parágrafo:\n");
	char *ponteiro = current_line;
	while (*ponteiro != '\0') {
		printf("Endereço de memória: %p\n", (void *)ponteiro);
		ponteiro++;
	}
	
	return (current_line);
}
