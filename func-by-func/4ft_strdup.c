
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