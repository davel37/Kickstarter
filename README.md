# Kickstarter
Kickstarter reward delivery system

Introduction
Your start-up company has just run a successful crowd-funding campaign for
developing a new type of surveillance drone. Backers of the campaign were promised
different types of rewards in return for a financial contribution. Rewards consist of
one or more surveillance drones, and prices depend on the amount of drones requested
and the time during the campaign in which the backer pledged their contribution. For
example, the earliest backers get a single drone for $99, two for $149 and three for
$199, but in week two of the campaign these prices go up to $149, $199 and $249
respectively.
Upon completing mass manufacturing of the drones, the company must decide the
best way to distribute the rewards to all of the campaign backers around the world.
You have been tasked with developing an efficient system to manage this complicated
process.
You are required to implement (using the C programming language) a prototype
management system for Kickstarter reward deliveries. Make use of techniques
covered in the course material: functions, file handling, dynamic memory allocation,
data structures and sorting algorithms.
The Kickstarter Reward Delivery System (KRDS) will have 2 important files: one file
to record information about the project backers and another file to record information
about the rewards each backer is due to receive. The backer’s name, unique backer
ID, email, and address are kept on file. Each reward will have a backer’s ID, price
paid, number of drones, dispatch priority and dispatch date (including time) on file. A
backer can have many rewards, since multiple contributions can be made during the
course of a campaign.
KRDS should provide functions to add backers and rewards, view backer information,
sort backer information by name, view reward by dispatch date, and sort reward by
dispatch priority.
Create a C program to implement the functions described below. Note that you may
add your own utility-style functions in addition to each of the functions required. Note
also that the program should be contained in one file only (i.e. no header files or
multiple source files). Document your code by including comments throughout, for
example, document functions with header comments. (Comments contained just
before the function definition.) Your system should include a short user manual
containing instructions on how to run KRDS as well as pseudo code and/or flowcharts
for each function.
