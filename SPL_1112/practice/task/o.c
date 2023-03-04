#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter text to display on LED matrix screen:\n");
  fgets(input, 100, stdin);
  int len = strlen(input);
  for (int i = 0; i < len; i++) {
    switch (input[i]) {
      case 'A':
        printf(" ***  \n*   * \n***** \n*   * \n*   * \n");
        break;
      case 'B':
        printf("****  \n*   * \n****  \n*   * \n****  \n");
        break;
      case 'C':
        printf(" ***  \n*   * \n*     \n*   * \n ***  \n");
        break;
      case 'D':
        printf("****  \n*   * \n*   * \n*   * \n****  \n");
        break;
      case 'E':
        printf("***** \n*     \n****  \n*     \n***** \n");
        break;
      case 'F':
        printf("***** \n*     \n****  \n*     \n*     \n");
        break;
      case 'G':
        printf(" ***  \n*   * \n*  ** \n*   * \n ***  \n");
        break;
      case 'H':
        printf("*   * \n*   * \n***** \n*   * \n*   * \n");
        break;
      case 'I':
        printf("***** \n  *   \n  *   \n  *   \n***** \n");
        break;
      case 'J':
        printf("***** \n   *  \n   *  \n*  *  \n **   \n");
        break;
      case 'K':
        printf("*   * \n*  *  \n***   \n*  *  \n*   * \n");
        break;
      case 'L':
        printf("*     \n*     \n*     \n*     \n***** \n");
        break;
      case 'M':
        printf("*   * \n** ** \n* * * \n*   * \n*   * \n");
        break;
      case 'N':
        printf("*   * \n**  * \n* * * \n*  ** \n*   * \n");
        break;
      case 'O':
        printf(" ***  \n*   * \n*   * \n*   * \n ***  \n");
        break;
      case 'P':
        printf("****  \n*   * \n****  \n*     \n*     \n");
        break;
      case 'Q':
        printf(" ***  \n*   * \n*   * \n*  ** \n ***  \n");
        break;
      case 'R':
        printf("****  \n*   * \n****  \n*  *  \n*   * \n");
        break;
      default:
        printf("     \n     \n  %c  \n     \n     \n", input[i]);
        break;
    }
  }
  return 0;
}
