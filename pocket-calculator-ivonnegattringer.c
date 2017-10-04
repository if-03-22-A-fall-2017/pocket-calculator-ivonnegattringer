#include <stdio.h>
#include <float.h>

void menu();
int get_operation();
void get_operants();
void perform_operation();
int multiply_over_under_flow();
int add_over_under_flow();


int main(int argc, char* argv[])
{
  int end = 1;
  while(end == 1)
  {

    menu();
    int choice = get_operation();
    if(choice != -1)
      {
      double first_number;
      double second_number;
      get_operants(&first_number, &second_number);
      perform_operation(choice, first_number, second_number);
      end = 1;
      }
      else
      end = 0;
    }
    return 0;
}
void menu()
{
    printf("Choose one of the following operations:\n Add (1)\n Subtract (2)\n Multiply (3) \n Divide (4) \n Stop programm (-1) \n Enter your choice: " );
}
int get_operation()
{

  int choice;
  int right_input = 0;
  do {
      scanf("%d", &choice);
      if(choice == -1 || choice == 1 || choice == 2  || choice == 3 || choice == 4){
        right_input = 1;
      }
      else{
        printf("Input not allowed.\n" );
      }
  } while(right_input== 0);

  return choice;
}
void get_operants(double* first_number, double* second_number)
{
  printf("Enter the first number:");
  scanf("%lf", first_number );
  printf("Enter the second number:");
  scanf("%lf", second_number );
}
void perform_operation(int choice, double first_number, double second_number)
{
    switch(choice)
    {
      case 1: if(add_over_under_flow(first_number, second_number) == 0)
      {
        printf("Summe: %lf\n",first_number+second_number );
      }
      break;
      case 2: printf("Difference: %lf\n",first_number - second_number ); break;
      case 3: if(multiply_over_under_flow(first_number, second_number)== 0){printf("Product: %lf\n", first_number * second_number);} break;
      case 4: if(second_number == 0){
          printf("Division by Zero\n" );
        }
        else{
          printf("Quotient: %lf\n", first_number/second_number );
        }
        break;
    }
}
int add_over_under_flow(double a, double b)
{
  if(a > 0 && DBL_MAX - b < a){
    printf("Overflow\n");
    return 1;
  }
  else if(b< 0 && DBL_MIN + a > b){
    printf("underflow\n" );
    return 1;
  }
  return 0;
}
int multiply_over_under_flow(double a, double b)
{
  int sum = a*b;
  if(a != 0 && sum / a != b){
    printf("overflow\n" );
    return 1;
  }
  return 0;
}
