#include "stdio.h"
#include "string.h"

void generate_y();
void reduse_data();


int main()
{
	generate_y();
	reduse_data();
	
	return 0;
}


void generate_y(){

	FILE *input_X1,*input_X2,*generted_y,*reduced_data_x1_x2;
	input_X1 = fopen("x1_values.txt","r");
	input_X2 = fopen("x2_values.txt","r");
	generted_y=fopen("y_values.txt","w");
	reduced_data_x1_x2=fopen("X1_X2_of_reduced_data.txt","w");

	
	char data_X1[100],data_X2[100];
	float value_X1,value_X2,value_y;
	int i;

	if(input_X2==NULL||input_X1==NULL || generted_y==NULL){
		printf("unable to open file\n");
	}else{
		for (i = 0; i < 53590; ++i)
		{
			fscanf(input_X1,"%s\t%f",data_X1,&value_X1);
			fscanf(input_X2,"%s\t%f",data_X2,&value_X2);
			if(strcmp(data_X2,data_X1) == 0){
				value_y=value_X2/value_X1;
				fprintf(generted_y,"%s\t%f\n",data_X1,value_y);
				if(value_y>4.47)
					fprintf(reduced_data_x1_x2, "%s\t%f\t%f\n",data_X1,value_X1,value_X2);	
			}else{
				printf("REF_ID for two genes dont match\n");
			}
		}
	}

	fclose(input_X1);
	fclose(input_X2);
	fclose(generted_y);	
}

void reduse_data(){

	FILE *generted_y,*output;
	generted_y=fopen("y_values.txt","r");
	output = fopen("reduced_data.txt","w");

	char data_X1[100];
	float value_y,diffrence;
	int i;

	if(generted_y==NULL|| output==NULL){
		printf("unable to open file\n");
	}else{
		for (i = 0; i < 53590; ++i)
		{
			fscanf(generted_y,"%s\t%f",data_X1,&value_y);
				if(value_y>4.47){
					fprintf(output,"%s\t%f\n",data_X1,value_y);
				}
		}
	}

	fclose(output);
	fclose(generted_y);
}