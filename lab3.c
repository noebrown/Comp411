#include<stdio.h>
#include<stdlib.h> 

int getSize (char * s) {
/*  returns size of input string */ 
    char * t;
    for (t = s; *t != '\0'; t++);
    return t - s;
}

void lab_swap_strings(char* strA, char* strB) {
/* Swaps contents of two character arrays (strings) */
  char *temp = strA; 
  strA = strB; 
  strB = temp;
}

int lab_str_cmp(char* strA, char* strB){
/* returns               */
/*     1  if strA > strB */
/*     0  if strA = strB */
/*     -1 if strA < strB */
  while (*strA && *strA == *strB) { ++strA; ++strB; }
  return (int)(unsigned char)(*strA) - (int)(unsigned char)(*strB);
}

void lab_str_upper(char* str){
/* CAPITALIZES STRING s */
   int c = 0;
   
   while (str[c] != '\0') {
      if (str[c] >= 'a' && str[c] <= 'z') {
         str[c] = str[c] - 32;
      }
      c++;
   }
}

void lab_str_lower(char* str){
/* lowercases string s */
   int c = 0;
   
   while (str[c] != '\0') {
      if (str[c] >= 'A' && str[c] <= 'Z') {
         str[c] = str[c] + 32;
      }
      c++;
   }
}

void mystrcpy(char* str1, char* str2){
     while(*str2!='\0') 
     *str1++=*str2++; 
     *str1='\0'; 
     return; 
}

int main() {

	// Variables from Lab 2.
    char processors[10][100];
    char str_temp[100];
    char sortby[10];
    char threshold[10];
    float costs[10];
    float costs_temp[100];
    float clockrates[10];
    float clockrates_temp[100];
    float cpis[10];
    float executiontimes[10];
    float temp = 0.0;
    float temptwo = 0.0;
    float thresholdvalue;
	  int number_of_processors = 0;



	// Enter in all of the different processors, costs, clock rate and CPI
    printf("Please enter the number of processors [1 to 10]:\n");
    scanf("%d", &number_of_processors );

    for (int i=0; i<number_of_processors; i++ ) {
		printf("Processor Name (no spaces):\n" );
		scanf("%s", processors[i] );
		printf("Processor cost (US dollars):\n" );
		scanf("%f", &costs[i] );
		printf("Processor clock rate (in GHz):\n" );
		scanf("%f", &clockrates[i] );
		printf("Processor average CPI:\n" );
		scanf("%f", &cpis[i] );

		executiontimes[i] = (cpis[i]*(1/clockrates[i]))/100;
    }

    printf("Which value would you like to sort on (from lowest to highest)?\n");
    scanf("%s", sortby);


// sort lowest to highest by price
// price
if (lab_str_cmp(sortby, "price") == 0) {
    for ( int i=0; i<number_of_processors-1; i++ ) {
        for( int j=0; j < number_of_processors-i-1; j++ ) {
            
            if ( costs[j] > costs[j+1] ) {
            
                temp = executiontimes[j];
                executiontimes[j] = executiontimes[j+1];
                executiontimes[j+1] = temp;
                
                temp = clockrates[j];
                clockrates[j] = clockrates[j+1];
                clockrates[j+1] = temp;
                
                temp = cpis[j];
                cpis[j] = cpis[j+1];
                cpis[j+1] = temp;
            
                temp = costs[j];
                costs[j] = costs[j+1];
                costs[j+1] = temp;

                mystrcpy( str_temp, processors[j] );
                mystrcpy( processors[j], processors[j+1] );
                mystrcpy( processors[j+1], str_temp );
              }
    	   }
    }
}


// sort lowest to highest by clock rate
// rate
else if (lab_str_cmp(sortby, "rate") == 0) {
    for ( int i=0; i<number_of_processors-1; i++ ) {
        for( int j=0; j < number_of_processors-i-1; j++ ) {
            
            if ( clockrates[j] > clockrates[j+1] ) {
            
                temp = clockrates[j];
                clockrates[j] = clockrates[j+1];
                clockrates[j+1] = temp;

                temp = executiontimes[j];
                executiontimes[j] = executiontimes[j+1];
                executiontimes[j+1] = temp;
                
                temp = cpis[j];
                cpis[j] = cpis[j+1];
                cpis[j+1] = temp;
            
                temp = costs[j];
                costs[j] = costs[j+1];
                costs[j+1] = temp;

                mystrcpy( str_temp, processors[j] );
                mystrcpy( processors[j], processors[j+1] );
                mystrcpy( processors[j+1], str_temp );
              }
    	   }
    }
}


// sort lowest to highest by execution time
// time
else if (lab_str_cmp(sortby, "time") == 0) {
    for ( int i=0; i<number_of_processors-1; i++ ) {
        for( int j=0; j < number_of_processors-i-1; j++ ) {
            
            if ( executiontimes[j] > executiontimes[j+1] ) {
            
                temp = executiontimes[j];
                executiontimes[j] = executiontimes[j+1];
                executiontimes[j+1] = temp;
                
                temp = clockrates[j];
                clockrates[j] = clockrates[j+1];
                clockrates[j+1] = temp;
                
                temp = cpis[j];
                cpis[j] = cpis[j+1];
                cpis[j+1] = temp;
            
                temp = costs[j];
                costs[j] = costs[j+1];
                costs[j+1] = temp;

                mystrcpy( str_temp, processors[j] );
                mystrcpy( processors[j], processors[j+1] );
                mystrcpy( processors[j+1], str_temp );
              }
    	   }
    }
}


// sort lowest to highest by name
// name
else if (lab_str_cmp(sortby, "name") == 0) {
	printf("Will sort by name");
}


printf("Would you rather place emphasis on values above or below a certain threshold??\n");
//scanf("%s", threshold);
printf("What is the threshold value for your comparison?\n");
//("%f", thresholdvalue);


// // highlight above the threshold
// // above value <<<
// if (lab_str_cmp(threshold, "above") == 0) {
//   if (lab_str_cmp(sortby, "price") == 0) {
//     for ( int i=0; i<number_of_processors-1; i++ ) {
//       if(costs[i] > thresholdvalue) {
//       // str_temp = lab_str_upper(processors[i])
//       // mystrcpy( str_temp, processors[i] );
//       }
//     }
//   } else if (lab_str_cmp(sortby, "rate") == 0) {
//     // insert

//   } else if(lab_str_cmp(sortby, "time") == 0) {
//     // insert
//   }
// } 


// // highlight below the threshold
// // below  value >>>
// else if (lab_str_cmp(threshold, "below") == 0) {
//     if (lab_str_cmp(sortby, "price") == 0) {
//       for ( int i=0; i<number_of_processors-1; i++ ) {
//         if(costs[i] < thresholdvalue) {
//       }
//     }
//   } else if (lab_str_cmp(sortby, "rate") == 0) {

//   } else if(lab_str_cmp(sortby, "time") == 0) {

//   }
// }


//print final result
printf("Your emphasized list of processors is...\n");
if (lab_str_cmp(sortby, "price") == 0) {
      // final price print
      for (int i=0; i<number_of_processors; i++ ) {
        printf("%s: %.4f\n", processors[i], costs[i]);
    }
  } else if (lab_str_cmp(sortby, "rate") == 0) {  
      // final clock rate print  
    for (int i=0; i<number_of_processors; i++ ) {
      printf("%s: %.4f\n", processors[i], clockrates[i]);
    }
  } else if(lab_str_cmp(sortby, "time") == 0) { 
      // final execution time print    
    for (int i=0; i<number_of_processors; i++ ) {
        printf("%s: %.4f\n", processors[i], executiontimes[i]);
    }
  } else if(lab_str_cmp(sortby, "name") == 0) {
    for (int i=0; i<number_of_processors; i++ ) {
        printf("%s", processors[i]);
  }
}
    return 0;

}