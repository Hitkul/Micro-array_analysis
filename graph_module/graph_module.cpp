#include "stdio.h"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void draw_axis( int (*cell_matrix)[189]);
void get_data(int *data_values);
void draw_graph(int (*cell_matrix)[189], int *data_values);

int main()
{
	Mat img=imread("1.jpg",1),graph_base;
	int cell_matrix[203][189],data_values[186],i,j,k,l;

	for (i = 0; i < 203; ++i)
		for (j = 0; j < 189; ++j)
			cell_matrix[i][j]=0;


	if ( img.empty() ) 
    	{ 
	  cout << "Error loading the image" << endl;
	  exit(1);
     	}

     	Size size(960,1015);
     	resize(img, graph_base,size);

     	draw_axis(cell_matrix);
     	get_data(&data_values[0]);
     	draw_graph(cell_matrix, &data_values[0]);
     	
     	for (i = 0; i < 203; ++i)
		  { 
	    		for (j = 0; j < 189; ++j)
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
	    		}	
	  	}

     	imwrite("graph.png", graph_base);

	return 0;
}

void draw_axis( int (*cell_matrix)[189]){
     	int i,j;
     	//Y axis
     	for(i=0;i<203;i++)
     		cell_matrix[i][1]=1;
     	//X axis
     	for ( j = 0; j < 189; ++j)
     		cell_matrix[201][j]=1;
}

void get_data(int *data_values){
	int i;
	FILE *input_values;
	float value;
	char id[100];

	input_values= fopen("reduced_data.txt","r");

	for (i = 0; i < 186; ++i)
	{
		fscanf(input_values,"%s\t%f",id,&value);
		data_values[i]=(int)(value*100);
	}
}

void draw_graph(int (*cell_matrix)[189], int *data_values){
	int i,j,count=0;

	for (j = 3; j < 186; j++,count++)
	{
		i=603-data_values[count];
		cell_matrix[i][j]=1;
	}
}