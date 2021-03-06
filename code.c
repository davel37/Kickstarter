
//The Kickstarter Rewards Delivery System program!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct Backer
 {
int backer_ID;
char backer_name[100];//delcare the backer struct
char email[25];
char country[25];
};  

 struct Reward
 {
int reward_number;
int backer_ID;
float price;       //declare the reward struct
int num_drones;
int priority;
char dispatch_date[20];
 };

struct Backer tempBacker[100];
struct Backer tempBacker2[100];//copy of array to perform bubble sort without changing the original content
struct Backer tempBacker3[100];
struct Reward tempReward[100];
struct Reward tempReward2[100];
struct Reward tempReward3[100];//copy of array to perform bubble sort without changing the original content

int  displayMenu();//declaring the functions in my program
void LoadData();
void new_backer();
void new_reward();
void backers_info();
void sort_backers();
void dispatch_date();
void sort_country();
void sort_priority();
void total_donations();
void save_data();

 int numbacker = 0;//declaring global counters for the two array structs
 int  numreward = 0;
int main ()
{
int menuItem;
 printf(    "\n***************************************\n");
	 printf(" **Kickstarter Reward Delivery System** ");
	 printf("\n***************************************\n");
	   LoadData();
	while ((menuItem = displayMenu()) != 9) {
		
		switch (menuItem)//Developing a switch case for my menu items. Each case will call one of my functions.
		 {
	 case 1:
			 new_backer();
			 break;
	 case 2:
		    new_reward();
			break;
	 case 3: backers_info();
		    break;
	 case 4: 
	        sort_backers();
			break;
	 case 5:
		   dispatch_date();
		   break;
	 case 6: sort_country();
		 break;
	 case 7: sort_priority();
	     break;
	 case 8: total_donations();
		 break;
	 default:
		 printf("Invaid Input %d!\n",menuItem);//if a number higher than 9 is entered
			break;
		 }
	 system("PAUSE"); 
	}
	save_data();//save the data when the exit program is chosen
	system("PAUSE");
	return 0;
}

//Function display menu,returns the options to the main program
 int displayMenu()
 {
	int option;

	 printf("1. Add a new backer:\n");
	 printf("2. Add a new reward:\n"),
	 printf("3. View all backer information:\n");
	 printf("4. Sort backer information by name:\n");
	 printf("5. View reward by dispatch date:\n");
	 printf("6. Sort rewards by delivery location:\n");
	 printf("7. Sort rewards by dispatch priority:\n");
	 printf("8. View the total donations:\n");
	 printf("9  Exit.\n");
	 printf("Enter your choice (1-9): ");
	 scanf("%d",&option);

	 return option;
 }
 //Function Load data. Checks to see if the two files exist,If not create the new files for writing. Unfortunatley due to time I never
 //got around to the dynamic memory allocation,I had hoped to return to it at a later date. Using fscan to scan through the two files and read my data
 //into my two struct arrays.
 void LoadData()
 {
	FILE * BackersPtr;
    FILE * RewardsPtr;
	char backerFilename[50]= "Backers.dat";
	char rewardFilename[50] = "Rewards.dat";
	int backer_ID;
	char backer_name[512];
	char email[20];
	char country[10];
	int reward_number;
	float price;
	int num_drones;
	int priority;
	char dispatch_date[20];

	BackersPtr=fopen(backerFilename,"r");
	if (!BackersPtr){
		printf("Creating Backer File! \n");
		BackersPtr = fopen(backerFilename,"w");
	}
	
	while (fscanf(BackersPtr,"%d %s %s %s", &backer_ID,&backer_name,&email,&country)!=EOF){//Check for end of file
      tempBacker[numbacker].backer_ID =backer_ID;
      strcpy(tempBacker[numbacker].backer_name,backer_name);
      strcpy(tempBacker[numbacker].email,email);
	  strcpy(tempBacker[numbacker].country,country);
	  ++numbacker;
	}
      RewardsPtr = fopen(rewardFilename,"r");

	// Check whether file was opened correctly
	if (!RewardsPtr){
		printf("Creating reward File! \n");
		RewardsPtr = fopen(rewardFilename,"w");
	}
	while (fscanf(RewardsPtr,"%d %d %f %d %d %s",&backer_ID,&reward_number,&price,&num_drones,&priority,&dispatch_date)!=EOF){
	       tempReward[numreward].backer_ID=backer_ID;
	       tempReward[numreward].reward_number =reward_number;
		   tempReward[numreward].price= price;
		   tempReward[numreward].num_drones=num_drones;
		   tempReward[numreward].priority = priority;
		   strcpy(tempReward[numreward].dispatch_date,dispatch_date);
		   ++numreward;
	}
	fclose(BackersPtr);
	fclose(RewardsPtr);
 }

 //Add a new backer to the array, prompt the user to enter the data to fill the four fields of the array.
 void new_backer(){
	 int ID;
	 char name[25];
	 char email[25];
	 char country[25];

	 printf("Add a new backer \n");

	 printf("Add ID number: ");
		 scanf("%d",&ID);
    
     printf("Input name: ");
	 scanf("%s",name);

	 printf("Input email: ");
	 scanf("%s", email);

	 printf("Enter the country: ");
	 scanf("%s",country);

	 tempBacker[numbacker].backer_ID =ID;
	 strcpy(tempBacker[numbacker].backer_name,name);
	 strcpy(tempBacker[numbacker].email,email);
	 strcpy(tempBacker[numbacker].country,country);
	 ++numbacker;

	 printf("New backer %s with ID number %d successfully added\n",name,ID);
 }
 //Add a new rewards to the rewards Array.
 void new_reward(){

	 int ID,reward_no,num_drones,priority;
     float price;
	 char dispatch_date[20];

	 printf("Add a new reward: \n");

	  printf("Enter the dispatch date ( dd/mm/yy): ");
      scanf("%s",dispatch_date);

	 
	 printf("Add ID number: ");
	 scanf("%d",&ID);

	 printf("Add reward number: ");
	 scanf("%d",&reward_no);

	 printf("Add number of drones: ");
      scanf("%d",&num_drones);

	  printf("Add the priority level: ");
	  scanf("%d",&priority);

	  printf("Price Paid: ");
	  scanf("%f", &price);

	  tempReward[numreward].backer_ID = ID;
	  tempReward[numreward].reward_number = reward_no;
	  tempReward[numreward].price = price;
	  tempReward[numreward].num_drones = num_drones;
	  tempReward[numreward].priority =priority;

	  strcpy(tempReward[numreward].dispatch_date,dispatch_date);
	  ++numreward;

	  printf("\nNew reward ID number %d  added\n",ID);
 }
 //Print all the backer info. Printing data from the two arrays.
 void backers_info(){
	 int i,j,backer_id,reward_number,num_drones,priority;
	 char backer_name[100],email[100],country[100],dispatch_date[100];
	
	 printf("View all backers information\n");
     printf("%s %12s %12s %20s %12s %10s %11s %10s", "Backer_ID","Name","Email","Country","Number","Drones","Priority"," Date\n");
     printf("*********************************************************************************************************************\n");


for (i=0;i<numbacker;i++)
for (j=0;j<numreward;j++)

	if (tempBacker[i].backer_ID == tempReward[j].backer_ID)
	printf("%d %20s %20s %10s %10d %10d %11d %15s \n",tempBacker[i].backer_ID,tempBacker[i].backer_name,tempBacker[i].email,
	tempBacker[i].country,tempReward[j].reward_number,tempReward[j].num_drones,tempReward[j].priority,tempReward[j].dispatch_date);
 }
 //Sort the backers by name using Bubblesort,I made a copy of the original array using memcpy so as not to change the data in the backers file.
 //This uses a mixture of bubblesort for strings and bubblesort for integers as we have covered previously in the course. As well as sorting the backer by
 //name we also need to print the backer ID and country. So we need to swap these over at each pass off the Bubblesort.
 void sort_backers(){

	 FILE * File3Ptr; 
	 int    i=0, j=0,tempID;
	 char  temp[512]={0},tempCountry[512]={0};
	 memcpy(&tempBacker2,&tempBacker,sizeof(tempBacker));

	 for (i=0; i<numbacker ; i++){

	 for (j=0; j<numbacker-1; j++){
		
		 if(strcmp(tempBacker2[j].backer_name,tempBacker2[j+1].backer_name)>0)
		 {
			 strcpy(temp,tempBacker2[j].backer_name);
			 tempID=tempBacker2[j].backer_ID;
			 strcpy(tempCountry,tempBacker2[j].country);

			 strcpy(tempBacker2[j].backer_name,tempBacker2[j+1].backer_name);
			 tempBacker2[j].backer_ID=tempBacker2[j+1].backer_ID;
			 strcpy(tempBacker2[j].country,tempBacker2[j+1].country);

			 strcpy(tempBacker2[j+1].backer_name,temp);
			 tempBacker2[j+1].backer_ID = tempID,
		     strcpy(tempBacker2[j+1].country,tempCountry);
		 }
	 }
	 }
	

	 printf("Sorted by backer Name :\n");
		 printf("Backer Name \t|Backer ID  \t| Country\n");
		 printf("***************************************\n");
		 for (j=0; j<numbacker; j++){
			 
			 printf("%s \t \t| %d \t \t|  %s\n",tempBacker2[j].backer_name,tempBacker2[j].backer_ID,tempBacker2[j].country);
		 }

 if ((File3Ptr=fopen("sorted.dat","w"))==NULL){//saving the data to the sorted.dat file
		printf("File could not be opened\n");
 }
 printf("The sorted data is stored in sorted.dat\n");
	 for (i=0; i<numbacker; i++)
fprintf(File3Ptr,"%s %d %s\n",tempBacker2[i].backer_name,tempBacker2[i].backer_ID,tempBacker2[i].country);
 }

 //Here we need to loop through the two arrays and print the data required to the screen. I'm still not fully sure if  my method of using two
 //counters to count through the two arrays and print the data is correct as I have problems with my program crashing, after it prints the information
 //to the screen and I save the data and later try to reopen the file. A problem also lies within my Rewards file so i have one more day to try and figure
 //it out!UPDATE :problem sorted.
 void dispatch_date(){
	 int rewardNo,i;

printf("Please enter the reward ID : ");
scanf("%d",&rewardNo);

printf("Rewards by dispatch date: \n");
printf(" Dispatch date \t| Backer Number | Country\n");
printf("*********************************************\n");
for (i=0; i<numbacker; i++){
for (i=0; i<numreward; i++){

	if(tempReward[i].reward_number ==rewardNo)
		printf("%s \t| %d \t \t|%s \n",tempReward[i].dispatch_date,tempReward[i].backer_ID,tempBacker[i].country);

}
}
 }
 //Perform Bubblesort again to sort by country. Not working!causes program to crash no time left to fix. Will leave here for the bubblesort code.
 void sort_country(){
 
 int i,j;

 char temp[512]={0};
 int swapRewardNo,swapnumDrones;
 memcpy(&tempBacker3,&tempBacker,sizeof(tempBacker));
 memcpy(&tempReward3,&tempReward,sizeof(tempReward));

 for (i=0;i<numbacker;i++){
 for (j=0;j<numbacker -1;j++){
 if (strcmp(tempBacker3[j].country,tempBacker3[j+1].country)>0)
 {

	strcpy(temp,tempBacker3[j].country);
		swapRewardNo  = tempReward3[j].reward_number;
		swapnumDrones = tempReward3[j].num_drones;

		strcpy(tempBacker3[j].country,tempBacker3[j +1].country);
			tempReward3[j].reward_number = tempReward3[j+1].reward_number;
			tempReward3[j].num_drones    = tempReward3[j+1].num_drones;


			strcpy(tempBacker3[j+1].country,temp);
			tempReward3[j+1].reward_number = swapRewardNo;
			tempReward3[j+1].num_drones    = swapnumDrones;
 }
 }
 }
  printf("Rewards sorted by country : \n");
 printf("Country  | Reward Number | Number of drones\n");
 printf("*********************************************\n");
 for (i=0;i<numbacker;i++)
for (i=0;i<numreward;i++)

	 printf("%s  %10s %10s",tempBacker3[i].country,tempReward3[i].reward_number,tempReward3[i].num_drones);
 }
 void sort_priority(){
	 FILE * File4Ptr;
int i, j;
 
float swapPrice;
int swapID,swapDrones,swapNum,temp;
memcpy(&tempReward2,&tempReward,sizeof(tempReward));

for (i=0; i<numreward; i++){
for (j =0; j<numreward-1; j++){

	if	(tempReward2[j].priority>tempReward2[j+1].priority){

	temp       = tempReward2[j].priority;
    swapID     = tempReward2[j].backer_ID;
	swapDrones = tempReward2[j].num_drones;
	swapNum    = tempReward2[j].reward_number;
	swapPrice  = tempReward2[j].price;
	
	tempReward2[j].priority      = tempReward2[j+1].priority;
	tempReward2[j].backer_ID     = tempReward2[j+1].backer_ID;
	tempReward2[j].num_drones    = tempReward2[j+1].num_drones;
	tempReward2[j].reward_number = tempReward2[j+1].reward_number;
	tempReward2[j].price         = tempReward2[j+1].price;
	

	tempReward2[j+1].priority      =   temp;
	tempReward2[j+1].backer_ID     =  swapID;
	tempReward2[j+1].num_drones    =  swapDrones;
	tempReward2[j+1].reward_number =  swapNum;
	tempReward2[j+1].price         =  swapPrice;
}	
}
}
printf("Rewards sorted by dispatch priority:\n");
printf("Priority | Backer ID | No of Drones | Reward No.| Price\n");
printf("*********************************************************\n");
for (j=0; j<numreward; j++){
printf("%d \t  %d \t \t %d \t \t %d \t %.2f\n",tempReward2[j].priority,tempReward2[j].backer_ID,tempReward2[j].num_drones,tempReward2[j].reward_number,
	   tempReward2[j].price);
}
 if ((File4Ptr=fopen("priority.dat","w"))==NULL){//saving the data to the priority.dat file
		printf("File could not be opened\n");
		
 }
 printf("The sorted data is stored in priority.dat\n");

   for (i=0;i<numreward;i++)

fprintf(File4Ptr,"%d %d %d %d %.2f\n",tempReward2[i].priority,tempReward2[i].backer_ID,tempReward2[i].num_drones,tempReward2[i].reward_number,
		tempReward2[i].price);
 
 }
 void total_donations()
 {
int i,j, drones=0;
float  total = 0,cost;

for (i=0;i<numreward;i++){

total += tempReward[i].price;
}
printf ("The total money donated is $%.2f\n",total);

for (j=0;j<numreward;j++){
	drones += tempReward[j].num_drones;
 
}
printf("The total number of drones to be delivered is %d\n",drones);
printf("\nThe average cost of a drone is $%.2f\n",(float) cost = total/drones);
 }

 void save_data()//Open the two files for writing and save the data when the exit menu option is chosen.
 {
	  FILE * BackerPtr;
	  FILE * RewardPtr;
	  int i;

	  BackerPtr = fopen("Backers.dat","w");
	  RewardPtr = fopen("Rewards.dat","w");

	  if (!BackerPtr){
	  printf("Error opening file! \n");

	  }
	  for(i=0;i<numbacker;++i)
		  fprintf(BackerPtr,"%d %s %s %s\n",tempBacker[i].backer_ID,tempBacker[i].backer_name,tempBacker[i].email,tempBacker[i].country);

	  if (!RewardPtr){
		  printf("Error opening file!\n");
	  }
		  for (i=0;i<numreward;++i)
		fprintf(RewardPtr,"%d %d %.2f %d %d %s\n",tempReward[i].backer_ID,tempReward[i].reward_number,tempReward[i].price,tempReward[i].num_drones,tempReward[i].priority,tempReward[i].dispatch_date);

		  fclose(BackerPtr);
		  fclose(RewardPtr);

		  printf("Saving Data to file\n");
	  }
