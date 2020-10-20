#include "http_checker.h"

const int RCCHECK_OK = 0;
const int RCCHECK_ERR_NOINIT = 1;
const int RCCHECK_ERR_PERFORM = 2;
const int RCCHECK_ERR_GETINFO = 3;

int get_response_code(char *url, long *resCode)
{
    CURL *curl;
	CURLcode res;
	int exitCode;

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

		res = curl_easy_perform(curl);
		
		if (CURLE_OK == res)
		{
			long *rc;

            res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &rc);

            if ((CURLE_OK == res) && rc)
            {
                resCode = rc;
                exitCode = RCCHECK_OK;
            }
            else
            {
                exitCode = RCCHECK_ERR_GETINFO;
            }
		}
        else 
        {
            exitCode = RCCHECK_ERR_PERFORM;
        }

		curl_easy_cleanup(curl);
	}
    else 
    {
        exitCode = RCCHECK_ERR_NOINIT;
    }

    return exitCode;
}
