#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*******ft_atoi******/

int main(int argc, char **argv)
{
    if (argc != 2) 
    {
        printf("Usage: %s <string_to_convert>\n", argv[0]);
        return (1);
    }

    int result = ft_atoi(argv[1]);
    printf("Converted number: %d\n", result);

    return (0);
}

gcc -Wall -Wextra -Werror -o test_ft_atoi main.c -L. -lft
./test_ft_atoi "42"
./test_ft_atoi "   -1234"
./test_ft_atoi "+5678"
./test_ft_atoi "invalid123"

/****** ft_bzero******/
int main(void)
{
    char buffer[20] = "Hello, World!";

    printf("Before ft_bzero: \"%s\"\n", buffer);
    ft_bzero(buffer + 7, 6);
    printf("After ft_bzero: \"");
    for (size_t i = 0; i < sizeof(buffer); i++)
    {
        if (buffer[i] == '\0')
            printf("\\0");
        else
            printf("%c", buffer[i]);
    }
    printf("\"\n");

    return (0);
}

/****** ft_calloc******/

int main(int argc, char **argv)
{
    if (argc != 3) 
    {
        printf("Usage: %s <count> <size>\n", argv[0]);
        return (1);
    }
    size_t count = (size_t)atoi(argv[1]);
    size_t size = (size_t)atoi(argv[2]);

    void *allocated_memory = ft_calloc(count, size);

    if (!allocated_memory) 
    {
        printf("Memory allocation failed.\n");
        return (1);
    }
    printf("Memory allocation successful.\n");
    printf("Allocated %zu bytes (%zu elements of size %zu).\n", count * size, count, size);
    unsigned char *bytes = (unsigned char *)allocated_memory;
    for (size_t i = 0; i < count * size; i++)
    {
        printf("%02x ", bytes[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n");
    free(allocated_memory);
    return (0);
}

/****** ft_isalnum ******/

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <character>\n", argv[0]);
        return (1);
    }
    char c = argv[1][0]; 
    if (ft_isalnum(c))
        printf("The character '%c' is alphanumeric.\n", c);
    else
        printf("The character '%c' is NOT alphanumeric.\n", c);

    return (0);
}

/****** ft_isalpha ******/

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <character>\n", argv[0]);
        return (1);
    }
    char c = argv[1][0]; 
    if (ft_isalpha(c))
        printf("The character '%c' is alphabetic.\n", c);
    else
        printf("The character '%c' is NOT alphabetic.\n", c);

    return (0);
}

/****** ft_isascii ******/

int main(int argc, char **argv)
{
    if (argc != 2) 
    {
        printf("Usage: %s <integer>\n", argv[0]);
        return (1);
    }
    int c = atoi(argv[1]); 
    if (ft_isascii(c))
        printf("The value '%d' is an ASCII character.\n", c);
    else
        printf("The value '%d' is NOT an ASCII character.\n", c);

    return (0);
}

/****** ft_isdigit ******/

int main(int argc, char **argv)
{
    if (argc != 2) 
    {
        printf("Usage: %s <character>\n", argv[0]);
        return (1);
    }
    char c = argv[1][0]; 
    if (ft_isdigit(c))
        printf("The character '%c' is a digit.\n", c);
    else
        printf("The character '%c' is NOT a digit.\n", c);

    return (0);
}

/****** ft_isprint ******/

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <integer>\n", argv[0]);
        return (1);
    }
    int c = atoi(argv[1]); 
    if (ft_isprint(c))
        printf("The value '%d' is a printable character.\n", c);
    else
        printf("The value '%d' is NOT a printable character.\n", c);

    return (0);
}

/****** ft_itoa ******/

int main(int argc, char **argv)
{
    if (argc != 2) 
    {
        printf("Usage: %s <integer>\n", argv[0]);
        return (1);
    }
    int n = atoi(argv[1]); 
    char *result = ft_itoa(n);
    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        return (1);
    }
    printf("The string representation of %d is: %s\n", n, result);
    free(result);
    return (0);
}

/****** ft_lstadd_back ******/

// Fonction pour créer un nouvel élément de liste
t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

// afficher_liste
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <list elements>\n", argv[0]);
        return (1);
    }
    t_list *head = NULL;
        for (int i = 1; i < argc; i++)
    {
        t_list *new_node = ft_lstnew(argv[i]);
        if (!new_node)
        {
            printf("Memory allocation failed for argument %s.\n", argv[i]);
            return (1);
        }
        ft_lstadd_back(&head, new_node);
    }
    printf("List created from arguments:\n");
    print_list(head);
    t_list *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return (0);
}

/****** ft_lstadd_front ******/

// créer un nouvel élément de liste
t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

//afficher_liste
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        printf("Usage: %s <list elements>\n", argv[0]);
        return (1);
    }
    t_list *head = NULL;
    for (int i = 1; i < argc; i++)
    {
        t_list *new_node = ft_lstnew(argv[i]);
        if (!new_node)
        {
            printf("Memory allocation failed for argument %s.\n", argv[i]);
            return (1);
        }
        ft_lstadd_front(&head, new_node);
    }
    printf("List created from arguments (added to front):\n");
    print_list(head);
    t_list *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return (0);
}

/****** ft_lstclear ******/

// Fonction créer un nouvel élément de liste
t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

// afficher_liste
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <list elements>\n", argv[0]);
        return (1);
    }
    t_list *head = NULL;
    for (int i = 1; i < argc; i++)
    {
        t_list *new_node = ft_lstnew(argv[i]);
        if (!new_node)
        {
            printf("Memory allocation failed for argument %s.\n", argv[i]);
            return (1);
        }
        ft_lstadd_front(&head, new_node);
    }
    printf("List created from arguments (added to front):\n");
    print_list(head);
    t_list *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return (0);
}

/***** ft_lstdelone ******/

// Fonction de suppression pour ft_lstdelone
void del_content(void *content)
{
    free(content);  // Exemple : libérer la mémoire allouée pour le contenu
    printf("Contenu supprimé.\n");
}

int main(void)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return (1);
    node->content = malloc(sizeof(char) * 6);
    if (!node->content)
    {
        free(node);
        return (1);
    }
    ft_strcpy(node->content, "Hello");
    printf("Contenu avant suppression : \"%s\"\n", (char *)node->content);
    ft_lstdelone(node, del_content);
    printf("Noeud supprimé. L'élément a été libéré.\n");
    return 0;
}

/***** ft_lstiter ******/

void print_content(void *content)
{
    printf("Contenu de l'élément : \"%s\"\n", (char *)content);
}

int main(void)
{
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    if (!node1 || !node2 || !node3)
        return (1);
    node1->content = strdup("Premier élément");
    node2->content = strdup("Deuxième élément");
    node3->content = strdup("Troisième élément");

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    ft_lstiter(node1, print_content);

    free(node1->content);
    free(node2->content);
    free(node3->content);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

/***** ft_lstlast ******/

void test_lstlast(t_list *lst)
{
    t_list *last = ft_lstlast(lst);

    if (last)
        printf("Le dernier élément de la liste a pour contenu : \"%s\"\n", (char *)last->content);
    else
        printf("La liste est vide.\n");
}

int main(void)
{
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    if (!node1 || !node2 || !node3)
        return (1);
    node1->content = strdup("Premier élément");
    node2->content = strdup("Deuxième élément");
    node3->content = strdup("Troisième élément");

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    test_lstlast(node1);

    free(node1->content);
    free(node2->content);
    free(node3->content);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

/***** ft_lstmap ******/

void *transform_content(void *content)
{
    
    char *str = (char *)content;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32; 
    }
    return content;
}
void del_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *node1 = ft_lstnew(strdup("hello"));
    t_list *node2 = ft_lstnew(strdup("world"));
    t_list *node3 = ft_lstnew(strdup("test"));
    
    if (!node1 || !node2 || !node3)
    {
        return (1);
    }
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    t_list *new_lst = ft_lstmap(node1, transform_content, del_content);
    t_list *tmp = new_lst;
    while (tmp)
    {
        printf("Contenu transformé : \"%s\"\n", (char *)tmp->content);
        tmp = tmp->next;
    }
    ft_lstclear(&new_lst, del_content);
    ft_lstclear(&node1, del_content);

    return 0;
}

/***** ft_lstsize ******/

void test_lstnew(void)
{
    char *content = strdup("Contenu du noeud");
    t_list *node = ft_lstnew(content);
    
    if (node)
    {
        printf("Le contenu du noeud est : \"%s\"\n", (char *)node->content);
        printf("L'adresse du prochain noeud est : %p\n", (void *)node->next);
    }
    else
    {
        printf("Échec de la création du noeud.\n");
    }
    free(content);
    free(node);
}

int main(void)
{
    test_lstnew();
    return 0;
}

/***** ft_lstsize ******/

void test_lstsize(t_list *lst)
{
    int size = ft_lstsize(lst);
    printf("La taille de la liste est : %d\n", size);
}

int main(void)
{
    t_list *node1 = ft_lstnew(strdup("Premier élément"));
    t_list *node2 = ft_lstnew(strdup("Deuxième élément"));
    t_list *node3 = ft_lstnew(strdup("Troisième élément"));
    
    if (!node1 || !node2 || !node3)
    {
        return (1);
    }

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    test_lstsize(node1);  
    ft_lstclear(&node1, free);

    return 0;
}

/***** ft_memchr ******/

int main(void)
{
    const char str[] = "Bonjour, libft memchr!";
    char c = 'o';
    char *result_libc = memchr(str, c, strlen(str));
    char *result_ft = ft_memchr(str, c, strlen(str));
    if (result_libc)
        printf("Libc: Caractère '%c' trouvé à l'adresse : %p\n", c, (void *)result_libc);
    else
        printf("Libc: Caractère '%c' non trouvé.\n", c);

    if (result_ft)
        printf("ft_memchr: Caractère '%c' trouvé à l'adresse : %p\n", c, (void *)result_ft);
    else
        printf("ft_memchr: Caractère '%c' non trouvé.\n", c);

    return 0;
}

/***** ft_memcmp ******/

int main(void)
{
    const char s1[] = "Bonjour";
    const char s2[] = "Bonjout";
    size_t n = 6;
    int result_libc = memcmp(s1, s2, n);
    int result_ft = ft_memcmp(s1, s2, n);

    printf("Libc memcmp result: %d\n", result_libc);
    printf("ft_memcmp result: %d\n", result_ft);

    if (result_libc == result_ft)
        printf("Les résultats de libc memcmp et ft_memcmp sont identiques.\n");
    else
        printf("Les résultats de libc memcmp et ft_memcmp sont différents.\n");

    return 0;
}

/***** ft_memcpy ******/

int main(void)
{
    char src[] = "Hello, World!";
    char dst[50]; 
    ft_memcpy(dst, src, 13);
    printf("Source: %s\n", src);
    printf("Destination après memcpy: %s\n", dst);
    char src2[] = "123456789";
    char dst2[10];
    ft_memcpy(dst2, src2, 9);
    printf("Source 2: %s\n", src2);
    printf("Destination 2 après memcpy: %s\n", dst2);

    return 0;
}

/***** ft_memmove ******/

int main(void)
{
    char src1[] = "Hello, World!";
    char dst1[50];
    printf("Avant memmove:\n");
    printf("Source: %s\n", src1);
    printf("Destination (avant): %s\n", dst1);
    ft_memmove(dst1, src1, 13);

    printf("Après memmove:\n");
    printf("Source: %s\n", src1);
    printf("Destination (après): %s\n", dst1);
    char src2[] = "ABCDEFGH";
    printf("\nAvant memmove (chevauchement):\n");
    printf("Source: %s\n", src2);
    ft_memmove(src2 + 1, src2, 4); 
    printf("Après memmove (chevauchement):\n");
    printf("Source: %s\n", src2);  
    return 0;
}

/***** ft_memset ******/
int main(void)
{
    
    char str1[50] = "Hello, World!";
    printf("Avant ft_memset: %s\n", str1);
    ft_memset(str1, 'X', 5);  
    printf("Après ft_memset: %s\n", str1);
    char str2[20] = "abcdef";
    printf("\nAvant ft_memset: %s\n", str2);
    ft_memset(str2, '1', 3);
    printf("Après ft_memset: %s\n", str2);
    return 0;
}

/***** ft_putnbr_fd ******/

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

int main(void)
{
    int fd = 1;
    int positive_num = 12345;
    printf("Affichage du nombre positif : ");
    ft_putnbr_fd(positive_num, fd);
    printf("\n"); 
    int negative_num = -98765;
    printf("Affichage du nombre négatif : ");
    ft_putnbr_fd(negative_num, fd);
    printf("\n");
    int zero_num = 0;
    printf("Affichage du zéro : ");
    ft_putnbr_fd(zero_num, fd);
    printf("\n");
    int large_num = 1234567890;
    printf("Affichage d'un grand nombre : ");
    ft_putnbr_fd(large_num, fd);
    printf("\n");

    return 0;
}

/***** ft_putchar_fd ******/

int main(void)
{
    char c = 'A';
    printf("Affichage de 'A' : ");
    ft_putchar_fd(c, 1);
    printf("\n");  
    c = 'B';
    printf("Affichage de 'B' : ");
    ft_putchar_fd(c, 1);
    printf("\n");

    c = '#';
    printf("Affichage de '#' : ");
    ft_putchar_fd(c, 1);
    printf("\n");

    c = '\n';
    printf("Affichage d'un retour à la ligne : ");
    ft_putchar_fd(c, 1);

    return 0;
}

/******ft_putendl_fd *****/

#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *str1 = "Hello, world!";
    printf("Affichage de la chaîne avec retour à la ligne : ");
    ft_putendl_fd(str1, 1); 
    char *str2 = "Ceci est un autre test.";
    printf("Affichage d'une autre chaîne : ");
    ft_putendl_fd(str2, 1);
    char *str3 = "";
    printf("Affichage d'une chaîne vide : ");
    ft_putendl_fd(str3, 1);

    return 0;
}


/******ft_putstr_fd *****/
int main(void)
{
    char *str1 = "Hello, world!";
    printf("Affichage de la chaîne : ");
    ft_putstr_fd(str1, 1);
    printf("\n");
    char *str2 = "Ceci est un test de ft_putstr_fd.";
    printf("Affichage d'une autre chaîne : ");
    ft_putstr_fd(str2, 1);
    printf("\n");
    char *str3 = "";
    printf("Affichage d'une chaîne vide : ");
    ft_putstr_fd(str3, 1);
    printf("\n");

    return 0;
}

/******ft_split *****/

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *str = "Bonjour tout le monde";
    char delimiter = ' ';
    char **result = ft_split(str, delimiter);
    if (result)
    {
        printf("Résultat de ft_split :\n");
        for (size_t i = 0; result[i] != NULL; i++)
        {
            printf("Sous-chaîne %zu : %s\n", i + 1, result[i]);
            free(result[i]); 
        }
        free(result); 
    }
    else
    {
        printf("Erreur lors de la division de la chaîne.\n");
    }
    char *empty_str = "";
    char **empty_result = ft_split(empty_str, delimiter);
    if (empty_result)
    {
        printf("Résultat de ft_split avec chaîne vide :\n");
        if (empty_result[0] == NULL)
            printf("La chaîne est vide, donc aucun mot n'a été trouvé.\n");
        free(empty_result);
    }

    return 0;
}

/***** ft_toupper ******/
int main(void)
{
    char c;
    printf("Entrez un caractère : ");
    scanf("%c", &c);

    int result = ft_toupper(c);
    printf("Caractère en majuscule : %c\n", result);

    return 0;
}

/*** ft_tolower ****/

int main(void)
{
    char c;
    printf("Entrez un caractère : ");
    scanf("%c", &c);

    int result = ft_tolower(c);
    printf("Caractère en minuscule : %c\n", result);

    return 0;
}

/****** ft_substr ****/

int main(void)
{
    char *str = "Hello, world!";
    unsigned int start = 7;
    size_t len = 5;
    char *result;

    result = ft_substr(str, start, len);
    if (result)
    {
        printf("Sous-chaîne : %s\n", result);
        free(result);
    }
    else
    {
        printf("Erreur : allocation de mémoire échouée.\n");
    }

    return 0;
}

/***** ft_strtrim *****/

int main(void)
{
    char *s1 = "   Hello, world!   ";
    char *set = " ";
    char *result;

    result = ft_strtrim(s1, set);
    if (result)
    {
        printf("Chaîne d'origine : \"%s\"\n", s1);
        printf("Caractères à supprimer : \"%s\"\n", set);
        printf("Résultat : \"%s\"\n", result);
        free(result); 
    }
    else
    {
        printf("Erreur : allocation de mémoire échouée.\n");
    }

    return 0;
}


/******ft_strrchr******/

int main(void)
{
    const char *s = "Hello, world!";
    int c = 'o';
    char *result;

    result = ft_strrchr(s, c);
    if (result)
        printf("Dernière occurrence de '%c' dans \"%s\" : \"%s\"\n", c, s, result);
    else
        printf("Le caractère '%c' n'est pas présent dans \"%s\".\n", c, s);

    return 0;
}

/******ft_strnstr *****/

int main(void)
{
    const char *haystack = "Hello, this is a simple test string.";
    const char *needle = "simple";
    size_t len = 20;
    char *result;

    result = ft_strnstr(haystack, needle, len);
    if (result)
        printf("Sous-chaîne trouvée : \"%s\"\n", result);
    else
        printf("La sous-chaîne \"%s\" n'est pas trouvée dans les %zu premiers caractères de \"%s\".\n",
               needle, len, haystack);

    return 0;
}

/******ft_strncmp *****/

int main(void)
{
    const char *s1 = "Hello, world!";
    const char *s2 = "Hello, everyone!";
    size_t n = 7;
    int result;

    result = ft_strncmp(s1, s2, n);
    if (result == 0)
        printf("Les %zu premiers caractères de \"%s\" et \"%s\" sont identiques.\n", n, s1, s2);
    else if (result < 0)
        printf("\"%s\" est inférieur à \"%s\" dans les %zu premiers caractères.\n", s1, s2, n);
    else
        printf("\"%s\" est supérieur à \"%s\" dans les %zu premiers caractères.\n", s1, s2, n);

    return 0;
}

/******ft_strmapi *****/

char my_function(unsigned int i, char c)
{
    if (i % 2 == 0)
        return c - 32; 
    return c;
}

int main(void)
{
    const char *s = "hello, world!";
    char *result;

    result = ft_strmapi(s, my_function);
    if (result)
    {
        printf("Chaîne d'origine : \"%s\"\n", s);
        printf("Chaîne transformée : \"%s\"\n", result);
        free(result);
    }
    else
    {
        printf("Erreur : allocation de mémoire échouée.\n");
    }

    return 0;
}

/******ft_strlen *****/
int main(void)
{
    const char *s = "Hello, world!";
    size_t length;

    length = ft_strlen(s);
    printf("La longueur de la chaîne \"%s\" est : %zu\n", s, length);
    return 0;
}

/******ft_strlcpy *****/

int main(void)
{
    const char *src = "Hello, world!";
    size_t dstsize = 8;
    char dst[dstsize]; 
    size_t result = ft_strlcpy(dst, src, dstsize);

    printf("Source : \"%s\"\n", src);
    printf("Destination après ft_strlcpy : \"%s\"\n", dst);
    printf("Longueur de la chaîne source : %zu\n", result);

    return 0;
}

/******ft_strlcat *****/

int main(void)
{
    char d[50] = "Hello, ";
    const char *s = "world!";
    size_t dstsize = 20;
    printf("Chaîne de destination avant ft_strlcat : \"%s\"\n", d);
    printf("Chaîne source : \"%s\"\n", s);
    size_t result = ft_strlcat(d, s, dstsize);
    printf("Chaîne de destination après ft_strlcat : \"%s\"\n", d);
    printf("Longueur totale de la chaîne après concaténation : %zu\n", result);
    return 0;
}

/******ft_strjoin *****/

int main(void)
{
    const char *s1 = "Hello, ";
    const char *s2 = "world!";
    char *result;

    result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("Chaîne jointe : \"%s\"\n", result);
        free(result); 
    }
    else
    {
        printf("Erreur d'allocation de mémoire.\n");
    }

    return 0;
}

/******ft_striteri *****/

void my_function(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = *c - 32; 
}

int main(void)
{
    char s[] = "hello, world!";
    printf("Chaîne avant ft_striteri : \"%s\"\n", s);
    ft_striteri(s, my_function);
    printf("Chaîne après ft_striteri : \"%s\"\n", s);

    return 0;
}

/******ft_strdup *****/

int main(void)
{
    const char *s1 = "Hello, world!";
    char *duplicate;

    duplicate = ft_strdup(s1);
    if (duplicate)
    {
        printf("Chaîne originale : \"%s\"\n", s1);
        printf("Chaîne dupliquée : \"%s\"\n", duplicate);
        free(duplicate); 
    }
    else
    {
        printf("Erreur d'allocation mémoire.\n");
    }

    return 0;
}

/******ft_strchr *****/

int main(void)
{
    const char *s = "Hello, world!";
    char c = 'o';
    char *result;

    result = ft_strchr(s, c);
    if (result)
    {
        printf("Le caractère '%c' a été trouvé dans la chaîne : \"%s\"\n", c, result);
    }
    else
    {
        printf("Le caractère '%c' n'a pas été trouvé dans la chaîne.\n", c);
    }

    return 0;
}

