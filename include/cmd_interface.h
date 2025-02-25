#ifndef _CMD_INTERFACE_PELZ_H_
#define _CMD_INTERFACE_PELZ_H_

typedef enum
{ EMPTY,    //NULL value
  SEAL,     
  EX,       //Exit     
  KEYTABLE, 
  PKI,      
  REMOVE,   
  LIST,     
  LOAD,     
  CERT,     
  PRIVATE,  
  OTHER     //Non-null value other then the ones listed above
}CmdArgValue;

/**
 * @brief Checks the command line argument for valid command entry
 *
 * @param[in]   arg  The null-terminated command line argument to be validated
 *
 * @returns CmdArgValue
 */
  CmdArgValue check_arg(char *arg);

/**
 * @brief Creates and sends message then listens for response on the pipe provided.
 *        Message includes an agrument to be passed to the service.
 *
 * @param[in]   pipe      The pipe to receive a response on
 * @param[in]   pipe_len  The character length of the pipe value
 * @param[in]   cmd       The value of the command to be sent on the pipe
 * @param[in]   arg       The command line argument to sent on the pipe
 * @param[in]   arg_len   The character length of the argument to be sent
 *
 * @returns 0 on success, 1 on error
 */
  int msg_arg(char *pipe, int pipe_len, int cmd, char *arg, int arg_len);

/**
 * @brief Creates and sends message then listens for a list of responses on the pipe provided.
 *
 * @param[in]   pipe      The pipe to receive a response on
 * @param[in]   pipe_len  The character length of the pipe value
 * @param[in]   cmd       The value of the command to be sent on the pipe
 *
 * @returns 0 on success, 1 on error
 */
  int msg_list(char *pipe, int pipe_len, int cmd);
#endif
