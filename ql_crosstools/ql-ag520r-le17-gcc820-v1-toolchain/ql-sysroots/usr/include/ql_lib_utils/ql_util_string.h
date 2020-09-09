/*-----------------------------------------------------------------------------------------------*/
/**
  @file ql_util_string.h
  @brief Safe string references API 
*/
/*-----------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  Copyright (c) 2018 Quectel Wireless Solution, Co., Ltd. All Rights Reserved.
  Quectel Wireless Solution Proprietary and Confidential.
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
  EDIT HISTORY
  This section contains comments describing changes made to the file.
  Notice that changes are listed in reverse chronological order.
  $Header: $
  when       who          what, where, why
  --------   ---          ----------------------------------------------------------
  20181024   tyler.kuang  Created .
  20190715   ewen.li      add qlu_str_atoi_ext function
-------------------------------------------------------------------------------------------------*/

#ifndef __QL_UTIL_STRING_H__
#define __QL_UTIL_STRING_H__

#ifdef __cplusplus
extern "C" {
#endif

/* is str is null, return TRUE */
#define QLU_STR_IS_NULL(str)    (!(str))

/* is str is empty, return TRUE */
#define QLU_STR_IS_EMPTY(str)   (!(str) || !(str)[0])


#define QLU_STR_SNPRINTF(str_buf, str_len, ...) \
    snprintf(&str_buf[strlen(str_buf)], str_len-strlen(str_buf), __VA_ARGS__)

#define QLU_STR_STRNCAT(str_buf, str_len, str) \
    strncat(str_buf, str, str_len-strlen(str_buf))

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief safe wapper of strncpy, it copies the string pointed to by src, including the terminating 
    null byte, to the buffer pointed to by dest.
  @param[out] dest Destination string buffer
  @param[in] src Source string buffer
  @param[in] dest_len Length of destination string buffer
  @return 
  0 - succeed
  -1 - dest or src is null
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_strncpy(char *dest, const char *src, int  dest_len);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief safe wapper of strcmp, it compares two strings
  @param[in] str1 String buffer 1 
  @param[in] str2 String buffer 2 
  @return 
  1 - str1 greater than str2
  0 - str1 equal to str2
  -1 - str1 less than str2
  -2 str1 or str2 is null
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_strcmp(const char *str1, const char *str2);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief safe wapper of strncmp, it only compares the first(at most)  n bytes of str1 and str2
  @param[in] str1 String buffer 1 
  @param[in] str2 String buffer 2 
  @param[in] compare_len
  @return 
  1 - str1 greater than str2
  0 - str1 equal to str2
  -1 - str1 less than str2
  -2 str1 or str2 is null
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_strncmp(const char *str1, const char *str2, int compare_len);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief safe wapper of strcasecmp, it compares two strings ignoring case
  @param[in] str1 String buffer 1 
  @param[in] str2 String buffer 2 
  @return 
  1 - str1 greater than str2
  0 - str1 equal to str2
  -1 - str1 less than str2
  -2 str1 or str2 is null
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_strcasecmp(const char *str1, const char *str2);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief safe wapper of strncasecmp, 
    it only compares the first(at most) compare_len bytes, ignoring the case of characters
  @param[in] str1 String buffer 1 
  @param[in] str2 String buffer 2 
  @param[in] compare_len
  @return 
  1 - str1 greater than str2
  0 - str1 equal to str2
  -1 - str1 less than str2
  -2 str1 or str2 is null
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_strncasecmp(const char *str1, const char *str2, int compare_len);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Converts the letter c to upper case
  @param[in] src Source string
  @param[out] dst Destination string
  @param[in] dst_len Length of destination string buffer 
  @return 
  -1 -  Failure
  0 - successful 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_toupper(const char *src, char *dst, int dst_len);


/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Converts the letter c to lower case
  @param[in] src Source string
  @param[out] dst Destination string
  @param[in] dst_len Length of destination string buffer 
  @return 
  -1 -  Failure
  0 - successful 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_tolower(const char *src, char *dst, int dst_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Remove the white space before and after the string src (tab, space, Line break, etc.), 
    exp: " abc def \r\n" to "abc def"
  @param[in] src Source string
  @param[out] dst Destination string
  @param[in] dst_len Length of destination string buffer 
  @return 
  -1 -  Failure
  0 - successful 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_strip(const char *src, char *dst, int dst_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief Remove the white space in the string src (tab, space, Line break, etc.), exp
  " abc def \r\n" to "abcdef"
  @param[in] src Source string
  @param[out] dst Destination string
  @param[in] dst_len Length of destination string buffer 
  @return 
  -1 -  Failure
  0 - successful 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_stripall(const char *src, char *dst, int dst_len);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief convert a string to a integer 
  @param[in] str Source string
  @param[val] val Returns converted data
  @return 
  -1 - failure, invalid format
  0 - successful 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_atoi(const char *str, int *val);

/*-----------------------------------------------------------------------------------------------*/
/** 
  @brief convert a string that hex to a integer  
  @param[in] str Source string
  @param[val] val Returns converted data
  @return 
  -1 - failure, invalid format
  0 - successful 
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_str_atoi_ext(const char *str, int *val);

#ifdef __cplusplus
} 
#endif

#endif

