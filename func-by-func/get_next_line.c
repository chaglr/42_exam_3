char *get_next_line(int fd)
{
	char	*line;
	char	*new_line;
	int		line_len;
	static char buf[BUFFER_SIZE +1];
	int countread;

	//buffer i line kopyalariz islem yapmak icin
	line = ft_strdup(buf);
	while((!ft_strchr(line, '\n') && countread = read(fd,buf, BUFFER_SIZE)) >0)
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf, countread);
	}
	//null check
	if(ft_strlen(line) == 0)
		return(free(line), NULL);

	//line icinde varsa \n o satiri cikartmamiz lazim. eger yoksa new_line null dur.
	new_line = ft_strchr(line, '\n');
	if(new_line != NULL)
	{
		//burada line sonuc olarak return edecegiz line icinden \n a kadar olan kismi traslayip line a geri gondeririz.
		//null term koyacagimizdan \n kadar olan len buluruz
		line_len= new_line - line +1;
		ft_strlcpy(buf, new_line+1, BUFFER_SIZE + 1);
	}
	else //(new_line == NULL) \n yok
	{
		line_len = ft_strlen(line);
		//buf i temizleriz.
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[line_len] = '\0';

	return(line);
}


char *get_next_line(int fd)
{
	char	*line;
	char	*new_line;
	int		line_len;
	static char buf[BUFFER_SIZE +1];
	int countread;

	line = ft_strdup(buf);
	while((!ft_strchr(line, '\n') && countread = read(fd,buf, BUFFER_SIZE)) >0)
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf, countread);
	}
	if(ft_strlen(line) == 0)
		return(free(line), NULL);

	new_line = ft_strchr(line, '\n');
	if(new_line != NULL)
	{
		line_len= new_line - line +1;
		ft_strlcpy(buf, new_line+1, BUFFER_SIZE + 1);
	}
	else //(new_line == NULL) \n yok
	{
		line_len = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1); 	//buf i temizleriz.
	}
	line[line_len] = '\0';

	return(line);
}


//buf i line a kopyala.
// '/n' bulana kadar okuma islemini yap ve buf a depola.
//okuma islemi basariliysa sonuna null term ekle.
//line ile buf birlestir okudugmuz byte boyutunda birlestir..
//


char *get_next_line(int fd)
{
	static char *buf[BUFFER_SIZE+1];
	char *line;
	char *new_line;
	int	countread;
	int to_copy;

	//once buf line a kopyala. ilk seferde line ve buf bos olacagindan bisi kopyalama yapilmaz.
	//tamamini kopyalacagimizdan ft_strdup
	line = ft_strdup(buf);
	//okumaya basla \n a kadar buradan \n kadar olan uzunlugunu bul ve onceki line ile bunu birlestir.
	while(!(ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE+1))>0)
	{
		buf[countread] = '\0';
		line =ft_strjoin(line, buf, countread);
		//burada line nin icine buf atilir. eski line silinir yeni bir line bellegi olusturulur.

	}
	//linein len sifir ise line i free le ve null dondur.
	if(ft_strlen(line) == NULL)
		return (free(line) ,NULL);
	//line icinde \n ara eger varsa bunu kismi new_line gonder
	new_line = ft_strchr(line, '\n');
	if(!new_line == NULL)
	{
		to_copy = new_line - line + 1;
		ft_strlcpy(buf, new_line+1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return(line);

}