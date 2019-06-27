#include <stdio.h>
#include <string.h>

int main()
{
	int list_length; /* mailing list length */
	int counter;     /* counter used to loop through all list entries */

	struct mailing {
		char first_name[30];
		char last_name[30];
		char gender[10];
		char email[40];
	};

	struct mailing list[] = {
		{
			"Jacob",
			"Huisman",
			"Male",
			"info@kernelthusiast.com"
		},
		{
			"Peter",
			"Stevens",
			"Male",
			"peter@peterstevens.com",
		},
	};

	list_length = sizeof(list) / sizeof(list[0]);

	for (counter = 0; counter < list_length; ++counter) {
		printf("** Subsriber %d **\n", (counter + 1));
		printf("First name: %s\n", list[counter].first_name);
		printf("Last name: %s\n", list[counter].last_name);
		printf("Gender: %s\n", list[counter].gender);
		printf("Email: %s\n", list[counter].email);

		printf("\n");
	}

	return 0;
}
