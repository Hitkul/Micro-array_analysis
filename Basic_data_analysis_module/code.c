#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int main()
{
	FILE *x1_value,*x2_value,*y_value,*y_reduced,*x1_x2_reduced,*output;
	float mean_x1=0,mean_x2=0,mean_y=0,mean_y_reduced=0,mean_x1_reduced=0,mean_x2_reduced=0;
	float variance_x1=0,variance_x2=0,variance_y=0,variance_y_reduced=0,variance_x1_reduced=0,variance_x2_reduced=0;
	float deviation_x1,deviation_x2,deviation_y,deviation_y_reduced,deviation_x1_reduced,deviation_x2_reduced;
	x1_value=fopen("x1_values.txt","r");
	x2_value=fopen("x2_values.txt","r");
	y_value=fopen("y_values.txt","r");
	y_reduced= fopen("reduced_data.txt","r");
	x1_x2_reduced= fopen("X1_X2_of_reduced_data.txt","r");
	output=fopen("Data_analysis_result.txt","w");

	char name[100];
	float value_1,value_2,value_3;
	int i;

	//type 1 call mean
	for ( i = 0; i < 53590; ++i)
		{
			fscanf(x1_value,"%s\t%f\n",name,&value_1);
			fscanf(x2_value,"%s\t%f\n",name,&value_2);
			fscanf(y_value,"%s\t%f\n",name,&value_3);
			mean_x1+=value_1;
			mean_x2+=value_2;
			mean_y+=value_3;
		}
		mean_x1/=53590;
		mean_x2/=53590;
		mean_y/=53590;
	//type 2 call mean
		for ( i = 0; i < 186; ++i)
		{
			fscanf(y_reduced,"%s\t%f\n",name,&value_1);
			mean_y_reduced+=value_1;
		}
		mean_y_reduced/=186;

	//type 3 call mean
	
	for ( i = 0; i < 186; ++i)
		{
			fscanf(x1_x2_reduced,"%s\t%f\t%f\n",name,&value_1,&value_2);
			mean_x1_reduced+=value_1;
			mean_x2_reduced+=value_2;
		}
		mean_x1_reduced/=186;
		mean_x2_reduced/=186;
	//type 1 call variance
	
	for ( i = 0; i < 53590; ++i)
		{
			fscanf(x1_value,"%s\t%f\n",name,&value_1);
			fscanf(x2_value,"%s\t%f\n",name,&value_2);
			fscanf(y_value,"%s\t%f\n",name,&value_3);
			variance_x1+=(value_1-mean_x1)*(value_1-mean_x1);
			variance_x2+=(value_2-mean_x2)*(value_2-mean_x2);
			variance_y+=(value_3-mean_y)*(value_3-mean_y);
		}
		variance_x1/=53589;
		deviation_x1=sqrt(variance_x1);
		variance_x2/=53589;
		deviation_x2=sqrt(variance_x2);
		variance_y/=53589;
		deviation_y=sqrt(variance_y);
	//type 2 call variance
	
	for ( i = 0; i < 186; ++i)
		{
			fscanf(y_reduced,"%s\t%f\n",name,&value_1);
			variance_y_reduced+=(value_1-mean_y_reduced)*(value_1-mean_y_reduced);
		}
		variance_y_reduced/=185;
		deviation_y_reduced=sqrt(variance_y_reduced);

	//type 3 call variance

		for ( i = 0; i < 186; ++i)
		{
			fscanf(x1_x2_reduced,"%s\t%f\t%f\n",name,&value_1,&value_2);
			variance_x1_reduced+=(value_1-mean_x1_reduced)*(value_1-mean_x1_reduced);
			variance_x2_reduced+=(value_2-mean_x2_reduced)*(value_2-mean_x2_reduced);
		}
		variance_x1_reduced/=185;
		deviation_x1_reduced=sqrt(variance_x1_reduced);
		variance_x2_reduced/=185;
		deviation_x2_reduced=sqrt(variance_x2_reduced);

	fprintf(output, "$$$$$$$$$$$$$$$$$$$$$$$$$$$DATA ANALYSIS OF WHOLE DATA$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	fprintf(output, "\n\n1.MEAN:-\nx1=%f\nx2=%f\ny=%f\n",mean_x1,mean_x2,mean_y );
	fprintf(output, "\n\n\n2.VARIANCE:-\nx1=%f\nx2=%f\ny=%f\n",variance_x1,variance_x2,variance_y);
	fprintf(output, "\n\n\n2.STANDARD DEVIATION:-\nx1=%f\nx2=%f\ny=%f\n\n\n",deviation_x1,deviation_x2,deviation_y);
	fprintf(output, "$$$$$$$$$$$$$$$$$$$$$$$$$$$DATA ANALYSIS OF REDUCED DATA$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	fprintf(output, "\n\n1.MEAN:-\nx1 =%f\nx2=%f\ny=%f\n",mean_x1_reduced,mean_x2_reduced,mean_y_reduced );
	fprintf(output, "\n\n\n2.VARIANCE:-\nx1=%f\nx2=%f\ny=%f\n",variance_x1_reduced,variance_x2_reduced,variance_y_reduced);
	fprintf(output, "\n\n\n2.STANDARD DEVIATION:-\nx1=%f\nx2=%f\ny=%f\n\n\n",deviation_x1_reduced,deviation_x2_reduced,deviation_y_reduced);

	fclose(x1_value);
	fclose(x2_value);
	fclose(y_value);
	fclose(y_reduced);
	fclose(x1_x2_reduced);
	fclose(output);
	return 0;
}
