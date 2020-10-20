#include <stdio.h>

#include "http_checker.h"

const int HC_OK_ALIVE = 0;
const int HC_OK_DEAD = 1;
const int HC_ERR_IO = 5;
const int HC_ERR_ARGS = 22;

const int HTTP_OK = 200;

int main(int argc, char *argv[]) 
{
	if (argc != 2) 
	{
		fprintf(stderr, "Expecting one argument (URL)");
		return HC_ERR_ARGS;
	}

	int res;
	char *url = argv[1];
	long resCode;

	res = get_response_code(url, &resCode);

	if (RCCHECK_OK == res)
	{
		printf("HTTP response code %ld", resCode);

		if (HTTP_OK == resCode)
		{
			return HC_OK_ALIVE;
		}
		else
		{
			return HC_OK_DEAD;
		}
	}
	
	fprintf(stderr, "Error occured when using cURL");
	return HC_ERR_IO;
}
