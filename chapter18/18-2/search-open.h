struct file {
	char filename[50];
};

FILE *search_open(struct file files[], int number_files);
