#include "tar.h"
#include "errors.h"
#include "command_handler.h"
#include "utils.h"
#include "path_lib.h"
#include "remove.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

#define CMD_NAME "rm"

static void set_remove_cmd_name()
{
  cmd_name_remove[0] = '\0';
  strcpy(cmd_name_remove, "rm");
}

int main(int argc, char *argv[])
{
  set_remove_cmd_name();
  unary_command cmd = {
    CMD_NAME,
    rm,
    false,
    false,
    SUPPORT_OPT_
  };
  return handle_unary_command (cmd, argc, argv);
}
