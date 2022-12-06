#include<stdio.h>
#include <stdlib.h>

int *split_nums(int number){
	int s1, s2, s3, s4;
	s1 = number / 1000;
	s2 = (number / 100) - s1 * 10;
	s3 = (number % 100) / 10;
	s4 = number % 10; 
	int *result = (int *)malloc(4*sizeof(int));
	result[0] = s1;
	result[1] = s2;
	result[2] = s3;
	result[3] = s4;
	// printf("result = %d\n", result[3]);
	if((s1 != s2) && (s1 != s3) && (s1 != s4) && (s2 != s3) && (s2 != s4) && (s3 != s4))
	return result;

}


int *guess(int nums)
{
  //setting your default no. or you can try randon 
	int guess_nums = 1234;
	int *guess_no = (int *)malloc(4 * sizeof(int));
	int *input_num = (int *)malloc(4 * sizeof(int));
	input_num = split_nums(nums);
	guess_no = split_nums(guess_nums);
	int A_count= 0, B_count = 0;
	int *result = (int *)malloc(4 * sizeof(int));
	for(int i = 0; i < 4; i++)
	{
	    if(guess_no[i] == input_num[i])
		{
				A_count += 1;
		}
		else 
		{
			for(int j = 0; j < 4; j++){
				if(guess_no[i] == input_num[j]){
					B_count += 1;
				}
			}
		}
	}
	printf("A_count = %d, B_count = %d\n", A_count, B_count);
	result[0] = A_count;
	result[1] = B_count;
	
	return result;
}

int main(int argc, char const *argv[])
{
  //input no. you guess
	int numbers = 2456;
  
	int *answer = (int *)malloc(2 * sizeof(int));
	answer = guess(numbers);
	printf("Your answer = %d A %d B\n", answer[0], answer[1]);
	free(answer);
	return 0;
}
