#include <iostream>
#include <string>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <cmath>
#include<algorithm> 

using namespace std;


const char check = 'N';





std::vector<int> minValInTasks, secondMin;

//Here we assign empty value with 1000

int t0[7] = {13,79,23,71,60,27,2};
int t1[7] = {31,13,14,94,60,61,57};
int t2[7] = {17,1,1000,23,36,8,86};
int t3[7] = {19,28,10,4,58,73,40};
int t4[7] = {94,75,1000,58,1000,68,46};
int t5[7] = {8,24,3,32,4,94,89};
int t6[7] = {10,57,13,1,92,75,29};
int t7[7] = {80,17,38,40,66,25,88};



void printOutput(int task, int machine){
    cout << "Task : " << task << " is assigned to machine : " << machine <<"\n";
}


int minValueCheck(int arr[], int n){
    int minValue = arr[0];

    for(int i = 0; i < 7; ++i){
        if(arr[i] < minValue){minValue = arr[i];}
    }

    return minValue;
}

int assignMachine(int task, int time){
    int assignMachine;

    switch (task)
    {
    case 0:
        for(int i = 0; i < 7; i++){
            if(t0[i] == time)
            {
                assignMachine = i;
            }
        }
        break;
    case 1:
        for(int i = 0; i < 7; i++){
            if(t1[i] == time)
            {
                assignMachine = i;
            }
        }
        break;
    case 2:
        for(int i = 0; i < 7; i++){
            if(t2[i] == time)
            {
            assignMachine = i;
            }

        }
        break;
    case 3:
        for(int i = 0; i < 7; i++){
            if(t3[i] == time)
            {
                assignMachine = i;
            }
        }
        break;
    case 4:
        for(int i = 0; i < 7; i++){
            if(t4[i] == time)
            {
            assignMachine = i;
            }
        }
        break;
    case 5:
        for(int i = 0; i < 7; i++){
            if(t5[i] == time)
            {
                assignMachine = i;
            }
        }
        break;
    case 6:
        for(int i = 0; i < 7; i++){
            if(t6[i] == time)
            {
                assignMachine = i;
            }
        }
        break;
    case 7:
        for(int i = 0; i < 7; i++){
            if(t7[i] == time)
            {
                assignMachine = i;
            }
        }
        break;
    
    default:
        break;
    }
    return assignMachine;
}



int second_smallest_num(int arr[], int n) {
   int smallest_num = INT8_MAX, second_smallest_num = INT8_MAX;
   for (int i = 0; i < n; i++) {
      if (arr[i] < smallest_num) {
         second_smallest_num = smallest_num;
         smallest_num = arr[i];
      }else if (arr[i] < second_smallest_num) {
         second_smallest_num = arr[i];
      }
   }

   return second_smallest_num;
}


void min_Min(){
    std::vector<int> taskMinValue;


// Determine its minimum completion time over all machines
    copy(minValInTasks.begin(), minValInTasks.end(), back_inserter(taskMinValue));





    for(int i = 0; i <= 7; i++){
        
        int min=0, minTime=INT8_MAX;
        //Over all tasks find the minimum completion time
        for(int j = 0; j < taskMinValue.size(); j++){
              


            if(taskMinValue[j] < minTime){
                min = j;
                minTime = taskMinValue[j];
            
            }
        }

        //Assign the task to the machine that gives this completion time

        int val= assignMachine(min, taskMinValue[min]);
        printOutput(min,val);
        taskMinValue[min]=INT8_MAX;

    }
}

void max_Min(){

    std::vector<int> taskMinValue;
//For each task determine its minimum completion time over all machines

    copy(minValInTasks.begin(), minValInTasks.end(), back_inserter(taskMinValue));


//Over all tasks finding the maximum completion time

    for(int i= 0; i <= 7; i++){
        int j, maxValue=0, t=0;
        for(j = 0; j < taskMinValue.size(); j++){

            if(taskMinValue[j] > t){
                maxValue = j;
                t = taskMinValue[j];

            }
        }
        //Assign the task to the machine that gives this completion time
    int val = assignMachine(maxValue, taskMinValue[maxValue]);
        printOutput(maxValue,val);
        taskMinValue[maxValue]=0;

    }
}

void sufferage(){
    std::vector<int> taskMinValue, secondMinValue;

        
//For each task determining the  minimum and second minimum completion time over all machines
    copy(minValInTasks.begin(), minValInTasks.end(), back_inserter(taskMinValue));
// second Min value
    copy(secondMin.begin(), secondMin.end(), back_inserter(secondMinValue));




 
//Over all tasks finding the maximum sufferage and difference as well done here

    for(int i = 0; i <= 7; i++){
        int j, min_val=INT8_MAX, t=0;
        for(j = 0; j < taskMinValue.size(); j++){
            if(secondMinValue[j]-taskMinValue[j] > t && secondMinValue[j] != INT8_MAX && taskMinValue[j] != INT8_MAX){
                min_val = j;
                t = secondMinValue[j]-taskMinValue[j];
               
            }
        }
        int val = assignMachine(min_val, taskMinValue[min_val]);
        printOutput(min_val, val);
        taskMinValue[min_val]=INT8_MAX;
    }
}




// Main Code Section

int main(){
int choice;
char c;

    
    minValInTasks.emplace_back(minValueCheck(t0, 7));
    minValInTasks.emplace_back(minValueCheck(t1, 7));
    minValInTasks.emplace_back(minValueCheck(t2, 7));
    minValInTasks.emplace_back(minValueCheck(t3, 7));
    minValInTasks.emplace_back(minValueCheck(t4,7));
    minValInTasks.emplace_back(minValueCheck(t5,7));
    minValInTasks.emplace_back(minValueCheck(t6,7));
    minValInTasks.emplace_back(minValueCheck(t7,7));

    secondMin.emplace_back(second_smallest_num (t0, 7));
    secondMin.emplace_back(second_smallest_num (t1,7));
    secondMin.emplace_back(second_smallest_num (t2,7));
    secondMin.emplace_back(second_smallest_num (t3,7));
    secondMin.emplace_back(second_smallest_num (t4,7));
    secondMin.emplace_back(second_smallest_num (t5,7));
    secondMin.emplace_back(second_smallest_num (t6,7));
    secondMin.emplace_back(second_smallest_num (t7,7));


//    for (int i=0; i<minValInTasks.size(); i++)
//       cout << minValInTasks[i] << " ";
//       cout<< endl;

            std::cout << "\nChoose the program below that you want to implement: ";
            std::cout <<endl<< "0. Stop the Program or Quit the Program" <<endl<< "1. Min-Min" << endl << "2. Max-Min" << endl << "3. Sufferage"  ;
	        std::cout << endl << "Enter your choice :";
            std::cin >> choice;

            while (choice != 0 ){

            
    
            switch(choice) {
      case 1:  cout << "\nImplementing Min-Min Program \n";
       min_Min();

        break;
      case 2: cout << "\nimplementing Max-Min Program \n";
         max_Min();
        break;
      case 3: cout << "\nimplementing Sufferage Program \n";
         sufferage();
        break;

      default:
        std::cout << "Invalid input";
    }


            std::cout << "\nChoose the program below that you want to implement: ";
            std::cout <<endl<< "0. Stop the Program or Quit the Program" <<endl<< "1. Min-Min" << endl << "2. Max-Min" << endl << "3. Sufferage"  ;
	        std::cout << endl << "Enter your choice or else enter 0 to stop the program :";
            std::cin >> choice;

            }
   

}

