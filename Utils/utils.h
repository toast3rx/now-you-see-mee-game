#ifndef _utils_h_
#define _utils_h_

/**
*@brief Split a string in words delimited by space
*
*@param str string to be split
*@param words_array the array where the words will be stored
*/
void split_string(char *str, char **words_array);

/**
 * @brief Read a command from stdin
 *
 * @param command to be read
 * @param args number of words in the command
 * @return the words of the command as a two-dimensional array
 */
char **read_command(char *command, int *args);

#endif