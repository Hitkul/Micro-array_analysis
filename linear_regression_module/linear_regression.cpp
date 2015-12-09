#include "stdio.h"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void draw_axis( int (*cell_matrix)[1003]);
void get_data(int *data_values_x1,int *data_values_x2);
void draw_graph(int (*cell_matrix)[1003], int *data_values_x1,int *data_values_x2);
void line_cofficents(int *data_values_x1,int *data_values_x2, float *slop_of_line, float *y_intercept_of_line);
float mean(int *data);
void liner_regression_line(int (*cell_matrix)[1003],float *slop_of_line, float *y_intercept_of_line);


int main()
{	
	Mat img=imread("1.jpg",1),graph_base;
	int cell_matrix[768][1003],data_values_x1[186],data_values_x2[186],i,j,k,l;
	float slop_of_line,y_intercept_of_line;
	for (i = 0; i < 768; ++i)
		for (j = 0; j < 1003; ++j)
			cell_matrix[i][j]=0;


	if ( img.empty() ) 
    	{ 
	  cout << "Error loading the image" << endl;
	  exit(1);
     	}

     	Size size(5015,3840);
     	resize(img, graph_base,size);

     	draw_axis(cell_matrix);
     	get_data(&data_values_x1[0],&data_values_x2[0]);
     	draw_graph(cell_matrix, &data_values_x1[0],&data_values_x2[0]);
     	line_cofficents(&data_values_x1[0],&data_values_x2[0], &slop_of_line, &y_intercept_of_line);
     	liner_regression_line(cell_matrix,&slop_of_line,&y_intercept_of_line);

     	printf("Slop of regression line is ==>%f and y intercept is ==>%f\n",slop_of_line,y_intercept_of_line );

     	for (i = 0; i < 768; ++i)
		  { 
	    		for (j = 0; j < 1003; ++j)
	    		{ 
	      		if(cell_matrix[i][j]==1){
	      			for (k = i*5; k < i*5+6; ++k)
	      			{
	      				for ( l = j*5; l < j*5+6; ++l)
	      				{
	     					graph_base.at<cv::Vec3b>(k,l)[0] =0;
			    			graph_base.at<cv::Vec3b>(k,l)[1] =0;
		      	      			graph_base.at<cv::Vec3b>(k,l)[2] =255;
	      				}
	      			}
			      }

			      if(cell_matrix[i][j]==2){
	      			for (k = i*5; k < i*5+6; ++k)
	      			{
	      				for ( l = j*5; l < j*5+6; ++l)
	      				{
	     					graph_base.at<cv::Vec3b>(k,l)[0] =255;
			    			graph_base.at<cv::Vec3b>(k,l)[1] =0;
		      	      			graph_base.at<cv::Vec3b>(k,l)[2] =0;
	      				}
	      			}
			      }
	    		}	
	  	}

     	imwrite("regression_plot.png", graph_base);

	return 0;
}

void draw_axis( int (*cell_matrix)[1003]){
     	int i,j;
     	//Y axis
     	for(i=0;i<768;i++)
     		cell_matrix[i][1]=1;
     	//X axis
     	for ( j = 0; j < 1003; ++j)
     		cell_matrix[766][j]=1;
}

void get_data(int *data_values_x1,int *data_values_x2){
	int i;
	FILE *input_values;
	float value_x1,value_x2;
	char id[100];

	input_values= fopen("data.txt","r");

	for (i = 0; i < 186; ++i)
	{
		fscanf(input_values,"%s\t%f\t%f",id,&value_x1,&value_x2);
		data_values_x1[i]=(int)(value_x1*1000);
		data_values_x2[i]=(int)(value_x2*10);

		
	}
}

void draw_graph(int (*cell_matrix)[1003], int *data_values_x1,int *data_values_x2){
	
	int i,j,count;
	for (count=0; count < 186;count++)
	{	
		j=(int)(1003-data_values_x1[count]);
		i=(int)(768-data_values_x2[count]);
		cell_matrix[i][j]=1;	
	}

}

void line_cofficents(int *data_values_x1,int *data_values_x2, float *slop_of_line, float *y_intercept_of_line){
	float mean_x1,mean_x2,temp1=0.0,temp2=0.0,data_x1[186],data_x2[186];
	int i;
	for (i = 0; i < 186; ++i){
		data_x1[i]=(float)data_values_x1[i]/1000.0;
		data_x2[i]=(float)data_values_x2[i]/10.0;
	}
	mean_x1=mean(&data_values_x1[0]);
	mean_x2=mean(&data_values_x2[0]);

	for (i = 0; i < 186; ++i)
	{
		temp1=temp1+((data_values_x1[i]-mean_x1)*(data_values_x2[i]-mean_x2));
		temp2=temp2+((data_values_x1[i]-mean_x1)*(data_values_x1[i]-mean_x1));
	}

	*slop_of_line=temp1/temp2;
	*y_intercept_of_line=mean_x2- ((*slop_of_line)*mean_x1);
}

float mean(int *data){
	int sum=0,i;
	for (i = 0; i < 186; ++i)
	{
		sum=sum+data[i];
	}

	return sum/186;
}
void liner_regression_line(int (*cell_matrix)[1003],float *slop_of_line, float *y_intercept_of_line){
	int i,j;
	for (j = 3; j < 1003; ++j)
	{
		i= (int)(((*slop_of_line)*j)+(*y_intercept_of_line));
		cell_matrix[i][j]=2;
	}
}