#!/bin/bash

FILES=("memset" "bzero" "memcpy" "memccpy" "memmove" "memchr" "memcmp" "strlen" "isalpha" "isdigit" "isalnum" "isascii" "isprint" "toupper" "tolower" "strchr" "strrchr" "strncmp" "strlcpy" "strlcat" "strnstr" "atoi" "calloc" "strdup" "substr" "strjoin" "strtrim" "split" "itoa" "strmapi" "putchar_fd" "putstr_fd" "putendl_fd" "putnbr_fd")
BONUS_FILES=("lstnew" "lstadd_front" "lstsize" "lstlast" "lstadd_back" "lstdelone" "lstclear" "lstiter" "lstmap")

touch libft.h Makefile
for file in "${FILES[@]}"
do
	touch "ft_${file}.c"
done

# for file in "${BONUS_FILES[@]}"
# do
# 	touch "ft_${file}.c"
# done