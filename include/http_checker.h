#ifndef HTTP_CHECKER_H
#define HTTP_CHECKER_H

#include <curl/curl.h>

const int RCCHECK_OK;
const int RCCHECK_ERR_NOINIT;
const int RCCHECK_ERR_PERFORM;
const int RCCHECK_ERR_GETINFO;

int get_response_code(char *url, long *resCode);

#endif