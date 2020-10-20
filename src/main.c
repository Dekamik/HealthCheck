#include <stdio.h>
#include <curl/curl.h>

int main(void) 
{
	CURL *curl;
	CURLcode res;
	int exitCode;

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

		res = curl_easy_perform(curl);
		

		if (res == CURLE_OK) 
		{

			fprintf(stderr, "HTTP status ");
			exitCode = 1;
		}
		else 
		{
			printf("HTTP status 200");
			exitCode = 0;
		}

		curl_easy_cleanup(curl);
	}
	else {
		fprintf(stderr, "cURL didn't initialize.");
		exitCode = 1;
	}

	
	return exitCode;
}
