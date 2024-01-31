char *ft_strjoin(char *s1, const char s2, size_t s2_len)
{
	char *join;
	//malloc yap onun icin len lazim.
	size_t s1_len = ft_strlen(s1);
	join = (char *)malloc(sizeof(char) * (s1_len + s2_len));
	//null checker
	if(!join)
		return(NULL);
	//start the copying first s1_len then s2_len
	ft_strlcpy(join, s1, s1_len+1);
	ft_strlcpy((join+s1_len), s2, s2_len+1);
	free(s1)
	return(join);
}