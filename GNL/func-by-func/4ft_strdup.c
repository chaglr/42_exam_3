
//malloc la src_len kadar bellek ayirip o bellege kopyalama yap.
// burada src_len ile dest_len esit olmali.
char* ft_srcdup(const char *src)
{
	size_t src_len = ft_strlen((src)+1);
	char *dest = (char *)malloc(dst_len));
	if (dest == NULL)
		return(NULL);
	ft_strlcpy(dst, src, src_len);
	return(dest);
}

//malloc yap
char*ft_strdup(const char *s)
{
	size_t len = ft_strlen(s)+1;
	char *dup;
	dup =(char *)malloc(dst_len);
	ft_strlcpy(dup, s, s_len);
	return(dup);
}

char *ft_strlcpy(char *dest, const char src, size_t dest_len)
{
	size_t src_len =ft_strlen(src);
	size_t int i;
	while(i < src_len && i < dest_len-1)
	{
		dest[i] =src[i];
		i++;
	}
	dest[i] = '\0';
	return(src_len);
}

char *ftstrdup(const char *s)
{
	size_t len = ft_strlen(s)+1;
	char * dup = (char *)malloc(sizeof(char)* len);
	if (dup == NULL)
		return(NULL);
	ft_strlcpy(dup, src, size_t src_len);
	return(dup);
}


char *ft_strdub()
