/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: emilyproctor
 */


#include <stdio.h>
#include <string.h>


void print_monthly_sales (float sales_array[])
{
      char *month_array[12] = {"January", "February", "March", "April", "May",
      "June", "July", "August", "September", "October", "November", "December"};

      printf("Monthly sales report for 2022:\n");
      printf("Month       Sales\n");
      for (int i = 0; i < 12; ++i) {
		printf("%-10s$%10.2f\n", month_array[i], sales_array[i]);
	}
      printf("\n");
}

void print_sales_summary (float sales_array[])
{
      char *month_array[12] = {"January", "February", "March", "April", "May",
      "June", "July", "August", "September", "October", "November", "December"};

      float max_sale = 0.0;
      float min_sale = sales_array[0];
      char *max_month;
      char *min_month = month_array[0];

      for (int i = 0; i < 12; ++i) {
            if (sales_array[i] > max_sale) {
                  max_sale = sales_array[i];
                  max_month = month_array[i];
            }
            if (sales_array[i] < min_sale) {
                  min_sale = sales_array[i];
                  min_month = month_array[i];
            }
      }

      float sum = 0;
      for (int i = 0; i < 12; ++i) {
            sum = sum + sales_array[i];
      }

      float average = sum / 12;


      printf("Sales summary:\n");
      printf("Minimum sales: $%.2f (%s)\n", min_sale, min_month);
      printf("Maximum sales: $%.2f (%s)\n", max_sale, max_month);
      printf("Average sales: $%.2f\n\n", average);
}

void print_six_month (float sales_array[])
{
      char *month_array[12] = {"January", "February", "March", "April", "May",
      "June", "July", "August", "September", "October", "November", "December"};

      float six_month_nums[7];
      float sum;
      for (int i = 0; i < 7; i++) {
            sum = sales_array[i] + sales_array[i + 1] + sales_array[i + 2] + sales_array[i + 3] + sales_array[i + 4] + sales_array[i + 5];
            six_month_nums[i] = sum / 6;
      }

      printf("Six-Month Moving Average Report:\n");
      for (int i = 0; i < 7; ++i) {
		printf("%s -   \t%s    \t$%.2f\n", month_array[i], month_array[i+5], six_month_nums[i]);
	}
      printf("\n");

}

void print_high_to_low (float sales_array[])
{
      char *month_array[12] = {"January", "February", "March", "April", "May",
      "June", "July", "August", "September", "October", "November", "December"};

      float sales_copy[12];
      for (int i = 0; i < 12; ++i) {
            sales_copy[i] = sales_array[i];
      }

      char *month_copy[12];
      for (int i = 0; i < 12; ++i) {
            month_copy[i] = month_array[i];
      }

      for (int i = 0; i < 12; ++i){
            for (int j = i + 1; j < 12; ++j) {
                  if (sales_copy[i] < sales_copy[j]) {
                        float a = sales_copy[i];
                        char *b = month_copy[i];
                        sales_copy[i] = sales_copy[j];
                        month_copy[i] = month_copy[j];
                        sales_copy[j] = a;
                        month_copy[j] = b;
                  }
            }
      }

      printf("Sales Report (highest to lowest:\n");
      printf("Month        \tSales\n");
      for (int i = 0; i < 12; ++i) {
		printf("%s     \t$%.2f\n", month_copy[i], sales_copy[i]);
      }
}

int main ()
{
       float sales_nums[12];

	FILE *file_ptr = fopen("input_file.txt", "r");

	float num;
	int i = 0;
	while(fscanf(file_ptr, "%f", &num) > 0) {
		sales_nums[i] = num;
		i++;
	}

	fclose(file_ptr);
      print_monthly_sales(sales_nums);
      print_sales_summary(sales_nums);
      print_six_month(sales_nums);
      print_high_to_low(sales_nums);
	return 0;
}

