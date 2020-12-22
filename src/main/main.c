#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <linux/limits.h>

#include "tsh.h"
#include "path_lib.h"
#include "tar.h"
#include "errors.h"
#include "tokens.h"

static void init_tsh();

static void init_tsh()
{
  char cwd[PATH_MAX];
  getcwd(cwd, PATH_MAX);
  setenv("PWD", cwd, 1); // In case PWD has not the right value at the begining
  set_ret_value(EXIT_SUCCESS);
  init_tsh_dir();
  init_redirections();
}


int main (int argc, char *argv[])
{
  init_tsh ();

  char *buf;
  while ((buf = readline(PROMPT)))
  {
    add_history(buf);
    set_ret_value(exec_line(buf));
  }

  return 0;
}
