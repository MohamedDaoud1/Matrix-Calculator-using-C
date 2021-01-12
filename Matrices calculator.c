#include<stdio.h>
#include<stdlib.h>
#include<cstdlib> 
#include<conio.h>

// Functions prototype
void Sum(double Mat1[][100] , double Mat2[][100] , double Mat3[][100] , int row , int column );
void Subtract(double Mat1[][100] , double Mat2[][100] , double Mat3[][100] , int row , int column );
void Multiply(double Mat1[][100] , double Mat2[][100] , double Mat3[][100] , int row,int column );
void Possible_Operations(int Row1,int Column1,int Row2,int Column2);
void Get_Matrix_Values(int Row1,int Column1,int Row2,int Column2,double Mat1[][100] , double Mat2[][100]);
void Print_Matrix(double Mat[][100],int row , int column,int MatNum);
double Determinant_2(double InputMatrix[][100]);
double Determinant_large(double InputMatrix[][100],int InputSize);
double Determinant_For_Adjoint_Matrix(double InputMatrix[][100],int InputSize,int r , int c);
void Transpose(double InputMatrix[][100],int InputSize, double OutputMatrix [][100]);
void Inverse_Matrix(double InputMatrix[][100],int InputSize, double OutputMatrix [][100]);
void Multiply_By_Constant(double InputMatrix[][100],int InputSize, double OutputMatrix [][100],int Constant );
int Menu();
void Power(double InputMatrix[][100]  , double OutputMatrix[][100] , int InputSize);
void main();
void Check_Symmetry(double InputMatrix[][100]  , int InputSize, int Num);
void Check_Diagonal(double InputMatrix[][100]  , int InputSize, int Num);
void Division(double Mat1[][100] , double Mat2[][100] , double Mat3[][100] , int size );
void Multiply_For_Linear_System(double Mat1[][1] , double Mat2[][100] , double Mat3[][1] , int row,int column );
void Linear_Equations(double Mat1[][100],int Row1, int Column1);
double Trace(double Mat[][100],int row);
void Reduced_Row_Echelon_Form(double Mat1[][100],int Row1, int Column1);
double Trace(double Mat[][100],int row);

//Functions

// This function prints name, section, and ID
void MohAshraf()  
{
	printf("Mohamed Ashraf Gamal El Din Dawoud\n");// Print my name
	printf("Section: 1\tID:13p1085\n");// Print my section & ID
	printf("===========================================================\n\n\n\n");
} 

// This function finds the summation of 2 matricies
void Sum(double Mat1[][100] , double Mat2[][100] , double Mat3[][100] , int row , int column ) 
{
	for(int n = 0 ; n < row ; n++) // Rows counter 
	{
		for(int i = 0 ; i< column ; i++) // Columns counter 
		{
			Mat3[n][i]=Mat1[n][i]+Mat2[n][i]; // Finding the summation of 2 elements 
		}

	}

}

// This function finds the subtaraction of 2 matricies
void Subtract(double Mat1[][100] , double Mat2[][100] , double Mat3[][100] , int row , int column ) 
{
	for(int n = 0 ; n < row ; n++) // Rows counter 
	{
		for(int i = 0 ; i< column ; i++) // Columns counter 
		{
			Mat3[n][i]=Mat1[n][i]-Mat2[n][i]; // Finding the Subtract of 2 elements 
		}

	}

}

// This function finds the multiplication of 2 matricies
void Multiply(double Mat1[][100] , double Mat2[][100] , double Mat3[][100] , int row1, int common,int column2 ) 
{
	int n=0,k=0,m=0;
	double sum=0;
	for (n = 0; n < row1 ; n++)  // Rows counter 
	{
      for (m = 0; m < column2 ; m++) // Rows counter 
	  {
         sum = 0;
         for (k = 0; k < common ; k++)  // Columns counter 
		 {
            sum += Mat1[n][k] * Mat2[k][m]; // Finding the summation of multiplication of each element in the row by each element the column
         }
         Mat3[n][m] = sum; //Put the result as an element in the Answer matrix
      }
   }
}

// Instead of using "Multiply" function, this function will multiply 2 matricies, first one has only 1 row and 
// the second one has only 1 column ( to reduce consumed RAM size ) in solving system of linear equations
void Multiply_Linear_Equations(double Mat1[][100] , double Mat2[][1] , double Mat3[][1] , int row,int column ) 
{
	int n=0,k=0,m=0;
	double sum=0;
	for (n = 0; n < row ; n++)  // Rows counter 
	{
      for (m = 0; m < row ; m++)  // Rows counter 
	  {
         sum = 0;
         for (k = 0; k < column ; k++) // Columns counter 
		 {
            sum += Mat1[n][k] * Mat2[k][m]; // Finding the summation of multiplication of each element in the row by each element the column
         }
         Mat3[n][m] = sum; //Put the result as an element in the Answer matrix
      }
   }
}

// This function will multiply any matrix by a constant number
void Multiply_By_Constant(double InputMatrix[][100],int row , int column , double OutputMatrix[][100])
{
	double Constant;
	printf("Enter the constant\n"); // Ask user to enter the constant
	scanf("%lf",&Constant);			// Store the constant in variable "Constant"

	for(int n =0;n<row;n++) // Rows counter
	{
		for(int m =0;m<column;m++) // Columns counter
		{
			OutputMatrix[n][m]=Constant*InputMatrix[n][m]; //Multiply each element in the matrix by the constant
		}

	}
}

// This fucntion finds the determinant of 2*2 matrix 
double Determinant_2(double InputMatrix[][100])
{
	double dete=0;
	dete=InputMatrix[0][0]*InputMatrix[1][1]-InputMatrix[0][1]*InputMatrix[1][0]; // Cross multiplication
	return dete;
}

// This fucntion finds the determinant of matrix has size larger than 2*2
double Determinant_large(double InputMatrix[][100],int InputSize)
{

	int  Sub_Matrix_Size=(InputSize-1);
	int n=0,m,i,l,x=0,y=0;
	double Sub_Matrix[100][100];
	double dete=0,minor=0;
	double ret=0;
	if(InputSize==2)
		{
			dete=Determinant_2(InputMatrix); // If the matrix size is 2, recall "Determinant_2" to find its determinante 
		}
	if(InputSize!=2)
	{
		for(m=0;m<InputSize;m++) // Eliminated columns counter
			{
				for(i=0;i<InputSize;i++) //Columns counter
				{
					if(i==n) continue; // First row is always eliminated
					for(l=0;l<InputSize;l++) //Columns counter
					{
						if(l==m) continue; // Eliminate the column
						Sub_Matrix[x][y]=InputMatrix[i][l]; // Create a sub matrix that does not contain the eliminated row and column
						y++; // Columns counter for sub matrix
					}
					y=0;
					x++;	 // Rows counter for sub matrix
				}
				x=0;
				if(InputSize!=2)
				{
					ret=Determinant_large(Sub_Matrix, Sub_Matrix_Size); // Recall "Determinant_large" to find sub matricies until the sub matrix size is 2 (Recursion)
					if(m%2==1) // Select the sign (+ve or -ve) of the eliminated element
					{
						dete+=-1*InputMatrix[n][m]*ret; // Multiply the determinant of sub matrix by the eliminated element
					}
					else if (m%2==0)
					{
						dete+=InputMatrix[n][m]*ret; // Multiply the determinant of sub matrix by the eliminated element
					}
										
				}
			}
		}

	
			
	return dete; //Return the determinant value
}

// Adjoint matrix requires each element to be eliminated with his row and column, and hence finding the determinant of submatrix, 
// this function do the pervious process
double Determinant_For_Adjoint_Matrix(double InputMatrix[][100],int InputSize,int r , int c)
{

	int  Sub_Matrix_Size=(InputSize-1);
	int n=0,m,i,l,x=0,y=0;
	double Sub_Matrix[100][100];
	double minor=0;
	double ret=0;
	if(InputSize==2) //If the matrix size is 2
		{
			minor=Determinant_2(InputMatrix); // Recall "Determinant_2" to calculate the determinant 
			return minor;
		}
	
	if(InputSize!=2 )
	{
		for(i=0;i<InputSize;i++) // Rows counter
		{
			if(i==r) continue; // Eliminate the row
			for(l=0;l<InputSize;l++) // Columns counter
			{
				if(l==c) continue; // Eliminate the column
				Sub_Matrix[x][y]=InputMatrix[i][l]; // Create a sub matrix that does not contain the eliminated row and column
				y++; // Columns counter for sub matrix
			}
			y=0;
			x++; // Rows counter for sub matrix
		}
		x=0;
	}
	if(InputSize!=2)
		{
			minor=Determinant_large(Sub_Matrix, Sub_Matrix_Size); // Recall "Determinant_large" to find sub matricies until the sub matrix size is 2
			return minor; //Return the minor value
								
		}
		
}

// This function finds the transpose of any matrix
void Transpose(double InputMatrix[][100],int InputSize, double OutputMatrix [][100])
{
	for(int n = 0; n<InputSize ; n++) // Rows counter
	{
		for(int i= 0; i<InputSize ; i++) // Columns counter 
		{
			OutputMatrix [i][n]= InputMatrix[n][i]; //Finding the transpose matrix
		}
	}
}

// This function finds the invers of a square matrix
void Inverse_Matrix(double InputMatrix[][100],int InputSize, double OutputMatrix [][100], int *P_state)
{
	double Trans[100][100];
	double Adjoint[100][100];
	double Deter;
	double Deter_1;
	Deter=Determinant_large(InputMatrix,InputSize); //Find the determinante of the matrix
	if(Deter==0) 
	{
		*P_state=0; //Return if the determinante = 0 
		return;
	}

	Transpose(InputMatrix, InputSize, Trans); // Recall "Transpose", to find the transpose matrix
	if(InputSize!=2)
	{
		for(int n =0;n<InputSize;n++) // Eliminated rows counter
		{
			for(int m =0;m<InputSize;m++) // Eliminated columns counter
			{
				Adjoint[n][m]=Determinant_For_Adjoint_Matrix(Trans, InputSize, n , m); // Recall "Determinant_For_Adjoint_Matrix", to create sub matrix does not contain row and column of the eliminated element
			}

		}
		
	}
	if(InputSize==2) // If the matrix size is 2*2 (Special case)
	{
		for(int n =0;n<InputSize-1;n++) // Rows counter
		{
			for(int m =0;m<InputSize-1;m++) // columns counter
			{
				Adjoint[n][m]=InputMatrix[n+1][m+1];
				Adjoint[n+1][m+1]=InputMatrix[n][m];
				Adjoint[n][m+1]=-1*InputMatrix[n][m+1];
				Adjoint[n+1][m]=-1*InputMatrix[n+1][m];
			}

		}
	}
	 
	Deter_1=1.0/Deter; // Inverse the determinante
		
	for(int n =0;n<InputSize;n++) // Rows counter
	{		
		for(int m =0;m<InputSize;m++) // columns counter
		{
			OutputMatrix[n][m]=Deter_1*Adjoint[n][m]; // Multiply each element in the matrix by the inversed determinante
		}
		
	}
	if(InputSize!=2)
	{
		for(int a =0;a<InputSize;a++) // Rows counter
		{
			for(int b =0;b<InputSize;b++) // columns counter
			{
					if(a%2!=0&&b%2==0) OutputMatrix[a][b]=-1*OutputMatrix[a][b]; // Multiply by -ve if required	
					if(a%2==0&&b%2!=0) OutputMatrix[a][b]=-1*OutputMatrix[a][b]; // Multiply by -ve if required	
			}
		}
	}
}

// This function gets the power of a given matrix to a certain number
void Power(double InputMatrix[][100]  , double OutputMatrix[][100] , int InputSize)
{
	int power;
	double Sub_Matrix[100][100];
	printf("Enter the power \n"); // Ask user to enter the power
	scanf("%d",&power);			  // Store the power in variable "power"

	for(int n = 0 ; n < InputSize ; n++) // Create diagonal matrix, each element of its diagonal = 1 , other elements = 0 
	{
		for(int i = 0 ; i < InputSize ;i++)
		{
			if(i==n)
			{
				Sub_Matrix[n][i]=1; // Put 1 in each diagonal element
				continue;
			}
			Sub_Matrix[n][i]=0; // Put 0  in other elements
		}
	}
	for(int p = 0 ; p < power; p++)
	{
		Multiply( InputMatrix , Sub_Matrix , OutputMatrix , InputSize,InputSize,InputSize ); // Recall "Multiply" function, to Multiply the matrix by itself 
		
		// Put the result in the OutputMatrix Matrix
		for(int n = 0 ; n < InputSize ; n++)  // Rows counter
		{
			for(int i = 0 ; i < InputSize ;i++) // Columns counter
			{
				Sub_Matrix[n][i]=OutputMatrix[n][i]; // Copy elements
			}
		}
	}
}

// This function checks if a given matrix is symmetric
void Check_Symmetry(double InputMatrix[][100]  , int row, int column, int Num)
{
	if(row!=column) // If the row does not equal column (not square), the matrix will be asymmetric
	{
		printf("Matrix %d is asymmetric\n\a",Num);
		printf("Matrix %d is not square matrix\n\a",Num);
		return;
	}
	for(int n = 0 ; n < row ; n++)
	{
		for(int i = 0 ; i < column ; i++)
		{
			if(i==n) continue;
			if(InputMatrix[n][i]!=InputMatrix[i][n])
			{
				printf("Matrix %d is asymmetric\n\a",Num); // If the matrix is not equal to its transpose, the matrix is asymmetric
				return;
			}
		}
	}
	printf("Matrix %d is symmetric\n\a",Num); // If the matrix is equal to its transpose, the matrix is symmetric
}

// This function checks if a given matrix is diagonal
void Check_Diagonal(double InputMatrix[][100]  ,int row, int column, int Num)
{
	if(row!=column) // If the row does not equal column (not square), the matrix will be asymmetric
	{
		printf("Matrix %d is not diagonal\n\a",Num);
		return;
	}
	for(int n = 0 ; n < row ; n++)
	{
		for(int i = 0 ; i < column ; i++)
		{
			if(i==n) continue; //  Ignore diagonal elements
			if(InputMatrix[n][i]!=0)
			{
				printf("Matrix %d is not diagonal\n\a",Num); // If the other elements are not zero, the matrix is not diagonal
				return;
			}
		}
	}
	printf("Matrix %d is diagonal\n\a",Num); // If the other elements are zero, the matrix is diagonal
}

// This function divides two matrices.
void Division(double Mat1[][100] , double Mat2[][100] , double Mat3[][100] , int size )
{
	 double Sub_Matrix[100][100];
	 int state_inverse=1;
	 for(int n = 0 ; n < size  ; n++)
	 {
		 for(int i = 0 ; i < size ; i++)
		 {
			 if(i==n)
			 {
				Sub_Matrix[n][i]=1;
				continue;
			 }
			 Sub_Matrix[n][i]=0;
		 }
	 }

	 Inverse_Matrix( Mat2, size,  Mat3,&state_inverse); // Recall "Inverse_Matrix", to find the matrix 2 inverse 
	 if(state_inverse==0) // If determinante = 0
		{			
			printf("Operation can not be calculated \n"); // Erorr message
			return ;
		}

	 Multiply(Mat1, Mat3, Sub_Matrix , size,size,size ); // Recall "Multiply", to find the multiplication of first matrix by the inverse of second
												   // matrix,which is equivalent to dividing the first matrix by the second matrix 

}

// This function solves system of linear equations 
void Linear_Equations(double Mat1[][100],int Row1, int Column1)
{
	
	int state=1;
	if(Row1<Column1-1) // If the number of unknowns is larger than the number of equations, the system has infinite number of solutions
	{
		printf("The system has infinite number of solutions\n\a");
		return ;
	}
	
	double Constants[100][1];
	double SubMatrix[100][100];
	double Result[100][1];
	int Constant_size=0;
	for(int n = 0 ; n < Column1-1 ; n++)
	{
		Constants[n][0]=Mat1[n][Column1-1]; // Take the constant term from each equation
		Constant_size++;
	}

	for(int m = 0 ; m < Column1-1 ; m++)
	{
		for(int i = 0 ; i < Column1-1 ; i++)
		{
			SubMatrix[m][i]=Mat1[m][i]; // Take the coefficients of unknowns from each equation 
		}

	}
	Inverse_Matrix( SubMatrix, Column1-1,  SubMatrix, &state ); // Recall "Inverse_Matrix", to find the inverse of sub matrix (which contains the coefficients)
	if(state==0) // If the determinante = 0, the system has no solution (infinite number of solutions has been checked)
	{
		printf("The system has no solution \a\n");
		return;	
	}

	Multiply_Linear_Equations(  SubMatrix,Constants  ,  Result ,  Constant_size,Constant_size );  // Get the value of each unknown
	for(int l=0 ; l<Column1-1; l++)
	{
		printf("x%d = %.4lf \n",l+1,-Result[l][0]);  // Print the value of each unknown
	}
	return;
}

//This function check if the system of linear equations has infinite number of solution
int Check_Infinite_Number_Of_Solution_Remove_IT(double Mat1[][100],int Row1, int Column1)
{
	double factor;
	int Output_Size=Row1,x=0,i=1;
	for(int n=0; n < Output_Size ; n++) // Rows counter
	{
		
		if(Mat1[n+i][x]!=0 && Mat1[n][x]!=0)
		{
			factor=Mat1[n][x]/Mat1[n+i][x]; // Get scalling factor
		}
		else if (Mat1[n+i][x]==0 && Mat1[n][x]!=0)
		{
			continue; // 2 Equations are not dependant
		}
		else if (Mat1[n][x]==0)
		{
			x++; // Choose answer coefficients to get the scalling factor
			n--; // Stay at the same equation
		}
		for(int m=0; m < Column1 ; m++) // Columns counter
		{

			if(Mat1[n][m]/Mat1[n+i][m] != factor) // Check if dependant
				break;
			if(m==Column1-1)
			{
				for(int l = n ; n < Output_Size ; n++) // Remove dependant equation
				{
					for(int r=0; r < Column1 ; r++)
					{
						Mat1[n][r]=Mat1[n+i][r];
					}
				}
				Output_Size--; //Decrease the number of equations
			}
		}
		x=0;
		if(i<Output_Size)
		{
			i++;
			n--;
		}
	}
	return Output_Size; // Return the new number of equations
}

// This function will decide possible operations depending on the size of each matrix
void Possible_Operations(int Row1,int Column1,int Row2,int Column2,int x,int *state1 ,int *state2)
{
	
	if(x!=3) printf("\n----------------------\n\n");
	if(x==2) // Print possible operations of 2 matricies operations
	{
		if(Row1==Row2 && Column1==Column2 && Column1==Row1) // If 2 matricies are square
		{
			printf("Possible operations: \n1- Summation\n2- Subtraction\n3- Multiplication\n4- Division\n");
			*state2 = 1;
		}
		else if(Row1==Row2 && Column1==Column2) // If 2 matricies are not square, but have the same size
		{
			printf("Possible operations: \n1- Summation\n2- Subtraction\n");
			*state2 = 2;
		}
		else if(Column1==Row2) // If 2 matricies are not square matricies, but multiplication could be calculated (R1*C1, R2*C2, and C1 = R2)
		{
			printf("Possible operations: \n1- Multiplication\n");
			*state2 = 3;
		}
		else
		{
			*state2 = 4;
		}

	}
	else if(x==1 && Column1==Row1) // Print possible operations of single matrix operations if the matrix is square
	{
		printf("Possible operations: \n1- Power\n2- Determinant\n3- Transpose\n4- Inverse \n5- Multiply by constant\n6- Trace\n7- Is a given matrix symmetric?\n8- Is a given matrix diagonal?\n");
		*state1 = 1;
	}
	else if(x==1 && Column1!=Row1) // Print possible operations of single matrix operations if the matrix is not square
	{
		printf("Possible operations: \n1- Multiply by constant\n2- Transpose \n");
		*state1 = 2;
	}	
	else if(Row1!=Row2 && x!=3|| Column1!=Column2 && x!=3 || Row1!=Column1 && x!=3 || Row2!=Column2 && x!=3)
	{
		printf("ERROR .. invalid input\n");
		return;
	}
	if(x!=3)printf("\n----------------------\n\n");
}

// This function will print a given matrix
void Print_Matrix(double Mat[][100],int row , int column,int MatNum)

{
	if(MatNum==3) 
	{
		printf("RESULT: \n\n\a");
	}

	for(int n = 0; n<row ; n++) // Rows Counter
	{
		for(int i= 0; i<column ; i++) // Columns counter
		{
			printf("%9.3lf    ",Mat[n][i]);
		}
		printf("\n");
	}
	printf("\n----------------------\n\n");
}

// This function will ask the user to enter the elements of each matrix
void Get_Matrix_Values(int Row1,int Column1,int Row2,int Column2,double Mat1[][100] , double Mat2[][100])
{
	for(int n = 0; n<Row1 ; n++) // Rows Counter
	{
		for(int i= 0; i<Column1 ; i++) // Columns counter
		{
			printf("Enter the element %d*%d in the first matrix\n",n+1,i+1); // Ask the user to enter the element
			scanf("%lf",&Mat1[n][i]);										 // Store the element in first matrix
		}

	}
	printf("\n----------------------\n\n");
	for(int n = 0; n<Row2 ; n++) // Rows Counter
	{
		for(int i= 0; i<Column2 ; i++) // Columns counter
		{
			printf("Enter the element %d*%d in the second matrix \n",n+1,i+1); // Ask the user to enter the element
			scanf("%lf",&Mat2[n][i]);										   // Store the element in first matrix
		}

	}
	if(Row2==0) return;
	printf("\n----------------------\n\n");
}

// This function calculates the trace of square matrix
double Trace(double Mat[][100],int row)
{
	double Trac=0;
	for(int i=0 ; i < row ; i++) // Columns & Rows counter
	{
		Trac+=Mat[i][i]; // Sum the diagonal elements
	}
	return Trac; // Return the value of "Trac"
}

// This function displays the main menu of the program
int Menu()
{
	int x;
	printf("Enter a number of the operation: \n"); // Ask the user to enter the number of operation
	printf("1- Single matrix operations (Transpose, Inverse, etc)\n");
	printf("2- Two matrices operations (Summation, Subtraction,etc)\n");
	printf("3- System of linear equations\n");
	printf("4- Close the program\n");
	scanf("%d",&x);
	if (x==4) exit(0); // Close the program
	if(x>3 && x!=3 || x<1 && x!=3)
	{
		printf("Wrong number !! \n");
		return 0;
	}
	return x;
}

// Main function
void main()
{
	while(1)
	{
	char Choice;
	double Mat1[100][100],Mat2[100][100],Mat3[100][100];
	double DETER,trace;
	int Row1,Column1,Row2=0,Column2=0;
	int x,state_T_F=1;
	int c=0,c1=0,c2=0;
	int state1=0 , state2=0 , *P_state1 , *P_state2, state_inverse=1;
	int Size_SLE_AFTER_CHECK; // Size of system of linear equations after removing dependant equations
	P_state1 = &state1;
	P_state2 = &state2;
	
	MohAshraf();	//Recall MohAshraf function to print name, section & ID
	x=Menu();		// Recall Menu function to display the main menu, and returns the number of operation 
	
	printf("Enter the size of Matrix 1 (e.g 3*3) \n");  // Ask the user to enter a size of first matrix
	scanf("%d*%d",&Row1,&Column1);			    		// Get the size of first matrix from the user
	
	if(x==2) // If the operation requires 2 matricies, get the size of second matrix
	{
		printf("Enter the size of Matrix 2 (e.g 3*3)\n");// Ask the user to enter a size of second matrix
		scanf("%d*%d",&Row2,&Column2);					 // Get the size of second matrix from the user
	}

	Possible_Operations( Row1, Column1, Row2, Column2,x,P_state1,P_state2); // Recall "Possible_Operations" function, to determine which operations could be produced
	
	if(state1==1 || state1==2 || state2==1 || state2==2 || state2==3)
	{
		printf("Enter the number of operation\n");
		scanf("%d",&c);
	}
	if(state1==1 && x==1 || state1==2 && x==1)
	{
		c1=c;
	}
	else if(state2==1 && x==2 || state2==2 && x==2 || state2==3 && x==2 || state2==4 && x==2)
	{
		c2=c;
	}
	
	if((c1>8 && state1 ==1)||(c1>2 && state1==2))	  // If the input choice is wrong, restart the program
	{
		printf("\nWrong number !! \n");
		state_T_F=0;
	}		
	if(c2==0 && x==2 || (c2>2 && state2==2)|| (c2>4 && state2 ==1) || (c2>1 && state2 ==3))  // If the input choice is wrong, restart the program
	{
		printf("\nWrong number !! \n");
		state_T_F=0;
	}

	// If the user chose solving system of linear equations
	if(x==3) printf("\nEnter coefficients by this sequanse:\nAnXn-1 + An-1Xn-2 + ...... + A0 = 0\n"); 
	if(state_T_F==1)Get_Matrix_Values( Row1, Column1, Row2, Column2, Mat1, Mat2);
	
	if(x==1&&state_T_F==1) // If single matrix operation
	{
		Check_Symmetry( Mat1, Row1,Column1, 1); // Check matrix if it symmetric
		Check_Diagonal( Mat1, Row1,Column1, 1); // Check matrix if it diagonal
		switch (state1)
		{
		case 1: // If matix 1 is square matrix
			switch (c)
			{
			case 1: // If user wants to get the power of the matrix to a certain number 
				for(int k = 0 ; k < Row1; k++)
				{
					Mat3[k][k]=1;
				}
				Power( Mat1, Mat3 , Row1);			  // Recall "Power" to get the power of the matrix to a certain number 
				Print_Matrix(Mat1, Row1 , Column1,1); // Print the original matrix
				Print_Matrix(Mat3, Row1 , Column1,3); // Print the result
				break;
			case 2: // If user wants to calculate the determinant of the matrix 
				DETER=Determinant_large(Mat1, Row1);  // Recall "Determinant_large" to calculate the determinant of the matrix 
				Print_Matrix(Mat1, Row1 , Column1,1); // Print the original matrix
				printf("Determinant = %.2lf\n\a",DETER);            // Print the result
				break;
			case 3: // If user wants to find the transpose matrix 
				Transpose(Mat1, Row1, Mat3); // Recall "Transpose" function to find the transpose matrix 
				Print_Matrix(Mat1, Row1 , Column1,1); // Print the original matrix
				Print_Matrix(Mat3, Column1 ,Row1,3);  // Print the result
				break;
			case 4: // If user wants to find the inverse matrix
				Inverse_Matrix(Mat1, Row1,Mat3,&state_inverse);  // Recall "Inverse_Matrix" function to find the inverse matrix
				if(state_inverse==0)
				{
					printf("Inverse can not be determined \n");
					printf("Determinant = ZERO !\n");
				}

				Print_Matrix(Mat1, Row1 , Column1,1); // Print the original matrix
				Print_Matrix(Mat3, Row1 , Column1,3); // Print the result
				break;
			case 5: // If user wants to multiply the matrix by constant 
				Multiply_By_Constant( Mat1, Row1 , Column1 , Mat3); // Recall "Multiply_By_Constant" function to multiply the matrix by constant 
				Print_Matrix(Mat1, Row1 , Column1,1); // Print the original matrix
				Print_Matrix(Mat3, Row1 , Column1,3); // Print the result
				break;
			
			case 6: // If user wants to calculate the matrix trace
				trace=Trace( Mat1, Row1); // Recall "Trace" function to calculate the matrix tracet 
				Print_Matrix(Mat1, Row1 , Column1,1); // Print the original matrix
				printf("Trace= %.3lf\n\a",trace);			  // Print the result
				
				break;
			case 7:
				Print_Matrix(Mat1, Row1 , Column1,1); // Print the original matrix
				break;
			case 8:
				Print_Matrix(Mat1, Row1 , Column1,1); // Print the original matrix
				break;

			break;
			}
			break;
		case 2: // If matix 1 is not square matrix
			switch (c)
			{
			case 1:										  // If user wants to multiply the matrix by constant 
				Multiply_By_Constant( Mat1, Row1 , Column1 , Mat3); // Recall "Multiply_By_Constant" function to multiply the matrix by constant 
				Print_Matrix(Mat1, Row1 , Column1,1);	  // Print the original matrix
				Print_Matrix(Mat3, Row1 , Column1,3);	  // Print the result
				break;
			
				case 2: // If user wants to find the transpose matrix 
				if(Row1>Column1)
				{
					Transpose(Mat1, Row1, Mat3);     // Recall "Transpose" function to find the transpose matrix 
				}
				else if (Row1<Column1)
				{
					Transpose(Mat1, Column1, Mat3); // Recall "Transpose" function to find the transpose matrix
				}

				Print_Matrix(Mat1, Row1 , Column1,1); // Print the original matrix
				Print_Matrix(Mat3, Column1 ,Row1,3);  // Print the results
				break;
			}
		}	
	}

	if(x==2&&state_T_F==1) // If 2 matricies operation
	{
		Check_Symmetry( Mat1, Row1, Column1, 1); // Check first matrix if it symmetric
		Check_Diagonal( Mat1, Row1, Column1, 1); // Check first matrix if it Diagonal
		Check_Symmetry( Mat2, Row2, Column2, 2); // Check second matrix if it symmetric
		Check_Diagonal( Mat2, Row2, Column2, 2); // Check second matrix if it Diagonal
		switch (state2) 
		{
		case 1:  // If 2 matricies are square matricies
			switch (c)
			{
			case 1: // If user wants to find the summation of 2 matricies
				Sum(Mat1,Mat2,Mat3, Row1 , Column1 ); // Recall "Sum" function to find the summation of 2 matricies
				Print_Matrix(Mat1, Row1 , Column1,1); // Print the first matrix
				Print_Matrix(Mat2, Row2 , Column2,2); // Print the second matrix
				Print_Matrix(Mat3, Row1 , Column1,3); // Print the result
				break;
			case 2: // If user wants to find the subtraction of 2 matricies
				Subtract(Mat1,Mat2,Mat3, Row1 , Column1 ); // Recall "Subtract" function to find the subtraction of 2 matricies
				Print_Matrix(Mat1, Row1 , Column1,1);	   // Print the first matrix
				Print_Matrix(Mat2, Row2 , Column2,2);	   // Print the second matrix
				Print_Matrix(Mat3, Row1 , Column1,3);	   // Print the result
				break;
			case 3: // If user wants to find the multiply of 2 matricies
				Multiply( Mat1 ,  Mat2 ,  Mat3 ,  Row1, Row2 , Column2 ); // Recall "Multiply" function to find the multiply of 2 matricies
				Print_Matrix(Mat1, Row1 , Column1,1);			   // Print the first matrix
				Print_Matrix(Mat2, Row2 , Column2,2);			   // Print the second matrix
				Print_Matrix(Mat3, Row1 , Column2,3);			   // Print the result
				break;
			case 4: // If user wants to find the division of 2 matricies
				Division( Mat1 ,  Mat2 ,  Mat3 ,  Row1 ); // Recall "Division" function to find the division of 2 matricies
				Print_Matrix(Mat1, Row1 , Column1,1);	  // Print the first matrix
				Print_Matrix(Mat2, Row2 , Column2,2);	  // Print the second matrix
				Print_Matrix(Mat3, Row1 , Column1,3);	  // Print the result
				break;
			}	
			break;
		case 2 : // If 2 matricies are not square matricies, but have the same size
			switch (c)
			{
			case 1: // If user wants to find the summation of 2 matricies
				Sum(Mat1,Mat2,Mat3, Row1 , Column1 ); // Recall "Sum" function to find the summation of 2 matricies
				Print_Matrix(Mat1, Row1 , Column1,1); // Print the first matrix
				Print_Matrix(Mat2, Row2 , Column2,2); // Print the second matrix
				Print_Matrix(Mat3, Row1 , Column1,3); // Print the result
				break;

			case 2: // If user wants to find the subtraction of 2 matricies
				Subtract(Mat1,Mat2,Mat3, Row1 , Column1 ); // Recall "Subtract" function to find the subtraction of 2 matricies
				Print_Matrix(Mat1, Row1 , Column1,1);	   // Print the first matrix
				Print_Matrix(Mat2, Row2 , Column2,2);	   // Print the second matrix
				Print_Matrix(Mat3, Row1 , Column1,3);	   // Print the result
				break;
			}
			break;
		case 3: // If 2 matricies are not square matricies, but multiplication could be calculated (R1*C1, R2*C2, and C1 = R2)
			Multiply( Mat1 ,  Mat2 ,  Mat3 ,   Row1, Row2 , Column2  );  // Recall "Multiply" function to find the multiply of 2 matricies
			Print_Matrix(Mat1, Row1 , Column1,1);				// Print the first matrix
			Print_Matrix(Mat2, Row2 , Column2,2);				// Print the second matrix
			Print_Matrix(Mat3, Row1 , Column2,3);				// Print the result
			break;

		case 4 : // If 2 matricies are not square matricies, and no operations can be calculated
			printf("No operations can be calculated \n\a");
			break;
		}
	}
	if(x==3&&state_T_F==1) // If solving system of linear equations
	{
		Size_SLE_AFTER_CHECK=Check_Infinite_Number_Of_Solution_Remove_IT(Mat1,Row1, Column1); // Recall "Check_Infinite_Number_Of_Solution_Remove_IT", to remove dependant equations
		Linear_Equations(Mat1, Size_SLE_AFTER_CHECK,  Column1);  // Recall "Linear_Equations" function to solve system of linear equations
	}
	printf("Enter 'y' if you want to do another operation\nEnter any other key if you want to exit\n");
	Choice=getch();
	if(Choice=='y'||Choice=='Y')
	{
		system("cls"); // Clear window
	}
	else 
	{
		exit(0); // Close the program
	}
}
}
// Number of lines :)